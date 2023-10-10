 /**
 * @author Ahmed Ferganey
 * @FileName DISPLAY_manager.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-09-19 11:19:14
 * @modify date 2023-09-19 11:19:14
 * @desc [description]
 */

#ifndef _DISPLAY_MANAGER_H_
#define _DISPLAY_MANAGER_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/
#include "LCD_interface.h"
#include "ULTRASONIC_interface.h"
#include "LED_interface.h"

/* -------------------------------- Macro Declarations ------------------------------------------*/
#define NUM_OF_LEDS     3


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/          
typedef struct 
{
	LED_t udt_Leds[NUM_OF_LEDS];

}DISPLAY_Led_t; 

/* -------------------------------- APIs Declarations ---------------------------------------*/
Std_ReturnType DISPLAY_udtDiplayInit
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
);

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayStartup
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
);

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayManual
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
);

/// @brief 
/// @param LED_pudtconfig 
/// @param copy_u8NumberOfLeds 
/// @return 
Std_ReturnType DISPLAY_udtDiplayAutonomous
(
const DISPLAY_Led_t* LED_pudtconfig,
uint8 copy_u8NumberOfLeds
);




#endif  /* _DISPLAY_MANAGER_H_ */
