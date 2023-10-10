 /**
 * @author Ahmed Ferganey
 * @FileName DISPLAY_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-09-19 11:18:56
 * @modify date 2023-09-19 11:18:56
 * @desc [description]
 */

/* -------------------------------- Includes --------------------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/
#include "LCD_interface.h"
#include "LED_interface.h"

/**			SERVICE Includes				**/
#include "DISPLAY_manager.h"

/* -------------------------------- Global Variables ------------------------------------------------------*/
/*
    pin_config_t LED_pin;
    LED_active_t LED_connection;
	LED_status_t LED_status;    
*/
volatile LED_t udt_Leds[4] =
{
	//////////////////////////////////////////////////////////////
        /*          Front-Left          */
	udt_Leds[0].LED_pin.port 	  	= LED_PORTC,
	udt_Leds[0].LED_pin.pin 		= LED_PIN2,
	udt_Leds[0].LED_pin.direction 	= LED_OUTPUT,
	udt_Leds[0].LED_pin.logic 		= LED_LOW,

    udt_Leds[0].LED_connection      = LED_ACTIVE_HIGH,
    udt_Leds[0].LED_status          = LED_OFF,
	//////////////////////////////////////////////////////////////
        /*          Back-Left           */
	udt_Leds[1].LED_pin.port 		= LED_PORTC,
	udt_Leds[1].LED_pin.pin 		= LED_PIN7,
	udt_Leds[1].LED_pin.direction 	= LED_OUTPUT,
	udt_Leds[1].LED_pin.logic	 	= LED_LOW,

    udt_Leds[1].LED_connection      = LED_ACTIVE_HIGH,
    udt_Leds[1].LED_status          = LED_OFF,			   
	//////////////////////////////////////////////////////////////
        /*          Front-Right            */
	udt_Leds[2].LED_pin.port 		= LED_PORTD,
	udt_Leds[2].LED_pin.pin 		= LED_PIN3,
	udt_Leds[2].LED_pin.direction 	= LED_OUTPUT,
	udt_Leds[2].LED_pin.logic	 	= LED_LOW,
	
    udt_Leds[2].LED_connection      = LED_ACTIVE_HIGH,
    udt_Leds[2].LED_status          = LED_OFF
	//////////////////////////////////////////////////////////////
        /*          Back-Right            */
	//udt_Leds[2].LED_pin.port 		= LED_PORTD,
	//udt_Leds[2].LED_pin.pin 		= LED_PIN3,
	//udt_Leds[2].LED_pin.direction = LED_OUTPUT,
	//udt_Leds[2].LED_pin.logic	 	= LED_LOW,
	//
    //udt_Leds[0].LED_connection    = LED_ACTIVE_HIGH,
    //udt_Leds[0].LED_status        = LED_OFF,

	//////////////////////////////////////////////////////////////
	
};





/* -------------------------------- APIs Implementation ---------------------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------------*/
Std_ReturnType DISPLAY_udtDiplayInit
(
const LED_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    /* DISPLAY Init Section*/
    udtReturnValue = LCD_udt4BitInitialize();

	for (int i = 0 ; i < copy_u8NumberOfLeds ; i++)
	{
		udtReturnValue = LED_udtInit(LED_pudtconfig);	
		++LED_pudtconfig;
	}

	return udtReturnValue;		
}
