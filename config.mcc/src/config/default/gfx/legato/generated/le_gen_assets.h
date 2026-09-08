/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.


  Description:
    Header file containing a list of asset specifications for use with the
    Legato Graphics Stack.

*******************************************************************************/


// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C)  Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// DOM-IGNORE-END

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

extern const lePalette leGlobalPalette;

/*****************************************************************************
 * Legato Graphics Image Assets
 *****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   imgMchp
 * Size:   180x28 pixels
 * Type:   RGB Data
 * Format: MONOCHROME
 ***********************************/
extern leImage imgMchp;

/*********************************
 * Legato Image Asset
 * Name:   btn
 * Size:   193x53 pixels
 * Type:   RGB Data
 * Format: MONOCHROME
 ***********************************/
extern leImage btn;

/*********************************
 * Legato Image Asset
 * Name:   btn2
 * Size:   193x53 pixels
 * Type:   RGB Data
 * Format: MONOCHROME
 ***********************************/
extern leImage btn2;

/*********************************
 * Legato Image Asset
 * Name:   arrowDoubleLine
 * Size:   80x80 pixels
 * Type:   RGB Data
 * Format: MONOCHROME
 ***********************************/
extern leImage arrowDoubleLine;

/*****************************************************************************
 * Legato Graphics Font Assets
 *****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         FontSmall
 * Height:       21
 * Baseline:     26
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  7
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont FontSmall;

/*********************************
 * Legato Font Asset
 * Name:         FontBig
 * Height:       19
 * Baseline:     76
 * Style:        Plain
 * Glyph Count:  95
 * Range Count:  2
 * Glyph Ranges: 0x20-0x7E
***********************************/
extern leRasterFont FontBig;

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   2
 *****************************************************************************/

// language IDs
#define language_Default    0

// string IDs
#define stringID_strQuickstart    0
#define stringID_strCount    1

extern const leStringTable stringTable;


// string list
extern leTableString string_strQuickstart;
extern leTableString string_strCount;

void initializeStrings(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
