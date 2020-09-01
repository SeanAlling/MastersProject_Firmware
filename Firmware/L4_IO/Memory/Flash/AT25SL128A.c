#include "AT25SL128A.h"

#include <stdint.h>

#include "BSP_SPI.h"
#include "BSP_GPO.h"

#include "MyDebug.h"
#if 0
// Default is to point to null.
static SPI_API * spiAPI = 0;
static GPO_API * gpoAPI = 0;
static GPO_Peripheral gpoCS   = 0;
static GPO_Peripheral gpoWP   = 0;
static GPO_Peripheral gpoHold = 0;

uint8_t AT25SL128A_Init(SPI_Peripheral const spi, 
                        GPO_Peripheral const cs,
                        GPO_Peripheral const wp,
                        GPO_Peripheral const hold
                        )
{
    
    spiAPI = BSP_SPI_Init(spi);
    gpoAPI = BSP_GPO_Init(GPO_07);
    gpoAPI = BSP_GPO_Init(GPO_08);
    gpoAPI = BSP_GPO_Init(GPO_09);
    gpoCS  = cs;
    gpoWP  = wp;
    gpoHold = hold;

    gpoAPI -> Set(gpoCS);
    gpoAPI -> Clear(gpoWP);
    gpoAPI -> Set(gpoHold);

    return 0;
}

uint8_t AT25SL128A_ReadManufacturerID(void)
{
    gpoAPI -> Clear(gpoCS);
    gpoAPI -> Set(gpoWP);
    gpoAPI -> Set(gpoHold);
    
    uint8_t buffer[4] = {0x9F, 0x00, 0x00, 0x00};
    spiAPI -> Write(buffer, 1);
    spiAPI -> Read(buffer, 3);
    gpoAPI -> Set(gpoCS);
    return buffer[0];
}
#endif