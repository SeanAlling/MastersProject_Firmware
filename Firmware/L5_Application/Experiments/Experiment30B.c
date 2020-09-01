#include "Experiments.h"


void Experiment30B_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);


    // Enable the memory
    STLQ015MXXX_Enable(&xbeeEnable);
    // Give the memory 100 ms to start up
    MyDelay(100);
}




void Experiment30B_Run(void)
{
    while(1)
    {
        XBee_Write("Hello World\n",11);
    }
}