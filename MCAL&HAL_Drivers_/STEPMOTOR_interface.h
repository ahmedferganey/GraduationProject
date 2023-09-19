/*
 * FileName		: STEPMOTOR_interface.h
 * Created		: 9/19/2023 12:45:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _STEPMOTOR_INTERFACE_H_
#define _STEPMOTOR_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/

	
	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/

typedef enum 
{
	STEPMOTOR_HALF_STEP=0,
	STEPMOTOR_FULL_STEP	
}STEPMOTOR_steptype_t;

typedef enum 
{
	STEPMOTOR_ANTI_CLOCK_WISE=0,
	STEPMOTOR_CLOCK_WISE	
}STEPMOTOR_direction_t;

/*
	this struct has some rules:
								index 0,1 for the same coil
								index 2,3 for the other coil
*/
typedef struct
{
	pin_config_t udtStepmotorInit[4];
	STEPMOTOR_steptype_t udtStepType;
	STEPMOTOR_direction_t udtDirection;
}STEPMOTOR_t;

/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType STEPMOTOR_udtInit
( 
STEPMOTOR_t* udtStepmotorObj 
);



Std_ReturnType STEPMOTOR_udtOff 
( 
STEPMOTOR_t* udtStepmotorObj  
);



Std_ReturnType STEPMOTOR_udtOn  
( 
u8 Copy_u8StepType, 
u8 Copy_u8Direction, 
u8 Copy_u8Speed, 
u16 Copy_u16Degree 
);



/*
	///////////////////////////////////////////////////////////////////////////////////////////

	https://www.electronicwings.com/avr-atmega/stepper-motor-interfacing-with-atmega32
	https://www.st.com/resource/en/datasheet/uln2001.pdf
	https://www.circuitspecialists.com/blogs/news/how-to-wire-a-stepper-motor#:~:text=Mo
		st%20commonly%20stepper%20motors%20come,meter%20to%20identify%20the%20wires.
		
	///////////////////////////////////////////////////////////////////////////////////////////
	
	A stepper motor can come with assortment of wire configurations. The type of motor 
	you've selected will determine the wire setup. Most commonly stepper motors come with 
	four, five, six, or eight wires.
	To begin, if your stepper motor only has four wires, this means it can only be used
	with a bipolar driver. You will notice each of the two phase windings has a pair of 
	wires, use your meter to identify the wires.
		orange + blue 
		red + yellow
	The Stepper controller has 4 wires out, 2 to each phase of the stepper motor 
	
	///////////////////////////////////////////////////////////////////////////////////////////
	
	Stepper motor is a brushless DC motor that divides the full rotation angle of 360° 
	into a number of equal steps.

		The motor is rotated by applying a certain sequence of control signals. The speed of
		rotation can be changed by changing the rate at which the control signals are applied.
		Various stepper motors with different step angles and torque ratings are available in 
		the market.
		A microcontroller can be used to apply different control signals to the motor to make 
		it rotate according to the need of the application.


	Here we are going to interface 6 wires Unipolar Stepper Motor with ATmega32 controller.
	Only four wires are required to control the stepper motor. 
	Two common wires of stepper motor connected to 5V supply.
	ULN2003 driver is used to the driving stepper motor.
	Note that to know winding coil and their center tap leads measure resistance 
	in between leads. From center leads, we will get half the resistance value of that winding.

	Steeper motor can be 4 wires, 6 wires, 8 wires.
	
	///////////////////////////////////////////////////////////////////////////////////////////
	
	The ULN2003A is an integrated circuit produced by Texas Instruments. It consists of 
	an array of seven NPN Darlington transistors capable of 500 mA, 50 V output. It features 
	common-cathode flyback diodes for switching inductive loads. It can come in PDIP, 
	SOIC, SOP or TSSOP packaging.

	///////////////////////////////////////////////////////////////////////////////////////////

*/



#endif  /* _STEPMOTOR_INTERFACE_H_ */