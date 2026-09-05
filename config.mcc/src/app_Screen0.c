/*******************************************************************************
 * Screen0 (Counter Screen) Application Logic
 *
 * Displays a counter (0-99) that increments via SW1 button or automatically
 * after an idle period. SW0 navigates to Screen1.
 ******************************************************************************/

#include <stdio.h>
#include "definitions.h"

#define APP_FIXED_STR_SIZE      3
#define DEFAULT_VALUE           0
#define MAX_VALUE               99
#define CLOCK_TICK_TIMER_PERIOD_MS  1000
#define IDLE_UPDATE_PERIOD_SECS     10

/* Counter display string buffer */
static leFixedString appFixedStr;
static leChar appFixedStrBuff[APP_FIXED_STR_SIZE] = {0};
static char cStrBuff[APP_FIXED_STR_SIZE];
static uint32_t counterValue = DEFAULT_VALUE;

/* Idle timer tracking */
static volatile unsigned int tickSecs = 0;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

/* Button press flags (set by ISR, cleared by update loop) */
static volatile bool sw0Pressed = false;
static volatile bool sw1Pressed = false;

/* 1-second periodic timer callback - tracks idle time */
static void Timer_Callback(uintptr_t context)
{
    tickSecs++;
}

#ifndef MGS_SIM
/* External interrupt handler for SW0/SW1 buttons */
static void EIC_SW_Handler(uintptr_t context)
{
    switch ((uint32_t)context)
    {
        /*
        case EIC_PIN_4:
          if (SW1_Get() == 1)
                sw1Pressed = true;
            break;

        case EIC_PIN_12:
            if (SW0_Get() == 1)
                sw0Pressed = true;
            break;
*/

        default:
            break;
    }

    tickSecs = 0;  /* Reset idle timer on any button press */
}
#endif

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
//     sw0Pressed = false;
//     sw1Pressed = false;
    counterValue = DEFAULT_VALUE;

    /* Initialize fixed string for counter display */
    leFixedString_Constructor(&appFixedStr, appFixedStrBuff, APP_FIXED_STR_SIZE);
    appFixedStr.fn->setFont(&appFixedStr, (leFont*)&FontBig);

    /* Start 1-second periodic timer for idle tracking */
    timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1,
                                        CLOCK_TICK_TIMER_PERIOD_MS,
                                        SYS_TIME_PERIODIC);

#ifndef MGS_SIM
    /* Register button interrupt handlers */
//     EIC_CallbackRegister(EIC_PIN_4, EIC_SW_Handler, EIC_PIN_4);
//     EIC_CallbackRegister(EIC_PIN_12, EIC_SW_Handler, EIC_PIN_12);
//     EIC_InterruptEnable(EIC_PIN_4);
//     EIC_InterruptEnable(EIC_PIN_12);

    /* Initial slow refresh to clear any E-Paper ghosting */
    gfxIOCTLArg_Value arg = {.value.v_uint = 0};
    DRV_EPD_IOCTL(GFX_IOCTL_EPD_FAST_REFRESH, &arg);
#endif
}

void Screen0_OnHide(void)
{
#ifndef MGS_SIM
//     EIC_InterruptDisable(EIC_PIN_4);
//     EIC_InterruptDisable(EIC_PIN_12);
#endif

    SYS_TIME_TimerDestroy(timer);
}

void Screen0_OnUpdate(void)
{
    
    if (sw0Pressed)
    {
        // SW0: Navigate to Screen1
        legato_showScreen(screenID_Screen1);
        sw0Pressed = false;
    }
    else if (sw1Pressed)
    {
        // SW1: Increment counter (fast refresh)
        IncrementCounter();
        UpdateCounterDisplay();
        sw1Pressed = false;
    }
    else if (tickSecs >= IDLE_UPDATE_PERIOD_SECS)
    {
        /* Idle timeout: increment counter and do full slow refresh to clear ghosting */
        IncrementCounter();
        UpdateCounterDisplay();

#ifndef MGS_SIM
        gfxIOCTLArg_Value arg = {.value.v_uint = 0};
        DRV_EPD_IOCTL(GFX_IOCTL_EPD_FAST_REFRESH, &arg);
#endif
        leRedrawAll();

        tickSecs = 0;
    }
}
