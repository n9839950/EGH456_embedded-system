#include "GUI.h"

// GUI - Canvas Drawing
// Set/Graph Menu Selection
Canvas(g_sMenuTypePage, WIDGET_ROOT, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);//0x00E09873

RectangularButton(g_sSetOption, &g_sMenuTypePage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 145, 200,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrBlack, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Control", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphOption, &g_sMenuTypePage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 145, 200,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Graph", 0, 0, 0, 0, 0);

// Set Menu Selection
Canvas(g_sMenuSetPage, &g_sMenuTypePage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240  -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sSetTemp, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Temp", 0, 0, 0, 0, 0);
RectangularButton(g_sSetMotor, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Motor", 0, 0, 0, 0, 0);
RectangularButton(g_sSetCurrent, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 115, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Current", 0, 0, 0, 0, 0);
RectangularButton(g_sSetAccel, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 115, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Accel", 0, 0, 0, 0, 0);
RectangularButton(g_sSetBack, &g_sMenuSetPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Back To Home", 0, 0, 0, 0, 0);

// Graph Menu Selection
Canvas(g_sMenuGraphPage, &g_sMenuTypePage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sGraphPower, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Power", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphSpeed, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 161, 25, 149, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Speed", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphAccel, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Accel", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphTemp, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 113, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Temp", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphLight, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 214, 115, 96, 80,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Light", 0, 0, 0, 0, 0);
RectangularButton(g_sGraphBack, &g_sMenuGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Back To Home", 0, 0, 0, 0, 0);

// Settings Pages
Canvas(g_sSettingPage, &g_sSetTemp, 0, 0,
       &g_sKentec320x240x16_SSD2119, 10, 25, 300, (240 - 25 -10),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sSetAdd, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 200, 35, 100, 70,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "+", 0, 0, 0, 0, 0);

RectangularButton(g_sSetSub, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 200, 120, 100, 70,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "-", 0, 0, 0, 0, 0);

CircularButton(g_sSetMotorMode, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 150, 70, 35,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x0023A369, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Turn On", 0, 0, 0, 0, 0);

RectangularButton(g_sSetSave, &g_sSettingPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 200, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, 0x00AED1D6, ClrWhite,
                   g_psFontCmss18b, "Confirm", 0, 0, 0, 0, 0);


// Graphing Page
Canvas(g_sGraphPage, &g_sMenuGraphPage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 0, 0, 320, (240 - 0 -0),
       CANVAS_STYLE_FILL, 0x007584AD, 0, 0, 0, 0, 0, 0);
Canvas(g_sGraph, &g_sGraphPage, 0, 0,
       &g_sKentec320x240x16_SSD2119, 20, 55, 280, 140,
       CANVAS_STYLE_FILL, 0x00314570, 0, 0, 0, 0, 0, 0);

RectangularButton(g_sGraphActBack, &g_sGraphPage, 0, 0,
                  &g_sKentec320x240x16_SSD2119, 10, 219, 300, 20,
                  (PB_STYLE_OUTLINE | PB_STYLE_TEXT_OPAQUE | PB_STYLE_TEXT |
                    PB_STYLE_FILL | PB_STYLE_RELEASE_NOTIFY),
                    0x00314570, ClrWhite, ClrWhite, ClrWhite,
                   g_psFontCmss18b, "Back", 0, 0, 0, 0, 0);



// Gets the current date and time
static char * getCurrentDateTime()
{
    static char t[30];
    struct tm * timeinfo;
    time_t t1 = time (NULL);
    timeinfo = localtime ( &t1 );
    timeinfo->tm_hour += 16;
    if (timeinfo->tm_hour>24){
        timeinfo->tm_hour -= 24;
        timeinfo->tm_mday +=1;
    }
    strcpy(t,asctime(timeinfo));
    return t;
}

uint8_t isButtonPressed()
{
    static unsigned char ucDelta = 0;
    static unsigned char ua = 0;
    static unsigned char ucState =0;
    ucState = ButtonsPoll(&ucDelta, &ua);
    if (BUTTON_PRESSED(SELECT_BUTTON, ucState, ucDelta) )
    {
        return BUTTON_SELECT;
    }
    if (BUTTON_PRESSED(DOWN_BUTTON, ucState, ucDelta) )
    {
        return BUTTON_DOWN;
    }
    return BUTTON_NONE;
}

// Draws the date, time and lux sensor results to the title bar
void DrawDateTime(tContext * sContext)
{
    if(drawTime)
    {
        if (isDayTime){
            GrContextForegroundSet(sContext, 0x00FFC300);
            GrCircleFill(sContext,5, 5,10);
            GrLineDraw(sContext,15, 15, 20, 20);
            GrLineDraw(sContext,18, 10, 23, 13);
            GrLineDraw(sContext,19, 5,25,6);
        }else{
            GrContextForegroundSet(sContext, 0x00D8D4D5);
            GrCircleFill(sContext,5, 5,10);
            GrContextForegroundSet(sContext, 0x007584AD);
            GrLineDraw(sContext,15, 15, 20, 20);
            GrLineDraw(sContext,18, 10, 23, 13);
            GrLineDraw(sContext,19, 5,25,6);
        }
        GrContextBackgroundSet(sContext, 0x007584AD);
        GrContextForegroundSet(sContext, ClrWhite);
        GrContextFontSet(sContext, g_psFontCmss18b);
        GrStringDrawCentered(sContext, getCurrentDateTime(), -1, 160, 8, true);
        GrFlush(sContext);
        drawTime = 0;
    }
}

// Initialises the user interface
void GUIInit(uint32_t systemclock, tContext * sContext, GUIParams * params)
{

    Kentec320x240x16_SSD2119Init(systemclock);
    GrContextInit(sContext, &g_sKentec320x240x16_SSD2119);
    SysCtlDelay(10);


    params->cView = VIEW_0;
    params->cSubView = 0;
    params->cInterItem = VIEW_0;
    graphedPointsCount = 0;
    ButtonsInit();

    GrContextBackgroundSet(sContext, 0x007584AD);
    GrContextForegroundSet(sContext, ClrWhite);
    GrContextFontSet(sContext, g_psFontCmss18b);

    // New Main Screen
    WidgetAdd(WIDGET_ROOT, (tWidget *)&g_sMenuTypePage);
    WidgetAdd((tWidget *)&g_sMenuTypePage, (tWidget *)&g_sSetOption);
    WidgetAdd((tWidget *)&g_sMenuTypePage, (tWidget *)&g_sGraphOption);

    // Set menu
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetTemp);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetCurrent);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetMotor);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetAccel);
    WidgetAdd((tWidget *)&g_sMenuSetPage, (tWidget *) &g_sSetBack);

    // Graph Menu
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphTemp);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphSpeed);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphPower);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphAccel);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphLight);
    WidgetAdd((tWidget *)&g_sMenuGraphPage, (tWidget *) &g_sGraphBack);

    // Settings page
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetAdd);
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetSub);
    WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetSave);
   // WidgetAdd((tWidget *)&g_sSettingPage, (tWidget *) &g_sSetMotorMode);

    // Graph page
    WidgetAdd((tWidget *)&g_sGraphPage, (tWidget *) &g_sGraph);
    WidgetAdd((tWidget *)&g_sGraphPage, (tWidget *) &g_sGraphActBack);
}

// Visually updates the selection on each page
static void updateMenuOptions(GUIParams * param)
{
    tPushButtonWidget *prev;
    tPushButtonWidget *curr;
    switch(param->cView)
    {
        case VIEW_0:
            switch(param->cInterItem)
            {
                case 0:
                    prev = &g_sGraphOption;
                    curr = &g_sSetOption;
                    break;
                case 1:
                    curr = &g_sGraphOption;
                    prev = &g_sSetOption;
                    break;
            }
            break;
        case VIEW_1:
            switch(param->cInterItem)
            {
                case 0:
                    prev = &g_sSetBack;
                    curr = &g_sSetTemp;
                    break;
                case 1:
                    prev = &g_sSetTemp;
                    curr = &g_sSetMotor;
                    break;
                case 2:
                    prev = &g_sSetMotor;
                    curr = &g_sSetCurrent;
                    break;
                case 3:
                    prev = &g_sSetCurrent;
                    curr = &g_sSetAccel;
                    break;
                case 4:
                    prev = &g_sSetAccel;
                    curr = &g_sSetBack;
                    break;
            }
            break;
        case VIEW_2:
            switch(param->cInterItem)
            {
                case 0:
                    prev = &g_sGraphBack;
                    curr = &g_sGraphPower;
                    break;
                case 1:
                    prev = &g_sGraphPower;
                    curr = &g_sGraphSpeed;
                    break;
                case 2:
                    prev = &g_sGraphSpeed;
                    curr = &g_sGraphAccel;
                    break;
                case 3:
                    prev = &g_sGraphAccel;
                    curr = &g_sGraphTemp;
                    break;
                case 4:
                    prev = &g_sGraphTemp;
                    curr = &g_sGraphLight;
                    break;
                case 5:
                    prev = &g_sGraphLight;
                    curr = &g_sGraphBack;
                    break;
            }
            break;
        case VIEW_3:
            switch(param->cInterItem)
            {
                case 0:
                    prev = &g_sSetSave;
                    curr = &g_sSetAdd;
                    if (param->cSubView == 1){
                        PushButtonOutlineColorSet(&g_sSetMotorMode, 0x00AED1D6);
                        WidgetPaint((tWidget *) &g_sSetMotorMode);
                    }
                    break;
                case 1:
                    prev = &g_sSetAdd;
                    curr = &g_sSetSub;
                    break;
                case 2:
                    prev = &g_sSetSub;
                    curr = &g_sSetSave;
                    break;
                case 3:
                    prev = &g_sSetSave;
                    curr = &g_sSetMotorMode;
                    break;
            }
            break;
    }

    // Render the selection
    PushButtonOutlineColorSet(prev, 0x00AED1D6);
    PushButtonOutlineColorSet(curr, ClrWhite);
    WidgetPaint((tWidget *) prev);
    WidgetPaint((tWidget *) curr);
}

// Draws the setting menu
static void DrawSetMenuScreen(tContext * sContext, GUIParams * params)
{
    uint8_t but_press;
    WidgetPaint((tWidget *) &g_sMenuSetPage);
    updateMenuOptions(params);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, VIEW_1_OPTION_NUM);
        if(but_press)
        {
            if (params->cInterItem == VIEW_1_OPTION_NUM){
                params->cInterItem = 0;
                params->cView = VIEW_0;
            }
            else{
                params->cView = VIEW_3;
                params->cSubView = params->cInterItem;
                params->cInterItem = VIEW_0;
            }
            break;
        }
    }
}

// Draws the graphing menu
static void DrawGraphMenuScreen(tContext * sContext, GUIParams * params)
{
    uint8_t but_press;
    WidgetPaint((tWidget *) &g_sMenuGraphPage);
    updateMenuOptions(params);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, VIEW_2_OPTION_NUM);
        if(but_press)
        {
            if (params->cInterItem == VIEW_2_OPTION_NUM){
                params->cInterItem = 1;
                params->cView = VIEW_0;
            }
            else{
                params->cView = VIEW_4;
                params->cSubView = params->cInterItem;
                params->cInterItem = 0;
            }
            break;
        }
    }
}

//// Handles the user wanting to change motor state
static void GuiMotorClicked(GUIParams * params)
{
//    if(MotorTracker.cState == MOTOR_RUNNING){
//        MotorTracker.nState = MOTOR_IDLE;
//        PushButtonFillColorSet(&g_sSetMotorMode, 0x0023A369);
//        PushButtonTextSet(&g_sSetMotorMode, "Turn On");
//        stopMotor();
//    }else if(MotorTracker.cState == MOTOR_IDLE){
//        MotorTracker.nState = MOTOR_RUNNING;
//        PushButtonFillColorSet(&g_sSetMotorMode, 0x00912B24);
//        PushButtonTextSet(&g_sSetMotorMode, "Turn Off");
//        startMotor();
//    }
//    WidgetPaint((tWidget *) &g_sSetMotorMode);
}

// Sets up the settings page
static int16_t SetupSettingScreen(tContext * sContext,GUIParams * params)
{

    WidgetPaint((tWidget *) &g_sSettingPage);
    WidgetMessageQueueProcess();
    int16_t measurement;
    char title[20];
    char units[20];
    if(params->cSubView == 0){
        measurement = settingTempLimit;
        sprintf(units, "celsius\0");
        sprintf(title, "Temperature\0");
    }else if(params->cSubView == 1){
        measurement = settingMotorSpeed;
        sprintf(units, "rpms\0");
        sprintf(title, "Speed\0");
    }else if(params->cSubView == 2){
        measurement = settingCurrentLimit;
        sprintf(units, "amps\0");
        sprintf(title, "Current\0");
    }else{
        measurement = settingAccelLimit;
        sprintf(units, "m/s\0");
        sprintf(title, "Acceleration\0");
    }
    GrStringDraw(sContext, "Setting:", -1, 30, 40, true);
    GrStringDraw(sContext, title, -1, 30, 60, true);
    GrStringDraw(sContext, units, -1, 100, 150, 1);
    updateMenuOptions(params);
    return measurement;
}

// Saves the values set in the settings page
static void SaveSettings(GUIParams * params, uint16_t newValue)
{
//    if(params->cSubView == 0){
//        settingTempLimit = newValue;
//    }else if(params->cSubView == 1){
//        settingMotorSpeed = newValue;
//        // if setting a new motor speed then probs want to accelerate (dont want constant duty change);
//        setMotorRPM(settingMotorSpeed);
//    }else if(params->cSubView == 2){
//        settingCurrentLimit = newValue;
//    }else{
//        settingAccelLimit = newValue;
//    }
//    params->cInterItem = 0;
//    params->cSubView = 0;
//    params->cView = VIEW_1;
}

// Draws the settings page
static void DrawSettingScreen(tContext * sContext, GUIParams * params)
{
    char meas[20];
    uint8_t but_press;
    int16_t measurement = SetupSettingScreen(sContext,params);
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, VIEW_3_OPTION_NUM);
        if(but_press){
            if (params->cInterItem == 0){
                    measurement += 10;
            }
            else if(params->cInterItem == 1){
                if (measurement > 10) // Dont know just seems like a bad idea to allow negatives
                    measurement-= 10;
            }else if(params->cInterItem == 2){
                SaveSettings(params,measurement);
                break;
            }else{
                GuiMotorClicked(params); //  clicked on motor start
            }
        }
        sprintf(meas, "%d \0",measurement);
        GrStringDraw(sContext, meas, -1, 60, 150, 1);
        WidgetMessageQueueProcess();
    }
}

// Graphs the chosen data on the map and scales accordingly
static void DrawDataOnGraph(tContext * sContext,GUIParams * params)
{
    // Define data
   // uint8_t data[7] = {10,20,30,40,13,18,20};

    uint16_t sx = 20;
    uint16_t sy = 55;
    uint16_t w = 279;
    uint16_t h = 140;

    uint16_t max_y;
    uint16_t mid_point;
    uint16_t max_x = GRAPH_X_SAMPLES; // number of seconds too plot (intervals)
    uint16_t last_sample;
    if(params->cSubView == 0){//PWR
        max_y = ADC_GRAPH_HIGH-ADC_GRAPH_LOW;
        mid_point = ADC_GRAPH_LOW;
        last_sample= adcLatestSampleOne;
    }else if(params->cSubView == 1){//speed;
        max_y = RPM_GRAPH_HIGH-RPM_GRAPH_LOW;
        mid_point = RPM_GRAPH_LOW;
        last_sample= rpmLatestSample;
    }else if(params->cSubView == 2){//accel
        max_y = ADC_GRAPH_HIGH-ADC_GRAPH_LOW;
        mid_point = ADC_GRAPH_LOW;
        last_sample= adcLatestSampleOne;
    }else if(params->cSubView == 3){//temp
        max_y = ADC_GRAPH_HIGH-ADC_GRAPH_LOW;
        mid_point = ADC_GRAPH_LOW;
        last_sample= adcLatestSampleOne;
    }else if(params->cSubView == 4){//light
        max_y = LUX_GRAPH_HIGH-RPM_GRAPH_LOW;
        mid_point = LUX_GRAPH_LOW;
        last_sample= luxLatestSample;
    }

    if(graphedPointsCount == GRAPH_X_SAMPLES){
        graphedPointsCount = 0;
        WidgetPaint((tWidget *) &g_sGraph);
        WidgetMessageQueueProcess();
    }


    // Calculate y and x scale
    float yscale = (float)h/(float)max_y;
    float xscale = (float)w/(float)max_x;

    uint16_t x1,x2,y1,y2;
    adcGraphSamples[graphedPointsCount] = last_sample;


    // Draw onto graph
    if(graphedPointsCount != 0){
        x1 = (graphedPointsCount*xscale)+sx;
        //y1 = ((adcGraphSamples[graphedPointsCount-1]-mid_point)*yscale+sy);
        y1 = ((sy+h)-(adcGraphSamples[graphedPointsCount-1]-mid_point)*yscale);
        x2 = ((graphedPointsCount+1)*xscale)+sx;
        //y2 = ((adcGraphSamples[graphedPointsCount]-mid_point)*yscale+sy);
        y2 = ((sy+h)-(adcGraphSamples[graphedPointsCount]-mid_point)*yscale);
        if(y1 < sy)y1 = sy+1;
        if(y1 > sy+h)y1 = sy+h-1;
        if(y2 < sy)y2 = sy+1;
        if(y2 > sy+h)y2 = sy+h-1;
        GrLineDraw(sContext,x1,y1,x2,y2);
    }
    graphedPointsCount +=1;
}

// Sets up the graphing screen
static void SetupGraphScreen(tContext * sContext,GUIParams * params)
{

    WidgetPaint((tWidget *) &g_sGraphPage);
    WidgetMessageQueueProcess();
    GrStringDraw(sContext, "Time (s)\0", -1, 130, 202, false);
    GrLineDrawV(sContext, 10,45,200);
    GrLineDrawH(sContext, 10,305,200);
    GrLineDraw(sContext,10,45,8,50);
    GrLineDraw(sContext,10,45,12,50);
    GrLineDraw(sContext,305,200,303,198);
    GrLineDraw(sContext,305,200,303,202);
    // Axis Tick
    GrLineDraw(sContext,300,195,300,205);
    GrLineDraw(sContext,5,55,15,55);
    // Draw line values
    char title[30];
    char lowLimit[20];
    char highLimit[20];
    if(params->cSubView == 0){//PWR
        sprintf(title, "Current (amps)\0");
        sprintf(lowLimit, "%d\0",ADC_GRAPH_LOW);
        sprintf(highLimit, "%d\0",ADC_GRAPH_HIGH);
    }else if(params->cSubView == 1){//speed
        sprintf(title, "Speed (RPM)\0");
        sprintf(lowLimit, "%d\0",RPM_GRAPH_LOW);
        sprintf(highLimit, "%d\0",RPM_GRAPH_HIGH);
    }else if(params->cSubView == 2){//accel
        sprintf(title, "Acceleration (m/s)\0");
        sprintf(lowLimit, "%d\0",ADC_GRAPH_LOW);
        sprintf(highLimit, "%d\0",ADC_GRAPH_HIGH);
    }else if(params->cSubView == 3){//temp
        sprintf(title, "Temperature (celsius)\0");
        sprintf(lowLimit, "%d\0",ADC_GRAPH_LOW);
        sprintf(highLimit, "%d\0",ADC_GRAPH_HIGH);
    }else if(params->cSubView == 4){//light
        sprintf(title, "Light (lux)\0");
        sprintf(lowLimit, "%d\0",LUX_GRAPH_LOW);
        sprintf(highLimit, "%d\0",LUX_GRAPH_HIGH);
    }

    // Plot measurement dependent stuff
    GrStringDraw(sContext, title, -1, 100, 25, true);
    GrStringDraw(sContext, lowLimit, -1, 10, 202, false);
    GrStringDraw(sContext, highLimit, -1, 18, 38, false);
}

// Draws the graphing screen
static void DrawGraphScreen(tContext * sContext, GUIParams * params)
{
    SetupGraphScreen(sContext,params);
    uint8_t button;
    while(1)
    {
        DrawDataOnGraph(sContext,params);
        button = isButtonPressed();
        if (button == BUTTON_SELECT){
            params->cView = VIEW_2;
            params->cSubView = 0;
            params->cInterItem = DEFAULT_VIEW_OPTION_NUM;
            break;
        }
        WidgetMessageQueueProcess();
        Task_sleep(50);
    }
}

// Draws the home screen
static void DrawHomeScreen(tContext *sContext, GUIParams *params)
{
    uint8_t but_press;
    WidgetPaint(WIDGET_ROOT);
    WidgetMessageQueueProcess();
    while(1)
    {
        DrawDateTime(sContext);
        but_press = checkUiControls(params, VIEW_0_OPTION_NUM);
        if(but_press){
            if (params->cInterItem == 0){
                params->cView = VIEW_1;
                params->cInterItem = DEFAULT_VIEW_OPTION_NUM;
            }else{
                params->cView = VIEW_2;
                params->cInterItem = DEFAULT_VIEW_OPTION_NUM;
            }
            break;
        }
    }
}

// Handles the UI controls for navigating and interacting with the pages
static uint8_t checkUiControls(GUIParams *params, uint8_t screen_opt_num)
{
    uint8_t button = isButtonPressed();
    if(button == BUTTON_NONE){
        return 0;
    }else{
        if (button == BUTTON_SELECT)
        {
            return 1;
        }else{ // is select button
            if(params->cInterItem < screen_opt_num)
            {
                params->cInterItem += 1;
            }
            else if(params->cInterItem == screen_opt_num)
            {
                if(params->cSubView != 1){
                    params->cInterItem = 0;
                }else{
                    params->cInterItem += 1;
                }
            }
            else if(params->cInterItem > screen_opt_num)
            {
                params->cInterItem = 0;
            }
            updateMenuOptions(params);
            WidgetMessageQueueProcess();
            return 0;
        }
    }
}

// Decides what pae to draw
void GUIDrawView(GUIParams * params, tContext * sContext)
{
    switch(params->cView)
    {
        case VIEW_0:
            DrawHomeScreen( sContext, params);
            break;
        case VIEW_1:
            DrawSetMenuScreen(sContext, params);
            break;
        case VIEW_2:
            DrawGraphMenuScreen(sContext, params);
            break;
        case VIEW_3:
            DrawSettingScreen(sContext, params);
            break;
        case VIEW_4:
            DrawGraphScreen(sContext, params);
            break;
    }
}



