#include "Experiments.h"

void Experiment23B_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    // Enable the memory
    STLQ015MXXX_Enable(&lightEnable);
    MyDelay(100);

}




void Experiment23B_Run(void)
{
    uint16_t data = 0;
    while(1)
    {
        OPT3001_ReadResult(&data);
    }
}