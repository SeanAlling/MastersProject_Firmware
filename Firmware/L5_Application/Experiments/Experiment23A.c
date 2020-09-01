#include "Experiments.h"


void Experiment23A_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    // Enable the memory
    STLQ015MXXX_Enable(&lightEnable);
    MyDelay(100);

}

void Experiment23A_Run(void)
{
    while(1)
    {
        PCM_shutdownDevice(PCM_LPM45);
    }
}