/*
 * FileName		: DCMOTOR_interface.h
 * Created		: 9/17/2023 7:17:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _DCMOTOR_INTERFACE_H_
#define _DCMOTOR_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
/*			DC MOTOR State			*/
typedef enum 
{
	DCMOTOR_CW =0,
	DCMOTOR_CCW,
	DCMOTOR_STOP
}DCMOTOR_State_t;

/*			DC MOTOR Config			*/
typedef struct 
{
	uint8 Copy_u8DcMotorPort ;
	uint8 Copy_u8DcMotorPinA ;
	uint8 Copy_u8DcMotorPinB ;
}DCMOTOR_Config_t;



/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType DCMotor_Controller_Init
(
void
);


Std_ReturnType DCMOTOR_udtControl 
(
DCMOTOR_Config_t* DcMotor_t, 
DCMOTOR_State_t Copy_udtState
);


#endif  /* _DCMOTOR_INTERFACE_H_ */