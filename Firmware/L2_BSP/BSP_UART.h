#ifndef BSP_UART_H_
#define BSP_UART_H_

#include <stdint.h>


typedef enum 
{
    UARTA0,
    NUM_UART_PERIPHERAL
}UART_Peripheral;


typedef struct
{
    uint8_t (*Write)(char const * const buffer, const uint32_t numBytes);
    uint8_t (*Read) (char * const buffer      , const uint32_t numBytes);
}UART_API;


UART_API* BSP_UART_Init(UART_Peripheral uart);

UART_API* BSP_UART_GetInstance(UART_Peripheral uart);


#endif // BSP_UART_H_