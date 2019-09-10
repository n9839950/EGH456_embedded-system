/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Seconds.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/drivers/I2C.h>
#include "inc/hw_memmap.h"

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

//ADDED
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "grlib/grlib.h"
#include "grlib/widget.h"
#include "grlib/canvas.h"
#include "grlib/pushbutton.h"
#include "drivers/Kentec320x240x16_ssd2119_spi.h"
#include "drivers/touch.h"
#include "driverlib/udma.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include <math.h>
//Motorstuff

#include <ti/drivers/PWM.h>
#include <ti/drivers/GPIO.h>
#include "inc/hw_ints.h"


/* Board Header file */
#include "Board.h"
#include "GUI.h"


// ----------------------- LIGHT REGISTERS AND SLAVE ADDRESS - Constants -----------------------

// Slave address
#define OPT3001_I2C_ADDRESS             0x47
#define OPT3001_I2C_ADDRESS_R           0xC7

// Register addresses
#define REG_RESULT                      0x00
#define REG_CONFIGURATION               0x01
#define REG_LOW_LIMIT                   0x02
#define REG_HIGH_LIMIT                  0x03
#define REG_MANUFACTURER_ID             0x7E
#define REG_DEVICE_ID                   0x7F

// Register values
#define MANUFACTURER_ID                 0x5449  // TI
#define DEVICE_ID                       0x3001  // Opt 3001
#define CONFIG_RESET                    0xC810
#define CONFIG_TEST                     0xCC10
//#define CONFIG_ENABLE                   0x10C4 // 0xC410   - 100 ms, continuous
#define CONFIG_ENABLE                   0x70C4 // 0xC410   - 100 ms, continuous
#define CONFIG_DISABLE                  0x10C0 // 0xC010   - 100 ms, shutdown

// Bit values
#define DATA_RDY_BIT                    0x0080  // Data ready


////////////////////////// ADC DEFUNITIONS ////////////////////////////////////
#ifndef MAXIMUM_BYTES_SIZE
    #define MAXIMUM_BYTES_SIZE 4096.0
#endif
#ifndef VOLTAGE
    #define VOLTAGE 3.3
#endif
#ifndef REFERENCE_VOLTAGE
    #define REFERENCE_VOLTAGE 2.5
#endif
#ifndef VOLTAGE_OFFSET
    #define VOLTAGE_OFFSET 0.5
#endif
/////////////////////////////////////////////////////////////////////////////

// Showing variables for GUI
#define DAY_LUX_LIMIT 5
#define MAX_PWM 65535
#define PERIOD_PWM 50
#define RPM_AVG_SAMPLE 8

#define SET_TEMP_DEFAULT 200 //celsius
#define SET_MOTOR_SPEED_DEFAULT 2000 // RPM
#define SET_ACCEL_DEFAULT 70 // m/s
#define SET_CURR_DEFAULT 60 //amps
#define DUTY_PER_RAD_S 0.1719354
#define MOTOR_LED Board_LED0
#define LUX_LED Board_LED1

#define GRAPH_SECONDS_TO_GRAPH 5 // the time interval of data to  graph
#define ADC_SAMPLE_RATE 2
#define LUX_TIMEOUT_RATE 100 //ms
#define GUI_CLOCK_RATE 1000

uint32_t adcLatestSampleOne;
uint16_t adcLatestSampleTwo;
uint16_t rpmLatestSample;
uint16_t luxLatestSample;

#define I2C_READ_BUFF 2
#define I2C_WRITE_BUFF 1
#define LUX_SAMPLES_AVG 5


Bool isDayTime;
uint8_t settingTempLimit;
uint16_t settingMotorSpeed;
uint16_t settingCurrentLimit;
uint16_t settingAccelLimit;

// Variables for LUX
float convertedLux[10];
uint16_t readBufferGlobal;
float luxBuff[65];

// variables for ADC
Swi_Struct swiStructADC;
Swi_Handle swiHandleADC;
Clock_Struct clockStructADC;

#define STACKSIZE           2048//512
tContext sContext;
GUIParams uiParams;
Char taskStackGUI[STACKSIZE];
Char taskStackLight[STACKSIZE];
Char taskStackMotor[STACKSIZE];
Bool drawTime;
Task_Handle taskHandleGUI,taskHandleLight;
Clock_Struct clk0Struct;

// Function - Initialization
void clockFxnGUITime(UArg arg0);
void taskFxnGUI(UArg arg0, UArg arg1);
void setSystemTime();


/////////////// LIGHT SENSOR FUNCTIONS //////////////////////

void write_i2c(I2C_Handle handle, uint8_t writeBuffer[3], uint8_t count)
{
    uint8_t ok;
    I2C_Transaction i2cTransaction;
    i2cTransaction.slaveAddress = OPT3001_I2C_ADDRESS; // 7-bit peripheral slave address
    i2cTransaction.writeCount = count; // number of bytes to be written
    i2cTransaction.writeBuf = writeBuffer; // buffer to be written
    i2cTransaction.readCount = 0; // numbers of bytes to be read
    i2cTransaction.readBuf = NULL; // buffer to be read
    ok = I2C_transfer(handle, &i2cTransaction); // Perform i2c transfer
    if (!ok) {
        System_printf("I2C - Could not write");
    } else {
        System_printf("I2C - Write success");
    }
    System_flush();
}

void read_i2c(I2C_Handle handle, uint16_t *rawData, uint8_t lightRegister)
{
    I2C_Transaction i2cTransaction;
    uint8_t txBufferLight[1];
    static uint8_t rBuff[2];
    txBufferLight[0] = lightRegister;

    i2cTransaction.slaveAddress = OPT3001_I2C_ADDRESS;
    i2cTransaction.writeBuf = txBufferLight;
    i2cTransaction.writeCount = I2C_WRITE_BUFF;
    i2cTransaction.readBuf = rBuff;
    i2cTransaction.readCount = I2C_READ_BUFF;
    uint8_t ok;
    ok = I2C_transfer(handle, &i2cTransaction); // Perform i2c transfer
    if (!ok) {
        //System_printf("I2C - Could not read");
    } else {
        //System_printf("I2C - Read Success");
    }
    //System_flush();
    // Set pointer to new bit value
    *rawData = ((uint16_t)rBuff[0] << 8) + rBuff[1];
}

Bool readMethod(I2C_Handle handle, uint16_t *readBuffer) {
    read_i2c(handle, (uint16_t *)readBuffer, REG_CONFIGURATION);
    Bool readSuccess;
    if((*readBuffer & DATA_RDY_BIT) == DATA_RDY_BIT)
    {
        readSuccess=1;
        read_i2c(handle, (uint16_t *)readBuffer, REG_RESULT);
    }else
    {
        readSuccess = 0;
        *readBuffer = 0;
    }
    return readSuccess;
}
// From example
void convertRawLight(uint16_t readBuffer, float *convertedLux) {
    uint16_t e, m;
    m = readBuffer & 0x0FFF;
    e = (readBuffer & 0xF000) >> 12;
    *convertedLux = m * (0.01 * exp2(e));
}
Void taskFxnLight(UArg arg0, UArg arg1)
{
    unsigned int    i = 0;
    Bool            readMethodSuccess;
    uint16_t        rxBufferLight;
    uint8_t         txBufferLight[3];
    I2C_Handle      i2cLight;
    I2C_Params      i2cParams;
    float           samples[LUX_SAMPLES_AVG];

    /* Create I2C for usage */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;
    i2cLight = I2C_open(Board_I2C_light, &i2cParams);
    if (i2cLight == NULL)
    {
        System_printf("I2C - Could not open\n");
    }
    else
    {
        System_printf("I2C - Open success\n");
    }
    System_flush();

    /* Set up configuration registers and perform initial write action
     * First byte - Continous mode, Auto full scale mode, 100ms time conversion
     * Second byte - Interrupt reporting mechanisms - FH and FL both set and end of conversion
     *               will set bit 1 to 1.
     */
    txBufferLight[0] = REG_CONFIGURATION;
    txBufferLight[1] = CONFIG_ENABLE & 0xFF;  // 0b11000100 - first config byte
    txBufferLight[2] = CONFIG_ENABLE >> 8; // 0b1110000 - second config byte
    write_i2c(i2cLight, txBufferLight, 3);
    for(;;) {
        readMethodSuccess = readMethod(i2cLight, &rxBufferLight);
        if (readMethodSuccess) {
            readBufferGlobal = rxBufferLight;
            convertRawLight(rxBufferLight, &samples[i]);
            // Average the lux
            if (i == LUX_SAMPLES_AVG-1) {
               i = 0;
               luxBuff[1] = (samples[0] +samples[1]+ samples[2]+samples[3]+samples[4])/LUX_SAMPLES_AVG;
           }
           else i++;
        }
        readBufferGlobal = luxBuff[1];
       // System_printf("luxBuff: %f\n", luxBuff[1]);
        luxLatestSample = luxBuff[1];
        if(luxBuff[1] < DAY_LUX_LIMIT)
        {
            isDayTime = 0;
            GPIO_write(LUX_LED,Board_LED_ON);

        }else{
            isDayTime = 1;
            GPIO_write(LUX_LED,Board_LED_OFF);
        }

        //System_flush();
        Task_sleep(LUX_TIMEOUT_RATE);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////// ADC FUNCTONS ///////////////////////////////////////////////

uint32_t processedGlobal;
uint32_t ui32Count;
uint32_t adcOneRaw[8];
uint32_t adcTwoRaw[8];
void initCurrentSensors(uint32_t ui32SysClock)
{
    //Enable the ADCs and GPIOS
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    // Set the Pin types - Data direction to input
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
    GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_7);

    // Setup sequencers
    ADCSequenceConfigure(ADC1_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceConfigure(ADC1_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);

    ADCSequenceStepConfigure(ADC1_BASE, 0, 0, ADC_CTL_IE | ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC1_BASE, 1, 0, ADC_CTL_IE | ADC_CTL_CH4);

    // Enable
    ADCSequenceEnable(ADC1_BASE, 0);
    ADCSequenceEnable(ADC1_BASE, 1);

    ADCIntEnable(ADC1_BASE,0);
    ADCIntEnable(ADC1_BASE,1);

    ADCIntClear(ADC1_BASE, 0);
    ADCIntClear(ADC1_BASE, 1);;
}
uint32_t check45;
uint32_t currentProcessedOneMilliVolts;
uint32_t currentProcessedTotalMilliVolts;
uint32_t milliAmpsOne;
uint32_t milliAmpsTotal;
Void swiFxnADC(UArg arg0, UArg arg1)
{
   uint32_t avgOne = 0;
   uint32_t avgTwo = 0;
   uint32_t avgTotal = 0;
   uint8_t index = 0;
   adcLatestSampleOne = 0;
   for (; index < 8; index++){
           avgOne += adcOneRaw[index];
           if (index < 4) {
               avgTwo += adcTwoRaw[index];
           }
   }
   avgTwo = avgTwo/8;
   avgOne = avgOne/8;
   adcLatestSampleOne = (avgOne+avgTwo)/2;
//   adcLatestSampleOne = avgOne;
//   //currentProcessed = (uint32_t)(((((((float)avg )/ MAXIMUM_BYTES_SIZE)*VOLTAGE)-REFERENCE_VOLTAGE)/VOLTAGE_OFFSET)*1000.0);
//   currentProcessedOneMilliVolts = avgOne*3300/4095;
//   milliAmpsOne = (currentProcessedOneMilliVolts/3.3) + 30;

//   uint32_t avgTwo = 0;
//   index = 0;
//   for (; index < 8; index++){
//           avgTwo += adcTwoRaw[index];
//   }
//   avgTwo = avgTwo/8;
//   avgTotal = (avgOne + avgTwo)/2;
//
//   adcLatestSampleOne = avgTotal;
//   currentProcessedTotalMilliVolts = avgTotal*3300/4095;
//   milliAmpsTotal = ((currentProcessedTotalMilliVolts/3.3) + 30)/1000;
}
void clockFxnADC(UArg arg0)
{
    ADCProcessorTrigger(ADC1_BASE,0);
    ADCProcessorTrigger(ADC1_BASE,1);
}
void hwiFxnADC(UArg arg0, UArg arg1) {
    uint32_t pui32ADC1Value[8];
    uint32_t pui32ADC2Value[8];

    // Clear the ints
    ADCIntClear(ADC1_BASE,0);
    ADCIntClear(ADC1_BASE,1);

    ui32Count= ADCSequenceDataGet(ADC1_BASE,0,pui32ADC1Value);
    ui32Count= ADCSequenceDataGet(ADC1_BASE,1,pui32ADC2Value);

    uint8_t index = 0;
    for (;index < 8; index++) {
        adcOneRaw[index] = pui32ADC1Value[index];
        adcTwoRaw[index] = pui32ADC2Value[index];
    }
    Swi_post(swiHandleADC);
}

//////////////////////////////////////////////////////////////////////////////////////


/////////////////////////// GUI FUNCTIONS /////////////////////////////////////////////
// Notifies the task when to update the time
void clockFxnGUITime(UArg arg0)
{
    drawTime = 1;
}
// Tasks Function to draw the interface
void taskFxnGUI(UArg arg0, UArg arg1)
{
    while(1)
    {
        GUIDrawView(&uiParams, &sContext);
    }
}

Bool setupGUI(uint32_t ui32SysClock){
    Task_Params taskParamsGUI;
    Clock_Params clkParamsGUI;
    Task_Params_init(&taskParamsGUI);
    taskParamsGUI.stackSize = STACKSIZE;
    taskParamsGUI.priority = 1;
    taskParamsGUI.stack = &taskStackGUI;
    taskParamsGUI.arg0 = ui32SysClock;
    taskHandleGUI = Task_create((Task_FuncPtr)taskFxnGUI, &taskParamsGUI, NULL);
    if (taskHandleGUI == NULL) {
        System_printf("Task - GUI FAILED SETUP");
        System_flush();
        return 0;
    }
    // Clock - Periodic interval for update clock on GUI
    Clock_Params_init(&clkParamsGUI);
    clkParamsGUI.period = GUI_CLOCK_RATE;
    clkParamsGUI.startFlag = TRUE;
    Clock_construct(&clk0Struct, (Clock_FuncPtr)clockFxnGUITime,
                    GUI_CLOCK_RATE, &clkParamsGUI);
    return 1;
}

Bool setupADC(){
    Clock_Params clkParamsADC;
    Hwi_Params hwiParamsADC;
    Swi_Params swiParamsADC;
    // Hardware interrupt for ADC trigger
    Hwi_Handle hwiHandleADC;
    Hwi_Params_init(&hwiParamsADC);
    hwiParamsADC.arg = 1;
    hwiParamsADC.priority = 0;
    hwiHandleADC = Hwi_create(62, (Hwi_FuncPtr)hwiFxnADC, &hwiParamsADC, NULL);
    if (hwiHandleADC == NULL) {
        System_printf("HWI - ADC FAILED SETUP");
        System_flush();
        return 0;
    }
    // SWI to handle processing of currents
    Swi_Params_init(&swiParamsADC);
    swiParamsADC.arg0 = 1;
    swiParamsADC.arg1 = 0;
    swiParamsADC.priority = 2;
    swiParamsADC.trigger = 0;
    Swi_construct(&swiStructADC, (Swi_FuncPtr)swiFxnADC, &swiParamsADC, NULL);
    swiHandleADC = Swi_handle(&swiStructADC);
    if (swiHandleADC == NULL) {
        System_printf("SWI - ADC FAILED SETUP");
        System_flush();
        return 0;
    }
    // Clock - Periodic interval for update clock on GUI
    Clock_Params_init(&clkParamsADC);
    clkParamsADC.period = ADC_SAMPLE_RATE;
    clkParamsADC.startFlag = TRUE;
    Clock_construct(&clockStructADC, (Clock_FuncPtr)clockFxnADC,100, &clkParamsADC);
    return 1;
}
Bool setupLight(uint32_t ui32SysClock){
    Task_Params taskParamsLight;
    /* Construct LIGHT Task thread */
   Task_Params_init(&taskParamsLight);
   taskParamsLight.stackSize = STACKSIZE;
   taskParamsLight.priority = 2;           // MUST BE HIGHER THEN GUI UPDATE
   taskParamsLight.stack = &taskStackLight;
   taskParamsLight.arg0 = ui32SysClock;
   taskHandleLight = Task_create((Task_FuncPtr)taskFxnLight, &taskParamsLight, NULL);
   if (taskHandleLight == NULL) {
       System_printf("TASK - LIGHT FAILED SETUP");
       System_flush();
       return 0;
   }
   return 1;
}
///////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    // Parameters
    Bool setupSuccess;
    adcLatestSampleOne=0;
    adcLatestSampleTwo=0;
    rpmLatestSample=0;
    luxLatestSample=0;
    // Intialialise board stuff
    Board_initGeneral();
    Board_initGPIO(); // For everything
    Board_initI2C(); // For light

    uint32_t ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
                                                SYSCTL_CFG_VCO_480), 120000000);
    ////////// SETUP TASKS ///////////////

    // Set limit default values
    settingTempLimit = SET_TEMP_DEFAULT;
    settingMotorSpeed = SET_MOTOR_SPEED_DEFAULT;
    settingCurrentLimit = SET_CURR_DEFAULT;
    settingAccelLimit = SET_ACCEL_DEFAULT;

    // ==========  User Interface SETUP =======================
    setupSuccess = setupGUI(ui32SysClock);
    if(!setupSuccess) System_exit(0);

    // ==========  Light Sensor SETUP =========================
    setupSuccess = setupLight(ui32SysClock);
    if(!setupSuccess) System_exit(0);

    //============= ADC SETUP ================================
    setupSuccess = setupADC();
    if(!setupSuccess) System_exit(0);

    /////////// Startup procedures //////////////
    // GUI
    GUIInit(ui32SysClock, &sContext, &uiParams);
    // ADC
    initCurrentSensors(ui32SysClock);

    /* Start BIOS */
    BIOS_start();
    return (0);
}


///////////////////// TODO - Known faults ////////////////////////

// Currently the read and write I2C cause the program to just skip out of the task and stop executing
//  FIX - This should be fixed wheen using a system with sensor board acutally attached, think it fails hard because it cant see anything.

// Check ADC values being output are correct
//  NOTE - Seems to be outputting same in class machine as hoome, this could be that both ahve same v accross pins, maybe not???

// If ADC samples at 2ms theen graphics takes forever to draw becaus the HWI is so damn frequent
// NOTE - 200 seems to work well
// FIXEDDDDD - Any system print_f and flush slows it down so much so its not even functional


// PWM cannot PWM_open to create the handler. Somethings is wrong here
//  NOTE - likely becuase it cant see it(not attached).

// Havent tested the System_exit;

// CHeck date shows correct (sat, sun, monday etc) when plugged in

// Test lux light works

// STARTING AND STOPPING MOTOR DEOSNT WORK ATM BECAUSE OF motor not attached
