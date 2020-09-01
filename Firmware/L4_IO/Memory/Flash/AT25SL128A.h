#ifndef AT25SL128A_H_
#define AT25SL128A_H_

#include <stdint.h>
#include "BSP_SPI.h"
#include "BSP_GPO.h"

uint8_t AT25SL128A_Init(SPI_Peripheral const spi, 
                        GPO_Peripheral const cs,
                        GPO_Peripheral const wp,
                        GPO_Peripheral const hold
                        );
uint8_t AT25SL128A_ReadManufacturerID(void);


#endif // AT25SL128A_H_