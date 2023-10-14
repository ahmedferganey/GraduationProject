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

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LCD_4_BIT_MODE     4
#define LCD_8_BIT_MODE     8
#define LCD_16_2           2
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


/**
 * Determine LCD PINS ON YOUR MCU
 **/
#define LCD_RS  PINB0
#define LCD_EN  PINB1
#if LCD_MODE == LCD_8_BIT_MODE
#define LCD_D0
#define LCD_D1
#define LCD_D2
#define LCD_D3
#endif
#define LCD_D4   PINA5
#define LCD_D5   PINA4
#define LCD_D6   PINA3
#define LCD_D7   PINA2



#endif /* GLCD_MODULE_LCD_CFG_H_ */
