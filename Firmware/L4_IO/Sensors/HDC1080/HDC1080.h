#ifndef HDC1080_H_
#define HDC1080_H_

#include "stdint.h"

#include "BSP_I2C.h"






uint8_t HDC1080_Init(I2C_Peripheral const i2c);
uint8_t HDC1080_ReadTemperature   (uint16_t * data);
uint8_t HDC1080_ReadHumidity      (uint16_t * data);
uint8_t HDC1080_ReadConfiguration (uint16_t * data);
uint8_t HDC1080_ReadSerialNumber  (uint8_t  * data);
uint8_t HDC1080_ReadManufacturerID(uint16_t * data );
uint8_t HDC1080_ReadDeviceID      (uint16_t * data );

uint8_t HDC1080_WriteConfiguration(uint16_t const data );

#endif // HDC1080_H_