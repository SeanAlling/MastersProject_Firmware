#ifndef PCB_H_
#define PCB_H_

// Include each header file for components that 
// are located on the PCB.
#include "FM24CL16B.h"
#include "HDC1080.h"
#include "OPT3001.h"
#include "PCF8523.h"
#include "XBee.h"


#include "STLQ015MXXX.h"

#include "BSP_GPI.h"
#include "BSP_GPO.h"
#include "BSP_UART.h"
#include "BSP_Timer.h"
#include "eink_display.h" 

extern STLQ015 framEnable       ;
extern STLQ015 temperatureEnable;
extern STLQ015 lightEnable      ;
extern STLQ015 displayEnable    ;
extern STLQ015 fpgaEnable       ;
extern STLQ015 xbeeEnable       ;



void PCB_Setup(void);




#endif // PCB_H_