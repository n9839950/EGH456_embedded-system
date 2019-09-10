#ifndef GUI_H_
    #define GUI_H_
#include <ti/drivers/GPIO.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <xdc/runtime/System.h>
// SHIT FROM INTERFACE BUTTOn
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "grlib/grlib.h"
#include "grlib/widget.h"
#include "grlib/canvas.h"
#include "grlib/pushbutton.h"
#include "drivers/frame.h"
#include "drivers/kentec320x240x16_ssd2119_spi.h"
#include "drivers/pinout.h"
#include "drivers/touch.h"
#include "drivers/buttons.h"
#include <time.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>
#include "driverlib/udma.h"

//*****************************************************************************
//
// The DMA control structure table.
//
//*****************************************************************************
#ifdef ewarm
#pragma data_alignment=1024
tDMAControlTable psDMAControlTable[64];
#elif defined(ccs)
#pragma DATA_ALIGN(psDMAControlTable, 1024)
tDMAControlTable psDMAControlTable[64];
#else
tDMAControlTable psDMAControlTable[64] __attribute__ ((aligned(1024)));
#endif


#ifndef VIEW_0
    #define VIEW_0 0
#endif
#ifndef VIEW_1
    #define VIEW_1 1
#endif
#ifndef VIEW_2
    #define VIEW_2 2
#endif
#ifndef VIEW_3
    #define VIEW_3 3
#endif
#ifndef VIEW_4
    #define VIEW_4 4
#endif

#ifndef DEFAULT_VIEW_OPTION_NUM
    #define DEFAULT_VIEW_OPTION_NUM 0
#endif
#ifndef VIEW_0_OPTION_NUM
    #define VIEW_0_OPTION_NUM 1
#endif
#ifndef VIEW_1_OPTION_NUM
    #define VIEW_1_OPTION_NUM 4
#endif
#ifndef VIEW_2_OPTION_NUM
    #define VIEW_2_OPTION_NUM 5
#endif
#ifndef VIEW_3_OPTION_NUM
    #define VIEW_3_OPTION_NUM 2
#endif

#ifndef MOTOR_IDLE
    #define MOTOR_IDLE      1
#endif
#ifndef MOTOR_RUNNING
    #define MOTOR_RUNNING   3
#endif

#ifndef BUTTON_NONE
    #define BUTTON_NONE 0
#endif
#ifndef BUTTON_DOWN
    #define BUTTON_DOWN 1
#endif
#ifndef BUTTON_SELECT
    #define BUTTON_SELECT 2
#endif

// GRAPHING
//#define ADC_GRAPH_HIGH 390
//#define ADC_GRAPH_LOW 350
#define ADC_GRAPH_HIGH 300
#define ADC_GRAPH_LOW 175

#define LUX_GRAPH_LOW 0
#define LUX_GRAPH_HIGH 10

#define RPM_GRAPH_LOW 0
#define RPM_GRAPH_HIGH 5000

#define GRAPH_X_SAMPLES 100


typedef struct MotorParams{
    uint8_t cState; // The current motor state
    uint8_t nState; // The desired motor state
}MotorParams;


typedef struct GUIParams{
    uint8_t cView;      // Current page
    uint8_t cInterItem; //  Selected interaction item within a page
    uint8_t cSubView;   // The sub view to show (determines different graphs/settings, accel, power,speed, etc.)
}GUIParams;

/*!
 *  @brief  Initialises the grpahical user interface.
 *
 *  @pre    Graphics library linked and GPIO enabled
 *
 *  @param  systemclock       The systems clock speed.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
void GUIInit(uint32_t systemclock, tContext * sContext, GUIParams * params);
/*!
 *  @brief  Draws the correct view in the graphical user interface
 *
 *  @pre    GUIinit()
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
void GUIDrawView(GUIParams * params, tContext * sContext);


// From GUI.c
// Function Initialization
/*!
 *  @brief  Gets the current date time as a string and returns.
 *
 * *
 */
static char * getCurrentDateTime();
/*!
 *  @brief  Draws the current date and time to the screen. Also draws the lux symbol.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 * *
 */
void DrawDateTime(tContext *sContext);
/*!
 *  @brief  Draws the current view to the GUI
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
void GUIDrawView(GUIParams *, tContext *);
/*!
 *  @brief  Visually update the current selection on the current view.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void updateMenuOptions(GUIParams *);
/*!
 *  @brief  Draws the menu screen for setting values.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawSetMenuScreen(tContext *, GUIParams *);
/*!
 *  @brief  Draws the menu screen for graphing values.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawGraphMenuScreen(tContext * sContext, GUIParams *);
/*!
 *  @brief  Draws the correct buttons and labels to the screen for the selected view.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static int16_t SetupSettingScreen(tContext *,GUIParams *);
/*!
 *  @brief  Set the limits chosen in the setting view that will then be read by the appropriate device.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void SaveSettings(GUIParams *, uint16_t newValue);
/*!
 *  @brief  Draws the setting screen with the previously setupSettingScreen()
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawSettingScreen(tContext *, GUIParams *);
/*!
 *  @brief  Triggers LED, GUI and motor state updates.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void GuiMotorClicked(GUIParams *);
/*!
 *  @brief  Draws the current view to the GUI
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawDataOnGraph(tContext *,GUIParams *);
/*!
 *  @brief  Draws the correct buttons, labels and data to the screen for the selected view.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void SetupGraphScreen(tContext *,GUIParams *);
/*!
 *  @brief  Draws the setting screen with the previously SetupGraphScreen().
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawGraphScreen(tContext *, GUIParams *);
/*!
 *  @brief  Draws the home screen
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static void DrawHomeScreen(tContext *, GUIParams *);
/*!
 *  @brief  Dictates the GUI screen control based on the current view and buttons pressed.
 *
 *  @param  sContext         The drawing context for the graphics library.
 *
 *  @param  params         The GUIParams that carry the state of the display.
 * *
 */
static uint8_t checkUiControls(GUIParams *, uint8_t);


// Global test variables
extern Bool drawTime;
extern Bool isDayTime;
extern uint8_t settingTempLimit;
extern uint16_t settingMotorSpeed;
extern uint16_t settingCurrentLimit;
extern uint16_t settingAccelLimit;
extern MotorParams MotorTracker;
extern uint16_t adcSampleCount;
extern uint32_t adcLatestSampleOne;
extern uint16_t rpmLatestSample;
extern uint16_t luxLatestSample;
uint16_t adcGraphSamples[GRAPH_X_SAMPLES];
uint16_t graphedPointsCount;

 /* GUI_H_ */
#endif
