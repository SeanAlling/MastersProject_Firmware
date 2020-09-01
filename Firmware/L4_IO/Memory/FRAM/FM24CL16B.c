#include "FM24CL16B.h"
#include "FM24CL16B_Config.h"

#include <stdint.h>

#include "BSP_I2C.h"

#include "MyDebug.h"

// Default is to point to null.
static I2C_API * i2cAPI = 0;

uint8_t FM24CL16B_Init(I2C_Peripheral const i2c)
{
    // Get the I2C instance hat is to be used for this peripheral
    i2cAPI = BSP_I2C_GetInstance(i2c);
    /*
       No special requirements for initializing the FRAM.
    */
    return 0;
}

/*
    The FM24CL16B contains 16Kb -> 2KB. The address to start a write is defined to be 11 bits, 
    the 3 LSB determine the page with the 8 LSB selecting the offset on the page. 

    The address is passed as a 16 bit number. The page and page offset are extracted so that proper 
    I2C operation is performed.
*/
uint8_t FM24CL16B_WriteByte(uint16_t const address, uint8_t const data)
{
    uint8_t i2cAddress = (I2C_ADRESS | (FM24CL16B_PAGE_MASK & (address>>8)));
    uint8_t pageOffset  = address & ~(FM24CL16B_PAGE_MASK);

    /* 
        Address should be a value between 0 to NUMBER_OF_ENTRIES
        If the value is not within this range then the user has given an invalid address.
    */
    if(address >= FM24CL16B_NUMBER_OF_ENTRIES)
    {
        ERROR("ERROR: FM24CL16B: Address out of range\n");
        return 1;
    }

    i2cAPI->Write(i2cAddress, pageOffset, &data, 1);
    return 0;
}

uint8_t FM24CL16B_ReadByte(uint16_t const address, uint8_t * const data)
{
    uint8_t i2cAddress = (I2C_ADRESS | (FM24CL16B_PAGE_MASK & (address>>8)));
    uint8_t pageOffet  = address & ~(FM24CL16B_PAGE_MASK);

    /* 
        Address should be a value between 0 to NUMBER_OF_ENTRIES
        If the value is not within this range then the user has given an invalid address.
    */
    if(address >= FM24CL16B_NUMBER_OF_ENTRIES)
    {
        ERROR("ERROR: FM24CL16B: Address out of range\n");
        return 1;
    }

    i2cAPI->Read(i2cAddress, pageOffet, data, 1);
    return 0;
}