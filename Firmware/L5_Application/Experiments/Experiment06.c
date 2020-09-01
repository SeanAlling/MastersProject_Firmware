#include "Experiments.h"


void Experiment06_Setup(void)
{
   // Do nothing
}

void Experiment06_Run(void)
{
    while(1)
    {
        PCM_setPowerState(PCM_LPM35_VCORE0);
    }
}