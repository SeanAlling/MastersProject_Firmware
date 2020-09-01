#include "XBee.h"

#include <stdint.h>

#include "BSP_UART.h"



// Default is to point to null.
static UART_API * uartAPI = 0;

uint8_t XBee_Init(UART_Peripheral const uart)
{
    // Get the I2C instance hat is to be used for this peripheral
    uartAPI = BSP_UART_GetInstance(uart);
    /*
       No special requirements for initializing the FRAM.
    */
    return 0;
}

uint8_t XBee_Write(char const * const data, uint32_t const numBytes)
{
    uartAPI->Write(data, numBytes);

    return 0;
}

uint8_t XBee_Read(char * const data, uint32_t const numBytes)
{
    uartAPI->Read(data, numBytes);

    return 0;
}