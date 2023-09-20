/*
 * FileName		: TIMER_register.h
 * Created		: 8/31/2023 1:47:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_

/* !Comment:	we will seperate our work to 5 categories
 *				///////////////////////////////////////////////////////////////
 *				8-bit Timer/Counter0 
 *						TCCR0
 *						TCNT0
 *						OCR0
 *				///////////////////////////////////////////////////////////////
 *				16-bit Timer/Counter1
 *						TCCR1A
 *						TCCR1B
 *						TCNT1H and TCNT1L
 *						OCR1AH and OCR1AL
 *						OCR1BH and OCR1BL
 *						ICR1H  and ICR1L
 *				////////////////////////////////////////////////////////////////
 *				8-bit Timer/Counter2 with PWM and Asynchronous Operation
 *						TCCR2
 *						TCNT2  
 *						OCR2
 *						ASSR
 *				///////////////////////////////////////////////////////////////
 *				Common REG Timer/Counter0 and Timer/Counter1 and Timer/Counter2 
 *						SFIOR
 *						TIMSK
 *						TIFR
 *				///////////////////////////////////////////////////////////////
 *				WDT TIMER 
 *						WDTCR
 */
/*-------------------------------- Includes --------------------------------------------------------*/
#include "STD_TYPES.h"



/*-------------------------------- Macro Declarations ----------------------------------------------*/
/* !Comment: ACCESSING TIMER0 */
#define TCNT0		*((volatile uint8*)0X52)
#define TCCR0		*((volatile uint8*)0X53)
#define OCR0		*((volatile uint8*)0X5C)
///////////////////////////////////////////////////////////////
/* !Comment: this pointer is point to TIMER1_t with address 0x46 end at 0x4F*/
#define TIMER1  	((TIMER1_t*)0x46)

#define ICR1		*((volatile uint16*)0X46)		 /* uint16 for HIGH & LOW */
#define OCR1B		*((volatile uint16*)0X48)		 /* uint16 for HIGH & LOW */
#define OCR1A		*((volatile uint16*)0X4A)		 /* uint16 for HIGH & LOW */
#define TCNT1		*((volatile uint16*)0X4C)   	 /* uint16 for HIGH & LOW */
///////////////////////////////////////////////////////////////
/* !Comment: this pointer is point to TIMER2_t with address 0x42 end at 0x45*/
#define TIMER2  	((TIMER2_t*)0x42)
///////////////////////////////////////////////////////////////
/* !Comment: Common REG Timer/Counter0 and Timer/Counter1 and Timer/Counter2 */
#define SFIOR		*((volatile uint8*)0X50)
#define TIFR		*((volatile uint8*)0X58)
#define TIMSK		*((volatile uint8*)0X59)
///////////////////////////////////////////////////////////////
/* !Comment: ACCESSING Watchdog Timer Control Register */
#define WDTCR       *((volatile uint8*)0x41)
///////////////////////////////////////////////////////////////
/* !Comment: ACCESSING SREG – AVR Status Register "Bit 7 – I: Global Interrupt Enable"*/
#define SREG        *((volatile uint8 *)0x5F)

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/
/* !Comment: TIMER1 REgisters	*/
typedef struct
{
	uint8 ICR1L;
	uint8 ICR1H;
	uint8 OCR1BL;	
	uint8 OCR1BH;
	uint8 OCR1AL;
	uint8 OCR1AH;
	uint8 TCNT1L;
	uint8 TCNT1H;
	uint8 TCCR1B;
	uint8 TCCR1A;	
}TIMER1_t;

/* !Comment: TIMER2 REgisters	*/
typedef struct
{
	uint8 ASSR;
	uint8 OCR2;
	uint8 TCNT2;	
	uint8 TCCR2;	
}TIMER2_t;

/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _TIMER_REGISTER_H_ */