#include "BSP_UART.h"

#include <stdint.h>
#include <string.h> 
// HEader file for MSP432 i2c operations. 
#include "uart.h"
#include "gpio.h"
#include "MyDebug.h"
#include "Experiments.h"



static uint8_t Write(char const * const buffer, const uint32_t numBytes);
static uint8_t Read(char * const buffer      , const uint32_t numBytes);

static UART_API instances[NUM_UART_PERIPHERAL] =
{
    {Write, Read}, // UARTA0
};


UART_API* BSP_UART_Init(UART_Peripheral uart)
{
    /* Selecting P1.2 and P1.3 in UART mode */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring UART Module */
    UART_initModule(EUSCI_A0_BASE, &uartConfig);
    
    /* Enable UART module */
    UART_enableModule(EUSCI_A0_BASE);

    return &instances[uart];
} 

UART_API* BSP_UART_GetInstance(UART_Peripheral uart)
{
    return &instances[uart];
}

static uint8_t Write(char const * const buffer, const uint32_t numBytes)
{
    for(uint32_t i = 0; i < numBytes; i++)
    {
        UART_transmitData(EUSCI_A0_BASE, buffer[i]);
    }
    return 0;
}
static uint8_t Read(char * const buffer      , const uint32_t numBytes)
{
    for(uint32_t i = 0; i < numBytes; i++)
    {
        buffer[i] = UART_receiveData(EUSCI_A0_BASE);
    }
    return 0;
}