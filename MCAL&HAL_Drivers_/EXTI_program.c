/*
 * FileName		: EXTI_program.c
 * Created		: 8/30/2023 4:40:37 PM
 * Author		: Ahmed Ferganey
 */ 


/* -------------------------------- Includes --------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

/* -------------------------------- Global Variables --------------------------------*/
/* !Comment: global pointers to function every pointer-> point to null to prevent wild pointer 
			 using of this poninter to point to function in APP layer "CAll Back" */
/* !Comment: EXTI_CallBack are array of 3 element every element is apointer which point to 
			 to function have no arguments, return void and this pointer point to NULL */
void (*EXTI_CallBack[2]) (void) = {NULL}; 
/*
void (*ptrFun0) (void) = NULL;
void (*ptrFun1) (void) = NULL;
void (*ptrFun2) (void) = NULL;
*/


/* -------------------------------- APIs Implementation --------------------------------*/
/********************************************************************************************/
/*  @brief	 : This Function Init THE EXTI ( Prebuild Function) 							*/
/*  @param	 : NOTHING  																	*/
/*  @return	 : NOTHING																		*/                                                                  
/********************************************************************************************/
void EXTI_vdInit              
( 
void
)
{
	/*  Check for EXTI line  */
	#if EXTI_State == EXTI_INT0
		SET_BIT(GICR, GICR_INT0);
		DIO_udtSetPinDirection(PORTD_INDEX, DIO_PIN2, DIO_DIRECTION_INPUT);
		DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN2, DIO_LOW);
		/* Check for Sence Mode  */	
		#if       EXTI_SENSE_MODE == EXTI_LOW_MODE
		CLR_BIT(MCUCR, MCUCR_ISC00); 
		CLR_BIT(MCUCR, MCUCR_ISC01);
		#elif     EXTI_SENSE_MODE == EXTI_FALLING_MODE
		CLR_BIT(MCUCR, MCUCR_ISC00); 
		SET_BIT(MCUCR, MCUCR_ISC01);		
		#elif     EXTI_SENSE_MODE == EXTI_ON_MODE
		SET_BIT(MCUCR, MCUCR_ISC00); 
		CLR_BIT(MCUCR, MCUCR_ISC01);			
		#elif     EXTI_SENSE_MODE == EXTI_RISING_MODE
		SET_BIT(MCUCR, MCUCR_ISC00); 
		SET_BIT(MCUCR, MCUCR_ISC01);
		#else
		// No valid sense control mode defined for INT0	
		#endif
	
	/*  Check for EXTI line  */
	#elif EXTI_State == EXTI_INT1
		SET_BIT(GICR, GICR_INT1);
		DIO_udtSetPinDirection(PORTD_INDEX, DIO_PIN3, DIO_DIRECTION_INPUT);
		DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN3, DIO_LOW);
		/* Check for Sence Mode  */	
		#if       EXTI_SENSE_MODE == EXTI_LOW_MODE
		CLR_BIT(MCUCR, MCUCR_ISC10); 
		CLR_BIT(MCUCR, MCUCR_ISC11);
		#elif     EXTI_SENSE_MODE == EXTI_FALLING_MODE
		CLR_BIT(MCUCR, MCUCR_ISC10); 
		SET_BIT(MCUCR, MCUCR_ISC11);		
		#elif     EXTI_SENSE_MODE == EXTI_ON_MODE
		SET_BIT(MCUCR, MCUCR_ISC10); 
		CLR_BIT(MCUCR, MCUCR_ISC11);			
		#elif     EXTI_SENSE_MODE == EXTI_RISING_MODE
		SET_BIT(MCUCR, MCUCR_ISC10); 
		SET_BIT(MCUCR, MCUCR_ISC11);
		#else
		// No valid sense control mode defined for INT0				
		#endif

	/*  Check for EXTI line  */
	#elif EXTI_State == EXTI_INT2
		SET_BIT(GICR, GICR_INT2);
		DIO_udtSetPinDirection(PORTB_INDEX, DIO_PIN2, DIO_DIRECTION_INPUT);
		DIO_udtSetPinValue(PORTB_INDEX, DIO_PIN2, DIO_LOW);
		/* Check for Sence Mode  */
		#if       EXTI_SENSE_MODE == EXTI_FALLING_MODE
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
		#elif     EXTI_SENSE_MODE == EXTI_RISING_MODE
		SET_BIT(MCUCSR, MCUCSR_ISC2);
		#else
		// No valid sense control mode defined for INT0		
		#endif
	#else
		// No valid EXTI request enabled
	#endif
}

/********************************************************************************************/
/*  @brief	 			   : This Function Disable EXTI 									*/
/*  @param	udtRequest_ID  : target EXTI (GICR REG #bit <5,6,7>)  		@ref EXTI_Request_t	*/
/*  @return	Std_ReturnType : 																*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)   : The function has issue to perform this action	*/
/********************************************************************************************/
Std_ReturnType EXTI_udtDisableInterrupt   
( 
const EXTI_Request_t udtRequest_ID
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	/* !Comment: Checking if bit between [5:7] of REG GICR */
	if ((udtRequest_ID >= GICR_INT2) && (udtRequest_ID <= GICR_INT1))  
	{
		/* Clear The Required BIT */
		CLR_BIT(GICR, udtRequest_ID);
		udtReturnValue = E_OK;
	}
	else 
	{
		udtReturnValue = E_NOT_OK;
	}	
	return udtReturnValue;
}

/********************************************************************************************/
/*  @brief	 			   : This Function Enable EXTI 										*/
/*  @param	udtRequest_ID  : target EXTI (GICR REG #bit <5,6,7>)  		@ref EXTI_Request_t	*/
/*  @return	Std_ReturnType : 											 					*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)   : The function has issue to perform this action	*/
/********************************************************************************************/
Std_ReturnType EXTI_udtEnableInterrupt    
( 
const EXTI_Request_t udtRequest_ID
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	/* !Comment: Checking if bit between [5:7] of REG GICR */	
	if ( (udtRequest_ID >= GICR_INT2) && (udtRequest_ID <= GICR_INT1) )  
	{
		/* Set The Required BIT */
		SET_BIT(GICR, udtRequest_ID);
		udtReturnValue = E_OK;		
	}
	else 
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;
}


/********************************************************************************************/
/*  @brief	 			      :This Function send signal to target EXTI<x> 					*/
/*  @param	udtSenseMode  	  :this enum have one of these options  @ref EXTI_SenseMode_t	*/
/* 								EXTI_LOW_LEVEL=0,											*/
/* 								EXTI_ON_CHANGE, 						 					*/	
/* 								EXTI_RISING_EDGE,											*/
/* 								EXTI_FALLING_EDGE											*/
/*  @param	copy_udtRequestID :this enum have one of these options  @ref EXTI_Request_t		*/
/*								GICR_INT2=5,												*/
/*                              GICR_INT0,													*/
/*                              GICR_INT1													*/
/*  @return	Std_ReturnType : 											 					*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)    : The function has issue to perform this action	*/
/********************************************************************************************/
Std_ReturnType EXTI_udtSetSignalLatch
(
const EXTI_SenseMode_t udtSenseMode, 
EXTI_Request_t copy_udtRequestID
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/* !Comment: For EXTI 0,1 */
	if(copy_udtRequestID >= GICR_INT0 && copy_udtRequestID <= GICR_INT1)
	{
		switch(udtSenseMode)
		{
			/* !Comment: this operation for Bit 0,1,2,3 of REG MCUCR, where there is 2 cases 
						 copy_udtRequestID = 6 or 7 if 6 then copy_udtRequestID will 
						 equal 0 after next line of code and if 7 copy_udtRequestID
						 will be 2. 
			*/
			copy_udtRequestID = (6 - copy_udtRequestID) * -2;
			
			case EXTI_LOW_LEVEL		: CLR_BIT(MCUCR, copy_udtRequestID); 
									  CLR_BIT(MCUCR, (copy_udtRequestID + 1));
									  udtReturnValue = E_OK;
									  break;
			case EXTI_ON_CHANGE		: SET_BIT(MCUCR, copy_udtRequestID); 
									  CLR_BIT(MCUCR, (copy_udtRequestID + 1));
									  udtReturnValue = E_OK;									  
									  break;			
			case EXTI_RISING_EDGE	: SET_BIT(MCUCR, copy_udtRequestID); 
									  SET_BIT(MCUCR, (copy_udtRequestID + 1));
									  udtReturnValue = E_OK;									  
									  break;
			case EXTI_FALLING_EDGE	: CLR_BIT(MCUCR, copy_udtRequestID); 
									  SET_BIT(MCUCR, (copy_udtRequestID + 1));
									  udtReturnValue = E_OK;									  
								      break;
			default:		  		  /*	!Comment: Do nothing	*/
									  break;									 
		}	
	}
	/* !Comment: For EXTI 2 */
	else if(copy_udtRequestID == GICR_INT2)
	{
		switch(udtSenseMode)
		{
			case EXTI_RISING_EDGE	: SET_BIT(MCUCR, copy_udtRequestID); 
									  SET_BIT(MCUCR, copy_udtRequestID);
									  udtReturnValue = E_OK;									  
									  break;
			case EXTI_FALLING_EDGE	: CLR_BIT(MCUCR, copy_udtRequestID); 
									  SET_BIT(MCUCR, copy_udtRequestID);
									  udtReturnValue = E_OK;									  
								      break;	
			default:		  		  /*	!Comment: Do nothing	*/
									  break;									  
		}		
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief	 			   : This Function clear Flag 										*/
/*  @param	udtRequest_ID  : target EXTI (GICR REG #bit <5,6,7>)  		@ref EXTI_Request_t	*/
/*  @return	Std_ReturnType : 											 					*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)   : The function has issue to perform this action	*/
/********************************************************************************************/
void EXTI_vdClearFlag 
(
EXTI_Request_t copy_udtRequestID
)
{
	SET_BIT(GIFR, copy_udtRequestID);	
}

/********************************************************************************************/
/*  @brief	 			   : This Function GET FLAG 										*/
/*  @param	udtRequest_ID  : target EXTI (GICR REG #bit <5,6,7>)  		@ref EXTI_Request_t	*/
/*  @return	Std_ReturnType : 											 					*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)   : The function has issue to perform this action	*/
/********************************************************************************************/
Std_ReturnType EXTI_vdGetFlag 
(
EXTI_Request_t copy_udtRequestID,
uint8* pu8FlagValue
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (pu8FlagValue == NULL)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		*pu8FlagValue  = GET_BIT(GIFR, copy_udtRequestID);
		udtReturnValue = E_OK;		
	}	
	return udtReturnValue;
}

/* !Comment: the next APIs respnsible for ISR or Helping for happenening ISR */
/********************************************************************************************/
/*  @brief	 			   	 : Setting CAll back  											*/
/*  @param	udtRequest_ID  	 : target EXTI   						@ref EXTI_Request_t*    */
/*  @param	Copy_pvdCallBack : pointer to function from APP layer   @ref EXTI_Request_t		*/
/*  @return	Std_ReturnType   : 											 					*/
/*							(E_OK)		  : The function done successfully					*/ 
/*							(E_NOT_OK)   : The function has issue to perform this action	*/
/********************************************************************************************/
Std_ReturnType EXTI_udtSetCallBack
(
void (*Copy_pvdCallBack)(void), 
const EXTI_Request_t copy_udtRequestID 
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(Copy_pvdCallBack == NULL)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		switch(copy_udtRequestID)
		{
			case GICR_INT0: EXTI_CallBack[EXTI_INT0] = Copy_pvdCallBack;
							udtReturnValue = E_OK;
							break;
			case GICR_INT1: EXTI_CallBack[EXTI_INT1] = Copy_pvdCallBack;
							udtReturnValue = E_OK;
							break;
			case GICR_INT2: EXTI_CallBack[EXTI_INT2] = Copy_pvdCallBack;
							udtReturnValue = E_OK;
							break;
			default:		  /* !Comment: Do nothing */
							break;			
		}
	}
	return udtReturnValue;
}

/********************************************************************************************/
/*  @brief	 			   	 : ISR IMPLEMENTATIon 											*/
/********************************************************************************************/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_CallBack[EXTI_INT0] != NULL)
	{
		/*!Comment: hhhhhh now we are calling a function from app layer */
		EXTI_CallBack[EXTI_INT0]();
		/*!Comment: Clearing Flag */
		SET_BIT(GIFR, BIT_6);	
	}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_CallBack[EXTI_INT1] != NULL)
	{
		/*!Comment: hhhhhh now we are calling a function from app layer */
		EXTI_CallBack[EXTI_INT1]();
		/*!Comment: Clearing Flag */
		SET_BIT(GIFR, BIT_5);	
	}	
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_CallBack[EXTI_INT2] != NULL)
	{
		/*!Comment: hhhhhh now we are calling a function from app layer */
		EXTI_CallBack[EXTI_INT2]();
		/*!Comment: Clearing Flag */
		SET_BIT(GIFR, BIT_7);	
	}	
}