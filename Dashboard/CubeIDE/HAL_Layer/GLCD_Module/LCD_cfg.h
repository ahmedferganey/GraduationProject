/*
 * LCD_cfg.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed-ferganey
 */

#ifndef GLCD_MODULE_LCD_CFG_H_
#define GLCD_MODULE_LCD_CFG_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include "LCD_interface.h"



extern const LCD_t LCD1;
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LCD_4_BIT_MODE     4
#define LCD_16_4           4


/******************************************************************************
* Configuration Constants
*******************************************************************************/

/**
 * LCD_4_BIT_MODE: For 4 Pins (D4,D5,D6,D7)
 * LCD_8_BIT_MODE: For 8 Pins (D0,D2,D3,D4,D5,D6,D7)
 *
**/
#define LCD_MODE           LCD_4_BIT_MODE

/**
 * LCD_16_2: For 16*2 LCD Character (16 COLOUMN, 2 ROW)
 * LCD_16_4: For 16*4 LCD Character (16 COLOUMN, 4 ROW)
**/
#define LCD_TYPE           LCD_16_4





#endif /* GLCD_MODULE_LCD_CFG_H_ */
