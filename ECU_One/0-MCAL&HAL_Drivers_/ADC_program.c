/*
 * FileName		: ADC_program.c
 * Created		: 8/29/2023 3:54:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes --------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"


/* -------------------------------- Global Variables --------------------------------*/
/*Global flag for the ADC State to use it in synh function */
static uint8 ADC_u8State= STD_IDLE;


/*Global flag for the ADC ISR State*/
static uint8 ADC_u8ISRState;
/*Global pointer to carry the conversion result in the Asynchronous execution*/
static uint16* ADC_pu16AsynchConversionResult = NULL;
/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_pvNotificationFunc)(void) = NULL;


/*Global pointer to carry the chain Channel*/
static uint8* ADC_pu8ChainChannel;
/*Global variable to carry the chain size*/
static uint8 ADC_u8ChainSize;
/*Global variable to indicate for the current ADC Chain*/
static uint8 ADC_u8Index;


/* -------------------------------- APIs Implementation --------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void ADC_vdEnable           
(
void
)
{
	SET_BIT(ADCSRA, ADCSRA_ADEN);	
}

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void ADC_vdDisable          
(
void
)
{
	CLR_BIT(ADCSRA, ADCSRA_ADEN);	
	
}

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void ADC_vdInterruptEnable  
(
void
)
{
	SET_BIT(ADCSRA, ADCSRA_ADIE);
}


/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void ADC_vdInterruptDisable 
(
void
)
{
	CLR_BIT(ADCSRA, ADCSRA_ADIE);
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
Std_ReturnType ADC_udtSetPrescaler 
(
uint8 Copy_u8Prescaler
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (Copy_u8Prescaler <= ADC_PRE_128)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK;
		ADCSRA |= Copy_u8Prescaler;		
		udtReturnValue = E_OK;
	}
	else
	{
		udtReturnValue = E_NOT_OK;	
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
Std_ReturnType ADC_udtInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*Select the voltage reference*/
	#if ADC_VREF == ADC_AREF
		CLR_BIT(ADMUX , ADMUX_REFS0);
		CLR_BIT(ADMUX , ADMUX_REFS1);
		udtReturnValue = E_OK;
	#elif ADC_VREF == ADC_AVCC
		SET_BIT(ADMUX , ADMUX_REFS0);
		CLR_BIT(ADMUX , ADMUX_REFS1);
		udtReturnValue = E_OK;		
	#elif ADC_VREF == ADC_INT_2_56_EXT_CAP
		SET_BIT(ADMUX , ADMUX_REFS0);
		SET_BIT(ADMUX , ADMUX_REFS1);
		udtReturnValue = E_OK;		
	#else
		#error "Wrong ADC_VREF config"
	#endif	

	/*Set Left or right Adjust Result*/
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
			CLR_BIT(ADMUX , ADMUX_ADLAR);
			udtReturnValue = E_OK;	
	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
			SET_BIT(ADMUX , ADMUX_ADLAR);
			udtReturnValue = E_OK;	
	#else
		#error "Wrong ADC_ADJUSTMENT config"
	#endif	
	
	/*Set Prescaler Value*/
	ADCSRA &= ADC_PRE_MASK;
	ADCSRA |= ADC_PRESCALLER;
	udtReturnValue = E_OK;
	
	/*Enable or disable ADC Peripheral*/	
	#if ADC_STATUS == ADC_DISABLE
		CLR_BIT(ADCSRA , ADCSRA_ADEN);
		udtReturnValue = E_OK;
	#elif ADC_STATUS == ADC_ENABLE
		SET_BIT(ADCSRA , ADCSRA_ADEN);
		udtReturnValue = E_OK;
	#else
		#error "Wrong ADC_STATUS config"
	#endif 
	
	/*Enable or disable ADC Interrupt*/
	#if ADC_INT_STATUS == ADC_INT_DISABLE
		CLR_BIT(ADCSRA , ADCSRA_ADIE);
		udtReturnValue = E_OK;
	#elif ADC_INT_STATUS == ADC_INT_ENABLE
		SET_BIT(ADCSRA , ADCSRA_ADIE);
		udtReturnValue = E_OK;
	#else
		#error "Wrong ADC_INT_STATUS config"
	#endif
	
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
Std_ReturnType ADC_udtSelectDefaultChannel
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    /* Configure the required channel */
	ADMUX &= ADC_CH_MASK;
	ADMUX |= ADC_CHANNEL;
	udtReturnValue = E_OK;
	
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
Std_ReturnType ADC_udtGetResultSync
(
const uint8 Copy_uint8Channel, 
uint16* Copy_pu16Result
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint32 l_u32TimeoutCounter = 0;

	if (Copy_pu16Result != NULL)
	{
		if (ADC_u8State == STD_IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = STD_ACTIVE;
			
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK;
			ADMUX |= Copy_uint8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/* !comment: Waiting until the conversion is completed
						 this counter is used to prevent mcu to stuck here,
						 if flag is not equal to 1 for the calculated conversion time */
			while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (l_u32TimeoutCounter < ADC_TIMEOUT))
			{
				l_u32TimeoutCounter++;
			}
			if (l_u32TimeoutCounter == ADC_TIMEOUT)
			{
				udtReturnValue = E_NOT_OK;
			}
			else
			{
				/* !Comment: Clear the interrupt flag by writing one "AVR Clearing flag technique"
						     this flag is cleared by HW when using Asynh function */
				SET_BIT(ADCSRA, ADCSRA_ADIF);

				/* !comment: Return Conversion Result 
							 not that in case Left, the calculated value will by ADCH only
							 and neglecting the value of low register */
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					*Copy_pu16Result = (ADCL|(ADCH << 8));

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*Copy_pu16Result = ADCH;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
			}

			/*setting ADC as IDLE to the next conversion */
			ADC_u8State = STD_IDLE;
			udtReturnValue = E_OK;			
		}
		else
		{
			ADC_u8State = STD_ACTIVE; 
			udtReturnValue = E_PENDING;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
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
Std_ReturnType ADC_udtStartConversionAsynch
( 
uint8 Copy_u8Channel, 
uint16* Copy_pu16Result, 
void(*Copy_pvNotificationFunc)(void) 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if ((Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_u8State == STD_IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = STD_ACTIVE;
			
			/*Set ISR State*/
			ADC_u8ISRState = SINGLE_CHANNEL_ASYNCH;
			
			/*Initialize the global result pointer*/
			ADC_pu16AsynchConversionResult = Copy_pu16Result;
			
			/*Initialize the global notification function pointer*/
			ADC_pvNotificationFunc = Copy_pvNotificationFunc;
			
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK;
			ADMUX |= Copy_u8Channel;			
			
			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			
			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA, ADCSRA_ADIE);
			udtReturnValue = E_OK;			
		}
		else
		{
			/* !Comment: Improvement Area in the Future to save memory & execution time*/
			ADC_u8State = STD_ACTIVE; 
			udtReturnValue = E_PENDING;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
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
Std_ReturnType ADC_udtStartChainAsynch     
( 
ADC_chain_t * Copy_ADC_Chain
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (((((Copy_ADC_Chain) != NULL) 
		&& (Copy_ADC_Chain->Channel != NULL)) 
		&& (Copy_ADC_Chain->NotificationFunc != NULL)) 
		&& (Copy_ADC_Chain->Result != NULL))
	{
		if(ADC_u8State == STD_IDLE)
		{
			/*ADC is now Busy*/
			ADC_u8State = STD_ACTIVE; 
			
			/*Set ISR State*/
			ADC_u8ISRState = CHAIN_CHANNEL_ASYNCH;
			
			/*Assign the ADC data globally*/
			ADC_pu16AsynchConversionResult = Copy_ADC_Chain->Result;
			ADC_pu8ChainChannel = Copy_ADC_Chain->Channel;
			ADC_u8ChainSize = Copy_ADC_Chain->Size;
			ADC_pvNotificationFunc = Copy_ADC_Chain->NotificationFunc;
			
			/*Set Index to first element*/
			ADC_u8Index = first_element_channel;
			
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK;
			ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];
			
			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);
			
			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA, ADCSRA_ADIE);
			udtReturnValue = E_OK;			
		}
		else
		{
			ADC_u8State = STD_ACTIVE; 			
			udtReturnValue = E_PENDING;	
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
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
Std_ReturnType ADC_udtSetCallBack
(
void (*Copy_pvCallBackFunc)(void)
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (Copy_pvCallBackFunc != NULL)
	{
		ADC_pvNotificationFunc= Copy_pvCallBackFunc;
		udtReturnValue = E_OK;		
	}
	else
	{
		udtReturnValue = E_NOT_OK;
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
/* ISR for ADC conversion complete */
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
	{
		/*Return Conversion Result*/
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
		*ADC_pu16AsynchConversionResult = (ADCL | (ADCH << 8));
#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
		*ADC_pu16AsynchConversionResult = ADCH;
#else
	#error "Wrong ADC_ADJUSTMENT config"
#endif
		/*ADC is IDLE*/
		ADC_u8State = STD_IDLE;	
		/*Call Notification Function*/
		ADC_pvNotificationFunc() ;		
		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}
	else
	{
		/*Return Conversion Result*/
#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
		*ADC_pu16AsynchConversionResult = (ADCL | (ADCH << 8));
#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
		*ADC_pu16AsynchConversionResult = ADCH;
#else
	#error "Wrong ADC_ADJUSTMENT config"
#endif
		/*Increment Data index of the chain*/
		ADC_u8Index++;

		if(ADC_u8Index == ADC_u8ChainSize)
		{
			/*ADC is IDLE*/
			ADC_u8State = STD_IDLE;	
			
			/*Call Notification Function*/
			ADC_pvNotificationFunc();
			
			/*Disable the Conversion Complete Interrupt*/
			CLR_BIT(ADCSRA, ADCSRA_ADIE);
		}
		else
		{
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_pu8ChainChannel[ADC_u8Index];
			
			/*Start Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);
		}
	}
}
