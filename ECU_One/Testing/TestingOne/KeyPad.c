/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"
#define F_CPU 16000000UL
#include "util/delay.h"



uint8 var = 0;
Std_ReturnType udtReturnValue = E_PENDING;

int main(void)
{
	udtReturnValue = LCD_udt4BitInitialize();
	udtReturnValue = KEYPAD_udtInit(&udtKeypadTarget);
	
	while (1)
	{
		udtReturnValue = KEYPAD_udtGetPressedKey(&udtKeypadTarget, &var);
		while (var == KPD_NO_PRESSED_VALUE)
		{
			var = KEYPAD_udtGetPressedKey(&udtKeypadTarget, &var);
		}
		LCD_udt4BitSendData(var);
	}
}


