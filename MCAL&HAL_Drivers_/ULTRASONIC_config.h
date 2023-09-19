/*
 * FileName		: ULTRASONIC_config.h
 * Created		: 9/19/2023 7:17:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _ULTRASONIC_CONFIG_H_
#define _ULTRASONIC_CONFIG_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
/*
	select:
			if OP PIN in your DIO module have logic 0 or 1, and also IP PIN
			if HIGH in your DIO module have logic 0 or 1, and also LOW
			
*/
#define 	DIO_OUTPUT			1
#define 	DIO_INPUT			0
	
#define 	DIO_LOW				0
#define 	DIO_HIGH			1

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/

#endif  /* _ULTRASONIC_CONFIG_H_ */