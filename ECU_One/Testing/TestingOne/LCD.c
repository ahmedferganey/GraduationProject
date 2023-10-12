/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"
#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	uint8 arrayofchar[]= {"ahmed"};

	LCD_udt4BitInitialize();

    while (1) 
	{
		LCD_udtGoTo(ROW1, COLUMN5);
		LCD_udt4BitPrintString(arrayofchar);
		_delay_ms(7000);
	}
}

