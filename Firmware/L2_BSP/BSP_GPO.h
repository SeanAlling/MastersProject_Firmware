#ifndef BSP_GPO_H_
#define BSP_GPO_H_

#include <stdint.h>

/*
    Define an an I2CX entry for each I2C peripheral. 
    Increment X for each I2C peripheral.
*/
typedef enum 
{
    GPO_01,
    GPO_02,
    GPO_03,
    GPO_04,
    GPO_05,
    GPO_06,

    GPO_DISPLAY_DC,
    GPO_DISPLAY_CS, 
    GPO_EINK_RST,
    NUM_GPO_PERIPHERAL
}GPO_Peripheral;


/*
    Defines he function prototypes for an I2C read and write functions.
*/
typedef struct
{
    uint8_t (*Set)(GPO_Peripheral const gpo);
    uint8_t (*Clear)(GPO_Peripheral const gpo);
    uint8_t (*Toggle)(GPO_Peripheral const gpo);
}GPO_API;

GPO_API* BSP_GPO_Init(GPO_Peripheral const gpo);

GPO_API* BSP_GPO_GetInstance(GPO_Peripheral gpo);


#endif // BSP_GPO_H_