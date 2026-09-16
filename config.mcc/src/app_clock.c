#include "app_clock.h"
#include "definitions.h"

typedef struct
{
    uint32_t frequency_hz;
    uint8_t  nvm_rws;
    uint8_t  osc16m_fsel;
    uint8_t  gclk0_src;
    uint8_t  gclk0_div;
    uint8_t  gclk1_src;
    uint8_t  gclk1_div;
    bool     dpll_enable;
} APP_CLOCK_CONFIG;

static const APP_CLOCK_CONFIG clockConfigs[APP_CLOCK_SPEED_COUNT] =
{
    [APP_CLOCK_SPEED_12MHZ] =
    {
        .frequency_hz = 12000000U,
        .nvm_rws      = 0,
        .osc16m_fsel  = 0x2U,          /* 12 MHz */
        .gclk0_src    = 5U,            /* OSC16M */
        .gclk0_div    = 1U,
        .gclk1_src    = 5U,            /* OSC16M */
        .gclk1_div    = 3U,            /* 4 MHz for PTC */
        .dpll_enable  = false,
    },
    [APP_CLOCK_SPEED_48MHZ] =
    {
        .frequency_hz = 48000000U,
        .nvm_rws      = 3,
        .osc16m_fsel  = 0x2U,          /* 12 MHz (still needed for GCLK1) */
        .gclk0_src    = 8U,            /* FDPLL96M */
        .gclk0_div    = 1U,
        .gclk1_src    = 5U,            /* OSC16M */
        .gclk1_div    = 3U,            /* 4 MHz for PTC */
        .dpll_enable  = true,
    },
};

static APP_CLOCK_SPEED currentSpeed = APP_CLOCK_SPEED_48MHZ;

static void GCLK_SyncWait(uint32_t mask)
{
    while ((GCLK_REGS->GCLK_SYNCBUSY & mask) != 0U) { }
}

static void DPLL_Enable(void)
{
    SUPC_REGS->SUPC_VREGPLL = SUPC_VREGPLL_ENABLE_Msk;

    OSCCTRL_REGS->OSCCTRL_DPLLCTRLB =
        OSCCTRL_DPLLCTRLB_FILTER(0U) |
        OSCCTRL_DPLLCTRLB_LTIME(0U) |
        OSCCTRL_DPLLCTRLB_REFCLK(0U);

    OSCCTRL_REGS->OSCCTRL_DPLLRATIO =
        OSCCTRL_DPLLRATIO_LDRFRAC(11U) |
        OSCCTRL_DPLLRATIO_LDR(2928U);

    while ((OSCCTRL_REGS->OSCCTRL_DPLLSYNCBUSY &
            OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk) != 0U) { }

    OSCCTRL_REGS->OSCCTRL_DPLLPRESC = OSCCTRL_DPLLPRESC_PRESC(1U);

    while ((OSCCTRL_REGS->OSCCTRL_DPLLSYNCBUSY &
            OSCCTRL_DPLLSYNCBUSY_DPLLPRESC_Msk) != 0U) { }

    OSCCTRL_REGS->OSCCTRL_DPLLCTRLA = OSCCTRL_DPLLCTRLA_ENABLE_Msk;

    while ((OSCCTRL_REGS->OSCCTRL_DPLLSYNCBUSY &
            OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) != 0U) { }

    while ((OSCCTRL_REGS->OSCCTRL_DPLLSTATUS &
            (OSCCTRL_DPLLSTATUS_LOCK_Msk | OSCCTRL_DPLLSTATUS_CLKRDY_Msk)) !=
            (OSCCTRL_DPLLSTATUS_LOCK_Msk | OSCCTRL_DPLLSTATUS_CLKRDY_Msk)) { }
}

static void DPLL_Disable(void)
{
    OSCCTRL_REGS->OSCCTRL_DPLLCTRLA = 0U;

    while ((OSCCTRL_REGS->OSCCTRL_DPLLSYNCBUSY &
            OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk) != 0U) { }

    SUPC_REGS->SUPC_VREGPLL = 0U;
}

void APP_Clock_Initialize(void)
{
    currentSpeed = APP_CLOCK_SPEED_48MHZ;
}

void APP_Clock_SetSpeed(APP_CLOCK_SPEED speed)
{
    if (speed >= APP_CLOCK_SPEED_COUNT || speed == currentSpeed)
        return;

    const APP_CLOCK_CONFIG *cfg = &clockConfigs[speed];
    const APP_CLOCK_CONFIG *cur = &clockConfigs[currentSpeed];
    bool speeding_up = (cfg->frequency_hz > cur->frequency_hz);

    /* When increasing frequency, raise NVM wait states BEFORE the switch */
    if (speeding_up)
    {
        NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(cfg->nvm_rws);
    }

    /* If the new config needs the DPLL and it's not running, start it */
    if (cfg->dpll_enable && !cur->dpll_enable)
    {
        DPLL_Enable();
    }

    /* Switch GCLK0 to the target source and divider */
    GCLK_REGS->GCLK_GENCTRL[0] =
        GCLK_GENCTRL_DIV(cfg->gclk0_div) |
        GCLK_GENCTRL_SRC(cfg->gclk0_src) |
        GCLK_GENCTRL_GENEN_Msk;
    GCLK_SyncWait(GCLK_SYNCBUSY_GENCTRL0_Msk);

    /* Update GCLK1 if its config changed */
    if (cfg->gclk1_src != cur->gclk1_src || cfg->gclk1_div != cur->gclk1_div)
    {
        GCLK_REGS->GCLK_GENCTRL[1] =
            GCLK_GENCTRL_DIV(cfg->gclk1_div) |
            GCLK_GENCTRL_SRC(cfg->gclk1_src) |
            GCLK_GENCTRL_GENEN_Msk;
        GCLK_SyncWait(GCLK_SYNCBUSY_GENCTRL1_Msk);
    }

    /* If the old config used DPLL and the new one doesn't, shut it down */
    if (!cfg->dpll_enable && cur->dpll_enable)
    {
        DPLL_Disable();
    }

    /* When decreasing frequency, lower NVM wait states AFTER the switch */
    if (!speeding_up)
    {
        NVMCTRL_REGS->NVMCTRL_CTRLB = NVMCTRL_CTRLB_RWS(cfg->nvm_rws);
    }

    currentSpeed = speed;
}

APP_CLOCK_SPEED APP_Clock_GetSpeed(void)
{
    return currentSpeed;
}

uint32_t APP_Clock_GetFrequencyHz(void)
{
    return clockConfigs[currentSpeed].frequency_hz;
}
