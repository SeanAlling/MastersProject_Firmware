#include "Experiments.h"

static     uint16_t data = 0;

/* Timer32 ISR */
static void T32_INT1_Int(void)
{
    Timer32_clearInterruptFlag(TIMER32_BASE);
    OPT3001_ReadResult(&data);


    GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    Timer32_setCount(TIMER32_BASE,Get_TIMER_PERIOD());
    Timer32_enableInterrupt(TIMER32_BASE);
    Timer32_startTimer(TIMER32_BASE, true);
}

void Experiment24_Setup(void)
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

    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);

    // Enable the memory
    STLQ015MXXX_Enable(&lightEnable);
    MyDelay(100);
}


void Experiment24_Run(void)
{
    while(1)
    {
        // Data is read inside of the ISR
    }

    // Tell test bench experiment is done. 
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN2);
}