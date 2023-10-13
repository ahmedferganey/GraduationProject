/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @file startup_stm32f10x.c
 * @create date 2023-10-13 09:54:45
 * @modify date 2023-10-13 09:54:45
 * @desc [this is startup code for STM32f10x]
 */


typedef unsigned long uint32_t;


extern void main(void);


uint32_t* Vector_Table[] __attribute__ ((section (".isr_vector"))) = {


};
