/*
    __c7seg_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __c7seg_driver.h
@brief    7seg Driver
@mainpage 7seg Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   C7SEG
@brief      7seg Click Driver
@{

| Global Library Prefix | **C7SEG** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _C7SEG_H_
#define _C7SEG_H_

/** 
 * @macro T_C7SEG_P
 * @brief Driver Abstract type 
 */
#define T_C7SEG_P    const uint8_t*

/** @defgroup C7SEG_COMPILE Compilation Config */              /** @{ */

   #define   __C7SEG_DRV_SPI__                            /**<     @macro __C7SEG_DRV_SPI__  @brief SPI driver selector */
//  #define   __C7SEG_DRV_I2C__                            /**<     @macro __C7SEG_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __C7SEG_DRV_UART__                           /**<     @macro __C7SEG_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup C7SEG_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup C7SEG_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup C7SEG_INIT Driver Initialization */              /** @{ */

#ifdef   __C7SEG_DRV_SPI__
void c7seg_spiDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P spiObj);
#endif
#ifdef   __C7SEG_DRV_I2C__
void c7seg_i2cDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P i2cObj, uint8_t slave);
#endif
#ifdef   __C7SEG_DRV_UART__
void c7seg_uartDriverInit(T_C7SEG_P gpioObj, T_C7SEG_P uartObj);
#endif


/** @defgroup C7SEG_FUNC Driver Functions */                   /** @{ */


/**
 * @breif Generic write data function
 *
 * @param[in] writeLeft      left data to write
 *
 * @param[in] writeRight     right data to write
 *
 * Function write left and right data on 7seg display
 */
void c7seg_writeData( uint8_t writeLeft, uint8_t writeRight );

/**
 * @breif Function set 7seg
 *
 * Function set 7seg display
 */
void c7seg_set7seg();

/**
 * @breif Turn ON 7seg display
 *
 * Function enable 7seg display
 */
void c7seg__displayOn();

/**
 * @breif Turn OFF 7seg display
 *
 * Function disable 7seg display
 */
void c7seg__displayOff();

/**
 * @breif Write number on 7seg diaplay
 *
 * @param[in] leftNumber      left data to write
 *
 * @param[in] rightNumber     right data to write
 *
 * Function write left and right number on 7seg display
 */
void c7seg_writeDataNumber( uint8_t leftNumber, uint8_t rightNumber );

/**
 * @breif Write character on 7seg diaplay
 *
 * @param[in] leftChar      left character to write
 *
 * @param[in] rightChar     right character to write
 *
 * Function write left and right character on 7seg display
 */
void c7seg_writeDataCharacter( char leftChar, char rightChar );






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_7seg_STM.c
    @example Click_7seg_TIVA.c
    @example Click_7seg_CEC.c
    @example Click_7seg_KINETIS.c
    @example Click_7seg_MSP.c
    @example Click_7seg_PIC.c
    @example Click_7seg_PIC32.c
    @example Click_7seg_DSPIC.c
    @example Click_7seg_AVR.c
    @example Click_7seg_FT90x.c
    @example Click_7seg_STM.mbas
    @example Click_7seg_TIVA.mbas
    @example Click_7seg_CEC.mbas
    @example Click_7seg_KINETIS.mbas
    @example Click_7seg_MSP.mbas
    @example Click_7seg_PIC.mbas
    @example Click_7seg_PIC32.mbas
    @example Click_7seg_DSPIC.mbas
    @example Click_7seg_AVR.mbas
    @example Click_7seg_FT90x.mbas
    @example Click_7seg_STM.mpas
    @example Click_7seg_TIVA.mpas
    @example Click_7seg_CEC.mpas
    @example Click_7seg_KINETIS.mpas
    @example Click_7seg_MSP.mpas
    @example Click_7seg_PIC.mpas
    @example Click_7seg_PIC32.mpas
    @example Click_7seg_DSPIC.mpas
    @example Click_7seg_AVR.mpas
    @example Click_7seg_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __c7seg_driver.h

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