#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   2
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[28] =
{
    0x02,0x00,0x01,0x00,0x00,0x0C,0x00,0x00,0x01,0x18,0x00,0x00,0x0A,0x00,0x51,0x75,
    0x69,0x63,0x6B,0x73,0x74,0x61,0x72,0x74,0x01,0x00,0x30,0x00,
};

/* font asset pointer list */
leFont* fontList[2] =
{
    (leFont*)&FontSmall,
    (leFont*)&FontBig,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        28, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_strQuickstart;
leTableString string_strCount;

void initializeStrings(void)
{
    leTableString_Constructor(&string_strQuickstart, stringID_strQuickstart);
    leTableString_Constructor(&string_strCount, stringID_strCount);
}
