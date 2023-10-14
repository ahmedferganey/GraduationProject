/*
 * LCD_interface.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed-ferganey
 */

#ifndef GLCD_MODULE_LCD_INTERFACE_H_
#define GLCD_MODULE_LCD_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "Std_Types.h"




/******************************************************************************
* Function Prototypes
*******************************************************************************/
Std_ReturnType HLCD_u8Init(void);
Std_ReturnType HLCD_u8CMD(uint8 Copy_u8Command);
Std_ReturnType HLCD_u8SetCursor(uint8 Copy_u8Row, uint8 Copy_u8Col);
Std_ReturnType HLCD_u8ClearPiexels(uint8 Cpy_ROW, uint8 Cpy_Initial, uint8 Cpy_End);
Std_ReturnType HLCD_u8ClearSreen(void);
Std_ReturnType HLCD_u8TurnOffDisplay(void);
Std_ReturnType HLCD_u8WriteChar(uint8 Copy_u8Character);
Std_ReturnType HLCD_u8WriteString(uint8 * Copy_u8String);
Std_ReturnType HLCD_u8WriteIntNum(uint8 Copy_u8Number);
Std_ReturnType HLCD_u8WriteFloatNum(float32 Copy_floatNumber);

#endif /* GLCD_MODULE_LCD_INTERFACE_H_ */
