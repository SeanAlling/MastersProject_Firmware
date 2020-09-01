#ifndef BSP_GPI_H_
#define BSP_GPI_H_

#include <stdint.h>

/*
    Define an an I2CX entry for each I2C peripheral. 
    Increment X for each I2C peripheral.
*/
typedef enum 
{
    GPI_EINK_BUSY,
    NUM_GPI_PERIPHERAL
}GPI_Peripheral;

/*
    Defines he function prototypes for an I2C read and write functions.
*/
typedef struct
{
    uint8_t (*Get)(GPI_Peripheral gpi); 
}GPI_API;

GPI_API* BSP_GPI_Init(GPI_Peripheral gpi);

GPI_API* BSP_GPI_GetInstance(GPI_Peripheral gpi);


#endif // BSP_GPI_H_