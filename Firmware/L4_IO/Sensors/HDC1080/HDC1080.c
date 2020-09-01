#include "HDC1080.h"

#include <stdint.h>

#include "BSP_I2C.h"

#include "MyDebug.h"

#define I2C_ADDRESS (0x40)


// Sensor register address macros
#define REGISTER_TEMPERATURE     (0x00)
#define REGISTER_HUMIDITY        (0x01)
#define REGISTER_CONFIGURATION   (0x02)
#define REGISTER_SERIAL_ID_HIGH  (0xFB)
#define REGISTER_SERIAL_ID_MID   (0xFC)
#define REGISTER_SERIAL_ID_LOW   (0xFD)
#define REGISTER_MANUFACTURER_ID (0xFE)
#define REGISTER_DEVICE_ID       (0xFF)

// Configurations masks
#define CONFIGURATION_RESET (1<<15)
#define CONFIGURATION_HEAT  (1<<13)
#define CONFIGURATION_MODE  (1<<12)
#define CONFIGURATION_BTST  (1<<11)
#define CONFIGURATION_TRES  (1<<10)
#define CONFIGURATION_HRES  (3<<8 )


// Default is to point to null.
static I2C_API * i2cAPI = 0;

uint8_t HDC1080_Init(I2C_Peripheral const i2c)
{
    // Get the I2C instance hat is to be used for this peripheral
    i2cAPI = BSP_I2C_GetInstance(i2c);
    /*
       No special requirements for initializing the FRAM.
    */
    return 0;
}

uint8_t HDC1080_ReadTemperature(uint16_t * data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    uint16_t configuration = 0;
    i2cAPI->Read(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    configuration = (buffer[0]<<8) | (buffer[1]<<0);
    // Set mode bit to zero for single temp measurement
    configuration = configuration & ~CONFIGURATION_MODE;
    // Set to high resolution.
    configuration = configuration & ~CONFIGURATION_TRES;
    // Write configuration back to chip. 
    buffer[1] = (configuration>>0) & 0xFF;
    buffer[0] = (configuration>>8) & 0xFF;
    i2cAPI->Write(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    // Tell sensor to start a measurement
    i2cAPI->Write(I2C_ADDRESS, REGISTER_TEMPERATURE, 0, 0);
    // Wait for configuration cycle to complete, then read back temperature.
    for(uint8_t i = 0; i < 200; i++)
    {
        // Empty for loop. Used as a delay.
        // his lets the conversion complete. 
        // Datasheet sates conversion will take 6.35ms to complete. 
        // TODO: A better solution would be to use a hardware timer.
    }
    i2cAPI->Read(I2C_ADDRESS, REGISTER_TEMPERATURE, buffer, 2);
    *data = (buffer[0]<<8) | (buffer[1]<<0);

    return 0;
}
uint8_t HDC1080_ReadHumidity (uint16_t * data)
{    
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    uint16_t configuration = 0;
    i2cAPI->Read(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    configuration = (buffer[0]<<8) | (buffer[1]<<0);
    // Set mode bit to zero for single temp measurement
    configuration = configuration & ~CONFIGURATION_MODE;
    // Set to high resolution.
    configuration = configuration & ~CONFIGURATION_HRES;
    // Write configuration back to chip. 
    buffer[1] = (configuration>>0) & 0xFF;
    buffer[0] = (configuration>>8) & 0xFF;
    i2cAPI->Write(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    // Tell sensor to start a measurement
    i2cAPI->Write(I2C_ADDRESS, REGISTER_HUMIDITY, 0, 0);
    // Wait for configuration cycle to complete, then read back temperature.
    for(uint32_t i = 0; i < 500; i++)
    {
        // Empty for loop. Used as a delay.
        // his lets the conversion complete. 
        // Datasheet sates conversion will take 6.35ms to complete. 
        // TODO: A better solution would be to use a hardware timer.
    }
    i2cAPI->Read(I2C_ADDRESS, REGISTER_HUMIDITY, buffer, 2);
    *data = (buffer[0]<<8) | (buffer[1]<<0);
    return 0;

}
uint8_t HDC1080_ReadConfiguration(uint16_t  * data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);
    *data = (buffer[0]<<8) | (buffer[1]<<0);
    return 0;
}
uint8_t HDC1080_ReadSerialNumber(uint8_t * data)
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[6] = {0,0,0,0,0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_SERIAL_ID_HIGH   , buffer, 8);
    // First byte should be ignored from the data array, it is always 0. 
    for(uint8_t i = 0; i < 6; i++)
    {
        // This array has the bytes in reverse endian order.
        // I2C works in big endian format.
        data[i-1] = buffer[i];
    }
    return 0;
}
uint8_t HDC1080_ReadManufacturerID(uint16_t * data )
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};
    i2cAPI->Read(I2C_ADDRESS, REGISTER_MANUFACTURER_ID, buffer, 2);
    *data = (buffer[0]<<8) | (buffer[1]<<0);
    return 0;
}

uint8_t HDC1080_ReadDeviceID(uint16_t * data )
{
    // Result is 16 bits. Place the read bytes here
    uint8_t buffer[2] = {0,0};

    if(i2cAPI->Read(I2C_ADDRESS, REGISTER_DEVICE_ID, buffer, 2) == 0)
    {
        *data = (buffer[0]<<8) | (buffer[1]<<0);
        return 0;
    }
    else
    {
        return 1;
    }
}

uint8_t HDC1080_WriteConfiguration(uint16_t const data )
{
    uint8_t buffer[2] = {0,0};
    // Write configuration back to chip. 
    buffer[1] = (data>>0) & 0xFF;
    buffer[0] = (data>>8) & 0xFF;
    i2cAPI->Write(I2C_ADDRESS, REGISTER_CONFIGURATION, buffer, 2);

    return 0;
}