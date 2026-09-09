# EPD Demo - Trane E-Paper Display Project

## Overview

Demonstration firmware for an e-paper (EPD) display module targeting Trane HVAC applications. The project drives a 240x416 monochrome e-paper panel with capacitive touch input on a PIC32CM LE microcontroller, using Microchip's MPLAB Harmony framework and Legato graphics library.

## Hardware

| Component         | Detail                                                        |
|-------------------|---------------------------------------------------------------|
| MCU               | PIC32CM5164LE00064 (ARM Cortex-M23, 512 KB Flash, 64 KB RAM) |
| Display           | AMP 240x416 monochrome e-paper panel                         |
| Display controller| UltraChip UC8253                                              |
| Display interface | 4-line SPI (SERCOM2) with DMA (TX ch0, RX ch1)               |
| Touch             | Capacitive touch surface via PIC32CM LE built-in PTC + QTouch |
| Programmer        | PICkit 5 at 3.3 V                                            |
| Clock             | OSC16M at 12 MHz (GCLK0), 4 MHz (GCLK1)                     |

### Display Control Pins

| Signal   | Pin  | Function               |
|----------|------|------------------------|
| CS       | PB31 | SPI chip select        |
| D/C      | PB00 | Data/command select    |
| PWR_EN   | PB01 | Display power enable   |
| RESET    | PB02 | Hardware reset         |
| nBUSY    | PB03 | Busy signal (active low)|

## Software Stack

| Layer               | Version  |
|---------------------|----------|
| MCC                 | 5.7.1 (core 5.9.1) |
| MPLAB Harmony       | 1.7.2    |
| GFX / Legato        | 3.17.1   |
| CSP                 | 3.26.0   |
| Core                | 3.17.0   |
| Touch               | 3.20.1   |
| CMSIS               | 6.3.0    |
| XC32 Compiler       | 5.10 (-O1) |

## Application Behavior

The firmware runs a bare-metal super-loop (no RTOS). The task loop polls: EPD driver update, touch driver, Legato graphics, system input, then app tasks.

### Screen 0 - Main Screen

- Displays a numeric value (counter or temperature) in a large centered label.
- **Counter mode**: auto-increments every second; wraps at 99 back to 0.
- **Temperature mode**: shows a temperature value (default 70) adjustable via Up/Down buttons.
- **Display mode toggle** (`btnDisplayMode`): switches between counter and temperature display.
- **Up/Down buttons**: increment/decrement the temperature value (0-99 range).
- **Touch position label**: shows the last touch (x,y) coordinates.
- Uses GC (slow) LUT for the initial full-screen paint, then DU2 (fast partial) refresh for subsequent updates. Overdraw IOCTL used during idle counter updates to maintain image quality.

### Screen 1 - QR Code Screen

- Displays a QR code image with a back button to return to Screen 0.

## E-Paper Refresh Modes

| Mode | LUT  | Use Case                          |
|------|------|-----------------------------------|
| GC   | Full | Initial paint / clean baseline    |
| DU   | Fast | General partial updates           |
| DU2  | Fast | Optimized partial updates (default after init) |

## Project Structure

```
epd_demo/
  config.mcc/
    mcc/                          MCC manifests and component YAML configs
      config_default/components/  Per-component configuration (SPI, timer, touch, GFX, ...)
    src/
      app.c                       Application state machine and touch input bridge
      app.h                       App data types and prototypes
      app_Screen0.c               Screen 0 event handlers and display logic
      main.c                      Entry point (SYS_Initialize + SYS_Tasks loop)
      config/default/
        initialization.c          SYS_Initialize implementation
        tasks.c                   SYS_Tasks polling loop
        peripheral/               PLIB drivers (PORT, CLOCK, SERCOM, TC, RTC, DMAC, ...)
        gfx/
          driver/controller/epaper/  EPD driver (UC8253 + AMP display vendor code)
          interface/spi4/            4-line SPI display interface
          legato/                    Legato graphics library
          legato/generated/          MCC-generated assets, screens, schemes, fonts, images
            screen/                  Screen0 and Screen1 widget trees
            font/                    FontBig (8pt), FontSmall (1pt) - Liberation Mono
            image/                   btn, btn2, imgMchp, arrowDoubleLine (monochrome)
        driver/
          spi/                     Harmony async SPI driver
          input/                   Integrated Touch Driver (ITD)
        system/                    System services (time, input, DMA, interrupts)
        touch/                     QTouch library integration
      packs/                       CMSIS and PIC32CM LE DFP headers
  cmake/                           Generated CMake build files
  _build/                          CMake build output
  out/                             Final build artifacts (default.elf)
  .vscode/                         VS Code / MPLAB extension project settings
```

## Memory Usage (latest build)

| Region  | Used     | Total    | Utilization |
|---------|----------|----------|-------------|
| Program | 109,886 B | 524,288 B | 21.0%       |
| Data    | 28,405 B  | 65,536 B  | 43.3%       |

## Commit History

| Hash    | Description                                                   |
|---------|---------------------------------------------------------------|
| f01f0ba | Add Up/Down button widgets, touch surface input, and MCC regeneration |
| 2721a09 | Reduce display flashing by using DU2 partial refresh for updates |
| d7556bd | Fix display not updating: correct port config and clean up screen logic |
| 5e693f3 | Update GFX library to v3.17.1 and add Legato generated UI assets |
| dae8ede | Remove FreeRTOS and regenerate MCC configuration              |
| 6ad8184 | Initial commit: EPD demo project for PIC32CM LE00             |

## Development Notes

- **No RTOS**: FreeRTOS was removed early in development (commit dae8ede). The application uses a polled bare-metal super-loop.
- **Touch bridging**: `app.c` registers a `SYS_INP_InputListener` to forward system touch events into the Legato graphics input layer.
- **EPD driver specifics**: The UC8253 driver uses dual frame buffers (old/BW at 0x10, new/RED at 0x13). Programmable LUT tables control waveform timing for different refresh modes.
- **Display vendor code**: Original EPD driver code provided by AMP (display module vendor), adapted for Harmony/Legato integration.
- **`MGS_SIM` guard**: EPD-specific IOCTL calls are conditionally compiled out when building for the MGS Harmony Graphics Simulator.
