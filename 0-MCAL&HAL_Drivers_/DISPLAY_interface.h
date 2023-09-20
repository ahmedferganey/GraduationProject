/*
 * FileName		: DISPLAY_interface.h
 * Created		: 9/19/2023 11:19:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _DISPLAY_INTERFACE_H_
#define _DISPLAY_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"
#include "TIMER_Interface.h"

/**			HAL Includes				**/
#include "LCD_interface.h"
#include "ULTRASONIC_interface.h"

/* -------------------------------- Macro Declarations ------------------------------------------*/

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType DISPLAY_udtUltrasonicLcdInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
uint8 u8NumOfUltrasonic
);

Std_ReturnType DISPLAY_udtUltrasonicDispLcd
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig
);










#endif  /* _DISPLAY_INTERFACE_H_ */