#include "Experiments.h"


void Experiment13A_Setup(void)
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




void Experiment13A_Run(void)
{   
    /*
        Set the MCU to shut down operation.  Want to limit the current consumed by the 
        MCU so the measurements are not skewed when measuring the current consumed by the FRAM.
    */
    while(1)
    {
         PCM_shutdownDevice(PCM_LPM45);
    }
}