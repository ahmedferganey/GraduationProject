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
Std_ReturnType SSD_udtInitialize  
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
		/* PIN0 */
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].logic						 
						 );			


		/* PIN1 */		
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].logic						 
						 );			


		/* PIN2 */		
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].logic						 
						 );			



		/* PIN3 */
        udtReturnValue = DIO_udtSetPinDirection
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].direction
						 );
						
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].pin,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].logic						 
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
/*
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
*/

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
/*
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
*/

/********************************************************************************************/
/*  @brief				  : Write a number to the segment 0 ~ 9 							*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType SSD_udtSendData       
( 
const SSD_t* SSD_pudtstructCfg 
uint8 Copy_u8Number 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    if((NULL == SSD_pudtstructCfg) && (9 < Copy_u8Number))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/*
			0000	---->	0
			0001	---->	1
			0010	---->	2
			0011	---->	3
			0100	---->	4
			0101	---->	5
			0110	---->	6
			0111	---->	7
			1000	---->	8
			1001	---->	9
		*/
        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN0].pin,
						  Copy_u8Number & 0x01						 
						 );

        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN1].pin,
						  (Copy_u8Number>>1) & 0x01						 
						 );

        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN2].pin,
						  (Copy_u8Number>>2) & 0x01						 
						 );


        udtReturnValue = DIO_udtSetPinValue
						 (
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].port,
						  SSD_pudtstructCfg->SSD_pins[SSD_PIN3].pin,
						  (Copy_u8Number>>3) & 0x01						 
						 );
						 
	}
	
	return udtReturnValue;	
	
}
