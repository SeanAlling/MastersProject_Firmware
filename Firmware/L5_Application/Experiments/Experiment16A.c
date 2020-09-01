#include "Experiments.h"


void Experiment16A_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    // Enable the memory
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0); // GPO_01
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); // GPO_02
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN3); // GPO_03
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2); // GPO_04
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4); // GPO_05
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN7);  // GPO_06
    // Give the memory 100 ms to start up
    MyDelay(100);
}




void Experiment16A_Run(void)
{
    while(1)
    {
        PCM_shutdownDevice(PCM_LPM45);
    }
}