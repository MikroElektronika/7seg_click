![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# 7seg Click

---

- **CIC Prefix**  : C7SEG
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Jul 2018.

---

### Software Support

We provide a library for the 7seg Click on our [LibStock](https://libstock.mikroe.com/projects/view/391/7seg-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**


The library covers all the necessary functions for  7SEG click control.

Key functions :

- ``` void c7seg_writeData( uint8_t writeLeft, uint8_t writeRight ) ``` - Generic write data function
- ``` void c7seg_writeDataNumber( uint8_t leftNumber, uint8_t rightNumber ) ``` - Function write left and right number on 7seg display
- ``` void c7seg_writeDataCharacter( char leftChar, char rightChar ) ``` - Function write left and right character on 7seg display

**Examples Description**

The application is composed of three sections :

- System Initialization - Following pins: CS, RST and PWM are set as output
and SPI module is initialized for communcation with 7seg click.
- Application Initialization - Driver initializaion and turning on the display
by setting PWM pin to logic 1 and prepare to communcation via SPI.
- Application Task - (code snippet) This example shows functionality of the 7seg click,
shows number or character on left and right display.


```.c

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

```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/391/7seg-click-example) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
