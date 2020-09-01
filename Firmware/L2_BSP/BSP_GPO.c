#include "BSP_GPO.h"

#include <stdint.h>

// HEader file for MSP432 i2c operations. 
#include "gpio.h"
#include "MyDebug.h"


typedef struct 
{
    uint8_t port;
    uint8_t pin;
} GPO_PortPin;




static uint8_t Set(GPO_Peripheral const gpo);
static uint8_t Clear(GPO_Peripheral const gpo);
static uint8_t Toggle(GPO_Peripheral const gpo);


/*
    All GPO use the same API. The user passes an enum that selects which GPO port and pins
    to use. 
*/
static GPO_API instance = {Set , Clear, Toggle}; // ENABLE_FM24CL16B

static uint8_t initilized[NUM_GPO_PERIPHERAL] = {0};

/*
    Declare a pin map for each of the port pin pairs for outputs
*/
static GPO_PortPin const  pinMap[NUM_GPO_PERIPHERAL] =
{
    {GPIO_PORT_P2, GPIO_PIN0}, // GPO_01
    {GPIO_PORT_P2, GPIO_PIN1}, // GPO_02
    {GPIO_PORT_P2, GPIO_PIN3}, // GPO_03
    {GPIO_PORT_P2, GPIO_PIN2}, // GPO_04
    {GPIO_PORT_P2, GPIO_PIN4}, // GPO_05
    {GPIO_PORT_P3, GPIO_PIN7},  // GPO_06
    {GPIO_PORT_P3, GPIO_PIN3}, // GPO_DISPLAY_DC,
    {GPIO_PORT_P3, GPIO_PIN5}, // GPO_DISPLAY_CS,
    {GPIO_PORT_P8, GPIO_PIN2}  // GPO_EINK_RST,
};



GPO_API* BSP_GPO_Init(GPO_Peripheral gpo)
{
    initilized[gpo] = 1;
    GPIO_setAsOutputPin(pinMap[gpo].port, pinMap[gpo].pin);
    return &instance;
}

GPO_API* BSP_GPO_GetInstance(GPO_Peripheral gpo)
{
    return &instance;
}

static uint8_t Set(GPO_Peripheral const gpo)
{
    GPIO_setOutputHighOnPin(pinMap[gpo].port, pinMap[gpo].pin);
    return 0;
}

static uint8_t Clear(GPO_Peripheral const gpo)
{
    GPIO_setOutputLowOnPin(pinMap[gpo].port, pinMap[gpo].pin);
    return 0;
}

static uint8_t Toggle(GPO_Peripheral const gpo)
{
    GPIO_toggleOutputOnPin(pinMap[gpo].port, pinMap[gpo].pin);
    return 0;
}







