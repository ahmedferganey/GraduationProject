 /**
 * @author Ahmed Ferganey
 * @FileName DISPLAY_manager.hpp
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

/* -------------------------------- Macro Declarations ------------------------------------------*/
/* 						LCD Macros 						*/


/* 						LED Macros 						*/

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/          

/* -------------------------------- Function Declarations ---------------------------------------*/


/* -------------------------------- classes Declarations ---------------------------------------*/
/// @brief LCD Class
class DISPLAY_lcd
{
private:
	/// @brief Private constructor
	/**
      * The Singleton's constructor should always be private to prevent direct
      * construction calls with the `new` operator.
      */
	DISPLAY_lcd(/* args */);
	~DISPLAY_lcd();
};









#endif  /* _DISPLAY_MANAGER_H_ */
