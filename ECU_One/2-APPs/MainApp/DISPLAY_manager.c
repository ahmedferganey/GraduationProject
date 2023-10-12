 /**
 * @author Ahmed Ferganey
 * @FileName DISPLAY_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-09-19 11:18:56
 * @modify date 2023-09-19 11:18:56
 * @desc [description]
 */

/* -------------------------------- Includes --------------------------------------------------------------*/
/**			SERVICE Includes				**/
#include "DISPLAY_manager.h"

/* -------------------------------- Global Variables ------------------------------------------------------*/
static uint8 g_StartMode[8]  = "Startup";
static uint8 g_ManualMode[7] = "Manual";
static uint8 g_AutoMode[5]   = "Auto";

/*
    pin_config_t LED_pin;
    LED_active_t LED_connection;
	LED_status_t LED_status;    
*/
volatile DISPLAY_Led_t udt_Leds =
{
	//////////////////////////////////////////////////////////////
        /*          Front-Left          */
	.udt_Leds[0].LED_pin.port 	  	= LED_PORTC,
	.udt_Leds[0].LED_pin.pin 		= LED_PIN2,
	.udt_Leds[0].LED_pin.direction 	= LED_OUTPUT,
	.udt_Leds[0].LED_pin.logic 		= LED_LOW,

    .udt_Leds[0].LED_connection      = LED_ACTIVE_HIGH,
    .udt_Leds[0].LED_status          = LED_OFF,
	//////////////////////////////////////////////////////////////
        /*          Back-Left           */
	.udt_Leds[1].LED_pin.port 		= LED_PORTC,
	.udt_Leds[1].LED_pin.pin 		= LED_PIN7,
	.udt_Leds[1].LED_pin.direction 	= LED_OUTPUT,
	.udt_Leds[1].LED_pin.logic	 	= LED_LOW,

    .udt_Leds[1].LED_connection      = LED_ACTIVE_HIGH,
    .udt_Leds[1].LED_status          = LED_OFF,			   
	//////////////////////////////////////////////////////////////
        /*          Front-Right            */
	.udt_Leds[2].LED_pin.port 		= LED_PORTD,
	.udt_Leds[2].LED_pin.pin 		= LED_PIN3,
	.udt_Leds[2].LED_pin.direction 	= LED_OUTPUT,
	.udt_Leds[2].LED_pin.logic	 	= LED_LOW,
	
    .udt_Leds[2].LED_connection      = LED_ACTIVE_HIGH,
    .udt_Leds[2].LED_status          = LED_OFF
	//////////////////////////////////////////////////////////////
        /*          Back-Right            */
	//udt_Leds[3].LED_pin.port 		= LED_PORTD,
	//udt_Leds[3].LED_pin.pin 		= LED_PIN3,
	//udt_Leds[3].LED_pin.direction = LED_OUTPUT,
	//udt_Leds[3].LED_pin.logic	 	= LED_LOW,
	//
    //udt_Leds[3].LED_connection    = LED_ACTIVE_HIGH,
    //udt_Leds[3].LED_status        = LED_OFF,

	//////////////////////////////////////////////////////////////
	
};





/* -------------------------------- APIs Implementation ---------------------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------------*/
/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayInit
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    LED_t* L_pudtptr = (LED_t*)LED_pudtconfig;

	if (((NULL != LED_pudtconfig) && (NULL != L_pudtptr)))
	{
    	/* DISPLAY Init Section*/
    	udtReturnValue = LCD_udt4BitInitialize();

		for (int i = 0 ; i < copy_u8NumberOfLeds ; i++)
		{
			udtReturnValue = LED_udtInit(L_pudtptr);	
			++L_pudtptr;
		}		
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}

	return udtReturnValue;		
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayStartup
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    LED_t* L_pudtptr = (LED_t*)LED_pudtconfig;

	if (((NULL != LED_pudtconfig) && (NULL != L_pudtptr)))
	{
    	/* DISPLAY Startup Section*/
			/* LCD */
    	udtReturnValue = LCD_udtClearScreen();
    	udtReturnValue = LCD_udt4BitPrintString(g_StartMode);
    	udtReturnValue = LCD_udtGoTo(ROW2, COLUMN1);
															//here for ultrasonic

			/* LED */
		for (int i = 0 ; i < copy_u8NumberOfLeds ; i++)
		{
			udtReturnValue = LED_udtToggle(L_pudtptr);	
			++L_pudtptr;
		}
		_delay_ms(200);

	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;		
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayManual
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    LED_t* L_pudtptr = (LED_t*)LED_pudtconfig;
	
	if (((NULL != LED_pudtconfig) && (NULL != L_pudtptr)))
	{
    	/* DISPLAY Manual Section*/
			/* LCD */
    	udtReturnValue = LCD_udtClearScreen();
    	udtReturnValue = LCD_udt4BitPrintString(g_ManualMode);
    	udtReturnValue = LCD_udtGoTo(ROW2, COLUMN1);
															//here for ultrasonic

			/* LED */

		
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;		
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayAutonomous
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    LED_t* L_pudtptr = (LED_t*)LED_pudtconfig;
	
	if (((NULL != LED_pudtconfig) && (NULL != L_pudtptr)))
	{
    	/* DISPLAY Autonomous Section*/
			/* LCD */
    	udtReturnValue = LCD_udtClearScreen();
    	udtReturnValue = LCD_udt4BitPrintString(g_AutoMode);
    	udtReturnValue = LCD_udtGoTo(ROW2, COLUMN1);
															//here for ultrasonic
		
			/* LED */

	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;	
}
