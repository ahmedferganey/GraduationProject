/*
 * FileName		: STEPMOTOR_program.c
 * Created		: 9/19/2023 12:42:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"

/**			HAL Includes				**/
#include "STEPMOTOR_interface.h"
#include "STEPMOTOR_config.h"
#include "STEPMOTOR_private.h"



/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 				*/
/*							to stepper motor as output pins									*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
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

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
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

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType STEPMOTOR_udtOn  
( 
STEPMOTOR_t* udtStepmotorObj   
uint8 Copy_u8Speed, 
uint16 Copy_u16Degree 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
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
				
			}
			else if (STEPPER_ANTI_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				
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
				
			}
			else if (STEPPER_ANTI_CLOCK_WISE == udtStepmotorObj->udtDirection)
			{
				
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
