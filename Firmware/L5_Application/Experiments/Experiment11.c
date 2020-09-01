#include "Experiments.h"


/* Timer32 ISR */
static void T32_INT1_Int(void)
{
    Timer32_clearInterruptFlag(TIMER32_BASE);
    GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    Timer32_setCount(TIMER32_BASE,Get_TIMER_PERIOD());
    Timer32_enableInterrupt(TIMER32_BASE);
    Timer32_startTimer(TIMER32_BASE, true);
}

void Experiment11_Setup(void)
{
        /* Configuring Timer32 to 128000 (1s) of MCLK in periodic mode */
        Timer32_initModule(TIMER32_BASE, TIMER32_PRESCALER_1, TIMER32_32BIT,TIMER32_PERIODIC_MODE);
 

        Timer32_setCount(TIMER32_BASE,Get_TIMER_PERIOD());

        Timer32_registerInterrupt(TIMER32_COMBINED_INTERRUPT,T32_INT1_Int);
        Timer32_enableInterrupt(TIMER32_BASE);
        Timer32_startTimer(TIMER32_BASE, true); 
        /* Enabling interrupts and starting the timer */
        MAP_Interrupt_enableSleepOnIsrExit();
        /* Enabling MASTER interrupts */
        MAP_Interrupt_enableMaster(); 
}

void Experiment11_Run(void)
{
    while(1)
    {
        PCM_gotoLPM0();
        // LED is toggled in interro
    }
}