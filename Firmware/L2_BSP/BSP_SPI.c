#include "BSP_SPI.h"

#include <stdint.h>


#include "spi.h"
#include "gpio.h"
#include "MyDebug.h"


static uint8_t BSP_SPI_Read(uint8_t * const buffer, const uint8_t numBytes);
static uint8_t BSP_SPI_Write(uint8_t const * const buffer, const uint8_t numBytes);

static SPI_API instances[NUM_SPI_PERIPHERAL] =
{
    {BSP_SPI_Write, BSP_SPI_Read}
};


static uint8_t initilized[NUM_SPI_PERIPHERAL] = {0};

#if 1
/* SPI Master Configuration Parameter */
static const eUSCI_SPI_MasterConfig spiMasterConfig =
{
        EUSCI_A_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
        3000000,                                   // SMCLK = DCO = 3MHZ
        500000,                                    // SPICLK = 500khz
        EUSCI_A_SPI_MSB_FIRST,                     // MSB First
        EUSCI_A_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT,    // Phase
        EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_LOW, // High polarity
        EUSCI_A_SPI_3PIN                           // 3Wire SPI Mode
};


SPI_API* BSP_SPI_Init(SPI_Peripheral spi)
{
    /* Selecting P1.5 P1.6 and P1.7 in SPI mode */
    GPIO_setAsPeripheralModuleFunctionInputPin(
            GPIO_PORT_P3,
            GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    /* Configuring SPI in 3wire master mode */
    SPI_initMaster(EUSCI_A2_BASE, &spiMasterConfig);

    //UCB0CTLW0 = (UCB0CTLW0 & ~(UCCKPL | UCCKPH)) | (UCCKPH);

    /* Enable SPI module */
    SPI_enableModule(EUSCI_A2_BASE);

    initilized[spi] = 1;

    return &instances[spi];
}

SPI_API* BSP_SPI_GetInstance(SPI_Peripheral spi)
{
    return &instances[spi];
}

static uint8_t BSP_SPI_Write(uint8_t const * const buffer, const uint8_t numBytes)
{
    /* USCI_B0 TX buffer ready? */
    while (!(SPI_getInterruptStatus(EUSCI_A2_BASE, EUSCI_A_SPI_TRANSMIT_INTERRUPT)));





    for(uint8_t i = 0; i < numBytes; i++)
    {
        /* Send the next data packet */
        SPI_transmitData(EUSCI_A2_BASE, buffer[i]);
        uint8_t dummyData = SPI_receiveData(EUSCI_A2_BASE);
    }

    return 0;
}

static uint8_t BSP_SPI_Read(uint8_t * const buffer, const uint8_t numBytes)
{
    /* USCI_B0 TX buffer ready? */
    while (!(SPI_getInterruptStatus(EUSCI_A2_BASE, EUSCI_A_SPI_TRANSMIT_INTERRUPT)));

    for(uint8_t i = 0; i < numBytes; i++)
    {
        /* Send the next data packet */
        SPI_transmitData(EUSCI_A2_BASE, 0x00);
        buffer[i] = SPI_receiveData(EUSCI_A2_BASE);
    }
    
    return 0;
}


#else
/* SPI Master Configuration Parameter */
static const eUSCI_SPI_MasterConfig spiMasterConfig =
{
        EUSCI_B_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
        3000000,                                   // SMCLK = DCO = 3MHZ
        500000,                                    // SPICLK = 500khz
        EUSCI_B_SPI_MSB_FIRST,                     // MSB First
        EUSCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT,    // Phase
        EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_LOW, // High polarity
        EUSCI_B_SPI_3PIN                           // 3Wire SPI Mode
};


SPI_API* BSP_SPI_Init(SPI_Peripheral spi)
{
    // Set the pins that are used for SPI
    /* Selecting P1.5 P1.6 and P1.7 in SPI mode */
    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P1,
        GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7,
        GPIO_PRIMARY_MODULE_FUNCTION
    );
    
    /* Configuring SPI in 3wire master mode */
    if( SPI_initMaster(EUSCI_B0_BASE, &spiMasterConfig) == false)
    {
        while(1)
        {
            // TODO: Error
        }
    }

    /* Enable SPI module */
    SPI_enableModule(EUSCI_B0_BASE);

    initilized[spi] = 1;

    return &instances[spi];
}

static uint8_t BSP_SPI_Write(uint8_t const * const buffer, const uint8_t numBytes)
{
    /* USCI_B0 TX buffer ready? */
    while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));





    for(uint8_t i = 0; i < numBytes; i++)
    {
        /* Send the next data packet */
        SPI_transmitData(EUSCI_B0_BASE, buffer[i]);
        uint8_t dummyData = SPI_receiveData(EUSCI_B0_BASE);
    }

    return 0;
}

static uint8_t BSP_SPI_Read(uint8_t * const buffer, const uint8_t numBytes)
{
    /* USCI_B0 TX buffer ready? */
    while (!(SPI_getInterruptStatus(EUSCI_B0_BASE, EUSCI_B_SPI_TRANSMIT_INTERRUPT)));

    for(uint8_t i = 0; i < numBytes; i++)
    {
        /* Send the next data packet */
        SPI_transmitData(EUSCI_B0_BASE, 0x00);
        buffer[i] = SPI_receiveData(EUSCI_B0_BASE);
    }
    
    return 0;
}
#endif
