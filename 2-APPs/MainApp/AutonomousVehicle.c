/*
 * FileName		: AutonomousVehicle..c
 * Created		: 8/5/2023 8:31:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "AutonomousVehicle..h"


Std_ReturnType udtReturnValue = E_NOT_OK;
extern ULTRASONIC_obj_t udt_Ultrasonic;
extern LED_t udt_Leds[3]; //must be 4 but for lack of leds, will use 3 pins


int main(void)
{

	udtReturnValue = AUTONOMOUSVEHICLE_udtAPPInit();

	while (1)
	{
		
		
		

	}
}


Std_ReturnType AUTONOMOUSVEHICLE_udtAPPInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = SENSOR_udtSensorsInit(&udt_Ultrasonic, 1);
	udtReturnValue = SYS_udtClockInit();
	udtReturnValue = SYS_udtCommunicationInit();
	udtReturnValue = DISPLAY_udtDiplayInit();
	udtReturnValue = MOV_udtMotorInit();

	return udtReturnValue;
}