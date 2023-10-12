/*
 * FileName		: SERVOMOTOR_interface.h
 * Created		: 9/18/2023 3:52:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SERVOMOTOR_INTERFACE_H_
#define _SERVOMOTOR_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/
#include "SERVOMOTOR_config.h"

/* -------------------------------- Macro Declarations ------------------------------------------*/
#define  REQUIRED_PORT					SERVOMOTOR_PORT
#define  REQUIRED_PIN					SERVOMOTOR_PIN

#define ATMEGA32A_PIN4_PORTD_OCR1A							5
#define ATMEGA32A_PIN4_PORTD_OCR1B							4

/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef enum
{
	RequiredPwmPin = REQUIRED_PIN,
}SERVOMOTOR_t;

/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType ServoMotor_udtInit
(
void
);

void ServoMotor_vdRotate
(
uint8 SERVOMOTOR_u8Angle,
SERVOMOTOR_t SERVOMOTOR_udtTarget
);







/*
	https://www.electronicwings.com/avr-atmega/servo-motor-interfacing-with-atmega16
	https://www.electronicwings.com/sensors-modules/servo-motor
	
	////////////////////////////////////////////////////////////////////////////////
	
	- The rotation angle of the servo motor is controlled by applying a PWM signal to it.
	
	////////////////////////////////////////////////////////////////////////////////

	- By varying the width of the PWM signal, we can change the rotation angle and 
	  direction of the motor.
	  
	////////////////////////////////////////////////////////////////////////////////
	  
	- SG90 servo motor practical duty cycle time for -90° to +90 rotation.
		At ~0.52ms duty cycle we get shaft position at -90° of its rotation.
		At ~1.4ms duty cycle we get shaft position at 0° (neutral) of its rotation.		
		At ~2.4ms duty cycle we get shaft position at +90° of its rotation.
		
	////////////////////////////////////////////////////////////////////////////////

*/



#endif  /* _SERVOMOTOR_INTERFACE_H_ */