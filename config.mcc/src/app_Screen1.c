/*******************************************************************************
 * Screen1 (Secondary Screen) Application Logic
 *
 * Simple navigation screen. SW0 returns to Screen0.
 ******************************************************************************/

#include "definitions.h"

/* Button press flags (set by ISR, cleared by update loop) */
static volatile bool sw0Pressed = false;
static volatile bool sw1Pressed = false;

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
}
#endif

void Screen1_OnShow(void)
{
    sw0Pressed = false;
    sw1Pressed = false;

#ifndef MGS_SIM
    /* Register button interrupt handlers */
//     EIC_CallbackRegister(EIC_PIN_4, EIC_SW_Handler, EIC_PIN_4);
//     EIC_CallbackRegister(EIC_PIN_12, EIC_SW_Handler, EIC_PIN_12);
//     EIC_InterruptEnable(EIC_PIN_4);
//     EIC_InterruptEnable(EIC_PIN_12);

    /* Slow refresh on screen entry to clear E-Paper ghosting */
    gfxIOCTLArg_Value arg = {.value.v_uint = 0};
    DRV_EPD_IOCTL(GFX_IOCTL_EPD_FAST_REFRESH, &arg);
#endif
}

void Screen1_OnHide(void)
{
#ifndef MGS_SIM
//     EIC_InterruptDisable(EIC_PIN_4);
//     EIC_InterruptDisable(EIC_PIN_12);
#endif
}

void Screen1_OnUpdate(void)
{
    if (sw0Pressed)
    {
        /* SW0: Navigate back to Screen0 */
        legato_showScreen(screenID_Screen0);
        sw0Pressed = false;
    }
    else if (sw1Pressed)
    {
        /* SW1: No action on this screen */
        sw1Pressed = false;
    }
}
