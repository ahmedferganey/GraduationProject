/*
 * FileName		: LDR_program.c
 * Created		: 9/18/2023 10:52:51 AM
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
#include "LDR_interface.h"
#include "LDR_config.h"
#include "LDR_private.h"




/* -------------------------------- Global Variables ---------------------------------------*/
/* ----------------- static API Decleration -----------------*/
static void LDR_vdNotificationFunc
(
void
);

/*Global pointer to function to carry the notification function called by ADC_ISR*/
static void (* LDR_pfvdCallBackFunc)(void) = LDR_vdNotificationFunc;









 
/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType LDR_udtInit
(
LDR_Config_t* pudtLDRConfig
)
{
	Std_ReturnType LDR_InitState = E_NOT_OK;
	
	if (pudtLDRConfig == NULL)
	{
		LDR_InitState = E_NOT_OK;
	}
	else
	{
		LDR_InitState = DIO_udtSetPinDirection(pudtLDRConfig->Copy_u8LDRPort,
											   pudtLDRConfig->Copy_u8LDRPin,
											   LDR_PIN_DIRECTION_INPUT);		
	}

	return LDR_InitState;
}

/*
	EX/
		typedef char uint8;
		typedef struct
		{
			uint8 Copy_u8LDRPort:4 ;
			uint8 Copy_u8LDRPin :4 ;
		}LDR_Config_t;
		int main()
		{
			LDR_Config_t LDR;
			LDR.Copy_u8LDRPort=5;
			LDR.Copy_u8LDRPin =2;
			printf("%i \n",LDR.Copy_u8LDRPort);	//5
			printf("%i \n",LDR.Copy_u8LDRPin);	//2
			return 0;
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
Std_ReturnType LDR_udtReadValue
(
uint16* pu16LDRValue,
LDR_Config_t* pudtLDRConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if(((pu16LDRValue == NULL) || (pudtLDRConfig == NULL)))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/*		udtReturnValue = ADC_udtSetCallBack(LDR_pfvdCallBackFunc)		*/
		udtReturnValue = ADC_udtStartConversionAsynch(pudtLDRConfig->Copy_u8LDRPin,
													  pu16LDRValue,
													  LDR_pfvdCallBackFunc);
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
static void LDR_vdNotificationFunc
(
void
)
{
	/* Nothing */
}
 