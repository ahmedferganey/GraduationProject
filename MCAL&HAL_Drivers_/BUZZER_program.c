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
#include "BUZZER_private.h"




/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  :  This Function initialize the pin which 						*/
/*							 connected to BUZ as output pin.			 					*/
/*  @param	 udtPortIndex : to determine the required port				 					*/
/*  @param	 u8Direction  : to Set the required Direction				 					*/
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
		udtReturnValue = E_NOT_OK;		
	}
	else
	{
		udtReturnValue = DIO_udtSetPinDirection
						(
						 BUZZER_pudtBuzzerConfig->pin_config_t.port,
						 BUZZER_pudtBuzzerConfig->pin_config_t.pin,
						 BUZZER_pudtBuzzerConfig->pin_config_t.direction
						);
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
BUZZER_t* BUZZ_pudtBuzzCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZ_pudtBuzzCfg == NULL)
	{
		udtReturnValue = E_NOT_OK;		
	}
	else
	{
		switch (BUZZ_pudtBuzzCfg->BUZZER_State_t)
		{
			case ACTIVE_LOW : udtReturnValue = DIO_udtSetPinValue
											   (
											    BUZZ_pudtBuzzCfg->pin_config_t.port,
											    BUZZ_pudtBuzzCfg->pin_config_t.pin,
											    BUZZ_pudtBuzzCfg->BUZZER_State_t.ACTIVE_LOW											   
											   );
							  break;
			
			case ACTIVE_HIGH: udtReturnValue = DIO_udtSetPinValue
											   (
											    BUZZ_pudtBuzzCfg->pin_config_t.port,
											    BUZZ_pudtBuzzCfg->pin_config_t.pin,
											    BUZZ_pudtBuzzCfg->BUZZER_State_t.ACTIVE_HIGH										   
											   );
							  break;
				
			default			: udtReturnValue = E_NOT_OK;	
							  break;			
		}		
		
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
BUZZER_t* BUZZ_pudtBuzzCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (BUZZ_pudtBuzzCfg == NULL)
	{
		udtReturnValue = E_NOT_OK;		
	}
	else
	{
		switch (BUZZ_pudtBuzzCfg->BUZZER_State_t)
		{
			case ACTIVE_LOW : udtReturnValue = DIO_udtSetPinValue
											   (
											    BUZZ_pudtBuzzCfg->pin_config_t.port,
											    BUZZ_pudtBuzzCfg->pin_config_t.pin,
											    BUZZ_pudtBuzzCfg->BUZZER_State_t.ACTIVE_HIGH											   
											   );
							  break;
			
			case ACTIVE_HIGH: udtReturnValue = DIO_udtSetPinValue
											   (
											    BUZZ_pudtBuzzCfg->pin_config_t.port,
											    BUZZ_pudtBuzzCfg->pin_config_t.pin,
											    BUZZ_pudtBuzzCfg->BUZZER_State_t.ACTIVE_LOW										   
											   );
							  break;
				
			default			: udtReturnValue = E_NOT_OK;	
							  break;			
		}		
		
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
		udtReturnValue = E_NOT_OK;		
	}
	else
	{

		udtReturnValue = DIO_udtTogglePinValue
						 (
						  BUZZ_pudtBuzzCfg->pin_config_t.port,
						  BUZZ_pudtBuzzCfg->pin_config_t.pin,
						 );		
	}
	return udtReturnValue;	
}
//////////////////////////////////////////////////////////////////////////////////////////////