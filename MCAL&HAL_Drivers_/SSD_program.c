/*
 * FileName		: SSD_program.c
 * Created		: 9/19/2023 12:46:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"

/**			HAL Includes				**/
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"



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
Std_ReturnType SSD_udtInitialDataPort  
( 
const SSD_t* SSD_pudtstructCfg 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == SSD_pudtstructCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{

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
Std_ReturnType SSD_udtEnable           
( 
const SSD_t* SSD_pudtstructCfg 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == SSD_pudtstructCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{

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
Std_ReturnType SSD_udtDisable          
( 
const SSD_t* SSD_pudtstructCfg 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == SSD_pudtstructCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{

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
Std_ReturnType SSD_udtSendNumber       
( 
const SSD_t* SSD_pudtstructCfg 
uint8 Copy_u8Number 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if(NULL == SSD_pudtstructCfg)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{

	}
	
	return udtReturnValue;	
	
}
