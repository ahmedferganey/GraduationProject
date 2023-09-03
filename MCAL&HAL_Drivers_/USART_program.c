/*
 * FileName		: USART_program.c
 * Created		: 9/3/2023 8:27:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"







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
	UBRRL = (uint8)Local_u16UBRR;	
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
uint8 USART_u8SendData 
(
uint8 Copy_u8Data
)
{
	
}
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
uint8 USART_u8RecevieData 
(
uint8 * Copy_u8ReceviedData
)
{
	
}

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
uint8 USART_u8SendStringSynch 
(
const uint8 * Copy_pchString
)
{
	
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
uint8 USART_u8SendStringAsynch 
(
const uint8 * Copy_pchString, 
void (* NotificationFunc)(void)
)
{
	
}
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
uint8 USART_u8ReceiveBufferSynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize
)
{
	
}
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
uint8 USART_u8ReceiveBufferAsynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize, 
void (* NotificationFunc)(void)
)
{
	
}