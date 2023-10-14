/*
 * LCD_program.c
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed-ferganey
 */

/******************************************************************************
* Includes
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "Std_Types.h"
#include "BIT_MATH.h"
//#include "GPIO_interface.h"
//#include "TMR_Interface.h"
#include "LCD_interface.h"
#include "LCD_cfg.h"
#include "LCD_private.h"






/******************************************************************************
* Function Definitions
*******************************************************************************/
static void HLCD_voidkick(uint8_t Copy_u8Character)
{
   /**
	* Assign Data on the pins of the confg
	* Make pulse to make lcd working
	**/
	for(uint8_t Local_u8Counter = 0;Local_u8Counter < LCD_DATA_PINS;Local_u8Counter++)
	{
		if(Copy_u8Character & (SET << Local_u8Counter))
		{
			HAL_GPIO_WritePin(Static_u8DataPins[Local_u8Counter], HIGH);
		}
		else
		{
			HAL_GPIO_WritePin(Static_u8DataPins[Local_u8Counter], LOW);
		}
	}
   MGPIO_u8SetPinValue(LCD_EN, HIGH);
   TMR_voidSetBusyWait(TIM3, 20);
   MGPIO_u8SetPinValue(LCD_EN, LOW);
   TMR_voidSetBusyWait(TIM3, 20);
}

Std_ReturnType HLCD_u8Init(void)
{
	   /**
		* Config the lcd to start working
		**/
	#if   LCD_MODE == LCD_4_BIT_MODE

	#elif LCD_MODE == LCD_8_BIT_MODE

	#endif

}

Std_ReturnType HLCD_u8CMD(const LCD_t* _cfg, uint8 Copy_u8Command);
{
	   /**
		* Select the register "command || data " in this case command
		* Sent the command
		**/
	   //MGPIO_u8SetPinValue(LCD_RS, LOW);
	   HAL_GPIO_WritePin(_cfg->LCD_port_control_rs, _cfg->LCD_pin_rs, GPIO_PIN_RSET);
	   HLCD_voidkick((Copy_u8Command) >> 4);
	   HLCD_voidkick(Copy_u8Command);
	   TMR_voidSetBusyWait(TIM3, 2000);
}

Std_ReturnType HLCD_u8SetCursor(uint8 Copy_u8Row, uint8 Copy_u8Col)
{

}

Std_ReturnType HLCD_u8ClearSreen(void)
{

}

Std_ReturnType HLCD_u8ClearPiexels(uint8 Cpy_ROW, uint8 Cpy_Initial, uint8 Cpy_End)
{

}

Std_ReturnType HLCD_u8TurnOffDisplay(void)
{

}

Std_ReturnType HLCD_u8WriteChar(uint8 Copy_u8Character)
{

}

Std_ReturnType HLCD_u8WriteString(uint8 * Copy_u8String)
{

}

Std_ReturnType HLCD_u8WriteIntNum(uint8 Copy_u8Number)
{

}

Std_ReturnType HLCD_u8WriteFloatNum(float32 Copy_floatNumber)
{

}

/*************** END OF FUNCTIONS ***************************************************************************/


