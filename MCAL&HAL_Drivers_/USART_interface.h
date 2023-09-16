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


/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/

void USART_voidInit 
(
void
);


Std_ReturnType USART_udtSendData 
(
uint8 Copy_u8Data
);  

Std_ReturnType USART_udtRecevieData 
(
uint8 * Copy_u8ReceviedData
);  


/********** synch Mode **********/
uint8 USART_u8SendStringSynch 
(
const uint8 * Copy_pchString
);

uint8 USART_u8ReceiveBufferSynch 
(
uint8 * Copy_pchString, 
uint32 Copy_uint32BufferSize
);


/********** Asynch Mode **********/
Std_ReturnType USART_u8SendBufferAsynch 
(
const uint8 * Copy_pu8TransferdData, 
void (* NotificationFunc)(void)
); 

Std_ReturnType USART_u8ReceiveBufferAsynch 
(
uint8 * Copy_pu8AppBuffer, 
uint16 Copy_u16BufferSize, 
void (* NotificationFunc)(void)
);

#endif  /* _USART_INTERFACE_H_ */