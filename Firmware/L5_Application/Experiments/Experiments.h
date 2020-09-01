#ifndef EXPERIMENTS_H_
#define EXPERIMENTS_H_

#include "driverlib.h"
#include "PCB.h"
#include <stdlib.h>
 

extern const eUSCI_UART_Config uartConfig;


uint32_t Get_TIMER_PERIOD(void);
uint32_t Get_SYSTICK_INIT_VALUE(void);

void MyDelay( const uint32_t delay_ms);

void Experiment_SetupSystemClock(void);

/* Perform any additional setup for this experiment */
void Experiment_Setup( void );

/* Run the experiment */
void Experiment_Run( void );

void Experiment00_Setup(void);
void Experiment00_Run(void);

void Experiment01_Setup(void);
void Experiment01_Run(void);

void Experiment02_Setup(void);
void Experiment02_Run(void);

void Experiment03_Setup(void);
void Experiment03_Run(void);

void Experiment04_Setup(void);
void Experiment04_Run(void);

void Experiment05_Setup(void);
void Experiment05_Run(void);

void Experiment06_Setup(void);
void Experiment06_Run(void);

void Experiment07_Setup(void);
void Experiment07_Run(void);

void Experiment08_Setup(void);
void Experiment08_Run(void);

void Experiment09_Setup(void);
void Experiment09_Run(void);

void Experiment10_Setup(void);
void Experiment10_Run(void);

void Experiment11_Setup(void);
void Experiment11_Run(void);

void Experiment12_Setup(void);
void Experiment12_Run(void);

void Experiment13_Setup(void);
void Experiment13_Run(void);

void Experiment14_Setup(void);
void Experiment14_Run(void);

void Experiment15_Setup(void);
void Experiment15_Run(void);

void Experiment16A_Setup(void);
void Experiment16A_Run(void);

void Experiment16B_Setup(void);
void Experiment16B_Run(void);

void Experiment17_Setup(void);
void Experiment17_Run(void);

void Experiment18_Setup(void);
void Experiment18_Run(void);

void Experiment19_Setup(void);
void Experiment19_Run(void);

void Experiment20_Setup(void);
void Experiment20_Run(void);

void Experiment21_Setup(void);
void Experiment21_Run(void);

void Experiment22_Setup(void);
void Experiment22_Run(void);

void Experiment23_Setup(void);
void Experiment23_Run(void);

void Experiment24_Setup(void);
void Experiment24_Run(void);

void Experiment25_Setup(void);
void Experiment25_Run(void);

void Experiment26_Setup(void);
void Experiment26_Run(void);

void Experiment27_Setup(void);
void Experiment27_Run(void);

void Experiment28_Setup(void);
void Experiment28_Run(void);

void Experiment29_Setup(void);
void Experiment29_Run(void);

void Experiment30A_Setup(void);
void Experiment30A_Run(void);

void Experiment30B_Setup(void);
void Experiment30B_Run(void);

void Experiment31_Setup(void);
void Experiment31_Run(void);

void Experiment32_Setup(void);
void Experiment32_Run(void);

void Experiment33_Setup(void);
void Experiment33_Run(void);

void Experiment34_Setup(void);
void Experiment34_Run(void);

void Experiment35_Setup(void);
void Experiment35_Run(void);

void Experiment36_Setup(void);
void Experiment36_Run(void);

void Experiment37_Setup(void);
void Experiment37_Run(void);

void Experiment38_Setup(void);
void Experiment38_Run(void);

void Experiment39_Setup(void);
void Experiment39_Run(void);

void Experiment40_Setup(void);
void Experiment40_Run(void);

void Experiment41_Setup(void);
void Experiment41_Run(void);

void Experiment42_Setup(void);
void Experiment42_Run(void);

void Experiment43_Setup(void);
void Experiment43_Run(void);

void Experiment44_Setup(void);
void Experiment44_Run(void);

void Experiment45_Setup(void);
void Experiment45_Run(void);

void Experiment46_Setup(void);
void Experiment46_Run(void);

void Experiment47_Setup(void);
void Experiment47_Run(void);

void Experiment48_Setup(void);
void Experiment48_Run(void);

void Experiment49_Setup(void);
void Experiment49_Run(void);

void Experiment50_Setup(void);
void Experiment50_Run(void);

void Experiment51_Setup(void);
void Experiment51_Run(void);

void Experiment52_Setup(void);
void Experiment52_Run(void);

void Experiment53_Setup(void);
void Experiment53_Run(void);

void Experiment54_Setup(void);
void Experiment54_Run(void);

void Experiment55_Setup(void);
void Experiment55_Run(void);

void Experiment56_Setup(void);
void Experiment56_Run(void);

void Experiment57_Setup(void);
void Experiment57_Run(void);

void Experiment58_Setup(void);
void Experiment58_Run(void);

void Experiment59_Setup(void);
void Experiment59_Run(void);


void Experiment70_Setup(void);
void Experiment70_Run(void);

void Experiment71_Setup(void);
void Experiment71_Run(void);

void Experiment72_Setup(void);
void Experiment72_Run(void);

void Experiment73_Setup(void);
void Experiment73_Run(void);

void Experiment74_Setup(void);
void Experiment74_Run(void);

void Experiment75_Setup(void);
void Experiment75_Run(void);

void Experiment76_Setup(void);
void Experiment76_Run(void);

void Experiment77_Setup(void);
void Experiment77_Run(void);

void Experiment78_Setup(void);
void Experiment78_Run(void);

void Experiment79_Setup(void);
void Experiment79_Run(void);

void Experiment80_Setup(void);
void Experiment80_Run(void);

void Experiment81_Setup(void);
void Experiment81_Run(void);

void Experiment82_Setup(void);
void Experiment82_Run(void);


#endif