#ifndef PCF8523_H_
#define PCF8523_H_

#include "stdint.h"

#include "BSP_I2C.h"

uint8_t PCF8523_Init(I2C_Peripheral const i2c);
uint8_t PCF8523_Read(uint8_t * const data);
uint8_t PCF8523_GetSeconds(uint8_t * const data);
uint8_t PCF8523_GetMinutes(uint8_t * const data);
uint8_t PCF8523_GetHours(uint8_t * const data);
uint8_t PCF8523_GetDays(uint8_t * const data);
uint8_t PCF8523_GetWeekdays(uint8_t * const data);
uint8_t PCF8523_GetMonths(uint8_t * const data);
uint8_t PCF8523_GetYears(uint8_t * const data);

#endif // PCF8523_H_