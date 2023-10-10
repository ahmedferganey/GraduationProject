/*
 * FileName		: AutonomousVehicle..c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#define F_CPU 8000000ul
#include "util/delay.h"
#include "AutonomousVehicle..h"

/* Standard Return */
Std_ReturnType udtReturnValue = E_NOT_OK;

/* Global Instances */
extern ULTRASONIC_obj_t udt_Ultrasonic;
extern DISPLAY_Led_t 	udt_Leds; 			//must be 4 but for lack of leds, will use 3 pins

/* Global Pointers */
LED_t* G_pudtptr = (LED_t*)&udt_Leds;


int main(void)
{

//udtReturnValue = AUTONOMOUSVEHICLE_udtAPPInit();

//udtReturnValue = LCD_udt4BitInitialize();
	udtReturnValue = DIO_udtSetPinDirection(PORTC_INDEX, DIO_PIN2, DIO_DIRECTION_OUTPUT);
	udtReturnValue = DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_LOW);

	while (1)
	{
//udtReturnValue = LED_udtToggle(G_pudtptr);
		udtReturnValue = DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_LOW);
		_delay_ms(2000);	
		udtReturnValue = DIO_udtSetPinValue(PORTC_INDEX, DIO_PIN2, DIO_HIGH);
		_delay_ms(2000);	
		
	}
}


Std_ReturnType AUTONOMOUSVEHICLE_udtAPPInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	//udtReturnValue = SENSOR_udtSensorsInit(&udt_Ultrasonic, 1);
	//udtReturnValue = SYS_udtClockInit();
	//udtReturnValue = SYS_udtCommunicationInit();
	udtReturnValue = DISPLAY_udtDiplayInit(&udt_Leds, NUM_OF_LEDS); 
	//udtReturnValue = MOV_udtMotorInit();

	return udtReturnValue;
}