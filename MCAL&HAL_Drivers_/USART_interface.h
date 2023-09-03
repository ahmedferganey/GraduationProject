/*
 * FileName		: USART_interface.h
 * Created		: 9/3/2023 8:27:20 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_


/*-------------------------------- Includes --------------------------------------------------------*/
#include "STD_TYPES.h"


/*-------------------------------- Macro Declarations ----------------------------------------------*/
/* Enable / Disable EUSART Module */

/* Selecting EUSART Working Mode */

/* Baud Rate Generator Asynchronous Speed Mode */

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/

/*-------------------------------- Software Interfaces Declarations --------------------------------*/

void USART_voidInit 
(
void
);

uint8 USART_u8SendData 
(
uint8 Copy_u8Data
);  

uint8 USART_u8RecevieData 
(
uint8 * Copy_u8ReceviedData
);  

uint8 USART_u8SendStringSynch 
(
const uint8 * Copy_pchString
);

uint8 USART_u8SendStringAsynch 
(
const uint8 * Copy_pchString, 
void (* NotificationFunc)(void)
); 

uint8 USART_u8ReceiveBufferSynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize
);

uint8 USART_u8ReceiveBufferAsynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize, 
void (* NotificationFunc)(void)
);

#endif  /* _USART_INTERFACE_H_ */