#include "BSP_GPI.h"

#include <stdint.h>

// HEader file for MSP432 i2c operations. 
#include "gpio.h"
#include "MyDebug.h"



typedef struct 
{
    uint8_t port;
    uint8_t pin;
} GPI_PortPin;


static uint8_t Get(GPI_Peripheral const gpi);

/*
    All GPO use the same API. The user passes an enum that selects which GPO port and pins
    to use. 
*/
static GPI_API instance = {Get}; // ENABLE_FM24CL16B



static uint8_t initilized[NUM_GPI_PERIPHERAL] = {0};

/*
    Declare a pin map for each of the port pin pairs for outputs
*/
static GPI_PortPin const  pinMap[NUM_GPI_PERIPHERAL] =
{
    #if 1
    {GPIO_PORT_P8, GPIO_PIN3}, // Display Busy
    #else
    {GPIO_PORT_P6, GPIO_PIN1}, // Display Busy
    #endif
};


GPI_API* BSP_GPI_Init(GPI_Peripheral gpi)
{
    initilized[gpi] = 1;
    GPIO_setAsInputPin(pinMap[gpi].port, pinMap[gpi].pin);
    return &instance;
}

GPI_API* BSP_GPI_GetInstance(GPI_Peripheral gpi)
{
    return  &instance;
} 

static uint8_t Get(GPI_Peripheral const gpi)
{
    return GPIO_getInputPinValue(pinMap[gpi].port, pinMap[gpi].pin);
}