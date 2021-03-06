#include "Experiments.h"


const static char data[32] = { 0xA5, 0x5A, 0xA5, 0x5A,0xA5, 0x5A, 0xA5, 0x5A,
                        0xA5, 0x5A, 0xA5, 0x5A,0xA5, 0x5A, 0xA5, 0x5A,
                        0xA5, 0x5A, 0xA5, 0x5A,0xA5, 0x5A, 0xA5, 0x5A,
                        0xA5, 0x5A, 0xA5, 0x5A,0xA5, 0x5A, 0xA5, 0x5A
                      };

void Experiment75_Setup(void)
{

    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0); // GPO_01
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); // GPO_02
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN3); // GPO_03
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2); // GPO_04
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4); // GPO_05
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7);  // GPO_06

    MyDelay(100);
}

void Experiment75_Run(void)
{   
    /*
        Set the MCU to shut down operation.  Want to limit the current consumed by the 
        MCU so the measurements are not skewed when measuring the current consumed by the FRAM.
    */
    while(1)
    {
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2); // GPO_04
        MyDelay(100);
        XBee_Write(data, 32);
        GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2); // GPO_04
        MyDelay(400);
    }
}