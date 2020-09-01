#include "Experiments.h"
#include "MyDebug.h"

void Experiment09_Setup(void)
{
        CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
        CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
        PCM_setPowerState(PCM_AM_LF_VCORE0);
}

void Experiment09_Run(void)
{
    while(1)
    {
        // Toggle a pin
        GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    }
}