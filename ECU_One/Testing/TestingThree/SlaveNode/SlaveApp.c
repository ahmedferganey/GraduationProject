/*
 * FileName		: SlaveApp.c
 * Created		: 9/17/2023 4:05:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */


//#define F_CPU 8000000ul
#include "APP.h"




Std_ReturnType DIO_State 		= E_NOT_OK;
Std_ReturnType IIC_SlaveState 	= E_NOT_OK;
port_index_t   PORT_State 		= PORTA_INDEX;
uint8          DirectionOutput  = 0xff;




int main(void)
{
	
	uint8 Data_Rx;
	
	DIO_State	   = DIO_udtSetPortDirection(PORTA_INDEX, DirectionOutput);
	IIC_vdInitSlave(0b10101010);

	while (1)
	{
		IIC_SlaveState = IIC_SlaveReadDataByte(&Data_Rx);
		DIO_State  	   = DIO_udtSetPortValue(PORTA_INDEX, Data_Rx);
		
	}
}


