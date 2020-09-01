                Linker Bug
--------------------------------------------------
There is a bug in the linker where if a large block 
of memory is being used in SRAM, the linker will 
overlap data. What happens is that the large block 
of SRAM will also contain local variables. 

This can be seen when the bss section is initialized. 
during initialization the local loop variable will be 
rewritten as 0, restating the process. 

To avoid this error, the large block of SRAM should 
be defined in the linker script. This avoids the issue 
outlined here. 



Hardware V3 Pin Connection
--------------------------------------------------
Power Control
    Power pins are active high. Pull low in order to disable the pins. 

    P2.0    ->  OPT3001
    P2.1    ->  HDC1080
    P2.2    ->  FPGA
    P2.3    ->  XBEE
    P2.4    ->  Display
    P3.7    ->  Memory (FRAM & FLASH)



Serial Communication
    P1.7    -> I2C SCL
    P1.6    -> I2C_SDA

    I2C
        This device is special in how its address must be used. Bits 7-4 are set to 0b1010. Bits 3-1 are the page select. 

UART 
    P1.3 UART TX
    P1.2 UART RX


XBEE 
    CH -> C
    ID -> 3332
    DH -> 0
    DL -> 0
    MY -> 0