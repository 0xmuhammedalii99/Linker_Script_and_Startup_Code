/*
**************************************************************************************************
**
** @file            : STM32F401xCTx_LinkerScript.ld
**
** @auther          : Muhammed Ali Ibrahim Ahmed
**
** @linkedIn        : https://www.linkedin.com/in/muhammedalii9/
**
** @breif           : Linker Script File for STM43F401xC Microcontroller From STM32F4 Series  
**                              256KBytes Flash 
**                              64KBytes SRAM
**
** @Target          :  STM32F4 Microcontrollers
**
**************************************************************************************************
*/

/* Entry Point */
ENTRY(Reset_Handler)

/* Highest Address of the Stack */
_estack = ORIGIN(RAM) + LENGTH(RAM);


_Min_Heap_Size = 0x200;         /* required amount of heap */
_Min_Stack_Size = 0x400;        /* required amount of stack */


/* Memory Definition */
MEMORY 
{
    FLASH   (rx)        : ORIGIN =  0x08000000,     LENGTH  =   256K
    RAM    (wrx)        : ORIGIN =  0x20000000,     LENGTH  =   64K         
}
/*
**          FLASH Sections Definitions 
*/
SECTIONS 
{
/*
**                          isr_vector Section Definition
**
**  KEEP (Keyword): Used in the linker script to instruct the linker to retain a specific section 
**                  even if it appears to be unused or unreferenced by the code.
**                  This is important for sections like the interrupt vector table
**                  because the microcontroller hardware accesses this
**                  table directly during interrupt handling. 
**
** @breif           :   contains the interrupt vector table, 
**                      which is a table of function pointers 
**                      pointing to the interrupt service routines (ISRs)
**                      for various interrupt sources.

** @location        :   FLASH
*/
    .isr_vector :
    {
        . = ALIGN(4);             /* Align by 4 Bytes */
        KEEP(*(.isr_vector))
        . = ALIGN(4);              /* Align by 4 Bytes */
    }>FLASH

/*
**                          .text Section Definition 
**
** @breif           :    Contain compiled code ( Assembly Instructions ) are stored 
**
** @location        :   FLASH
*/
    .text :
    {
        . = ALIGN(4);               /* Align by 4 Bytes */
        _stext = .;                   /* Symbol to Store start .text address */
        *(.text)                    /* Add .text Files*/
        *(.text*)                   /* Add All .text Files*/
        . = ALIGN(4);               /* Align by 4 Bytes */
        _etext = .;                   /* Symbol to Store end .text address */
    }>FLASH

/*
**                          .rodata Section Definition 
**
** @breif           :   " read-only data " is a section in the memory of a program where
**                      read-only data is stored
**
** @location        :   FLASH
*/
    .rodata :
    {
        . = ALIGN(4);               /* Align by 4 Bytes */
        _srodata = .;                 /* Symbol to Store start .rodata address */
        *(.rodata)                  /* Add .rodata Files*/
        *(.rodata*)                 /* Add All .rodata Files*/
        . = ALIGN(4);               /* Align by 4 Bytes */
        _erodata = .;                 /* Symbol to Store end .rodata address */
    }>FLASH

/*
**                          .data Section Definition 
**
** @breif           :   Contains initialized global and static variables in a program
**
** @explain         :   We Store all Initialized Global and Static Variable in Flash Memory
**                      So if the power is Off or Reset, he keeps a copy of them on Flash and 
**                      load variables to RAM again
**
** @location        :   Flash : ' Sotre it at Running time in ' : RAM
*/

    /* 
     ** Used by the Start up Code to initialize data section
     ** LOADADDR : To Store the Load Memory Address of .data in _sidata
     */
    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);               /* Align by 4 Bytes */
        _sdata = .;                   /* Symbol to Store start .data address */
        *(.data)                    /* Add .data Files*/
        *(.data*)                   /* Add All .data Files*/
        . = ALIGN(4);               /* Align by 4 Bytes */
        _edata = .;                   /* Symbol to Store end .data address */
    } >RAM AT>FLASH

/*
**                          .bss Section Definition 
**
** @breif           :   contains uninitialized or zero-initialized global and static variables
**                      in a program
**
** @location        :   RAM
*/

    .bss :
    {
        . = ALIGN(4);           /* Align by 4 Bytes */
        _sbss = .;                /* Symbol to Store start .bss address */
        *(.bss)                 /* Add .bss Files*/
        *(.bss*)                /* Add All .bss Files*/
        . = ALIGN(4);           /* Align by 4 Bytes */
        _ebss = .;                /* Symbol to Store end .bss address */
    }
}