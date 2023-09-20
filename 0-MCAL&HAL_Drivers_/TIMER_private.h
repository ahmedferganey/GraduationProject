/*
 * FileName		: TIMER_private.h
 * Created		: 8/31/2023 1:45:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_


/*-------------------------------- Includes --------------------------------------------------------*/



/*-------------------------------- Macro Declarations ----------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						Timer/Counter0								*/
/*	!COMMENT: TCCR0 – Timer/Counter Control Register"BITS#" */
#define TCCR0_CS00	0		/* Clock Select */
#define TCCR0_CS01	1		/* Clock Select */
#define TCCR0_CS02	2		/* Clock Select */
#define TCCR0_WGM00	6		/* Waveform Generation Mode */
#define TCCR0_WGM01	3		/* Waveform Generation Mode */
#define TCCR0_COM00	4		/* Compare Match Output Mode */
#define TCCR0_COM01	5		/* Compare Match Output Mode */	
#define TCCR0_FOC0	7  		/* Force Output Compare */

//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						Timer/Counter1								*/
/*	!COMMENT: TCCR1A – Timer/Counter1 Control Register A */
#define TCCR1A_WGM10		0	/* Waveform Generation Mode*/
#define TCCR1A_WGM11		1	/* Waveform Generation Mode*/
#define TCCR1A_COM1B0		4	/* Compare Output Mode for Compare unit B*/
#define TCCR1A_COM1B1		5	/* Compare Output Mode for Compare unit B*/
#define TCCR1A_COM1A0		6	/* Compare Output Mode for Compare unit A*/
#define TCCR1A_COM1A1		7	/* Compare Output Mode for Compare unit A*/
#define TCCR1A_FOC1B		2	/* Force Output Compare for Compare unit B*/
#define TCCR1A_FOC1A		3	/* Force Output Compare for Compare unit A*/
/*	!COMMENT: TCCR1B – Timer/Counter1 Control Register B */
#define TCCR1B_CS10			0	
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2
#define TCCR1B_WGM12		3	/* Waveform Generation Mode*/
#define TCCR1B_WGM13		4	/* Waveform Generation Mode*/
#define TCCR1B_COM1A1		5	/*this bit read only bit*/
#define TCCR1B_ICES1		6	/*Input Capture Edge Select*/
#define TCCR1B_ICNC1		7	/*Input Capture Noise Canceler*/
//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						Timer/Counter2								*/
/*	!COMMENT: TCCR2 – Timer/Counter Control Register"BITS#" */
#define TCCR2_CS20	0		/* Clock Select */
#define TCCR2_CS21	1		/* Clock Select */
#define TCCR2_CS22	2		/* Clock Select */
#define TCCR2_WGM20	6		/* Waveform Generation Mode */
#define TCCR2_WGM21	3		/* Waveform Generation Mode */
#define TCCR2_COM20	4		/* Compare Match Output Mode */
#define TCCR2_COM21	5		/* Compare Match Output Mode */	
#define TCCR2_FOC2	7  		/* Force Output Compare */
/*	!COMMENT: Setting Prescaler "TIMER<2>_TCCR2_CS2<0,1,2>" */
#define TIMER2_PRESCALER_MASK			0b11111000 	
#define TIMER2_NO_CLOCK_SOURCE          0
#define TIMER2_NO_PRESCALER_FACTOR      1
#define TIMER2_DIVISION_FACTOR_8        2
#define TIMER2_DIVISION_FACTOR_32       3
#define TIMER2_DIVISION_FACTOR_264      4
#define TIMER2_DIVISION_FACTOR_128      5
#define TIMER2_DIVISION_FACTOR_256      6
#define TIMER2_DIVISION_FACTOR_1024		7
//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:			COMMON													*/
/*	!COMMENT: TIMSK - Timer/Counter Interrupt Mask Register */
#define TIMER0_TIMSK_TOIE0	0	/*TIMER0 Overflow Interrupt Enable*/
#define TIMER0_TIMSK_OCIE0	1	/*TIMER0 Output Compare Match Interrupt Enable*/
#define TIMER1_TIMSK_TOIE1	2	/*TIMER1 Overflow Interrupt Enable*/
#define TIMER1_TIMSK_OCIE1B 3   /*TIMER1 Output Compare B Match Interrupt Enable*/
#define TIMER1_TIMSK_OCIE1A 4   /*TIMER1 Output Compare A Match Interrupt Enable*/
#define TIMER1_TIMSK_TICIE1 5   /*TIMER1 Input Capture Interrupt Enable */
#define TIMER2_TIMSK_TOIE2	6	/*TIMER2 Overflow Interrupt Enable */
#define TIMER2_TIMSK_OCIE2	7	/*TIMER2 Output Compare Match Interrupt Enable */
/*	!COMMENT: Setting Prescaler "TIMER<0,1>_TCCR0_CS0<0,1,2>" */
#define TIMER01_PRESCALER_MASK					          0b11111000 	
#define TIMER01_NO_CLOCK_SOURCE                           0
#define TIMER01_NO_PRESCALER_FACTOR                       1
#define TIMER01_DIVISION_FACTOR_8                         2
#define TIMER01_DIVISION_FACTOR_64                        3
#define TIMER01_DIVISION_FACTOR_256                       4
#define TIMER01_DIVISION_FACTOR_1024                      5
#define TIMER01_T0_EXTERNAL_CLOCK_SOURCE_FALLING          6
#define TIMER01_T0_EXTERNAL_CLOCK_SOURCE_RISING           7
/*	!COMMENT: Timer/Counter0 and Timer/Counter1 Prescalers */
/*	!COMMENT: SFIOR – Special Function IO Register */
#define SFIOR_PSR10		0	/*Prescaler Reset Timer/Counter01*/
#define SFIOR_PSR2		1	/*Prescaler Reset Timer/Counter2*/

//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:			WATCH DOG Timer											*/
/*	!COMMENT: WDTCR Bits */
#define		WDTCR_WDP0 			0
#define		WDTCR_WDP1 			1
#define		WDTCR_WDP2			2
#define		WDTCR_WDE 			3
#define		WDTCR_WDTOE 		4

/*	!COMMENT: WDT Prescaler select  */
#define		WDT_PS_MASKING			0b11111000
#define		WDT_PS_16k				0
#define		WDT_PS_32k      		1
#define		WDT_PS_64k      		2
#define		WDT_PS_128k 			3
#define		WDT_PS_256k 			4
#define		WDT_PS_512k 			5
#define		WDT_PS_1024k			6
#define		WDT_PS_2048k			7

#define 	WDT_DISABLE_MASKING		0b00011000










//////////////////////////////////////////////////////////////////////////////////

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _TIMER_PRIVATE_H_ */