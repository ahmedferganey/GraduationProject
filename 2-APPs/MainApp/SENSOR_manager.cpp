/**
 * @author Ahmed Ferganey
 * @FileName SENSOR_manager.cpp
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-09 02:35:18
 * @modify date 2023-10-09 02:35:18
 * @desc [description]
 */

/* Comment!: Includes */
/**			SERVICE Includes				**/
#include "SENSOR_manager.hpp"



/*
SENSOR_sonic::udt_UltrasonicOne =
{
	//////////////////////////////////////////////////////////////
	.udt_UltrasonicOne[0].udtTriggerPin.port 	  	= SENSOR_PORTB_INDEX,
	.udt_UltrasonicOne[0].udtTriggerPin.pin 		= SENSOR_DIO_PIN0,
	.udt_UltrasonicOne[0].udtTriggerPin.direction 	= SENSOR_DIO_DIRECTION_OUTPUT,
	.udt_UltrasonicOne[0].udtTriggerPin.logic 		= SENSOR_DIO_LOW,

	.udt_UltrasonicOne[0].udtEchoPin.port 			= SENSOR_PORTD_INDEX,
	.udt_UltrasonicOne[0].udtEchoPin.pin 			= SENSOR_DIO_PIN6,
	.udt_UltrasonicOne[0].udtEchoPin.direction 		= SENSOR_DIO_DIRECTION_INPUT,
	.udt_UltrasonicOne[0].udtEchoPin.logic 			= SENSOR_DIO_LOW,	
	//////////////////////////////////////////////////////////////
	.udt_UltrasonicOne[1].udtTriggerPin.port 		= SENSOR_PORTB_INDEX,
	.udt_UltrasonicOne[1].udtTriggerPin.pin 		= SENSOR_DIO_PIN1,
	.udt_UltrasonicOne[1].udtTriggerPin.direction 	= SENSOR_DIO_DIRECTION_OUTPUT,
	.udt_UltrasonicOne[1].udtTriggerPin.logic	 	= SENSOR_DIO_LOW,
			   
	.udt_UltrasonicOne[1].udtEchoPin.port 			= SENSOR_PORTD_INDEX,
	.udt_UltrasonicOne[1].udtEchoPin.pin 			= SENSOR_DIO_PIN6,
	.udt_UltrasonicOne[1].udtEchoPin.direction 		= SENSOR_DIO_DIRECTION_INPUT,
	.udt_UltrasonicOne[1].udtEchoPin.logic 			= SENSOR_DIO_LOW,	
	//////////////////////////////////////////////////////////////
	.udt_UltrasonicOne[2].udtTriggerPin.port 		= SENSOR_PORTB_INDEX,
	.udt_UltrasonicOne[2].udtTriggerPin.pin 		= SENSOR_DIO_PIN2,
	.udt_UltrasonicOne[2].udtTriggerPin.direction 	= SENSOR_DIO_DIRECTION_OUTPUT,
	.udt_UltrasonicOne[2].udtTriggerPin.logic 		= SENSOR_DIO_LOW,

	.udt_UltrasonicOne[2].udtEchoPin.port 			= SENSOR_PORTD_INDEX,
	.udt_UltrasonicOne[2].udtEchoPin.pin 			= SENSOR_DIO_PIN6,
	.udt_UltrasonicOne[2].udtEchoPin.direction 		= SENSOR_DIO_DIRECTION_INPUT,
	.udt_UltrasonicOne[2].udtEchoPin.logic 			= SENSOR_DIO_LOW,
	//////////////////////////////////////////////////////////////
	.udt_UltrasonicOne[3].udtTriggerPin.port 		= SENSOR_PORTB_INDEX,
	.udt_UltrasonicOne[3].udtTriggerPin.pin 		= SENSOR_DIO_PIN3,
	.udt_UltrasonicOne[3].udtTriggerPin.direction 	= SENSOR_DIO_DIRECTION_OUTPUT,
	.udt_UltrasonicOne[3].udtTriggerPin.logic 		= SENSOR_DIO_LOW,
	
	.udt_UltrasonicOne[3].udtEchoPin.port 			= SENSOR_PORTD_INDEX,
	.udt_UltrasonicOne[3].udtEchoPin.pin 			= SENSOR_DIO_PIN6,
	.udt_UltrasonicOne[3].udtEchoPin.direction 		= SENSOR_DIO_DIRECTION_INPUT,
	.udt_UltrasonicOne[3].udtEchoPin.logic 			= SENSOR_DIO_LOW
	//////////////////////////////////////////////////////////////		
	
};
*/

/* -------------------------------- Classes Implementation ------------------------------------------*/
SENSOR_sonic::~SENSOR_sonic()
{
}


SENSOR_ldr::SENSOR_ldr(/* args */)
{
}

SENSOR_ldr::~SENSOR_ldr()
{
}
