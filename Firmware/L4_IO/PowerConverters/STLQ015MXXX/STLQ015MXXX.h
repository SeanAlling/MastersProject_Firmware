#ifndef STLQ15MXXX_H_
#define STLQ15MXXX_H_

#include <stdint.h>
#include "BSP_GPO.h"

typedef struct 
{
    GPO_API * api;
    GPO_Peripheral gpo;
}STLQ015;

uint8_t STLQ015MXXX_Init(STLQ015 * const converter, GPO_Peripheral const gpo);
uint8_t STLQ015MXXX_Enable(STLQ015 const * const converter);
uint8_t STLQ015MXXX_Disable(STLQ015 const * const converter);

#endif // FM24CL16B_H_