/*
 * FileName		: HC05_program.c
 * Created		: 9/18/2023 1:47:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "USART_Interface.h"

/**			HAL Includes				**/
#include "HC05_interface.h"
#include "HC05_config.h"
#include "HC05_private.h"


/*
			Important Notes :
								You must initilize USART module firstly
*/

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
Std_ReturnType HC05_udtTx_Char
(
uint8 HC05_TXData
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	udtReturnValue = USART_udtSendData(HC05_TXData);
	
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
Std_ReturnType HC05_udtRx_Char
(
uint8* HC05_pu8RXChar
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	udtReturnValue = USART_udtRecevieData(HC05_pu8RXChar);
	
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
Std_ReturnType HC05_udtTx_String
(
uint8* HC05_pu8TXString
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = USART_udtSendStringSynch(HC05_pu8TXString);

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
Std_ReturnType HC05_pu8Rx_String
(
uint8* HC05_pu8RXString, 
uint32  HC05_u32BufferSize
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/* note HC05_u32BufferSize will determine number of indexes for 
			array which recieve data in APP Layer where recieveing 
			data will continue until receieve all indexes 
	*/
	udtReturnValue = USART_udtReceiveBufferSynch(HC05_pu8RXString, 
												 HC05_u32BufferSize);

	return udtReturnValue;		
}




