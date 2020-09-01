#include "Experiments.h"
#include<stdio.h> 




/* Timer32 ISR */
static void T32_INT1_Int(void)
{
    Timer32_clearInterruptFlag(TIMER32_BASE);
    //GPIO_toggleOutputOnPin(GPIO_PORT_P6, GPIO_PIN4);
    Timer32_setCount(TIMER32_BASE,Get_TIMER_PERIOD());
    Timer32_enableInterrupt(TIMER32_BASE);
    Timer32_startTimer(TIMER32_BASE, true);
}


void Experiment37_Setup(void)
{
    /* Configuring Timer32 to 128000 (1s) of MCLK in periodic mode */
    Timer32_initModule(TIMER32_BASE, TIMER32_PRESCALER_1, TIMER32_32BIT,TIMER32_PERIODIC_MODE);


    Timer32_setCount(TIMER32_BASE,Get_TIMER_PERIOD());

    Timer32_registerInterrupt(TIMER32_COMBINED_INTERRUPT,T32_INT1_Int);
    Timer32_enableInterrupt(TIMER32_BASE);
    Timer32_startTimer(TIMER32_BASE, true); 
    /* Enabling interrupts and starting the timer */
    /* Enabling MASTER interrupts */
    MAP_Interrupt_enableMaster(); 

    /*
        Default P6.2 to low. This tells the test bench that the test has not run or is incomplete.
    */
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN2);


}


typedef enum 
{
    READ_LIGHT,
    READ_TEMP,
    TRANSMIT_XBEE,
    NUM_FSM_SYSTEM_STATES

}FSM_Sysem;

void Experiment37_Run(void)
{

    FSM_Sysem fsmState = READ_LIGHT;
    uint16_t data[2];
    uint8_t data2[6] = {0,0,0,0,0,0};
    uint32_t dataPtr = 0;
     uint8_t seconds = 0;
    uint8_t minutes = 0;
    uint8_t hours   = 0;

    char buffer[50];
    while(1)
    {
        switch(fsmState)
        {
            case READ_LIGHT:
                // Enable the memory
                STLQ015MXXX_Enable(&lightEnable);
                // Give the memory 25 ms to start up
                // Minimum time as specified in the datasheet.
                MyDelay(25);
                // Read the data from the light sensor
                // Data will be stored in data after function returns.. 
                OPT3001_ReadResult(&data[0]);
                // Turn off light sensor and turn on memory. 
                STLQ015MXXX_Disable(&lightEnable);
                STLQ015MXXX_Enable(&framEnable);
                // Small delay to make sure that FRAM is ready to go.
                MyDelay(10);
                // Store result in FRAM. Place at location dstaPtr points to. 
                // After each write increment the data pointer. Not ding so there is the 
                // chance that a future write will not write to FRAM. 
                FM24CL16B_WriteByte((uint8_t)((data[0]>>0) & 0xFF), dataPtr++);
                FM24CL16B_WriteByte((uint8_t)((data[0]>>8) & 0xFF), dataPtr++);
                // Once data is written turn off FRAM.
                STLQ015MXXX_Disable(&framEnable);
                fsmState = READ_TEMP;
                break;
            case READ_TEMP: 
                // Enable the memory
                STLQ015MXXX_Enable(&temperatureEnable);
                // Give the memory 25 ms to start up
                // Minimum time as specified in the datasheet.
                MyDelay(25);
                // Read the data from the temp followed by humidity
                // Data will be stored in data after function returns.. 
                //HDC1080_ReadTemperature(&data[0]);
                //HDC1080_ReadHumidity(&data[1]);
                
    
                PCF8523_GetSeconds( &seconds);
                PCF8523_GetMinutes( &minutes);
                PCF8523_GetHours( &hours);


                // Turn off light  on memory. 
                STLQ015MXXX_Disable(&temperatureEnable);
                STLQ015MXXX_Enable(&framEnable);
                // Small delay to make sure that FRAM is ready to go.
                MyDelay(10);
                // Store result in FRAM. Place at location dstaPtr points to. 
                // After each write increment the data pointer. Not ding so there is the 
                // chance that a future write will not write to FRAM. 
                FM24CL16B_WriteByte((uint8_t)((data[0]>>0) & 0xFF), dataPtr++);
                FM24CL16B_WriteByte((uint8_t)((data[0]>>8) & 0xFF), dataPtr++);
                FM24CL16B_WriteByte((uint8_t)((data[1]>>0) & 0xFF), dataPtr++);
                FM24CL16B_WriteByte((uint8_t)((data[1]>>8) & 0xFF), dataPtr++);
                // Once data is written turn off FRAM.
                STLQ015MXXX_Disable(&framEnable);
                fsmState = TRANSMIT_XBEE;
                break;
            case TRANSMIT_XBEE:
                // Enable the memory & XBee
                STLQ015MXXX_Enable(&xbeeEnable);
                STLQ015MXXX_Enable(&framEnable);
                // Give the memory and xbee 10 ms to start up
                MyDelay(10);
                

                FM24CL16B_ReadByte(0,&data2[0]);
                FM24CL16B_ReadByte(1,&data2[1]);
                FM24CL16B_ReadByte(2,&data2[2]);
                FM24CL16B_ReadByte(3,&data2[3]);
                FM24CL16B_ReadByte(4,&data2[4]);
                FM24CL16B_ReadByte(5,&data2[5]);
                sprintf(buffer, "0x%02X%02X,0x%02X%02X,0x%02X%02X\n",
                    data2[0], data2[1],
                    data2[2], data2[3],
                    seconds, minutes
                );
                XBee_Write(buffer,28);
                MyDelay(500);
                // Enable the memory & XBee
                STLQ015MXXX_Disable(&xbeeEnable);
                STLQ015MXXX_Disable(&framEnable);
                // Reset the dataPtr to 0. 
                dataPtr = 0;
                fsmState = READ_LIGHT;
                break;
        }
        MyDelay(500);
        //PCM_setPowerState(PCM_LPM0_LF_VCORE0);
    }
}