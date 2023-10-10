/*
 * FileName		: USART_program.c
 * Created		: 9/3/2023 8:27:11 AM
 * Author		: Ahmed Ferganey
 */ 

//////////////////////////////////////////////////////////////////////////////////////////////
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"






//////////////////////////////////////////////////////////////////////////////////////////////
/* -------------------------------- Global Variables ---------------------------------------*/
/*static Global flag for the USART Busy State*/
static uint8 USART_u8State = STD_IDLE;
/*static Global pointer to function to carry the notification function called by RX ISR*/
static void (*USART_vdRXC_Callback)(void)=NULL;
/*static Global pointer to function to carry the notification function called by TX ISR*/
static void (*USART_vdTXC_Callback)(void)=NULL;

/*Global variable to indicate for the current Data index of the buffer*/
static uint8 USART_u8Index;
/*Global variable to carry the buffer size This variable is static to have file scope*/
	/*global not initilized is equal to zero init*/
static uint16 USART_u16BufferSize;
/* Global variable to carry the Received Data*/
static uint8* USART_pu8ReceivedData = NULL;
/*Global variable to carry the Transfered Data*/
	/*this data should be constant data to prevent any change on data so
	  this  pointer is point to static & const data*/
static const uint8* USART_pu8TransferData = NULL;



//////////////////////////////////////////////////////////////////////////////////////////////
/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void USART_voidInit 
(
void
)
{
	/* 1- Set baud rate */
				/* Calculate The r Calculating UBRR Value which equvalent to Baud rate 
				   Asynchronous Normal Mode	page 147 */
	uint16 Local_u16UBRR = (uint16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)) - 1) ;
				/* Check 3 Modes */
	#if   (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X1)
		CLR_BIT(USART->UCSRA, UCSRA_U2X);
	
	#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X2)
		SET_BIT(USART->UCSRA, UCSRA_U2X);		
		Local_u16UBRR /= 2;	
		
	#elif (USART_MODE == SYNCHRONOUS)
		Local_u16UBRR /= 8;
	
	#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif	
				/* Set Baud Rate in UBRRH & UBRRL REG */				
	UBRRH = (uint8)(Local_u16UBRR>>8);
	USART->UBRRL = (uint8)Local_u16UBRR;	
	/****************************************************************************************/
	/* 2- UCSRC – USART Control and Status Register Config */
		/* The UCSRC Register shares the same I/O location as the UBRRH Register.
		   Bit 7 – URSEL: Register Select This bit selects between accessing the 
		   UCSRC or the UBRRH Register. It is read as one when reading UCSRC.The 
		   URSEL must be one when writing the UCSRC,
		   initial value of URSEL is 1 
		*/

				/* Register Select */		
	SET_BIT(UCSRC, UCSRC_URSEL);
	
				/* USART Mode Select */
	#if   USART_MODE == ASYNCHRONOUS
		CLR_BIT(UCSRC, UCSRC_UMSEL);
		
	#elif USART_MODE == SYNCHRONOUS
		SET_BIT(UCSRC, UCSRC_UMSEL);
		
	#else
		#error "Wrong USART_MODE config"
	#endif				
				
				/* Parity Mode */
	#if   USART_PARITY_MODE == DISABLE
		CLR_BIT(UCSRC, UCSRC_UPM0);
		CLR_BIT(UCSRC, UCSRC_UPM1);
		
	#elif USART_PARITY_MODE == EVEN_PARITY
		CLR_BIT(UCSRC, UCSRC_UPM0);
		SET_BIT(UCSRC, UCSRC_UPM1);
		
	#elif USART_PARITY_MODE == ODD_PARITY
		SET_BIT(UCSRC, UCSRC_UPM0);
		SET_BIT(UCSRC, UCSRC_UPM1);
		
	#else
		#error "Wrong USART_PARITY_MODE config"
	#endif				
				
				/* Stop Bit Select */
	#if   USART_STOP_BIT == STOP_BIT_1
		CLR_BIT(UCSRC, UCSRC_USBS);
		
	#elif USART_STOP_BIT == STOP_BIT_2
		SET_BIT(UCSRC, UCSRC_USBS);
		
	#else
		#error "Wrong USART_STOP_BIT config"
	#endif
						
				/* Character Size */
	#if   USART_DATA_SIZE == DATA_SIZE_5_BIT
		CLR_BIT(UCSRC, UCSRC_UCSZ0);
		CLR_BIT(UCSRC, UCSRC_UCSZ1);
		CLR_BIT(USART->UCSRB, UCSRB_UCSZ2) ;
		
	#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
		SET_BIT(UCSRC, UCSRC_UCSZ0);
		CLR_BIT(UCSRC, UCSRC_UCSZ1);
		CLR_BIT(USART->UCSRB, UCSRB_UCSZ2) ;
		
	#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
		CLR_BIT(UCSRC, UCSRC_UCSZ0);
		SET_BIT(UCSRC, UCSRC_UCSZ1);
		CLR_BIT(USART->UCSRB, UCSRB_UCSZ2) ;
		
	#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
		SET_BIT(UCSRC, UCSRC_UCSZ0);
		SET_BIT(UCSRC, UCSRC_UCSZ1);
		CLR_BIT(USART->UCSRB, UCSRB_UCSZ2) ;
		
	#elif USART_DATA_SIZE == DATA_SIZE_9_BIT
		SET_BIT(UCSRC, UCSRC_UCSZ0);
		SET_BIT(UCSRC, UCSRC_UCSZ1);
		SET_BIT(USART->UCSRB, UCSRB_UCSZ2) ;
		
	#else
		#error "Wrong USART_DATA_SIZE config"
	#endif
				
				
				/* Clock Polarity */
	#if USART_MODE == SYNCHRONOUS
		#if   USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
			CLR_BIT(UCSRC, UCSRC_UCPOL);
			
		#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
			SET_BIT(UCSRC, UCSRC_UCPOL);
			
		#else
			#error "Wrong USART_Clock_Polarity config"
		#endif
	#endif

	/* there is another technique to init this register
		where store all the valuse in Local_u8UCSRC
		and then in one operation set value in REG
			Set UCSRC Mode
	SET_BIT(Local_u8UCSRC , UCSRC_URSEL) ;

			Store the value in UCSRC Register (one operation) 
	UCSRC = Local_u8UCSRC ;
	*/
	/****************************************************************************************/
 	/* 3- UCSRB – Enable receiver and transmitter */
				/* Receive Enable */
	#if   USART_RECEIVER_ENABLE == DISABLE
		CLR_BIT(USART->UCSRB, UCSRB_RXEN);
		
	#elif USART_RECEIVER_ENABLE == ENABLE
		SET_BIT(USART->UCSRB, UCSRB_RXEN);
		
	#else
		#error "Wrong USART_RECEIVER_ENABLE config"
	#endif
	
				/* Transmitter Enable */
	#if   USART_TRANSMITTER_ENABLE == DISABLE
		CLR_BIT(USART->UCSRB, UCSRB_TXEN);
		
	#elif USART_TRANSMITTER_ENABLE == ENABLE
		SET_BIT(USART->UCSRB, UCSRB_TXEN);
		
	#else
		#error "Wrong USART_TRANSMITTER_ENABLE config"
	#endif				
				
				/* RX Complete Interrupt Enable */
	#if   USART_RX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(USART->UCSRB, UCSRB_RXCIE);
		
	#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(USART->UCSRB, UCSRB_RXCIE);
		
	#else
		#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
	#endif				
				
				/* TX Complete Interrupt Enable */
	#if   USART_TX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(USART->UCSRB, UCSRB_TXCIE);
		
	#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(USART->UCSRB, UCSRB_TXCIE);
		
	#else
		#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
	#endif				
				
				/* UDR Empty Interrupt Enable */
	#if   USART_UDR_EMPTY_INTERRUPT == DISABLE
		CLR_BIT(USART->UCSRB, UCSRB_UDRIE);
		
	#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
		SET_BIT(USART->UCSRB, UCSRB_UDRIE);
		
	#else
		#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
	#endif
	/****************************************************************************************/
	/*Multi-Processor Communication mode*/
	#if USART_MPCM == DISABLE
		CLR_BIT(USART->UCSRA, UCSRA_MPCM);
		
	#elif USART_MPCM == ENABLE
		SET_BIT(USART->UCSRA, UCSRA_MPCM);
		
	#else
		#error "Wrong USART_MPCM config"
	#endif	
}

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType USART_udtSendData 
(
uint8 Copy_u8Data
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint32 Local_u32TimeoutCounter = 0;
	if (USART_u8State == STD_IDLE)
	{
		USART_u8State = STD_ACTIVE;
		/*
			 - TIMEOUT to avoid infinity loop.
			 - Wait until a Transmiting complete or Timing out.
		*/		
		/* If UDRE is one, the buffer is empty */
			/* there is implicit declaration here 
				GET_BIT(USART->UCSRA, UCSRA_UDRE) == 0 */
		while (((GET_BIT(USART->UCSRA, UCSRA_UDRE) == 0) 
			   && (Local_u32TimeoutCounter != USART_u32TIMEOUT)))
		{
			Local_u32TimeoutCounter++;
		}
		if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
		{
			udtReturnValue = E_TIMEOUT;
		}
		else
		{
			/* store data in buffer */
			(USART->UDR) = Copy_u8Data;
			udtReturnValue = E_OK;		
		}
		USART_u8State = STD_IDLE;
	}
	else
	{
		udtReturnValue = E_PENDING;
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
Std_ReturnType USART_udtRecevieData 
(
uint8 * Copy_u8ReceviedData
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint32 Local_u32TimeoutCounter = 0;
	if (Copy_u8ReceviedData != NULL)
	{
		if (USART_u8State == STD_IDLE)
		{
			USART_u8State = STD_ACTIVE;
			/*
				- TIMEOUT to avoid infinity loop.
				- Wait until a Receiving complete or Timing out.
			*/		
			/* 
			This flag bit "UCSRA_RXC" is set when there are unread data 
			in the receive buffer and cleared when the receive buffer 
			is empty
			*/
			while (((GET_BIT(USART->UCSRA, UCSRA_RXC) == 0) 
				&& (Local_u32TimeoutCounter != USART_u32TIMEOUT)))
			{
				Local_u32TimeoutCounter++;
			}
			if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
			{
				udtReturnValue = E_TIMEOUT;
			}
			else
			{
				/* store data in buffer */
				* Copy_u8ReceviedData = (USART->UDR);
				udtReturnValue = E_OK;		
			}
			USART_u8State = STD_IDLE;
		}
		else
		{
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
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType USART_udtSendStringSynch 
(
const uint8 * Copy_pchString
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	uint32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Copy_pchString[Local_u32Index] != '\0')
		{
			udtReturnValue = USART_udtSendData(Copy_pchString[Local_u32Index]);
			Local_u32Index++ ;
			if (udtReturnValue != E_OK)
			{
				return udtReturnValue ;
			}
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK ;
	}

	return udtReturnValue ;	
}
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType USART_udtReceiveBufferSynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	uint32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Local_u32Index < Copy_uint32BufferSize)
		{
			udtReturnValue = USART_udtRecevieData(&Copy_pchString[Local_u32Index]) ;
			Local_u32Index++ ;

			if (udtReturnValue != E_OK)
			{
				return udtReturnValue ;
			}
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK ;
	}

	return udtReturnValue ;	
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
Std_ReturnType USART_u8SendBufferAsynch 
(
const uint8 * Copy_pu8TransferdData, 
void (* NotificationFunc)(void)
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (USART_u8State == STD_IDLE)
	{
		if ((NotificationFunc != NULL) && (Copy_pu8TransferdData != NULL))
		{
			/*1-USART is now Busy*/
			USART_u8State = STD_ACTIVE;
			
			
			/*2-Assign the USART data globally*/
			USART_vdTXC_Callback = NotificationFunc;
			USART_pu8TransferData = Copy_pu8TransferdData;
			
			/*3-Set Index to first element*/
			USART_u8Index = 0;
			

			/*4-Send first Data */
			(USART->UDR) = USART_pu8TransferData[USART_u8Index];
			
			/*5-USART Transmit Interrupt Enable to switch interrupt & inside 
				it calling Notification function*/
			SET_BIT(USART->UCSRB, UCSRB_RXCIE);
			udtReturnValue = E_OK;			
			
		}
		else
		{
				udtReturnValue = E_NOT_OK;
		}
	}
	else
	{
		udtReturnValue = E_PENDING;
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
Std_ReturnType USART_u8ReceiveBufferAsynch 
(
uint8 * Copy_pu8AppBuffer, 
uint16 Copy_u16BufferSize, 
void (* NotificationFunc)(void)
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (USART_u8State == STD_IDLE)
	{
		if ((Copy_pu8AppBuffer != NULL) && (NotificationFunc != NULL))
		{
			/*1-USART is now Busy*/
			USART_u8State = STD_ACTIVE;	

			/*2-Assign the USART data globally*/
				/*initilize Call Back Func by app*/
			USART_vdRXC_Callback = NotificationFunc;
				/*initilize pointer with the required address in app*/
			USART_pu8ReceivedData = Copy_pu8AppBuffer;
				/*Assigning Buffer size */	
				/*Copy_u16BufferSize is equal to number of bytes required */				
			USART_u16BufferSize = Copy_u16BufferSize;

			/*3-Set Index to first element*/
			USART_u8Index = 0;

			/*4-USART Recieve Interrupt Enable */
			SET_BIT(USART->UCSRB, UCSRB_RXCIE);

			udtReturnValue = E_OK;		
		}
		else
		{
			/*this code is reachable in case of pointing to NULL Pointer*/
			udtReturnValue = E_NOT_OK;
		}
	}
	else
	{
			/*this code is reachable in case of USART is BUSY*/
			udtReturnValue = E_PENDING;	
	}
	return udtReturnValue;
	
}




//////////////////////////////////////////////////////////////////////////////////////////////
/* -------------------------------- ISRs Implementation ------------------------------------*/
/* ISR for RX complete */
void __vector_13 (void)		__attribute__ ((signal));
void __vector_13 (void)
{
	/*1- Receive next Data*/
		/*static global make variable in data segment & the life time until progrem end */
	USART_pu8ReceivedData[USART_u8Index] = (USART->UDR);
	/*2-Increment Data index of the buffer"pointer as array Ptr[i]"*/
		/* this is similar to full & empty Ascending or deascending stack */
	USART_u8Index++;


	/*3-Send Data Complete*/
		/*if inex not equal buffer size this means that usart still recieve data*/
	if (USART_u8Index == USART_u16BufferSize)
	{
		/*
		When the Receive Complete Interrupt Enable 
		(RXCIE) in UCSRB is set, the USART Receive 
		Complete Interrupt will be executed as long 
		as the RXC Flag is set (provided that global 
		interrupts are enabled). When interrupt-driven
		data reception is used, the receive complete 
		routine must read the received data from UDR 
		in order to clear the RXC Flag, otherwise a new 
		interrupt will occur once the interrupt routine 
		terminates.
		*/
		/*re-intilize with 0 to can recieve another new data*/
		USART_u8Index=0;
		
		/*USART is now IDLE*/
		USART_u8State = STD_IDLE;
		
		/*Call Notification Function*/
		USART_vdRXC_Callback();
		
		/*USART Recieve Interrupt Disable*/
		CLR_BIT(USART->UCSRB , UCSRB_RXCIE);			

	}
	else
	{
		/*Do Noting*/		
	}
}



/* ISR for TX complete */
void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{
	/*Increment Data index of the buffer*/
	USART_u8Index++;
	
	if (USART_pu8TransferData[USART_u8Index] == '\0')
	{
		/*Receive Data Complete*/
		USART_u8Index=0;
		
		/*USART is now IDLE*/
		USART_u8State = STD_IDLE;
		
		/*Call Notification Function*/
		USART_vdTXC_Callback();
		
		/*USART Transmit Interrupt Disable*/
		CLR_BIT(USART->UCSRB , UCSRB_TXCIE);			
		
	}
	else
	{
		/*Send Data not Complete*/
			/*Send next Data*/	
			/*this aree is reachable if my data do not contain null termination*/
			/* note that interrupt still enable to can transmit new data according to
			   next index*/
			/*you can consider, we are in infinite loop, and this loop will terminate 
			  if and only if find null termination and then enter if condition 
			  and finally will disable interrupt and start execution main program.
			  also, this thing is bad to make main is isolated end execute interrupt for 
			  long time*/
		(USART->UDR) = USART_pu8TransferData[USART_u8Index];
	
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////

	
	
