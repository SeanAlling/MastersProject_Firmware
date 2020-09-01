#ifndef OPT3001_H_
#define OPT3001_H_

#include "stdint.h"

#include "BSP_I2C.h"





uint8_t OPT3001_Init(I2C_Peripheral const i2c);
uint8_t OPT3001_ReadResult        (uint16_t * data);
uint8_t OPT3001_ReadConfiguration (uint16_t * data);
uint8_t OPT3001_ReadLowLimit      (uint16_t * data);
uint8_t OPT3001_ReadHighLimit     (uint16_t * data);
uint8_t OPT3001_ReadManufacturerID(uint16_t * data );
uint8_t OPT3001_ReadDeviceID      (uint16_t * data );

uint8_t OPT3001_WriteConfiguration(uint16_t const data );


#endif // OPT3001_H_