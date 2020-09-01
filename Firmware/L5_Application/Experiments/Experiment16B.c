#include "Experiments.h"


void Experiment16B_Setup(void)
{
    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    // Enable the memory
    STLQ015MXXX_Enable(&temperatureEnable);
    // Give the memory 100 ms to start up
    MyDelay(100);
}




void Experiment16B_Run(void)
{
    uint16_t data = 0;

    while(1)
    {
        HDC1080_ReadTemperature(&data);
        HDC1080_ReadHumidity(&data);
    }

}