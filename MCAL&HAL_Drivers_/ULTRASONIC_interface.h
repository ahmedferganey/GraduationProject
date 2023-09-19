/*
 * FileName		: ULTRASONIC_interface.h
 * Created		: 9/19/2023 7:18:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _ULTRASONIC_INTERFACE_H_
#define _ULTRASONIC_INTERFACE_H_

/*
	https://www.electronicwings.com/sensors-modules/ultrasonic-module-hc-sr04
	https://maxbotix.com/blogs/blog/how-ultrasonic-sensors-work#:~:text=An%20ultrasonic%20sensor%20is%20an,information%20about%20an%20object's%20proximity.
	https://www.electronicwings.com/avr-atmega/ultrasonic-module-hc-sr04-interfacing-with-atmega1632
*/


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
#define SOUND_SPEED_CM_SECOND       34000


	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef struct{
    pin_config_t udtTriggerPin;
    pin_config_t udtEchoPin; 
}ULTRASONIC_obj_t;



/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType Ultrasonic_udtInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig
);


Std_ReturnType Ultrasonic_udtCalculateDistance
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig, 
uint16* ULTRASONIC_pu8Distance
);


/*
	Measure Distance and Print on LCD16x2 using Ultrasonic Sensor and Atmega16 Microcontroller
	
	Let’s design an application in which we will find the distance to an object by interfacing 
	ultrasonic module HC-SR04 with AVR ATmega16 and display the distance on 16x2 LCD.
	
	Steps of Programming
	
	1- ATmega16 microcontroller needs to transmit at least 10 us trigger pulse to the HC-SR04 
	Trig Pin.
	
	2- After getting a trigger pulse, HC-SR04 automatically sends eight 40 kHz sound waves 
	and the microcontroller waits for rising edge output at the Echo pin.
	
	3- When the rising edge capture occurs at the Echo pin which is connected to an input of 
	ATmega16, start Timer of ATmega16 and again wait for a falling edge on the Echo pin.
	
	As soon as the falling edge is captured at the Echo pin, the microcontroller reads the 
	count of the Timer. This time count is used to calculate the distance to an object.
	Here we are using the input capture mode of ATmega16 on PD6(ICP1) pin as shown in 
	the above interfacing diagram.
	
	Calculation (distance in cm) (H1)
	
	Sound velocity =   343.00 m/s = 34300 cm/s
	
	
	
	The distance of Object (in cm) = \mathbf{\frac{Sound Velocity * TIMER}{2}}             
	
												= \mathbf{\frac{34300 * TIMER}{2}}
	
												= \textbf{17150 * TIMER} 
	
	Now, here we have selected an internal 8 MHz oscillator frequency for ATmega16, 
	with No-presale for timer frequency. Then time to execute 1 instruction is 0.125 us.
	
	So, the timer gets incremented after 0.125 us time elapse.
	
					= 17150 x (TIMER value) x 0.125 x 10^-6 cm
	
					= 0.125 x (TIMER value)/58.30 cm
	
					= (TIMER value) / 466.47 cm

*/

#endif  /* _ULTRASONIC_INTERFACE_H_ */