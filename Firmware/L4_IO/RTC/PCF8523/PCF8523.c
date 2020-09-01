#include "PCF8523.h"
#include "PCF8523_Config.h"

#include <stdint.h>

#include "BSP_I2C.h"

#include "MyDebug.h"

#define I2C_ADDRESS (0x68)


// Default is to point to null.
static I2C_API * i2cAPI = 0;

uint8_t PCF8523_Init(I2C_Peripheral const i2c)
{
    // Get the I2C instance hat is to be used for this peripheral
    i2cAPI = BSP_I2C_GetInstance(i2c);
    /*
       No special requirements for initializing the FRAM.
    */
    return 0;
}


uint8_t PCF8523_Read(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, 0x02, data, 1);
    return 0;
}

uint8_t PCF8523_GetSeconds(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_SECONDS, data, 1);
    *data = (*data) & 0X7F;
    return 0;
}

uint8_t PCF8523_GetMinutes(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_MINUTES, data, 1);
    *data = (*data) & 0x7F;
    return 0;
}

uint8_t PCF8523_GetHours(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_HOURS, data, 1);
    *data = (*data) & 0x1F;
    return 0;
}

uint8_t PCF8523_GetDays(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_DAYS, data, 1);
    return 0;
}

uint8_t PCF8523_GetWeekdays(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_WEEKDAYS, data, 1);
    return 0;
}

uint8_t PCF8523_GetMonths(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_MONTHS, data, 1);
    return 0;
}

uint8_t PCF8523_GetYears(uint8_t * const data)
{
    i2cAPI->Read(I2C_ADDRESS, REGISTER_YEARS, data, 1);
    return 0;
}