#include "Experiments.h"


void Experiment12_Setup(void)
{
    #warning UNDEFINE TEST
    CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    PCM_setPowerState(PCM_AM_LF_VCORE0);

    // Need to set up systick to run at low frequency
}

void Experiment12_Run(void)
{
    while(1)
    {
        MyDelay(500); 
        GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    }
}