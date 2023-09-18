/*
 * FileName		: SWITCH_program.c
 * Created		: 9/19/2023 12:05:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"

/**			HAL Includes				**/
#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"





/* -------------------------------- Global Variables ---------------------------------------*/




/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				        : 											 				*/
/*  @param	 LM35_pudtConfig    : struct has the LM35 Channel, ADC VoltageReference , 		*/
/* 								  ADCResolution						 @ref *LM35_config_t	*/
/*  @param	 LM35_pu8TempValue  : Pointer to TEMP Variable which 							*/
/* 								  will return in it		 			 @ref *uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType SWITCH_udtInitialize
(
const SWITCH_t* SWITCH_pudtBtn
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == SWITCH_pudtBtn)
	{
        udtReturnValue = E_NOT_OK;
    }
    else
	{
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  SWITCH_pudtBtn->button_pin.port,
						  SWITCH_pudtBtn->button_pin.pin,
						  SWITCH_pudtBtn->button_pin.direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SWITCH_pudtBtn->button_pin.port,
						  SWITCH_pudtBtn->button_pin.pin,
						  SWITCH_pudtBtn->button_pin.logic						 
						 );		
    }

	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief				        : 											 				*/
/*  @param	 LM35_pudtConfig    : struct has the LM35 Channel, ADC VoltageReference , 		*/
/* 								  ADCResolution						 @ref *LM35_config_t	*/
/*  @param	 LM35_pu8TempValue  : Pointer to TEMP Variable which 							*/
/* 								  will return in it		 			 @ref *uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType SWITCH_udtReadState
(
const SWITCH_t* SWITCH_pudtBtn,
SWITCH_state_t* SWITCH_state
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	logic_t SWITCH_udtLogic = DIO_LOW;
	
    if((NULL == SWITCH_pudtBtn) || (NULL == SWITCH_state))
	{
        udtReturnValue = E_NOT_OK;
    }
    else
	{
		udtReturnValue = DIO_udtGetPinValue
						 (
						  SWITCH_pudtBtn->button_pin.port,
						  SWITCH_pudtBtn->button_pin.pin,
						  &SWITCH_udtLogic
						 );
		/* BUTTON_ACTIVE_HIGH = 1 */
			/* 1 == 1 */
			/* Active high, when pressed give logic high */
		if (BUTTON_ACTIVE_HIGH == SWITCH_pudtBtn->button_connection)
		{
				/* 1 == ? */
			if (DIO_HIGH == SWITCH_udtLogic)
			{
				*SWITCH_state = BUTTON_PRESSED;
			}
			else
			{
				*SWITCH_state = BUTTON_RELEASED;				
			}
			udtReturnValue = E_OK;
		}
		/* BUTTON_ACTIVE_LOW = 0 */
					/* 0 == 0 */
		else if (BUTTON_ACTIVE_LOW == SWITCH_pudtBtn->button_connection)
		{
			if (DIO_HIGH == SWITCH_udtLogic)
			{
				*SWITCH_state = BUTTON_RELEASED;				
			}
			else
			{
				*SWITCH_state = BUTTON_PRESSED;				
			}
			
			udtReturnValue = E_OK;
		}
		else
		{
			udtReturnValue = E_NOT_OK;
		}
    }
	
	return udtReturnValue;		
}


//////////////////////////////////////////////////////////////////////////////////////////////
