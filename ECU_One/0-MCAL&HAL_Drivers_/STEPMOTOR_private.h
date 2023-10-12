/*
 * FileName		: STEPMOTOR_private.h
 * Created		: 9/19/2023 12:44:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _STEPMOTOR_PRIVATE_H_
#define _STEPMOTOR_PRIVATE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
#define 	STEPMOTOR_DIRECTION_INIT		1		// for DIO_DIRECTION_OUTPUT
#define 	STEPMOTOR_LOGIC_INIT			0		// for DIO_LOW
#define 	STEPMOTOR_LOGIC_HIGH			0		// for DIO_HIGH
#define 	STEPMOTOR_LOGIC_LOW				0		// for DIO_LOW

#define 	STEPPER_FULL_STEP    			1
#define 	STEPPER_HALF_STEP    			0
	
#define 	STEPPER_CLOCK_WISE       		1
#define 	STEPPER_ANTI_CLOCK_WISE  		0

#define 	STEPMOTOR_FULL_STEP_ANGLE		1.8
#define 	STEPMOTOR_HALF_STEP_ANGLE		0.9

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/

#endif  /* _STEPMOTOR_PRIVATE_H_ */