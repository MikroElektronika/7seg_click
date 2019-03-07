/*
    __c7seg_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__c7seg_driver.h"
#include "__c7seg_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __C7SEG_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static const uint8_t _C7SEG_CHAR_TABLE[51]={
    0x80, // '-'
    0x01, // '.'   Sevensegment bit order
    0x00, // '/'   (g)(f)(e)(d)(c)(a)(b)(dp)
    0x7E, // '0'
    0x0A, // '1'    _a_
    0xB6, // '2'  f|   |b
    0x9E, // '3'   |_g_|
    0xCA, // '4'  e|   |c
    0xDC, // '5'   |_d_|.dp
    0xFC, // '6'
    0x0E, // '7'
    0xFE, // '8'
    0xDE, // '9'
    0x00, // ':'
    0x00, // ';'
    0x00, // '<'
    0x00, // '='
    0x00, // '>'
    0x00, // '?'
    0x00, // '@'
    0xEE, // 'A'
    0xF8, // 'B'
    0x74, // 'C'
    0xBA, // 'D'
    0xF4, // 'E'
    0xE4, // 'F'
    0x7C, // 'G'
    0xEA, // 'H'
    0x0A, // 'I'
    0x3A, // 'J'
    0xE0, // 'K'
    0x70, // 'L'
    0x2C, // 'M'
    0xA8, // 'N'
    0x7E, // 'O'
    0xE6, // 'P'
    0xCE, // 'Q'
    0x64, // 'R'
    0xDC, // 'S'
    0xF0, // 'T'
    0x7A, // 'U'
    0x7B, // 'V'
    0xFB, // 'W'
    0xEA, // 'X'
    0xDA, // 'Y'
    0xB6, // 'Z'
    0x00, // '['
    0x00, // '/'
    0x00, // ']'
    0x00, // '^'
    0x10, // '_'
};

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

uint8_t c7seg_getChar( char Character );
uint8_t c7seg_getDigit( uint8_t Digit );

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

uint8_t c7seg_getChar( char Character )
{
    if ( ( Character >= '-' ) && ( Character <= '_' ) )
        return _C7SEG_CHAR_TABLE[ Character - '-' ];
    else
        return 0;
}

uint8_t c7seg_getDigit( uint8_t Digit )
{
    if ( ( Digit >= 0 ) && ( Digit <= 9 ) )
        return _C7SEG_CHAR_TABLE[ Digit + 3 ];
    else
        return 0;
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __C7SEG_DRV_SPI__

void c7seg_spiDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(0);
    hal_gpio_pwmSet(1);
    Delay_10ms();
    
}

#endif
#ifdef   __C7SEG_DRV_I2C__

void c7seg_i2cDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __C7SEG_DRV_UART__

void c7seg_uartDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */



/* Generic write data function */
void c7seg_writeData( uint8_t writeLeft, uint8_t writeRight )
{
    uint8_t buffer[2];
    buffer[0] = writeRight;
    buffer[1] = writeLeft;
    
    hal_gpio_csSet(0);
    hal_spiWrite( buffer, 2);
    Delay_10us();
    hal_gpio_csSet(1);
    
}

/* Function set 7seg */
void c7seg_set7seg()
{
    hal_gpio_rstSet(0);
    Delay_10us();
    hal_gpio_rstSet(1);
}

/* Function enable 7seg display */
void c7seg__displayOn()
{
     hal_gpio_pwmSet(1);
}

/* Function disabled 7seg display */
void c7seg__displayOff()
{
     hal_gpio_pwmSet(0);
}

/* Function write left and right number on 7seg display */
void c7seg_writeDataNumber( uint8_t leftNumber, uint8_t rightNumber )
{
    c7seg_writeData( c7seg_getDigit( leftNumber ), c7seg_getDigit( rightNumber ) );
}

/* Function write left and right character on 7seg display */
void c7seg_writeDataCharacter( char leftChar, char rightChar )
{
    c7seg_writeData( c7seg_getChar( leftChar ) , c7seg_getChar( rightChar ) );
}






/* -------------------------------------------------------------------------- */
/*
  __c7seg_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */