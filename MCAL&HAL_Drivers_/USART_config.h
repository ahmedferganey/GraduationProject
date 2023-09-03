/*
 * FileName		: USART_config.h
 * Created		: 9/3/2023 8:26:32 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _USART_CONFIG_H_
#define _USART_CONFIG_H_
/*-------------------------------- Includes --------------------------------------------------------*/


/*-------------------------------- Macro Declarations ----------------------------------------------*/
/*Set System Frequency*/
#define SYSTEM_FREQUENCY				16000000UL
/*Set Baud Rate*/
#define USART_BAUD_RATE					9600UL
/*Set USART Mode Select:
			ASYNCHRONOUS				SYNCHRONOUS
*/
#define USART_MODE						ASYNCHRONOUS
/*Set System Speed:
			USART_X1			USART_X2  (Double Speed Mode)
*/
#define USART_SYSTEM_SPEED				USART_X1
/*Set Parity Mode:
			DISABLE		EVEN_PARITY		ODD_PARITY
*/
#define USART_PARITY_MODE				DISABLE
/*Set Stop bit:
			STOP_BIT_1			STOP_BIT_2
*/
#define USART_STOP_BIT					STOP_BIT_1
/*Set Data Size:
  DATA_SIZE_5_BIT		DATA_SIZE_6_BIT			DATA_SIZE_7_BIT		
  DATA_SIZE_8_BIT		DATA_SIZE_9_BIT
*/
#define USART_DATA_SIZE					DATA_SIZE_8_BIT

/*Set Clock Polarity (for SYNCHRONOUS mode only):
 XCK_RISING_TX_XCH_FALLING_RX				XCK_RISING_RX_XCH_FALLING_TX
*/
#define USART_CLOCK_POLARITY			XCK_RISING_TX_XCH_FALLING_RX

/*Set RX Complete Interrupt Enable
			DISABLE        ENABLE 
*/
#define USART_RX_COMPLETE_INTERRUPT		DISABLE

/*Set TX Complete Interrupt Enable
			DISABLE         ENABLE
*/
#define USART_TX_COMPLETE_INTERRUPT		DISABLE

/*Set UDR Empty Interrupt Enable
			DISABLE     ENABLE
*/
#define USART_UDR_EMPTY_INTERRUPT		DISABLE

/*Set Receiver Enable
			DISABLE    ENABLE
*/
#define USART_RECEIVER_ENABLE			ENABLE

/*Set Transmitter Enable
			DISABLE       ENABLE
*/
#define USART_TRANSMITTER_ENABLE		ENABLE

/*Set Multi-Processor Communication mode
		DISABLE				ENABLE
*/
#define USART_MPCM						DISABLE











/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/

/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif  /* _USART_CONFIG_H_ */