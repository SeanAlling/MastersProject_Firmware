#include "OPT3001.h"

#include <stdint.h>

#include "BSP_I2C.h"

#include "MyDebug.h"

#define I2C_ADDRESS (0x45)

// Sensor register address macros
#define REGISTER_RESULT          (0x00)
#define REGISTER_CONFIGURATION   (0x01)
#define REGISTER_LOW_LIMIT       (0x02)
#define REGISTER_HIGH_LIMIT      (0x03)
#define REGISTER_MANUFACTURER_ID (0x7E)
#define REGISTER_DEVICE_ID       (0x7F)

// Configurations masks
#define CONFIGURATION_RESET (1<<15)
#define CONFIGURATION_HEAT  (1<<13)
#define CONFIGURATION_MODE  (1<<12)
#define CONFIGURATION_BTST  (1<<11)
#define CONFIGURATION_TRES  (1<<10)
#define CONFIGURATION_HRES  (3<<8 )


/*
    I2C sends MSB first. So for sending or receiving keep this in mind.
 */


// Default is to point to null.
static I2C_API * i2cAPI = 0;

uint8_t OPT3001_Init(I2C_Peripheral const i2c)
{
    // Get the I2C instance hat is to be used for this peripheral
    i2cAPI = BSP_I2C_GetInstance(i2c);
    /*
       No special requirements for initializing the FRAM.
    */
    return 0;
}

uint8_t OPT3001_ReadResult(uint16_t * data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_RESULT, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_ReadConfiguration(uint16_t *   data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_ReadLowLimit(uint16_t *   data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_LOW_LIMIT, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_ReadHighLimit(uint16_t *   data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_HIGH_LIMIT, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_ReadManufacturerID(uint16_t *  data )
{
  // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_MANUFACTURER_ID, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_ReadDeviceID(uint16_t *  data )
{
  // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    //i2cAPI->Write(I2C_ADDRESS, REGISTER_DEVICE_ID, 0, 0);
    i2cAPI->Read(I2C_ADDRESS, REGISTER_DEVICE_ID, buffer, 2);
    *data = (uint16_t)((buffer[0]<<8) | (buffer[1]<<0));
    return 0;
}

uint8_t OPT3001_WriteConfiguration(uint16_t  data )
{
  // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    buffer[0] = (data>>0) & 0xFF;
    buffer[1] = (data>>8) & 0xFF;
    i2cAPI->Write(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    return 0;
}

