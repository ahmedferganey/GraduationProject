/*
 * FileName		: SERVOMOTOR_private.h
 * Created		: 9/18/2023 3:53:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SERVOMOTOR_PRIVATE_H_
#define _SERVOMOTOR_PRIVATE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
#define  SERVOMOTOR_DIR_PIN_OUT		1

#define  SERVO_MAX				    19999

/*
	Generate PWM using AVR ATmega16
		To control the servo motor in between -90° to +90° rotation. 
		We need to generate a PWM waveform of 50Hz with duty cycle variation 
		from ~0.5ms to ~2.4ms. We can use a fast PWM mode of ATmega16 using Timer1.
		
		Here we are generating PWM on the PD5/OC1A pin of ATmega16.
		We are using the 14th waveform generation mode of Timer1 in ATmega16, 
		where TOP value for timer1 is decided by the ICR1 register i.e. we can load 
		TOP value in the ICR1 register, where timer1 overflow occurs and timer1 
		overflow flag gets set.
		We have used internal 8MHz clock frequency and FOSC/64 clock for 
		timer1 i.e. we set 8MHz/64 = 125KHz clock for timer1.
		
				Now Fast PWM frequency formula is
		
		
						FPWM = FOSC / ( N * ( 1 + TOP ) )
								Where N is pre-scaler divider i.e. 1, 8, 64, 256, or 1024.
		
		Hence to get 50Hz PWM frequency we need to load TOP value as 
		2499 so we get PWM frequency as,
						FPWM = 8000000 / ( 64 * ( 1 + 2499 ) )
		
		
		
		So here we are loading ICR1 = 2499.
		Now just load OCR1A register values to get a compare match at the desired duty cycle.
		As here Timer1 clock is of 125KHz we get a one-timer count of 1/125 kHz = 8 us time 
		period.
		Now suppose we want a PWM duty cycle period of 1ms as shown in the above figure, 
		then we need to load the OCR1A register with 1ms/8us i.e. OCR1A = 125.
		So load OCR1A register as per duty cycle period requirement.

*/



	
	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/

#endif  /* _SERVOMOTOR_PRIVATE_H_ */