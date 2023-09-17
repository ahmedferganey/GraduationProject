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
/*  @brief				        : 											 				*/
/*  @param	 LM35_pudtConfig    : struct has the LM35 Channel, ADC VoltageReference , 		*/
/* 								  ADCResolution						 @ref *LM35_config_t	*/
/*  @param	 LM35_pu8TempValue  : Pointer to TEMP Variable which 							*/
/* 								  will return in it		 			 @ref *uint8			*/
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
	uint16 Local_u16ADCDigitalResult;
	uint16 Local_u16AnalogValue;
	/*  To Convert Local_u8ADCReference from ( V --> mV )*/
	uint16 Local_u8ADCReference = (LM35_pudtConfig->Copy_u8ADCVoltageRef)*1000;


	if (((LM35_pudtConfig == NULL) || (pu8TempValue == NULL)))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		
	/* ADC Digital Reading  */
	udtReturnValue = ADC_udtGetResultSync(LM35_pudtConfig->Copy_u8LM35Channel, 
										  &Local_u16ADCDigitalResult);
		
	/* Check for ADC Resolution  */
	if (LM35_pudtConfig->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT)
	{
		Local_u16AnalogValue = (((uint32)Local_u16ADCDigitalResult * 
								 (uint32)Local_u8ADCReference) 
								  / LM35_ADC_10_BIT_RESOLUTION);
	}
	else if (LM35_pudtConfig->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT)
	{
		Local_u16AnalogValue = (((uint32)Local_u16ADCDigitalResult * 
								 (uint32)Local_u8ADCReference) 
								  / LM35_ADC_8_BIT_RESOLUTION);
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}		
		
	/* Get value, Convert ( mv --> Temp ) */
	*LM35_pu8TempValue = (Local_u16AnalogValue / Sensitivity);
		
	}
	
	return udtReturnValue;	
}

//////////////////////////////////////////////////////////////////////////////////////////////
