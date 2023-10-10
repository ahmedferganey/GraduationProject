/*
 * FileName		: AutonomousVehicle..c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#define F_CPU 8000000ul
#include "util/delay.h"
#include "AutonomousVehicle..h"

/************** Std_ReturnType ****************/
Std_ReturnType udtReturnValue = E_NOT_OK;

/************** Global Instances **************/
extern ULTRASONIC_obj_t udt_Ultrasonic;
extern DISPLAY_Led_t 	udt_Leds; 					//must be 4 but for lack of leds, will use 3 pins

/************** Global Pointers ***************/
LED_t* G_pudtptr = (LED_t*)&udt_Leds;


int main(void)
{
	/* !Comment: Init App System */
	udtReturnValue = AUTONOMOUSVEHICLE_udtAppInit();

	while (1)
	{
	
	/* !Comment: 1- Input App System */

	/* !Comment: 2- Update App System */

	/* !Comment: 3- Output App System */

	}
}



/********************************************** APP APIs	**********************************************/
/*******************************  APP Init	*******************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtAppInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = SENSOR_udtSensorsInit(&udt_Ultrasonic, 1);
	udtReturnValue = SYS_udtClockIntrerruptInit();
	udtReturnValue = SYS_udtCommunicationInit();
	udtReturnValue = DISPLAY_udtDiplayInit(&udt_Leds, NUM_OF_LEDS); 
	udtReturnValue = MOV_udtMotorInit();

	return udtReturnValue;
}
/*******************************  APP Input		********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtUpdate
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	return udtReturnValue;
}
/*******************************  APP Update	********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtUpdate
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	return udtReturnValue;
}
/*******************************  APP Output	********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtUpdate
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	return udtReturnValue;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////