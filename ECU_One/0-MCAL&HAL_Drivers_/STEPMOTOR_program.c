/*
 * FileName		: STEPMOTOR_program.c
 * Created		: 9/19/2023 12:42:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes --------------------------------------------------------------*/
/**			LIBRARY Includes			**/
#define F_CPU 8000000UL
#define __DELAY_BACKWARD_COMPATIBLE__			
/* 
	If you use the following define before the #include statement 
   the delay functions can also be called with variables 
   instead of numerical constants												
*/																								
#include "util/delay.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"

/**			HAL Includes				**/
#include "STEPMOTOR_interface.h"
#include "STEPMOTOR_config.h"
#include "STEPMOTOR_private.h"



/* -------------------------------- Global Variables ------------------------------------------------------*/


/* -------------------------------- APIs Implementation ---------------------------------------------------*/
/***********************************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 							   */
/*							to stepper motor as output pins												   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType STEPMOTOR_udtInit
( 
STEPMOTOR_t* udtStepmotorObj 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/* Set 4 PIN DIRECTION, DIR MUST BE OUTPUT = 1 */
	udtReturnValue = DIO_udtSetPinDirection(udtStepmotorObj->udtStepmotorInit[0].port,
											udtStepmotorObj->udtStepmotorInit[0].pin,
											STEPMOTOR_DIRECTION_INIT
											);
											
	udtReturnValue = DIO_udtSetPinDirection(udtStepmotorObj->udtStepmotorInit[1].port,
											udtStepmotorObj->udtStepmotorInit[1].pin,
											STEPMOTOR_DIRECTION_INIT
											);
											
	udtReturnValue = DIO_udtSetPinDirection(udtStepmotorObj->udtStepmotorInit[2].port,
											udtStepmotorObj->udtStepmotorInit[2].pin,
											STEPMOTOR_DIRECTION_INIT
											);
											
	udtReturnValue = DIO_udtSetPinDirection(udtStepmotorObj->udtStepmotorInit[3].port,
											udtStepmotorObj->udtStepmotorInit[3].pin,
											STEPMOTOR_DIRECTION_INIT
											);	



	/* Set 4 PIN logic, at init logic should be low */	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
										udtStepmotorObj->udtStepmotorInit[0].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
										udtStepmotorObj->udtStepmotorInit[1].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
										udtStepmotorObj->udtStepmotorInit[2].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
										udtStepmotorObj->udtStepmotorInit[3].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	
	return udtReturnValue;	
}

/***********************************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t				   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType STEPMOTOR_udtOff 
( 
STEPMOTOR_t* udtStepmotorObj  
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/* Set 4 PIN logic, at off state must be low */	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
										udtStepmotorObj->udtStepmotorInit[0].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
										udtStepmotorObj->udtStepmotorInit[1].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
										udtStepmotorObj->udtStepmotorInit[2].pin,
										STEPMOTOR_LOGIC_INIT
										);	
	udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
										udtStepmotorObj->udtStepmotorInit[3].pin,
										STEPMOTOR_LOGIC_INIT
										);
	return udtReturnValue;	
}

/***********************************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t				   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType STEPMOTOR_udtOn  
( 
STEPMOTOR_t* udtStepmotorObj,   
uint8 Copy_u8Speed, 
uint32 Copy_u32Degree 
)
{
			/* delay will control between the speed of step and the next */
	
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint32 STEPMOTOR_Lu32Iterator = 0;
		
	if (NULL == udtStepmotorObj)
	{
		udtReturnValue = E_NOT_OK;		
	}
	else
	{
		if (STEPPER_FULL_STEP == udtStepmotorObj->udtStepType)
		{
			if (STEPPER_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				for (STEPMOTOR_Lu32Iterator = 0 ; 
					 STEPMOTOR_Lu32Iterator < ((uint32)(((d64)Copy_u32Degree/STEPMOTOR_FULL_STEP_ANGLE)/4)); 
					 STEPMOTOR_Lu32Iterator++)
				{
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
	
	
	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);													
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_HIGH
														);
					_delay_ms( Copy_u8Speed );
														
				}									
													
			}
			else if (STEPPER_ANTI_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				for (STEPMOTOR_Lu32Iterator = 0 ; 
					 STEPMOTOR_Lu32Iterator < ((uint32)(((d64)Copy_u32Degree/STEPMOTOR_FULL_STEP_ANGLE)/4)); 
					 STEPMOTOR_Lu32Iterator++)
				{
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_HIGH
														);
					_delay_ms( Copy_u8Speed );
	
	
	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);													
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
				}									
													
			}
			else
			{
				udtReturnValue = E_NOT_OK;
			}
		}
		else if (STEPPER_HALF_STEP == udtStepmotorObj->udtStepType)
		{
			if (STEPPER_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				for (STEPMOTOR_Lu32Iterator = 0 ; 
					 STEPMOTOR_Lu32Iterator < ((uint32)(((d64)Copy_u32Degree/STEPMOTOR_HALF_STEP_ANGLE)/4)); 
					 STEPMOTOR_Lu32Iterator++)
				{
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
	
	
	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);													
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_HIGH
														);
					_delay_ms( Copy_u8Speed );
														
				}					
			}
			else if (STEPPER_ANTI_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				for (STEPMOTOR_Lu32Iterator = 0 ; 
					 STEPMOTOR_Lu32Iterator < ((uint32)(((d64)Copy_u32Degree/STEPMOTOR_HALF_STEP_ANGLE)/4)); 
					 STEPMOTOR_Lu32Iterator++)
				{
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_HIGH
														);
					_delay_ms( Copy_u8Speed );
	
	
	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);													
					_delay_ms( Copy_u8Speed );
														
		
		
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[0].port,
														udtStepmotorObj->udtStepmotorInit[0].pin,
														STEPMOTOR_LOGIC_HIGH
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[1].port,
														udtStepmotorObj->udtStepmotorInit[1].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[2].port,
														udtStepmotorObj->udtStepmotorInit[2].pin,
														STEPMOTOR_LOGIC_LOW
														);	
					udtReturnValue = DIO_udtSetPinValue(udtStepmotorObj->udtStepmotorInit[3].port,
														udtStepmotorObj->udtStepmotorInit[3].pin,
														STEPMOTOR_LOGIC_LOW
														);
					_delay_ms( Copy_u8Speed );
														
				}				
			}
			else
			{
				udtReturnValue = E_NOT_OK;
			}

		}
		else
		{
			udtReturnValue = E_NOT_OK;
		}
	}
	return udtReturnValue;	
}
