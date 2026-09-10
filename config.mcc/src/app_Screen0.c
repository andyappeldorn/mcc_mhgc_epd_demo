/*******************************************************************************
 * Screen0 - Touch Troubleshooting
 *
 * Displays per-sensor delta values (signal - reference) for all 12 touch
 * sensor nodes, plus scaled X/Y position. Updated every 250ms.
 ******************************************************************************/

#include <stdio.h>
#include "definitions.h"
#include "touch/touch_api_ptc.h"
#include "driver/input/drv_touch_itd.h"

#define NUM_SENSORS             12
#define DELTA_STR_SIZE          8
#define COORD_STR_SIZE          8
#define MAX_POS_VALUE           255
#define UPDATE_PERIOD_MS        250

static leFixedString deltaFixedStr[NUM_SENSORS];
static leChar deltaFixedStrBuff[NUM_SENSORS][DELTA_STR_SIZE];
static char deltaCStrBuff[NUM_SENSORS][DELTA_STR_SIZE];

static leFixedString xFixedStr;
static leChar xFixedStrBuff[COORD_STR_SIZE] = {0};
static char xCStrBuff[COORD_STR_SIZE];

static leFixedString yFixedStr;
static leChar yFixedStrBuff[COORD_STR_SIZE] = {0};
static char yCStrBuff[COORD_STR_SIZE];

static volatile bool updateTick = false;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

static leLabelWidget** sensorLabels[NUM_SENSORS];

static void Timer_Callback(uintptr_t context)
{
    updateTick = true;
}

static void UpdateSensorDeltas(void)
{
    for (int i = 0; i < NUM_SENSORS; i++)
    {
        int16_t delta = (int16_t)get_sensor_node_signal(i)
                      - (int16_t)get_sensor_node_reference(i);
        snprintf(deltaCStrBuff[i], DELTA_STR_SIZE, "%d", delta);
        deltaFixedStr[i].fn->setFromCStr(&deltaFixedStr[i], deltaCStrBuff[i]);

        leLabelWidget* lbl = *sensorLabels[i];
        lbl->fn->setString(lbl, (leString*)&deltaFixedStr[i]);
    }
}

static void UpdatePositionDisplay(void)
{
    int raw_x = get_surface_position(HOR_POS);
    int raw_y = get_surface_position(VER_POS);

    int delta = raw_x - (MAX_POS_VALUE / 2);
    delta = (delta * TOUCH_SCREEN_ACTIVE_WIDTH) / MAX_POS_VALUE;
    int16_t scaledX = TOUCH_SCREEN_ACTIVE_WIDTH / 2 + delta;

    delta = raw_y - (MAX_POS_VALUE / 2);
    delta = (delta * TOUCH_SCREEN_ACTIVE_HEIGHT) / MAX_POS_VALUE;
    int16_t scaledY = TOUCH_SCREEN_ACTIVE_HEIGHT / 2 + delta;

    snprintf(xCStrBuff, COORD_STR_SIZE, "%d", scaledX);
    xFixedStr.fn->setFromCStr(&xFixedStr, xCStrBuff);
    Screen0_lbl_xPos->fn->setString(Screen0_lbl_xPos, (leString*)&xFixedStr);

    snprintf(yCStrBuff, COORD_STR_SIZE, "%d", scaledY);
    yFixedStr.fn->setFromCStr(&yFixedStr, yCStrBuff);
    Screen0_lbl_yPos->fn->setString(Screen0_lbl_yPos, (leString*)&yFixedStr);
}

void Screen0_OnShow(void)
{
    sensorLabels[0]  = &Screen0_lbl_y1;
    sensorLabels[1]  = &Screen0_lbl_y2;
    sensorLabels[2]  = &Screen0_lbl_y3;
    sensorLabels[3]  = &Screen0_lbl_y4;
    sensorLabels[4]  = &Screen0_lbl_y5;
    sensorLabels[5]  = &Screen0_lbl_y6;
    sensorLabels[6]  = &Screen0_lbl_y7;
    sensorLabels[7]  = &Screen0_lbl_x1;
    sensorLabels[8]  = &Screen0_lbl_x2;
    sensorLabels[9]  = &Screen0_lbl_x3;
    sensorLabels[10] = &Screen0_lbl_x4;
    sensorLabels[11] = &Screen0_lbl_x5;

    for (int i = 0; i < NUM_SENSORS; i++)
    {
        memset(deltaFixedStrBuff[i], 0, DELTA_STR_SIZE);
        leFixedString_Constructor(&deltaFixedStr[i], deltaFixedStrBuff[i], DELTA_STR_SIZE);
        deltaFixedStr[i].fn->setFont(&deltaFixedStr[i], (leFont*)&FontSmall);
    }

    leFixedString_Constructor(&xFixedStr, xFixedStrBuff, COORD_STR_SIZE);
    xFixedStr.fn->setFont(&xFixedStr, (leFont*)&FontSmall);

    leFixedString_Constructor(&yFixedStr, yFixedStrBuff, COORD_STR_SIZE);
    yFixedStr.fn->setFont(&yFixedStr, (leFont*)&FontSmall);

    timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1,
                                        UPDATE_PERIOD_MS,
                                        SYS_TIME_PERIODIC);

#ifndef MGS_SIM
    gfxIOCTLArg_Value arg = {.value.v_uint = 0};
    DRV_EPD_IOCTL(GFX_IOCTL_EPD_FAST_REFRESH, &arg);
#endif
}

void Screen0_OnHide(void)
{
    SYS_TIME_TimerDestroy(timer);
}

void Screen0_OnUpdate(void)
{
    if (updateTick)
    {
        updateTick = false;
        UpdateSensorDeltas();
        UpdatePositionDisplay();
        Screen0_pnlBase->fn->invalidate(Screen0_pnlBase);
    }
}
