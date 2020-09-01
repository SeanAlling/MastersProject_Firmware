#include "BSP_I2C.h"

#include <stdint.h>

// HEader file for MSP432 i2c operations. 
#include "i2c.h"
#include "gpio.h"
#include "MyDebug.h"


static uint8_t BSP_I2C_Read0(uint8_t const address, uint8_t reg, uint8_t * const buffer, const uint8_t numBytes);
static uint8_t BSP_I2C_Write0(uint8_t const address, uint8_t reg, uint8_t const * const buffer, const uint8_t numBytes);

static I2C_API instances[NUM_I2C_PERIPHERAL] =
{
    {BSP_I2C_Write0, BSP_I2C_Read0}
};


static uint8_t initilized[NUM_I2C_PERIPHERAL] = {0};


/* I2C Master Configuration Parameter */
const eUSCI_I2C_MasterConfig i2cConfig =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,                                // SMCLK = 3MHz
        EUSCI_B_I2C_SET_DATA_RATE_400KBPS,      // Desired I2C Clock of 400khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
};

I2C_API* BSP_I2C_Init(I2C_Peripheral i2c)
{
    /* Select Port 1 for I2C - Set Pin 6, 7 to input Primary Module Function,
     *   (UCB0SIMO/UCB0SDA, UCB0SOMI/UCB0SCL).
     */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN6 + GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Initializing I2C Master to SMCLK at 400kbs with no autostop */
    I2C_initMaster(EUSCI_B0_BASE, &i2cConfig);


    /* Set Master in transmit mode */
    I2C_setMode(EUSCI_B0_BASE, EUSCI_B_I2C_TRANSMIT_MODE);

    /* Enable I2C Module to start operations */
    I2C_enableModule(EUSCI_B0_BASE);

    initilized[i2c] = 1;

    return &instances[i2c];
}

I2C_API* BSP_I2C_GetInstance(I2C_Peripheral i2c)
{
    return &instances[i2c];
}

static uint8_t BSP_I2C_Write0(uint8_t const address, uint8_t reg, uint8_t const * const buffer, const uint8_t numBytes)
{

    if(!initilized[I2C0])
    {
        ERROR("ERROR: I2C EUSCI B0 not initialized\n");
        return 1;
    }
    while( I2C_masterIsStopSent(EUSCI_B0_BASE) != EUSCI_B_I2C_STOP_SEND_COMPLETE );

    /* Specify slave address */
    I2C_setSlaveAddress(EUSCI_B0_BASE, address);

    // Send the first byte in the buffer. 
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE, reg);

    for(uint8_t i = 0; i < numBytes; i++)
    {
        I2C_masterSendMultiByteNext(EUSCI_B0_BASE,buffer[i]);
    }
    I2C_masterSendMultiByteStop(EUSCI_B0_BASE);
    while( I2C_masterIsStopSent(EUSCI_B0_BASE) != EUSCI_B_I2C_STOP_SEND_COMPLETE );
    return 0;
}


/*
    Note this function uses repeated starts. The Master will first write the slave address followed by 
    the register of the slave hat should be read, which is then followed by reads. 

    NOTE: the following is based off of code found at 
    https://e2e.ti.com/support/microcontrollers/msp430/f/166/t/696111

    When ding a sinle byte read IT IS VERY IMPORTANT TO SEND THE STOP AS THE READ START. The following 
    comes from the technical manual for the MSP432. 

    When transmitting a single byte of data, the UCTXSTP bit must be set while the byte is being 
    transmitted or any time after transmission begins, without writing new data into UCBxTXBUF. 
    Otherwise, only the address is transmitted. When the data is transferred from the buffer 
    to the shift register, UCTXIFG0 is set, indicating data transmission has begun, and the UCTXSTP 
    bit may be set. When UCASTPx = 10 is set, the byte counter is used for STOP generation and the 
    user does not need to set the UCTXSTP. This is recommended when transmitting only one byte.

    The most important is that first sentence. If its not  obeyed then I2C will not work correctly. 
*/
static uint8_t BSP_I2C_Read0(uint8_t const address, uint8_t reg, uint8_t * const buffer, const uint8_t numBytes)
{
    if(!initilized[I2C0])
    {
        ERROR("ERROR: I2C EUSCI B0 not initialized\n");
        return 1;
    }
    /* Specify slave address */
    I2C_setSlaveAddress(EUSCI_B0_BASE, address);

    while( I2C_masterIsStopSent(EUSCI_B0_BASE) );


    // Writes the slave address and the register that the user is requesting access to. 
    I2C_masterSendMultiByteStart(EUSCI_B0_BASE,reg);
    /* Wait until the last byte has been output to shift register */
    while(!(I2C_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_I2C_TRANSMIT_INTERRUPT0)))

    // Send the restart condition, read bytes, send the stop condition right away
    EUSCI_B0->CTLW0 &= ~(EUSCI_B_CTLW0_TR);
    EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_TXSTT;


    while(I2C_masterIsStartSent(EUSCI_B0_BASE));

    for(uint8_t i = 0; i < numBytes; i++)
    {
        if(i == numBytes - 1)
        {
            EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_TXSTP; // Send stop
        }
        //while(!(I2C_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_I2C_RECEIVE_INTERRUPT0)));
        // I2C_masterReceiveSingle is a polling based function.
        buffer[i] = I2C_masterReceiveSingle(EUSCI_B0_BASE);
    }
    

    return 0;
}