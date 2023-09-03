/*
 * FileName		: USART_private.h
 * Created		: 9/3/2023 8:25:41 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_

/*-------------------------------- Includes --------------------------------------------------------*/




/*-------------------------------- Macro Declarations ----------------------------------------------*/
#define USART  	((USART_t*)0x29)			/* point to "UBRRL UCSRB UCSRA UDR"	*/
#define UCSRC  	(*(volatile uint8*)0x40)	/* Access UCSRC	*/
#define UBRRH  	(*(volatile uint8*)0x40)	/* Access UBRRH	*/


#define UCSRA_RXC		7
#define UCSRA_TXC		6
#define UCSRA_UDRE		5
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0


#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0


#define UCSRC_URSEL 	7
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#define UCSRC_UCPOL		0

#define UBRRH_URSEL		7



/*-------------------------------- Macro Functions Declarations ------------------------------------*/



/*-------------------------------- Data Type Declarations ------------------------------------------*/
/*  !Comment:  Registers  Summary  */
typedef struct 
{
	uint8 UBRRL;
	uint8 UCSRB;
	uint8 UCSRA;
	uint8 UDR;	
}USART_t;





/*-------------------------------- Software Interfaces Declarations --------------------------------*/







#endif  /* _USART_PRIVATE_H_ */