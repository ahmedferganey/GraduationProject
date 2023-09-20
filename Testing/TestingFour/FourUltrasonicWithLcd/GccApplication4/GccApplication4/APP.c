/*
 * FileName		: APP.c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "APP.h"

DISPLAY_t MY_OBJs =
{
	//////////////////////////////////////////////////////////////
	.udtDispObjs[0].udtTriggerPin.port 	  		= DISPLAY_PORTB_INDEX,
	.udtDispObjs[0].udtTriggerPin.pin 			= DISPLAY_DIO_PIN0,
	.udtDispObjs[0].udtTriggerPin.direction 	= DISPLAY_DIO_DIRECTION_OUTPUT,
	.udtDispObjs[0].udtTriggerPin.logic 		= DISPLAY_DIO_LOW,

	.udtDispObjs[0].udtEchoPin.port 			= DISPLAY_PORTD_INDEX,
	.udtDispObjs[0].udtEchoPin.pin 				= DISPLAY_DIO_PIN6,
	.udtDispObjs[0].udtEchoPin.direction 		= DISPLAY_DIO_DIRECTION_INPUT,
	.udtDispObjs[0].udtEchoPin.logic 			= DISPLAY_DIO_LOW,	
	//////////////////////////////////////////////////////////////
	.udtDispObjs[1].udtTriggerPin.port 			= DISPLAY_PORTB_INDEX,
	.udtDispObjs[1].udtTriggerPin.pin 			= DISPLAY_DIO_PIN1,
	.udtDispObjs[1].udtTriggerPin.direction 	= DISPLAY_DIO_DIRECTION_OUTPUT,
	.udtDispObjs[1].udtTriggerPin.logic	 		= DISPLAY_DIO_LOW,
			   
	.udtDispObjs[1].udtEchoPin.port 			= DISPLAY_PORTD_INDEX,
	.udtDispObjs[1].udtEchoPin.pin 				= DISPLAY_DIO_PIN6,
	.udtDispObjs[1].udtEchoPin.direction 		= DISPLAY_DIO_DIRECTION_INPUT,
	.udtDispObjs[1].udtEchoPin.logic 			= DISPLAY_DIO_LOW,	
	//////////////////////////////////////////////////////////////
	.udtDispObjs[2].udtTriggerPin.port 			= DISPLAY_PORTB_INDEX,
	.udtDispObjs[2].udtTriggerPin.pin 			= DISPLAY_DIO_PIN2,
	.udtDispObjs[2].udtTriggerPin.direction 	= DISPLAY_DIO_DIRECTION_OUTPUT,
	.udtDispObjs[2].udtTriggerPin.logic 		= DISPLAY_DIO_LOW,

	.udtDispObjs[2].udtEchoPin.port 			= DISPLAY_PORTD_INDEX,
	.udtDispObjs[2].udtEchoPin.pin 				= DISPLAY_DIO_PIN6,
	.udtDispObjs[2].udtEchoPin.direction 		= DISPLAY_DIO_DIRECTION_INPUT,
	.udtDispObjs[2].udtEchoPin.logic 			= DISPLAY_DIO_LOW,
	//////////////////////////////////////////////////////////////
	.udtDispObjs[3].udtTriggerPin.port 			= DISPLAY_PORTB_INDEX,
	.udtDispObjs[3].udtTriggerPin.pin 			= DISPLAY_DIO_PIN3,
	.udtDispObjs[3].udtTriggerPin.direction 	= DISPLAY_DIO_DIRECTION_OUTPUT,
	.udtDispObjs[3].udtTriggerPin.logic 		= DISPLAY_DIO_LOW,
	
	.udtDispObjs[3].udtEchoPin.port 			= DISPLAY_PORTD_INDEX,
	.udtDispObjs[3].udtEchoPin.pin 				= DISPLAY_DIO_PIN6,
	.udtDispObjs[3].udtEchoPin.direction 		= DISPLAY_DIO_DIRECTION_INPUT,
	.udtDispObjs[3].udtEchoPin.logic 			= DISPLAY_DIO_LOW
	//////////////////////////////////////////////////////////////		
	
};



ULTRASONIC_obj_t* ptr = &MY_OBJs;
uint8 NumOfUltrasonic = 4;
volatile Std_ReturnType  udtReturnValue = E_NOT_OK;

int main(void)
{

		
	/*
	udtReturnValue = DISPLAY_udtUltrasonicLcdInit(ptr, NumOfUltrasonic);
	*/
			/*
					const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
					uint8 u8NumOfUltrasonic			
			*/


			/*
							distance=UltrasonicReadDistance(&ultrasonic1);
							LCD_Send_String_Pos("                ",2,1);
							LCD_Send_Number_Pos(distance, 2, 1);
							_delay_ms(100);
							distance=UltrasonicReadDistance(&ultrasonic2);
					
							LCD_Send_Number_Pos(distance, 2, 5);
					
							_delay_ms(100);
							distance=UltrasonicReadDistance(&ultrasonic3);
					
							LCD_Send_Number_Pos(distance, 2, 9);
							_delay_ms(100);
			*/

	udtReturnValue = LCD_udt4BitInitialize();
	
	while (1)
	{
		
		udtReturnValue = LCD_udt4BitSendData(80);
		_delay_ms(2000);
		/*
		udtReturnValue = DISPLAY_udtUltrasonicDispLcd(ptr);
		*/
				/*
					const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig				
				*/

	}
}


