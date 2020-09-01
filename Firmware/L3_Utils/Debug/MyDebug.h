#ifndef MY_DEBUG_H_
#define MY_DEBUG_H_


// Macro defines for simple printing messages during debug. 

#ifdef DEBUG2
    #include "SEGGER_RTT.h"

    #define INFO(str)    (SEGGER_RTT_WriteString(0,str))
    #define WARNING(str) (SEGGER_RTT_WriteString(0,str))
    #define ERROR(str)   (SEGGER_RTT_WriteString(0,str))

    #define WRITE_INTEGER(str) (SEGGER_RTT_printf(0,"Data: %d", str))
#else
    #define INFO(str)    
    #define WARNING(str) 
    #define ERROR(str)   
#endif

#endif // MY_DEBUG_H_