#include "Experiments.h"


void Experiment13B_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);


    // Enable the memory
    STLQ015MXXX_Enable(&framEnable);
    // Give the memory 100 ms to start up
    MyDelay(100);
}




void Experiment13B_Run(void)
{
    // Wait for test bench signal to start the test.
    while(!GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN3))
    {

    }

    for(uint8_t i = 0; i < 3; i++)
    {
        for(uint32_t i = 0 ; i < 2048 ; i++)
        {
            FM24CL16B_WriteByte(i, i);
        }

        MyDelay(500);

        for(uint32_t i = 0 ; i < 2048 ; i++)
        {
            FM24CL16B_WriteByte(i, 0);
        }

        MyDelay(500);

        for(uint32_t i = 0 ; i < 2048 ; i++)
        {
            FM24CL16B_WriteByte(i, 1);
        }

        MyDelay(500);
    
    }
    
    // Tell test bench experiment is done. 
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN2);
}