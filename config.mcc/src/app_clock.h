#ifndef APP_CLOCK_H
#define APP_CLOCK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    APP_CLOCK_SPEED_12MHZ,
    APP_CLOCK_SPEED_48MHZ,
    APP_CLOCK_SPEED_COUNT
} APP_CLOCK_SPEED;

void APP_Clock_Initialize(void);
void APP_Clock_SetSpeed(APP_CLOCK_SPEED speed);
APP_CLOCK_SPEED APP_Clock_GetSpeed(void);
uint32_t APP_Clock_GetFrequencyHz(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_CLOCK_H */
