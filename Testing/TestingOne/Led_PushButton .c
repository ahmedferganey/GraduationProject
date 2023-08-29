/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"
#include "DIO_interface.h"



/********************************************************************************************/
/*  @brief:																					*/
/*			 this Programm can turn on 3 Leds when and only when you press on button1		*/
/*			 Leds are initilized as output and sensitive to high so it is pull down			*/
/*			 buttons are initilized as input and sensitive to high so it is pull down		*/
/********************************************************************************************/

int main(void)
{
			/* !Comment: INIT of LED0 - LED1 - LED2 */
	DIO_udtSetPinDirection(PORTC_INDEX, DIO_PIN2, DIO_DIRECTION_OUTPUT);
	DIO_udtSetPinDirection(PORTC_INDEX, DIO_PIN7, DIO_DIRECTION_OUTPUT);
	DIO_udtSetPinDirection(PORTD_INDEX, DIO_PIN3, DIO_DIRECTION_OUTPUT);
	DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_LOW);
	DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN7, DIO_LOW);
	DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN3, DIO_LOW);

			/* !Comment: INIT of BUTTON1 */
	uint8 pushButtonValue1;
	DIO_udtSetPinDirection(PORTD_INDEX, DIO_PIN6, DIO_DIRECTION_INPUT);
	DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN6, DIO_LOW);
	  
    while (1) 
    {
		DIO_udtGetPinValue(PORTD_INDEX, DIO_PIN6, &pushButtonValue1);
		if (pushButtonValue1 == DIO_HIGH)
		{
			DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_HIGH);
			DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN7, DIO_HIGH);
			DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN3, DIO_HIGH);
		}
		else
		{
			/* !Comment: this section to make if released button, the leds will turn off */
			DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_LOW);
			DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN7, DIO_LOW);
			DIO_udtSetPinValue(PORTD_INDEX, DIO_PIN3, DIO_LOW);
		}
		
    }
}

