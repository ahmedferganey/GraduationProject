/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-13 10:07:14
 * @modify date 2023-10-13 10:07:14
 * @desc [Linker-Script File for stm32f103c8t6 Device from STM32F10xxx devices ]
 */


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
		. = ALIGN (4);          //cause size of the address is 4 byte
		*(.isr_vector)
		. = ALIGN (4);
	}>FLASH

    .text :
    {
		. = ALIGN (4); 


		. = ALIGN (4);          
    }

    .rodata :
    {
		. = ALIGN (4); 
        
                 
		. = ALIGN (4);  
    }

    .data :
    {
		. = ALIGN (4); 
        
                 
		. = ALIGN (4);  
    }

    .bss :
    {
		. = ALIGN (4); 
        
                 
		. = ALIGN (4);  
    }


}