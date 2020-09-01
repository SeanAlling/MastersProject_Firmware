#include "Experiments.h"

#include "BSP_Timer.h"

 


// Derive a 500ms timer period
#if defined(EXP_DCO_1500000)
    #define TIMER_PERIOD    (1500000/2)
#elif defined(EXP_DCO_3000000)
    #define TIMER_PERIOD    (3000000/2)
#elif defined(EXP_DCO_6000000)
    #define TIMER_PERIOD    (6000000/2)
#elif defined(EXP_DCO_12000000)
    #define TIMER_PERIOD    (12000000/2)
#elif defined(EXP_DCO_24000000)
    #define TIMER_PERIOD    (24000000/2)
#elif defined(EXP_DCO_48000000)
    #define TIMER_PERIOD    (48000000/2) 
#else
    #error ERROR: UNSUPPORTED FREQUENCY DEFINED
#endif
 
// Setup systick timer with a rate of 1ms.
#if defined(EXP_DCO_1500000)
     #define SYSTICK_INIT_VALUE (1500000)
#elif defined(EXP_DCO_3000000)
    #define SYSTICK_INIT_VALUE (3000000)
#elif defined(EXP_DCO_6000000)
     #define SYSTICK_INIT_VALUE (6000000)
#elif defined(EXP_DCO_12000000)
     #define SYSTICK_INIT_VALUE (12000000)
#elif defined(EXP_DCO_24000000)
     #define SYSTICK_INIT_VALUE (24000000)
#elif defined(EXP_DCO_48000000)
     #define SYSTICK_INIT_VALUE (48000000)
#else
    #error ERROR: UNSUPPORTED FREQUENCY DEFINED
#endif 

#define EXP_UART_BAUD_115200

// Setup systick timer with a rate of 1ms.
#if defined(EXP_DCO_1500000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
    #if defined(EXP_UART_BAUD_115200)
        const eUSCI_UART_Config uartConfig =
        {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                13,                                      // BRDIV = 78
                0,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION  // Oversampling
        };
    #else // Baud rate 9600
        const eUSCI_UART_Config uartConfig =
        {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                9,                                      // BRDIV = 78
                12,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
    #endif
#elif defined(EXP_DCO_3000000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
    #if defined(EXP_UART_BAUD_115200)
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            26,                                      // BRDIV = 78
            0,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
     #else // Baud rate 9600
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            19,                                      // BRDIV = 78
            8,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION  // Oversampling
        };
    #endif
#elif defined(EXP_DCO_6000000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
    #if defined(EXP_UART_BAUD_115200)
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            3,                                      // BRDIV = 78
            4,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
    #else // Baud rate 9600
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            39,                                      // BRDIV = 78
            1,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
    #endif
#elif defined(EXP_DCO_12000000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
        #if defined(EXP_UART_BAUD_115200)
            const eUSCI_UART_Config uartConfig =
            {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                6,                                      // BRDIV = 78
                8,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
            };
        #else // Baud rate 9600
            const eUSCI_UART_Config uartConfig =
            {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                78,                                      // BRDIV = 78
                2,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
            };
        #endif
#elif defined(EXP_DCO_24000000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
        #if defined(EXP_UART_BAUD_115200)
            const eUSCI_UART_Config uartConfig =
            {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                13,                                      // BRDIV = 78
                0,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
            };
        #else // Baud rate 9600
            const eUSCI_UART_Config uartConfig =
            {
                EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
                156,                                      // BRDIV = 78
                4,                                       // UCxBRF = 2
                0,                                       // UCxBRS = 0
                EUSCI_A_UART_NO_PARITY,                  // No Parity
                EUSCI_A_UART_LSB_FIRST,                  // LSB First
                EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
                EUSCI_A_UART_MODE,                       // UART mode
                EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
            };
        #endif
#elif defined(EXP_DCO_48000000)
    /* UART Configuration Parameter. These are the configuration parameters to
     * make the eUSCI A UART module to operate with a 9600 baud rate. These
     * values were calculated using the online calculator that TI provides
     * at:
     *http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
     *
     * Following is set up for an SMCLK of 12MHz
     */
    #if defined(EXP_UART_BAUD_115200)
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            26,                                      // BRDIV = 78
            1,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
    #else // Baud rate 9600
        const eUSCI_UART_Config uartConfig =
        {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
            312,                                      // BRDIV = 78
            8,                                       // UCxBRF = 2
            0,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
    #endif
#else
    #error ERROR: UNSUPPORTED FREQUENCY DEFINED
#endif 








uint32_t Get_TIMER_PERIOD(void)
{
    return TIMER_PERIOD;
}

uint32_t Get_SYSTICK_INIT_VALUE(void)
{
    return SYSTICK_INIT_VALUE;
}




void MyDelay( const uint32_t delay_ms)
{
    uint32_t currentTime_ms = GetSysTickTimerValue()+delay_ms;
    while( (currentTime_ms) >= GetSysTickTimerValue());
}

void Experiment_SetupSystemClock(void)
{

    #if defined(EXP_DCO_1500000)
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_1_5);
    #elif defined(EXP_DCO_3000000)
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_3);
    #elif defined(EXP_DCO_6000000)
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_6);
    #elif defined(EXP_DCO_12000000)
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);
    #elif defined(EXP_DCO_24000000)
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
    #elif defined(EXP_DCO_48000000)
        // The following is needed to get the system to run at 48MHz.
        MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
        // Two wait states needed in order since the max clock speed is lower than 
        // the maximum system clock speed.
        MAP_FlashCtl_setWaitState(FLASH_BANK0, 2);
        MAP_FlashCtl_setWaitState(FLASH_BANK1, 2);
        CS_startHFXT(false);
        CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
    #else
        #error ERROR: UNSUPPORTED FREQUENCY DEFINED
    #endif

    Timer_SysTickInit(3000000);
}

/* Perform any additional setup for this experiment */
void Experiment_Setup( void )
{
    #if   defined(USER_EXPERIMENT_00)
        Experiment00_Setup();
    #elif defined(USER_EXPERIMENT_01)
        Experiment01_Setup();
    #elif defined(USER_EXPERIMENT_02)
        Experiment02_Setup();
    #elif defined(USER_EXPERIMENT_03)
        Experiment03_Setup();
    #elif defined(USER_EXPERIMENT_04)
        Experiment04_Setup();
    #elif defined(USER_EXPERIMENT_05)
        Experiment05_Setup();
    #elif defined(USER_EXPERIMENT_06)
        Experiment06_Setup();
    #elif defined(USER_EXPERIMENT_07)
        Experiment07_Setup();
    #elif defined(USER_EXPERIMENT_08)
        Experiment08_Setup();
    #elif defined(USER_EXPERIMENT_09)
        Experiment09_Setup();
    #elif defined(USER_EXPERIMENT_10)
        Experiment10_Setup();
    #elif defined(USER_EXPERIMENT_11)
        Experiment11_Setup();
    #elif defined(USER_EXPERIMENT_12)
        Experiment12_Setup();
    #elif defined(USER_EXPERIMENT_13)
        Experiment13_Setup();
    #elif defined(USER_EXPERIMENT_14)
        Experiment14_Setup();
    #elif defined(USER_EXPERIMENT_15)
        Experiment15_Setup();
    #elif defined(USER_EXPERIMENT_16A)
        Experiment16A_Setup();
    #elif defined(USER_EXPERIMENT_16B)
        Experiment16B_Setup();
    #elif defined(USER_EXPERIMENT_17)
        Experiment17_Setup();
    #elif defined(USER_EXPERIMENT_18)
        Experiment18_Setup();
    #elif defined(USER_EXPERIMENT_19)
        Experiment19_Setup();
    #elif defined(USER_EXPERIMENT_20)
        Experiment20_Setup();
    #elif defined(USER_EXPERIMENT_21)
        Experiment21_Setup();
    #elif defined(USER_EXPERIMENT_22)
        Experiment22_Setup();
    #elif defined(USER_EXPERIMENT_23)
        Experiment23_Setup();
    #elif defined(USER_EXPERIMENT_24)
        Experiment24_Setup();
    #elif defined(USER_EXPERIMENT_25)
        Experiment25_Setup();
    #elif defined(USER_EXPERIMENT_26)
        Experiment26_Setup();
    #elif defined(USER_EXPERIMENT_27)
        Experiment27_Setup();
    #elif defined(USER_EXPERIMENT_28)
        Experiment28_Setup();
    #elif defined(USER_EXPERIMENT_29)
        Experiment29_Setup();
    #elif defined(USER_EXPERIMENT_30A)
        Experiment30A_Setup();
    #elif defined(USER_EXPERIMENT_30B)
        Experiment30B_Setup();
    #elif defined(USER_EXPERIMENT_31)
        Experiment31_Setup();
    #elif defined(USER_EXPERIMENT_32)
        Experiment32_Setup();
    #elif defined(USER_EXPERIMENT_33)
        Experiment33_Setup();
    #elif defined(USER_EXPERIMENT_34)
        Experiment34_Setup();
    #elif defined(USER_EXPERIMENT_35)
        Experiment35_Setup();
    #elif defined(USER_EXPERIMENT_36)
        Experiment36_Setup();
    #elif defined(USER_EXPERIMENT_37)
        Experiment37_Setup();
    #elif defined(USER_EXPERIMENT_38)
        Experiment38_Setup();
    #elif defined(USER_EXPERIMENT_39)
        Experiment39_Setup();
    #elif defined(USER_EXPERIMENT_40)
        Experiment40_Setup();
    #elif defined(USER_EXPERIMENT_41)
        Experiment41_Setup();
    #elif defined(USER_EXPERIMENT_42)
        Experiment42_Setup();
    #elif defined(USER_EXPERIMENT_43)
        Experiment43_Setup();
    #elif defined(USER_EXPERIMENT_44)
        Experiment44_Setup();
    #elif defined(USER_EXPERIMENT_45)
        Experiment45_Setup();
    #elif defined(USER_EXPERIMENT_46)
        Experiment46_Setup();
    #elif defined(USER_EXPERIMENT_47)
        Experiment47_Setup();
    #elif defined(USER_EXPERIMENT_48)
        Experiment48_Setup();
    #elif defined(USER_EXPERIMENT_49)
        Experiment49_Setup();
    #elif defined(USER_EXPERIMENT_50)
        Experiment50_Setup();
    #elif defined(USER_EXPERIMENT_51)
        Experiment51_Setup();
    #elif defined(USER_EXPERIMENT_52)
        Experiment52_Setup();
    #elif defined(USER_EXPERIMENT_53)
        Experiment53_Setup();
    #elif defined(USER_EXPERIMENT_54)
        Experiment54_Setup();
    #elif defined(USER_EXPERIMENT_55)
        Experiment55_Setup();
    #elif defined(USER_EXPERIMENT_56)
        Experiment56_Setup();
    #elif defined(USER_EXPERIMENT_57)
        Experiment57_Setup();
    #elif defined(USER_EXPERIMENT_58)
        Experiment58_Setup();
    #elif defined(USER_EXPERIMENT_59)
        Experiment59_Setup();
    #elif defined(USER_EXPERIMENT_60)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_61)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_62)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_63)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_64)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_65)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_66)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_67)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_68)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_69)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_70)
        Experiment70_Setup();
    #elif defined(USER_EXPERIMENT_71)
        Experiment71_Setup();
    #elif defined(USER_EXPERIMENT_72)
        Experiment72_Setup();
    #elif defined(USER_EXPERIMENT_73)
        Experiment73_Setup();
    #elif defined(USER_EXPERIMENT_74)
        Experiment74_Setup();
    #elif defined(USER_EXPERIMENT_75)
        Experiment75_Setup();
    #elif defined(USER_EXPERIMENT_76)
        Experiment76_Setup();
    #elif defined(USER_EXPERIMENT_77)
        Experiment77_Setup();
    #elif defined(USER_EXPERIMENT_78)
        Experiment78_Setup();
    #elif defined(USER_EXPERIMENT_79)
        Experiment79_Setup();
    #elif defined(USER_EXPERIMENT_81)
        Experiment81_Setup();
    #elif defined(USER_EXPERIMENT_82)
        Experiment82_Setup();
    #else
        #error UNDEFINED EXPERIMENT
    #endif
}

/* Run the experiment */
void Experiment_Run( void )
{
    #if   defined(USER_EXPERIMENT_00)
        Experiment00_Run();
    #elif defined(USER_EXPERIMENT_01)
        Experiment01_Run();
    #elif defined(USER_EXPERIMENT_02)
        Experiment02_Run();
    #elif defined(USER_EXPERIMENT_03)
        Experiment03_Run();
    #elif defined(USER_EXPERIMENT_04)
        Experiment04_Run();
    #elif defined(USER_EXPERIMENT_05)
        Experiment05_Run();
    #elif defined(USER_EXPERIMENT_06)
        Experiment06_Run();
    #elif defined(USER_EXPERIMENT_07)
        Experiment07_Run();
    #elif defined(USER_EXPERIMENT_08)
        Experiment08_Run();
    #elif defined(USER_EXPERIMENT_09)
        Experiment09_Run();
    #elif defined(USER_EXPERIMENT_10)
        Experiment10_Run();
    #elif defined(USER_EXPERIMENT_11)
        Experiment11_Run();
    #elif defined(USER_EXPERIMENT_12)
        Experiment12_Run();
    #elif defined(USER_EXPERIMENT_13)
        Experiment13_Run();
    #elif defined(USER_EXPERIMENT_14)
        Experiment14_Run();
    #elif defined(USER_EXPERIMENT_15)
        Experiment15_Run();
    #elif defined(USER_EXPERIMENT_16A)
        Experiment16A_Run(); 
    #elif defined(USER_EXPERIMENT_16B)
        Experiment16B_Run();
    #elif defined(USER_EXPERIMENT_17)
        Experiment17_Run();
    #elif defined(USER_EXPERIMENT_18)
        Experiment18_Run();
    #elif defined(USER_EXPERIMENT_19)
        Experiment19_Run();
    #elif defined(USER_EXPERIMENT_20)
        Experiment20_Run();
    #elif defined(USER_EXPERIMENT_21)
        Experiment21_Run();
    #elif defined(USER_EXPERIMENT_22)
        Experiment22_Run();
    #elif defined(USER_EXPERIMENT_23)
        Experiment23_Run();
    #elif defined(USER_EXPERIMENT_24)
        Experiment24_Run();
    #elif defined(USER_EXPERIMENT_25)
        Experiment25_Run();
    #elif defined(USER_EXPERIMENT_26)
        Experiment26_Run();
    #elif defined(USER_EXPERIMENT_27)
        Experiment27_Run();
    #elif defined(USER_EXPERIMENT_28)
        Experiment28_Run();
    #elif defined(USER_EXPERIMENT_29)
        Experiment29_Run();
    #elif defined(USER_EXPERIMENT_30A)
        Experiment30A_Run();
    #elif defined(USER_EXPERIMENT_30B)
        Experiment30B_Run();
    #elif defined(USER_EXPERIMENT_31)
        Experiment31_Run();
    #elif defined(USER_EXPERIMENT_32)
        Experiment32_Run();
    #elif defined(USER_EXPERIMENT_33)
        Experiment33_Run();
    #elif defined(USER_EXPERIMENT_34)
        Experiment34_Run();
    #elif defined(USER_EXPERIMENT_35)
        Experiment35_Run();
    #elif defined(USER_EXPERIMENT_36)
        Experiment36_Run();
    #elif defined(USER_EXPERIMENT_37)
        Experiment37_Run();
    #elif defined(USER_EXPERIMENT_38)
        Experiment38_Run();
    #elif defined(USER_EXPERIMENT_39)
        Experiment39_Run();
    #elif defined(USER_EXPERIMENT_40)
        Experiment40_Run();
    #elif defined(USER_EXPERIMENT_41)
        Experiment41_Run();
    #elif defined(USER_EXPERIMENT_42)
        Experiment42_Run();
    #elif defined(USER_EXPERIMENT_43)
        Experiment43_Run();
    #elif defined(USER_EXPERIMENT_44)
        Experiment44_Run();
    #elif defined(USER_EXPERIMENT_45)
        Experiment45_Run();
    #elif defined(USER_EXPERIMENT_46)
        Experiment46_Run();
    #elif defined(USER_EXPERIMENT_47)
        Experiment47_Run();
    #elif defined(USER_EXPERIMENT_48)
        Experiment48_Run();
    #elif defined(USER_EXPERIMENT_49)
        Experiment49_Run();
    #elif defined(USER_EXPERIMENT_50)
        Experiment50_Run();
    #elif defined(USER_EXPERIMENT_51)
        Experiment51_Run();
    #elif defined(USER_EXPERIMENT_52)
        Experiment52_Run();
    #elif defined(USER_EXPERIMENT_53)
        Experiment53_Run();
    #elif defined(USER_EXPERIMENT_54)
        Experiment54_Run();
    #elif defined(USER_EXPERIMENT_55)
        Experiment55_Run();
    #elif defined(USER_EXPERIMENT_56)
        Experiment56_Run();
    #elif defined(USER_EXPERIMENT_57)
        Experiment57_Run();
    #elif defined(USER_EXPERIMENT_58)
        Experiment58_Run();
    #elif defined(USER_EXPERIMENT_59)
        Experiment59_Run();
    #elif defined(USER_EXPERIMENT_60)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_61)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_62)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_63)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_64)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_65)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_66)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_67)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_68)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_69)
        #error UNDEFINED EXPERIMENT
    #elif defined(USER_EXPERIMENT_70)
        Experiment70_Run();
    #elif defined(USER_EXPERIMENT_71)
        Experiment71_Run();
    #elif defined(USER_EXPERIMENT_72)
        Experiment72_Run();
    #elif defined(USER_EXPERIMENT_73)
        Experiment73_Run();
    #elif defined(USER_EXPERIMENT_74)
        Experiment74_Run();
    #elif defined(USER_EXPERIMENT_75)
        Experiment75_Run();
    #elif defined(USER_EXPERIMENT_76)
        Experiment76_Run();
    #elif defined(USER_EXPERIMENT_77)
        Experiment77_Run();
    #elif defined(USER_EXPERIMENT_78)
        Experiment78_Run();
    #elif defined(USER_EXPERIMENT_79)
        Experiment79_Run();
    #elif defined(USER_EXPERIMENT_81)
        Experiment81_Run();
    #elif defined(USER_EXPERIMENT_82)
        Experiment82_Run();
    #else
        #error UNDEFINED EXPERIMENT
    #endif
}