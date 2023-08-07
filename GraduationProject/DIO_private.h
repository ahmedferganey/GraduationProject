/*
 * FileName		: DIO_private.h
 * Created		: 8/5/2023 9:37:28 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/* Section: Includes */


/* Section: Data Type Declarations */
typedef struct
{
	uint8 PIND;
	uint8 DDRD;
	uint8 PORTD;
	
	uint8 PINC;
	uint8 DDRC;
	uint8 PORTC;
	
	uint8 PINB;
	uint8 DDRB;
	uint8 PORTB;
	
	uint8 PINA;
	uint8 DDRA;
	uint8 PORTA;
	
}DIO_t;

/* Section: Macro Declarations */
#define DIO  ((DIO_t*)0x30)

/* Section: Macro Functions Declarations */


/* Section: Function Declarations */


#endif	/* _DIO_PRIVATE_H_ */