#ifndef BSP_I2C_H_
#define BSP_I2C_H_

#include <stdint.h>

/*
    Define an an I2CX entry for each I2C peripheral. 
    Increment X for each I2C peripheral.
*/
typedef enum 
{
    I2C0,
    NUM_I2C_PERIPHERAL
}I2C_Peripheral;

/*
    Defines he function prototypes for an I2C read and write functions.
*/
typedef struct
{
    uint8_t (*Write)(uint8_t const address, uint8_t reg, uint8_t const * const buffer, const uint8_t numBytes);
    uint8_t (*Read) (uint8_t const address, uint8_t reg, uint8_t * const buffer, const uint8_t numBytes);
}I2C_API;

/**
 * @brief      Initialize the I2C peripheral specified by the user. 
 *
 * @param[in]  peripheral I2C peripheral ID that a user can specify which 
 *                        I2C peripheral on chip can be initialized. If only
 *                        a single I2C peripheral exists then the user can 
 *                        pass whatever any number as the implementation will
 *                        ignore this parameter. 
 *                        
 * @return     NULL is init failed, otherwise an a pointer ti the read and write functions
 *             for the I2C peripheral.
 */
I2C_API* BSP_I2C_Init(I2C_Peripheral i2c);

I2C_API* BSP_I2C_GetInstance(I2C_Peripheral i2c);


#endif // BSP_I2C_H_