 /**
 * @author Ahmed Ferganey
 * @FileName DISPLAY_manager.cpp
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
#include "ULTRASONIC_interface.h"

/**			SERVICE Includes				**/
#include "DISPLAY_interface.h"

/* -------------------------------- Global Variables ------------------------------------------------------*/





/* -------------------------------- APIs Implementation ---------------------------------------------------*/
/***********************************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 							   */
/*							to stepper motor as output pins												   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType DISPLAY_udtUltrasonicLcdInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
uint8 u8NumOfUltrasonic
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/* 1- Init LCD */
	udtReturnValue = LCD_udt4BitInitialize();
	
	/* 2- Init ULTRASONIC SENSORS */
	for (int i = 0 ; i < u8NumOfUltrasonic ; i++)
	{
		udtReturnValue = Ultrasonic_udtInit(ULTRASONIC_pudtconfig);	
		++ULTRASONIC_pudtconfig;
	}

	/* 3- Init TIMERS & ICU */
		/*
			The Input Capture unit is easy to use in Normal mode. However, observe 
			that the maximum interval between the
			external events must not exceed the resolution of the counter. If the 
			interval between events are too long, the timer
			overflow interrupt or the prescaler must be used to extend the resolution 
			for the capture unit.	
		*/
		/*
			No Prescaler +  Normal Mode + 8MHZ + ICU + Rising ----->  .125 Sec for 1 Tick		
		*/
	TIMER1_vdInit();
	
	
	
	return udtReturnValue;		
}


/***********************************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 							   */
/*							to stepper motor as output pins												   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType DISPLAY_udtUltrasonicDispLcd
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint16 ULTRASONIC_LocalDistance[4]= {0};
	
	uint8 u8Row = ROW1 ;
	uint8 u8Column = COLUMN1 ;
	
	/* ICU */
		/*
			The Input Capture is updated with the counter (TCNT1) value each time an 
			event occurs on the ICP1 pin (or
			optionally on the analog comparator output for Timer/Counter1). The Input Capture 
			can be used for defining the counter TOP value
		*/
	
	for (uint8 i = 0 ; i < 4 ; i++)
	{
		udtReturnValue = Ultrasonic_udtCalculateDistance(ULTRASONIC_pudtconfig, 
														 &ULTRASONIC_LocalDistance[i]);

	/*
		for (uint8 j = 0 ; j < u8NumOfUltrasonic ; j++)
		{

			udtReturnValue = LCD_udtGoTo( , );
		
			udtReturnValue = LCD_udt4BitSendData((uint8)ULTRASONIC_LocalDistance[i]);
		}
	*/
		udtReturnValue = LCD_udtGoTo(u8Row, u8Column);
		
		udtReturnValue = LCD_udtSendNumber(ULTRASONIC_LocalDistance[i]);
			
		u8Column += COLUMN5;		
		++ULTRASONIC_pudtconfig;
	}

	return udtReturnValue;	
	
}
