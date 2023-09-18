/*
 * FileName		: BUZZER_program.c
 * Created		: 9/18/2023 8:50:17 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"

/**			HAL Includes				**/
#include "BUZZER_interface.h"
#include "BUZZER_config.h"
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
Std_ReturnType BUZ_udtInit
(
BUZZER_t* BUZZER_pudtBuzzerConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZER_pudtBuzzerConfig == NULL)
	{
		udtReturnValue = E_NOT_OK		
	}
	else
	{
		
		
		
		
	}
	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType BUZ_udtTurnON
(
BUZZER_t* BUZZER_pudtBuzzerConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZER_pudtBuzzerConfig == NULL)
	{
		udtReturnValue = E_NOT_OK		
	}
	else
	{
		
		
		
		
	}
	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType BUZ_udtTurnOFF
(
BUZZER_t* BUZZER_pudtBuzzerConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZER_pudtBuzzerConfig == NULL)
	{
		udtReturnValue = E_NOT_OK		
	}
	else
	{
		
		
		
		
	}
	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType BUZ_udtToggle 
( 
BUZZER_t* BUZZER_pudtBuzzerConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZER_pudtBuzzerConfig == NULL)
	{
		udtReturnValue = E_NOT_OK		
	}
	else
	{
		
		
		
		
	}
	return udtReturnValue;	
}