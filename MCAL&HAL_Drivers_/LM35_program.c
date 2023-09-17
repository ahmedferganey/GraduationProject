/*
 * FileName		: LM35_program.c
 * Created		: 9/17/2023 11:16:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "ADC_interface.h"

/**			HAL Includes				**/
#include "LM35_interface.h"
#include "LM35_config.h"
#include "LM35_private.h"





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
/*********************		 getter API		 *********************/
Std_ReturnType LM35_udtGetTemp 
(
LM35_config_t* LM35_pudtConfig, 
uint8* LM35_pu8TempValue
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint16 Local_u16ADCResult;


	if (((LM35_pudtConfig == NULL) || (pu8TempValue == NULL)))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		
	/* ADC Digital Reading  */
	udtReturnValue = ADC_udtGetResultSync(LM35_pudtConfig->Copy_u8LM35Channel, &Local_u16ADCResult);
		
	/* Check for ADC Resolution  */


		
		
	/* Get value, Convert ( mv --> Temp ) */
	*LM35_pu8TempValue = ;
		
	}
	
	return udtReturnValue;	
}