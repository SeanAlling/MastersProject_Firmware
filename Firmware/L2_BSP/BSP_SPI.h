#ifndef BSP_SPI_H_
#define BSP_SPI_H_



#include <stdint.h>

typedef enum 
{
    SPI0,
    NUM_SPI_PERIPHERAL
}SPI_Peripheral;

/*
    Defines he function prototypes for an I2C read and write functions.
*/
typedef struct
{
    uint8_t (*Write)(uint8_t const * const buffer, const uint8_t numBytes);
    uint8_t (*Read) (uint8_t * const buffer, const uint8_t numBytes);
}SPI_API;

SPI_API* BSP_SPI_Init(SPI_Peripheral spi);

SPI_API* BSP_SPI_GetInstance(SPI_Peripheral spi);


#endif // BSP_SPI_H_