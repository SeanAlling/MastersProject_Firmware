#include "Experiments.h"


void Experiment07_Setup(void)
{
   // Do nothing
}

void Experiment07_Run(void)
{
    while(1)
    {
        PCM_shutdownDevice(PCM_LPM45);
    }
}