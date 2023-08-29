/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"
#define F_CPU 16000000UL
#include "util/delay.h"


uint8 arrayofarabicOne[8] = {0b00110,0b00100,0b01100,0b00000,0b00100,0b00100,0b00100,0b00000};
uint8 arrayofarabicTwo[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11100, 0b00010, 0b11110, 0b00000};
uint8 arrayofarabicThree[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b01110};
uint8 arrayofarabicFour[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00100, 0b00100, 0b11111, 0b00000};
	
int main(void)
{
	Std_ReturnType volatile udtReturnValue = E_NOT_OK;
	LCD_udt4BitInitialize();

    while (1) 
	{
				udtReturnValue = LCD_udtCreateSpecialChar(arrayofarabicOne, LOCATION_ONE, ROW1, COLUMN16);
				udtReturnValue = LCD_udtCreateSpecialChar(arrayofarabicTwo, LOCATION_TWO, ROW1, COLUMN15);
				udtReturnValue = LCD_udtCreateSpecialChar(arrayofarabicThree, LOCATION_THREE, ROW1, COLUMN14);
				udtReturnValue = LCD_udtCreateSpecialChar(arrayofarabicFour, LOCATION_FOUR, ROW1, COLUMN13);
				_delay_ms(2500);

	}
}

