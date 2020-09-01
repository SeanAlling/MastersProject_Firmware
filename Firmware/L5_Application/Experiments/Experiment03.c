#include "Experiments.h"


void Experiment03_Setup(void)
{
    CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    PCM_setPowerState(PCM_AM_LF_VCORE0);
}

void Experiment03_Run(void)
{
    while(1)
    {
        PCM_setPowerState(PCM_LPM0_LF_VCORE0);
    }
}