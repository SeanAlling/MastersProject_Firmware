#include "Experiments.h"
#include "BSP_Timer.h"

void Experiment10_Setup(void)
{
        CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
        CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
        PCM_setPowerState(PCM_AM_LF_VCORE0);
        Timer_SysTickInit(Get_SYSTICK_INIT_VALUE());
}

void Experiment10_Run(void)
{
    while(1)
    {
        /*
            LED is toggled at a fixed rate. The rate is determined by polling the systick timer.
        */
        MyDelay(500); 
        GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    }
}