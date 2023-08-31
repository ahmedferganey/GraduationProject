/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"
#define F_CPU 8000000ul
#include <util/delay.h>


pin_config_t ledone = {
	.port		= PORTC_INDEX,
	.pin		= DIO_PIN3,
	.direction	= DIO_DIRECTION_OUTPUT,
	.logic		= DIO_LOW,
	};

void ISRINT2 (void);

int main(void)
{
	DIO_udtSetPinDirection(ledone.port,ledone.pin,ledone.direction);
	DIO_udtSetPinValue(ledone.port,ledone.pin,ledone.logic);
	GIE_VoidEnable();
	EXTI_vdInit();
	
	EXTI_SenseMode_t Sensingmode = EXTI_RISING_MODE;
	EXTI_Request_t Requestid = GICR_INT2;
	
	
	while (1)
	{
		EXTI_udtSetCallBack(ISRINT2, Requestid);
		EXTI_udtSetSignalLatch (Sensingmode, Requestid);		
	}
}


void ISRINT2 (void)
{
	DIO_udtSetPinValue(PORTC_INDEX,DIO_PIN3,DIO_HIGH);
	_delay_ms(2000);
	DIO_udtSetPinValue(PORTC_INDEX,DIO_PIN3,DIO_LOW);
}
