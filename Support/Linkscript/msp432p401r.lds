/******************************************************************************
*
* Copyright (C) 2012 - 2017 Texas Instruments Incorporated - http://www.ti.com/
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
*  Redistributions of source code must retain the above copyright
*  notice, this list of conditions and the following disclaimer.
*
*  Redistributions in binary form must reproduce the above copyright
*  notice, this list of conditions and the following disclaimer in the
*  documentation and/or other materials provided with the
*  distribution.
*
*  Neither the name of Texas Instruments Incorporated nor the names of
*  its contributors may be used to endorse or promote products derived
*  from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* GCC linker script for Texas Instruments MSP432P401R
*
* File creation date: 08/03/17
*
******************************************************************************/


MEMORY
{
    MAIN_FLASH (RX) : ORIGIN = 0x00000000, LENGTH = 0x00040000
    INFO_FLASH (RX) : ORIGIN = 0x00200000, LENGTH = 0x00004000

    /* 
        SRAM region is aliased into the code region. This makes it efficient to execute from SRAM. 
        See User MAnual page 90-92

        Creating separate regions is SRAM to avoid the linker issues with double allocating SRAm 
        regions.

        Total Size = 64kB SRAM
            4k SystemView buffer
            2k RTT buffer
            58kB for system

        Must change start address of both SRAM regions SRAM and its aliased location for 
        proper operation.
    
        A resource for implementing the sizes of ranges is explained in the following 
        stack overflow question. See answer 2 for including this in the build system.
        https://stackoverflow.com/questions/47074801/gnu-linker-script-stm32f4xx-global-variables
    */
    
    /*
        SystemView has an 8 byte downbuffer tahtw ill be placed in the same region. Total size is 
        of this region is then 4K + 8
    */
    SRAM_SYSVIEW_DATA (RW): ORIGIN = 0x20000000               , LENGTH = 4K + 8
    SRAM_RTT_DATA     (RW): ORIGIN = 0x20000000 + 4K + 8      , LENGTH = 2K
    SRAM_TASK_STACKS  (RW): ORIGIN = 0x20000000 + 4K + 8 + 2K , LENGTH = 10K
    SRAM_DATA        (RW) : ORIGIN = 0x20000000 + 4K + 8 + 2K + 10K , LENGTH = 64K - 4K - 8 - 2K - 10K
    SRAM_CODE        (RWX): ORIGIN = 0x01000000 + 4K + 8 + 2K + 10K , LENGTH = 64K - 4K - 8 - 2K - 10K
}

REGION_ALIAS("REGION_TEXT", MAIN_FLASH);
REGION_ALIAS("REGION_INFO", INFO_FLASH);
REGION_ALIAS("REGION_BSS", SRAM_DATA);
REGION_ALIAS("REGION_DATA", SRAM_DATA);
REGION_ALIAS("REGION_STACK", SRAM_DATA);
REGION_ALIAS("REGION_HEAP", SRAM_DATA);
REGION_ALIAS("REGION_ARM_EXIDX", MAIN_FLASH);
REGION_ALIAS("REGION_ARM_EXTAB", MAIN_FLASH);

REGION_ALIAS("REGION_RTT_BUFFER"     , SRAM_RTT_DATA);
REGION_ALIAS("REGION_SYSVIEW_BUFFER" , SRAM_SYSVIEW_DATA);
REGION_ALIAS("REGION_TASK_STACKS"    , SRAM_TASK_STACKS);

SECTIONS {

    /* section for the interrupt vector area                                 */
    PROVIDE (_intvecs_base_address =
        DEFINED(_intvecs_base_address) ? _intvecs_base_address : 0x0);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        KEEP (*(.intvecs))
    } > REGION_TEXT

    /* The following three sections show the usage of the INFO flash memory  */
    /* INFO flash memory is intended to be used for the following            */
    /* device specific purposes:                                             */
    /* Flash mailbox for device security operations                          */
    PROVIDE (_mailbox_base_address = 0x200000);

    .flashMailbox (_mailbox_base_address) : AT (_mailbox_base_address) {
        KEEP (*(.flashMailbox))
    } > REGION_INFO

    /* TLV table for device identification and characterization              */
    PROVIDE (_tlv_base_address = 0x00201000);

    .tlvTable (_tlv_base_address) (NOLOAD) : AT (_tlv_base_address) {
        KEEP (*(.tlvTable))
    } > REGION_INFO

    /* BSL area for device bootstrap loader                                  */
    PROVIDE (_bsl_base_address = 0x00202000);

    .bslArea (_bsl_base_address) : AT (_bsl_base_address) {
        KEEP (*(.bslArea))
    } > REGION_INFO

    PROVIDE (_vtable_base_address =
        DEFINED(_vtable_base_address) ? _vtable_base_address : 0x20000000);

    .vtable (_vtable_base_address) : AT (_vtable_base_address) {
        KEEP (*(.vtable))
    } > REGION_DATA

    .text : {
        CREATE_OBJECT_SYMBOLS
        KEEP (*(.text))
        *(.text.*)
        . = ALIGN(0x4);
        KEEP (*(.ctors))
        . = ALIGN(0x4);
        KEEP (*(.dtors))
        . = ALIGN(0x4);
        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;
        KEEP (*(.init))
        KEEP (*(.fini*))
    } > REGION_TEXT AT> REGION_TEXT

    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } > REGION_TEXT AT> REGION_TEXT

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > REGION_ARM_EXIDX AT> REGION_ARM_EXIDX

    .ARM.extab : {
        KEEP (*(.ARM.extab* .gnu.linkonce.armextab.*))
    } > REGION_ARM_EXTAB AT> REGION_ARM_EXTAB

    __etext = .;

    .data : {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        KEEP (*(.data))
        KEEP (*(.data*))
        . = ALIGN (4);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_TEXT

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        KEEP (*(.bss))
        *(.bss.*)
        *(COMMON)
        . = ALIGN (4);
        __bss_end__ = .;
    } > REGION_BSS AT> REGION_BSS

    .heap : {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        KEEP (*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > REGION_HEAP AT> REGION_HEAP

    .sysviewBuffer : ALIGN(0x8) {
        KEEP(*(.sysviewBuffer))
    } > REGION_SYSVIEW_BUFFER AT> REGION_SYSVIEW_BUFFER

    .rttBuffer : ALIGN(0x8) {
        KEEP(*(.rttBuffer))
    } > REGION_RTT_BUFFER AT> REGION_RTT_BUFFER

    .taskStacks  : ALIGN(0x8) {
        KEEP(*(.taskStacks))
    } > REGION_TASK_STACKS AT> REGION_TASK_STACKS

    .stack (NOLOAD) : ALIGN(0x8) {
        _stack = .;
        KEEP(*(.stack))
    } > REGION_STACK AT> REGION_STACK

	__StackTop = ORIGIN(REGION_STACK) + LENGTH(REGION_STACK);
    PROVIDE(__stack = __StackTop);
}

