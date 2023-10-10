/**
 * @author Ahmed Ferganey
 * @FileName SENSOR_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-09 02:35:18
 * @modify date 2023-10-09 02:35:18
 * @desc [description]
 */

/* Comment!: Includes */
/**			SERVICE Includes				**/
#include "SENSOR_manager.h"


/* -------------------------------- GLOBAL Variable ------------------------------------------*/
volatile ULTRASONIC_obj_t udt_Ultrasonic =
{
	//////////////////////////////////////////////////////////////
	.udtTriggerPin.port 	  	= SENSOR_PORTA_INDEX,
	.udtTriggerPin.pin 			= SENSOR_DIO_PIN0,
	.udtTriggerPin.direction 	= SENSOR_DIO_DIRECTION_OUTPUT,
	.udtTriggerPin.logic 		= SENSOR_DIO_LOW,
	.udtEchoPin.port 			= SENSOR_PORTD_INDEX,
	.udtEchoPin.pin 			= SENSOR_DIO_PIN6,
	.udtEchoPin.direction 		= SENSOR_DIO_DIRECTION_INPUT,
	.udtEchoPin.logic 			= SENSOR_DIO_LOW,	
	//////////////////////////////////////////////////////////////	
};






/* -------------------------------- APIs Implementation ------------------------------------------*/
Std_ReturnType SENSOR_udtSensorsInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
uint8 u8NumOfUltrasonic
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (!(SENSOR_NUM_ULTRSONIC == u8NumOfUltrasonic))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/* 1- Init ULTRASONIC SENSOR"s" */
		for (int i = 0 ; i < u8NumOfUltrasonic ; i++)
		{
			udtReturnValue = Ultrasonic_udtInit(ULTRASONIC_pudtconfig);	
			++ULTRASONIC_pudtconfig;
		}	
	}

	/* 2- Init LDR SENSOR */
	
	return udtReturnValue;		
}
