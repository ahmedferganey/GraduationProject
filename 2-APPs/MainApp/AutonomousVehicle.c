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
extern ULTRASONIC_obj_t   udt_Ultrasonic;
extern DISPLAY_Led_t 	  udt_Leds; 			    //must be 4 but for lack of leds, will use 3 pins
upd_vehiclemode_t  udt_VehicleMode = 0;				//this value can be 0,1,2 "start, manual, autonomous"

/************** Global Pointers ***************/
LED_t* G_pudtptr = (LED_t*)&udt_Leds;






///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  separeted into 4 sections "init, input, update, output"
/// @param  void
/// @return no meaning for return cause presence of super loop
int main(void)
{
	/* !Comment: Init App System */
	udtReturnValue = AUTONOMOUSVEHICLE_udtAppInit();

	while (1)
	{
	
	/* !Comment: 1- Input App System */
		udtReturnValue = AUTONOMOUSVEHICLE_udtAppInput();

	/* !Comment: 2- Update App System */
		udtReturnValue = AUTONOMOUSVEHICLE_udtAppUpdate();

	/* !Comment: 3- Output App System */
		udtReturnValue = AUTONOMOUSVEHICLE_udtAppOutput();

	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////





/********************************************** APP APIs	**********************************************/
/*******************************  APP Init	************************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtAppInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = SYS_udtCommunicationInit();					//init USART     & Bluetooth  & Buzzer
	udtReturnValue = MOV_udtMotorInit();							//init SERVO     & JOYSTICK   & DC-CONTROLLER
	udtReturnValue = DISPLAY_udtDiplayInit(&udt_Leds, NUM_OF_LEDS); //init LCD 	     & LEDS
	udtReturnValue = SYS_udtClockIntrerruptInit();					//init TIMERS    & GIE & EXTI
	udtReturnValue = SENSOR_udtSensorsInit(&udt_Ultrasonic, 1);		//init ULRASONIC & LDR

	return udtReturnValue;
}
/*******************************  APP Input		********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtAppInput
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = UPD_udtSystemInput(&udt_VehicleMode);

	return udtReturnValue;
}
/*******************************  APP Update	********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtAppUpdate
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = UPD_udtSystemUpadte(&udt_VehicleMode);

	return udtReturnValue;
}
/*******************************  APP Output	********************************/
Std_ReturnType AUTONOMOUSVEHICLE_udtAppOutput
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = UPD_udtSystemOutput(&udt_VehicleMode);

	return udtReturnValue;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////