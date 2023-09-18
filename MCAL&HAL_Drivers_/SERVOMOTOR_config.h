/*
 * FileName		: SERVOMOTOR_config.h
 * Created		: 9/18/2023 3:51:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SERVOMOTOR_CONFIG_H_
#define _SERVOMOTOR_CONFIG_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
/* 
	for ATMEGA32A there 2 options OC1A  OR	OC1B for Timer1 where as it is the only 
		one has ICU.
	these pins will generate PWM Signal.
	
		SERVOMOTOR_PORT = 3		 ATMEGA32A_PIN4_PORTD = 4		 //OC1B
		SERVOMOTOR_PORT = 3		 ATMEGA32A_PIN5_PORTD = 5		 //OC1A
*/
#define  SERVOMOTOR_PORT			3
#define  SERVOMOTOR_PIN				5


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/

#endif  /* _SERVOMOTOR_CONFIG_H_ */