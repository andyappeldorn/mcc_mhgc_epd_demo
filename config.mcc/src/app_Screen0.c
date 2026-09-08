/*******************************************************************************
 * Screen0 (Counter Screen) Application Logic
 *
 * Displays a counter (0-99) that increments automatically after an idle period.
 ******************************************************************************/

#include <stdio.h>
#include "definitions.h"

#define APP_FIXED_STR_SIZE      3
#define DEFAULT_VALUE           0
#define MAX_VALUE               99
#define CLOCK_TICK_TIMER_PERIOD_MS  1000
#define IDLE_UPDATE_PERIOD_SECS     1

/* Counter display string buffer */
static leFixedString appFixedStr;
static leChar appFixedStrBuff[APP_FIXED_STR_SIZE] = {0};
static char cStrBuff[APP_FIXED_STR_SIZE];
static uint32_t counterValue = DEFAULT_VALUE;
static uint32_t temperatureValue = 70;

/* Idle timer tracking */
static volatile unsigned int tickSecs = 0;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

/* 1-second periodic timer callback - tracks idle time */
static void Timer_Callback(uintptr_t context)
{
    tickSecs++;
}

/* Updates the counter label widget with current value */
static void UpdateCounterDisplay(void)
{
    snprintf(cStrBuff, APP_FIXED_STR_SIZE, "%lu", counterValue);
    appFixedStr.fn->setFromCStr(&appFixedStr, cStrBuff);
    Screen0_lblCounter->fn->setString(Screen0_lblCounter, (leString*)&appFixedStr);
    Screen0_lblCounter->fn->invalidate(Screen0_lblCounter);
}

/* Increments counter with wraparound */
static void IncrementCounter(void)
{
    counterValue = (counterValue < MAX_VALUE) ? counterValue + 1 : DEFAULT_VALUE;
}

void Screen0_OnShow(void)
{
    counterValue = DEFAULT_VALUE;

    /* Initialize fixed string for counter display */
    leFixedString_Constructor(&appFixedStr, appFixedStrBuff, APP_FIXED_STR_SIZE);
    appFixedStr.fn->setFont(&appFixedStr, (leFont*)&FontBig);

    /* Start 1-second periodic timer for idle tracking */
    timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1,
                                        CLOCK_TICK_TIMER_PERIOD_MS,
                                        SYS_TIME_PERIODIC);

#ifndef MGS_SIM
    /* Use GC (slow) LUT for the initial paint to establish a clean baseline.
     * The driver auto-promotes to DU2 (fast) after this first blit. */
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
    if (tickSecs >= IDLE_UPDATE_PERIOD_SECS)
    {
        IncrementCounter();
        UpdateCounterDisplay();

#ifndef MGS_SIM
        gfxIOCTLArg_Value arg = {.value.v_uint = 0};
        DRV_EPD_IOCTL(GFX_IOCTL_EPD_OVERDRAW, &arg);
#endif

        tickSecs = 0;
    }
}

void event_Screen0_ButtonWidget_Up_OnReleased(leButtonWidget* btn)
{
    //legato_showScreen(screenID_Help);
    // increment counter
    // force update
}

void event_Screen0_ButtonWidget_Down_OnReleased(leButtonWidget* btn)
{
    //legato_showScreen(screenID_Help);
    // decrement counter
    // force update
}
