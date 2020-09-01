#include "PCB.h"
#include "driverlib.h"

/*
    Declare the variables that will hold the instance for the DC/DC converters.
    These are global since they need t be accessed by multiple files. 
*/
STLQ015 framEnable        ;
STLQ015 temperatureEnable;
STLQ015 lightEnable      ;
STLQ015 displayEnable    ;
STLQ015 fpgaEnable       ;
STLQ015 xbeeEnable       ;

void PCB_Setup(void)
{
    #if 0
    /*
        Set the unused pins in a default state. Now they have a defined state and are not floating./
        This helps reduce the amount of static current draw on the MMSP432.
    */
    GPIO_setAsOutputPin(GPIO_PORT_P1 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P2 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P3 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P4 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P5 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P6 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P7 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P8 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P9 , PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_P10, PIN_ALL8);
    GPIO_setAsOutputPin(GPIO_PORT_PJ , PIN_ALL8);

    GPIO_setOutputLowOnPin(GPIO_PORT_P1 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P8 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P9 , PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_P10, PIN_ALL8);
    GPIO_setOutputLowOnPin(GPIO_PORT_PJ , PIN_ALL8);

    #else


    /*
        Init BSP subsystem
    */
    BSP_I2C_Init(I2C0);
    BSP_UART_Init(UARTA0);

    /*
        Init devices on PCB
    */
    FM24CL16B_Init(I2C0);
    HDC1080_Init(I2C0);
    OPT3001_Init(I2C0);
    PCF8523_Init(I2C0);
    XBee_Init(UARTA0);

    ePaper_Init(
                 SPI0,
                 GPO_DISPLAY_CS,
                 GPO_DISPLAY_DC,
                 GPO_EINK_RST,
                 GPI_EINK_BUSY
                );

    /* 
        Setup each of the DC/DC converters. The following is really just an alias to turning on or off a GPIO.
    */
    STLQ015MXXX_Init(&framEnable       , GPO_06);
    STLQ015MXXX_Init(&temperatureEnable, GPO_02);
    STLQ015MXXX_Init(&lightEnable      , GPO_01);
    STLQ015MXXX_Init(&displayEnable    , GPO_05);
    STLQ015MXXX_Init(&fpgaEnable       , GPO_03);
    STLQ015MXXX_Init(&xbeeEnable       , GPO_04);

    /*
        Default is to turn off all subsystems.
    */
    STLQ015MXXX_Disable(&framEnable);
    STLQ015MXXX_Disable(&temperatureEnable);
    STLQ015MXXX_Disable(&lightEnable);
    STLQ015MXXX_Disable(&displayEnable);
    STLQ015MXXX_Disable(&fpgaEnable);
    STLQ015MXXX_Disable(&xbeeEnable);


    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0); // GPO_01
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); // GPO_02
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN3); // GPO_03
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2); // GPO_04
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4); // GPO_05
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7);  // GPO_06

    #endif
}
