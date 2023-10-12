/*
 * FileName		: MasterApp.c
 * Created		: 9/17/2023 4:07:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"



Std_ReturnType IICMasterState =  E_NOT_OK;

int main(void)
{
	
	uint8 num = 0;

	IIC_vdInitMaster(0b01010101);
	GIE_VoidEnable();
	
	while (1)
	{
		_delay_ms(500);
		IICMasterState = IIC_udtSendStartCondition();
		IICMasterState = IIC_udtSendSlaveAddressWrite(0b10101010);
		IICMasterState = IIC_MasterWriteDataByte(num++);	
		IIC_vdSendStopCondition();
	}
}


