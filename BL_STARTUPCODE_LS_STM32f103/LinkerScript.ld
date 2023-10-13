/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-13 10:07:14
 * @modify date 2023-10-13 10:07:14
 * @desc [ Linker-Script File for stm32f103c8t6 Device from STM32F10xxx devices ]
 */




_Min_Heap_Size = 0x100;              /* Required Amount of Heap */
_Min_Stack_Size = 0x400;             /* Required Amount of Stack */

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* End of "RAM" Ram type memory */

/***************** Memory Definition *******************/
MEMORY
{
    RAM(xrw)  : ORIGIN = 0x20000000,    LENGTH = 20K
    FLASH(rx) : ORIGIN = 0x08000000,    LENGTH = 64K
}


/***************** Sections Definition *****************/
SECTIONS
{
	/* Starting of Flash Sections with IVT */
	.isr_vector :
	{
		. = ALIGN (4);          /* cause size of the address is 4 byte */
		*(.isr_vector)
		. = ALIGN (4);
	} >FLASH

		/* .text section, The program code and other data into "FLASH" Rom type memory */
    .text :
    {
		. = ALIGN (4); 
        *(.text)
        *(.text*)               /*any file .textxxxxxx*/
		. = ALIGN (4);  
        _etext = .;        /* Define a global symbols at end of code */                
    } > FLASH

		/* .rodata section, Constant data into "FLASH" Rom type memory */
    .rodata :
    {
		. = ALIGN (4); 
        *(.rodata)
        *(.rodata*)                     
		. = ALIGN (4);  
    } >FLASH

    /* Used by the startup to initialize data, this is start of .data or end of rodata */
    _sidata = LOADADDR(.data);

		/* .data section, Initialized data sections into "RAM" Ram type memory */
    .data :
    {
		. = ALIGN (4); 
        _sdata = .;        /* Create a global symbol at data start */        
        *(.data)
        *(.data*)                        
		. = ALIGN (4); 
        _edata = .;        /* Define a global symbol at data end */         
    } > RAM AT > FLASH

		/* .bss section, Uninitialized data section into "RAM" Ram type memory */
    .bss :
    {
		. = ALIGN (4); 
        _sbss = .;         /* Define a global symbol at bss start */        
        *(.bss)
        *(.bss*)                      
		. = ALIGN (4);  
        _ebss = .;         /* Define a global symbol at bss end */        
    } >RAM

        /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
    ._user_heap_stack :
    {
      . = ALIGN(8);
      . = . + _Min_Heap_Size;
      . = . + _Min_Stack_Size;
      . = ALIGN(8);
    } >RAM
}
