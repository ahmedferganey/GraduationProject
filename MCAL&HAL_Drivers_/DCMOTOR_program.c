/*
 * FileName		: DCMOTOR_program.c
 * Created		: 9/17/2023 7:16:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"

/**			HAL Includes				**/
#include "DCMOTOR_interface.h"
#include "DCMOTOR_private.h"




/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType DCMOTOR_udtControl 
(
DCMOTOR_Config_t* DcMotor_t, 
DCMOTOR_State_t Copy_udtState
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	switch(Copy_udtState)
	{
		case DCMOTOR_CW   :
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinA,
													DC_MOTOR_LOW);
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinB,
													DC_MOTOR_HIGH);				
								 break;            
		case DCMOTOR_CCW  :	
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinA,
													DC_MOTOR_HIGH);
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinB,
													DC_MOTOR_LOW);					
								 break;             
		case DCMOTOR_STOP :
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinA,
													DC_MOTOR_LOW);
				udtReturnValue = DIO_udtSetPinValue(DcMotor_t->Copy_u8DcMotorPort, 
													DcMotor_t->Copy_u8DcMotorPinB,
													DC_MOTOR_LOW);				
								 break;            
		default : udtReturnValue = E_NOT_OK;
				  break;
		
	}
	
	return udtReturnValue;	
}
