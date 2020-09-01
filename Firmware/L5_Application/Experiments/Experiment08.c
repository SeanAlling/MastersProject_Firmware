#include "Experiments.h"


void Experiment08_Setup(void)
{
   // Do nothing
}

void Experiment08_Run(void)
{
    while(1)
    {
        // Toggle a pin
        GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    }
}