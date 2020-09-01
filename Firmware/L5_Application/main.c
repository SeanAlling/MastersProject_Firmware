/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



/* TI includes. */
/* DriverLib Includes */
#include "driverlib.h"

#include "MyDebug.h"
#include "PCB.h"
#include "BSP_UART.h"
#include "BSP_Timer.h"
#include "eink_display.h" 
/*-----------------------------------------------------------*/

 
#include "Experiments.h"


int main( void )
{
    /* Halting the Watchdog */
    MAP_WDT_A_holdTimer();

    Experiment_SetupSystemClock();

    /* Initialize the PCB. Sets up all peripherals that are to be used */
    PCB_Setup();

    /* Perform any additional setup for this experiment */
    Experiment_Setup();

    /* Run the experiment */
    Experiment_Run();

    while(1)
    {

    }

}