#ifndef FM24CL16B_H_
#define FM24CL16B_H_

#include <stdint.h>
#include "BSP_I2C.h"

uint8_t FM24CL16B_Init(I2C_Peripheral const i2c);
uint8_t FM24CL16B_WriteByte(uint16_t const address, uint8_t const data);
uint8_t FM24CL16B_ReadByte(uint16_t const address, uint8_t * const data);


#endif // FM24CL16B_H_