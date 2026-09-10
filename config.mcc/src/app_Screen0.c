/*******************************************************************************
 * Screen0 (Counter Screen) Application Logic
 *
 * Displays a counter (0-99) that increments automatically after an idle period.
 ******************************************************************************/

#include <stdio.h>
#include "definitions.h"
#include "touch/touch_api_ptc.h"
#include "driver/input/drv_touch_itd.h"

#define TEMP_STR_SIZE           8
#define TOUCH_STR_SIZE          16
#define MAX_POS_VALUE           255

/* Temperature display string buffer */
static leFixedString tempFixedStr;
static leChar tempFixedStrBuff[TEMP_STR_SIZE] = {0};
static char tempCStrBuff[TEMP_STR_SIZE];
static uint32_t temperatureValue = 70;

/* Touch coordinate display string buffer */
static leFixedString touchFixedStr;
static leChar touchFixedStrBuff[TOUCH_STR_SIZE] = {0};
static char touchCStrBuff[TOUCH_STR_SIZE];

static bool wasTouching = false;
static int16_t lastScaledX = 0;
static int16_t lastScaledY = 0;

static void UpdateTemperatureDisplay(void)
{
    snprintf(tempCStrBuff, TEMP_STR_SIZE, "%lu", temperatureValue);
    tempFixedStr.fn->setFromCStr(&tempFixedStr, tempCStrBuff);
    Screen0_lblCounter->fn->setString(Screen0_lblCounter, (leString*)&tempFixedStr);
    Screen0_lblCounter->fn->invalidate(Screen0_lblCounter);
}

static void UpdateTouchDisplay(int16_t x, int16_t y)
{
    snprintf(touchCStrBuff, TOUCH_STR_SIZE, "%d, %d", x, y);
    touchFixedStr.fn->setFromCStr(&touchFixedStr, touchCStrBuff);
    Screen0_LabelTouchCoordinate->fn->setString(Screen0_LabelTouchCoordinate, (leString*)&touchFixedStr);
    Screen0_LabelTouchCoordinate->fn->invalidate(Screen0_LabelTouchCoordinate);
}

void Screen0_OnShow(void)
{
    leFixedString_Constructor(&tempFixedStr, tempFixedStrBuff, TEMP_STR_SIZE);
    tempFixedStr.fn->setFont(&tempFixedStr, (leFont*)&FontBig);

    leFixedString_Constructor(&touchFixedStr, touchFixedStrBuff, TOUCH_STR_SIZE);
    touchFixedStr.fn->setFont(&touchFixedStr, (leFont*)&FontSmall);

    UpdateTemperatureDisplay();

#ifndef MGS_SIM
    gfxIOCTLArg_Value arg = {.value.v_uint = 0};
    DRV_EPD_IOCTL(GFX_IOCTL_EPD_FAST_REFRESH, &arg);
#endif
}

void Screen0_OnHide(void)
{
}

void Screen0_OnUpdate(void)
{
    bool touching = (get_surface_status() & TOUCH_ACTIVE) != 0;

    if (touching)
    {
        int raw_x = get_surface_position(HOR_POS);
        int raw_y = get_surface_position(VER_POS);

        int delta = raw_x - (MAX_POS_VALUE / 2);
        delta = (delta * TOUCH_SCREEN_ACTIVE_WIDTH) / MAX_POS_VALUE;
        lastScaledX = TOUCH_SCREEN_ACTIVE_WIDTH / 2 + delta;

        delta = raw_y - (MAX_POS_VALUE / 2);
        delta = (delta * TOUCH_SCREEN_ACTIVE_HEIGHT) / MAX_POS_VALUE;
        lastScaledY = TOUCH_SCREEN_ACTIVE_HEIGHT / 2 + delta;

        wasTouching = true;
    }
    else if (wasTouching)
    {
        wasTouching = false;
        UpdateTouchDisplay(lastScaledX, lastScaledY);
    }
}

void event_Screen0_ButtonWidget_Up_OnReleased(leButtonWidget* btn)
{
    // increment temperature value
    // update screen
}

void event_Screen0_ButtonWidget_Down_OnReleased(leButtonWidget* btn)
{
    // decrement temperature value
    // update screen
}

void event_Screen0_btnMode_OnReleased(leButtonWidget* btn)
{
    // switch between displaying temperature and counter
    // update screen
}

