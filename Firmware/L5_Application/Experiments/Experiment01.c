#include "Experiments.h"


void Experiment01_Setup(void)
{
    CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    PCM_setPowerState(PCM_AM_LF_VCORE0);
}

void Experiment01_Run(void)
{
    // Low frequency active mode w/ empty while loop

    while(1)
    {
        
    }
}