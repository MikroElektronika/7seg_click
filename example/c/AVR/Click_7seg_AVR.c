/*
Example for 7seg Click

    Date          : Jul 2018.
    Author        : Nenad Filipovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Following pins: CS, RST and PWM are set as output
and SPI module is initialized for communcation with 7seg click.
- Application Initialization - Driver initializaion and turning on the display
by setting PWM pin to logic 1 and prepare to communcation via SPI.
- Application Task - (code snippet) This example shows functionality of the 7seg click,
shows number or character on left and right display.

Additional Functions :

- SPI

*/

#include "Click_7seg_types.h"
#include "Click_7seg_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_C7SEG_SPI_CFG[0] );

    Delay_100ms();
}

void applicationInit()
{
    c7seg_spiDriverInit( (T_C7SEG_P)&_MIKROBUS1_GPIO, (T_C7SEG_P)&_MIKROBUS1_SPI );
    c7seg_set7seg();
    Delay_100ms();
}

void applicationTask()
{
    uint8_t counter;

    c7seg__displayOn();
    Delay_1sec();

    c7seg_writeDataCharacter( 'A', 'B' );
    Delay_1sec();

    c7seg_writeData( 0x10, 0x01 );
    Delay_1sec();

    c7seg_writeDataCharacter( '.', '-' );
    Delay_1sec();

    for ( counter = 0; counter < 9; counter ++ )
    {
        c7seg_writeDataNumber( counter, counter+1 );
        Delay_1sec();
    }
    Delay_1sec();

    for ( counter = 65; counter < 90; counter ++ )
    {
        c7seg_writeDataCharacter( counter, counter+1 );
        Delay_1sec();
    }
    Delay_1sec();

    c7seg__displayOff();
    Delay_1sec();

}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}