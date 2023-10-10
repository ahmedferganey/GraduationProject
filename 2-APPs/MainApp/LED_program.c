/*
 * FileName		: LED_program.c
 * Created		: 9/19/2023 12:48:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			HAL Includes				**/
#include "LED_interface.h"


/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType LED_udtInit        
( 
const LED_t* LED_pudtCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == LED_pudtCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  LED_pudtCfg->LED_pin.port,
						  LED_pudtCfg->LED_pin.pin,
						  LED_pudtCfg->LED_pin.direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  LED_pudtCfg->LED_pin.port,
						  LED_pudtCfg->LED_pin.pin,
						  LED_pudtCfg->LED_pin.logic						 
						 );	
	}
	
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
Std_ReturnType LED_udtOn          
( 
const LED_t* LED_pudtCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == LED_pudtCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		switch (LED_pudtCfg->LED_connection)
		{
			case LED_ACTIVE_LOW	:   udtReturnValue = DIO_udtSetPinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin,
													 LED_LOGIC_LOW					 
													);
									break;
			
			case LED_ACTIVE_HIGH:   udtReturnValue = DIO_udtSetPinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin,
													 LED_LOGIC_HIGH												 
													);
									break;
			
			default				:   udtReturnValue = E_NOT_OK;
			break;
		}
	}
	
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
Std_ReturnType LED_udtOff         
( 
const LED_t* LED_pudtCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == LED_pudtCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		switch (LED_pudtCfg->LED_connection)
		{
			case LED_ACTIVE_LOW	:   udtReturnValue = DIO_udtSetPinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin,
													 LED_LOGIC_HIGH					 
													);
									break;
			
			case LED_ACTIVE_HIGH:   udtReturnValue = DIO_udtSetPinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin,
													 LED_LOGIC_LOW												 
													);
									break;
			
			default				:   udtReturnValue = E_NOT_OK;
			break;
		}
	}
	
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
Std_ReturnType LED_udtToggle      
( 
const LED_t* LED_pudtCfg
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == LED_pudtCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		switch (LED_pudtCfg->LED_connection)
		{
			case LED_ACTIVE_LOW	:   udtReturnValue = DIO_udtTogglePinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin
													);
									break;
			
			case LED_ACTIVE_HIGH:   udtReturnValue = DIO_udtTogglePinValue
													(
													 LED_pudtCfg->LED_pin.port,
													 LED_pudtCfg->LED_pin.pin
													);
									break;
			
			default				:   udtReturnValue = E_NOT_OK;
			break;
		}
	}
	
	return udtReturnValue;	
	
} 
