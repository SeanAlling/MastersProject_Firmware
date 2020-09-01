#ifndef XBEE_H_
#define XBEE_H_

#include "stdint.h"

#include "BSP_UART.h"


uint8_t XBee_Init(UART_Peripheral const uart);
uint8_t XBee_Write(char const * const data, uint32_t const numBytes);
uint8_t XBee_Read(char * const data       , uint32_t const numBytes);





#endif // XBEE_H_