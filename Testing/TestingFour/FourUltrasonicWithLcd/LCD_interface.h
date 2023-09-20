/*
 * FileName		: LCD_interface.h
 * Created		: 8/6/2023 3:31:16 PM
 * Author		: Ahmed Ferganey
 */ 

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

/* Comment!: Includes start */
#define F_CPU 8000000UL
#include "util/delay.h"

#include "STD_TYPES.h"


#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"


/* Comment!: Includes end */



/* Comment!: Macro Declarations start */
/* Comment!: LCD command hex */
#define LCD_CLEAR_DISPLAY								0X01	/* Comment!: CLEAR dISPLAY & SET DDRAM ADDRESS 0 IN ADDRESS COUNTER */
#define LCD_RETURN_HOME									0x02	/* Comment!: SET DDRAM ADDRESS 0 AND RETURN DISPLAY TO ORIGINAL POSITION */
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF					0x04	/* Comment!: Decrement cursor (shift cursor to left) */
#define LCD_ENTRY_MODE_DEC_SHIFT_ON						0x05	/* Comment!: Shift display right */
#define LCD_ENTRY_MODE_INC_SHIFT_OFF					0x06	/* Comment!: Increment cursor (shift cursor to right)*/
#define LCD_ENTRY_MODE_INC_SHIFT_ON						0x07	/* Comment!: Shift display left, when initialize LCD we find on data bus 0x07 by default */
#define LCD_DISPLAY_OFF_CURSOR_OFF						0x08	/* Comment!: Display off, cursor off */
#define LCD_DISPLAY_OFF_UNDERLINE_OFF_CURSOR_ON			0x0A	/* Comment!: Display off, cursor on */
#define LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF			0x0C	/* Comment!: Display on, cursor off */
#define LCD_DISPLAY_ON_CURSOR_BLINKING_OFF				0x0E	/* Comment!: Display on, cursor blinking */
#define LCD_DISPLAY_ON_CURSOR_BLINKING_ON				0x0F	/* Comment!: Display on, cursor blinking */
#define LCD_CURSOR_MOVE_SHIFT_LEFT						0x10	/* Comment!: Shift cursor position to left */
#define LCD_CURSOR_MOVE_SHIFT_RIGHT						0x14	/* Comment!: Shift the cursor position to the right */
#define LCD_DISPLAY_SHIFT_LEFT							0x18	/* Comment!: Shift the entire display to the left */
#define LCD_DISPLAY_SHIFT_RIGHT							0x1C	/* Comment!: Shift the entire display to the right */
#define LCD_FORCE_CURSOR_BEGINNING_FIRST_LINE			0x80	/* Comment!: Force cursor to the beginning ( 1st line) */
#define LCD_FORCE_CURSOR_BEGINNING_SECOND_LINE			0xC0	/* Comment!: Force cursor to the beginning ( 2nd line) */
#define LCD_8BIT_MODE_2_LINE_5_IN_7						0x38	/* Comment!: 2 lines and 5×7 matrix, 8BIT MODE */
#define LCD_4BIT_MODE_2_LINE_5_IN_7						0x28	/* Comment!: 2 lines and 5×7 matrix, 4BIT MODE */
/* Comment!: DDRAM &CGRAM address Command */			
#define LCD_BIT7_SET_DDRAM_ADDRESS	128
#define LCD_START_ADDRESS_COL_TWO	0x40
#define LCD_BIT6_SET_CGRAM_ADDRESS	64
						
/* Comment!: no of rows of LCD */										
#define ROW1 1								
#define ROW2 2								
#define ROW3 3								
#define ROW4 4						
/* Comment!: no of columns of LCD */
#define COLUMN1      0
#define COLUMN2      1
#define COLUMN3      2
#define COLUMN4      3
#define COLUMN5      4
#define COLUMN6      5
#define COLUMN7      6
#define COLUMN8      7
#define COLUMN9      8
#define COLUMN10     9
#define COLUMN11     10
#define COLUMN12     11
#define COLUMN13     12
#define COLUMN14     13
#define COLUMN15     14
#define COLUMN16     15
#define COLUMN17     16
#define COLUMN18     17
#define COLUMN19     18
#define COLUMN20     19
/* Comment!: required location of special character in CGRAM */
#define LOCATION_ONE		0
#define LOCATION_TWO		1
#define LOCATION_THREE		2
#define LOCATION_FOUR		3
#define LOCATION_FIVE		4
#define LOCATION_SIX		5
#define LOCATION_SEVEN		6
#define LOCATION_EIGHT		7
/* Comment!: Macro Declarations end */



/* Comment!: Macro Functions Declarations start */


/* Comment!: Macro Functions Declarations end   */



/* Comment!: Data Type Declarations start */
typedef struct{
	pin_config_t lcd_rs;
	pin_config_t lcd_en;	
	pin_config_t lcd_data[4];
}lcd_4Bit_t;

typedef struct{
	pin_config_t lcd_rs;
	pin_config_t lcd_en;
	pin_config_t lcd_data[8];
}lcd_8Bit_t;

/* Comment!: Data Type Declarations end	  */



/* Comment!: Function Declarations End */
extern Std_ReturnType LCD_udt4BitInitialize(void);
extern Std_ReturnType LCD_udt4BitSendCommand(uint8 u8Command);
extern Std_ReturnType LCD_udt4BitSendData(uint8 u8Data);
extern Std_ReturnType LCD_udt4BitPrintString(uint8* pu8Word);
extern Std_ReturnType LCD_udtGoTo(uint8 u8Row, uint8 u8Column);
extern Std_ReturnType LCD_udtCreateSpecialChar (uint8* pu8CharArr, uint8 u8CGRAMLocation, uint8 u8DDRAMRow, uint8 u8DDRAMColumn);
extern Std_ReturnType LCD_udtClearScreen(void);



/* Comment!: Function Declarations End */

#endif	/* _LCD_INTERFACE_H_ */