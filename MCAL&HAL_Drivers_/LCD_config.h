/*
 * FileName		: LCD_config.h
 * Created		: 8/6/2023 3:32:29 PM
 * Author		: Ahmed Ferganey
 */


#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/* Comment!: Includes */


/* Comment!: Macro Declarations start */
/* !Comment: Data Pins of LCD */
#define LCD_DATA_PORT        DIO -> PORTA
#define LCD_DATA_DIRECTION   DIO -> DDRA
/* !Comment: Control Pins of LCD */
#define LCD_RS	PORTB_INDEX, DIO_PIN1
#define LCD_RW	PORTB_INDEX, DIO_PIN2
#define LCD_E	PORTB_INDEX, DIO_PIN3
/* !Comment: configuration of LCD Mode */
#define	CONFIG_ENABLE	0x01
#define	CONFIG_DISABLE	0x00
#define	LCD_4_BIT_MODE_CONFIGURATIONS		CONFIG_ENABLE
#define	LCD_8_BIT_MODE_CONFIGURATIONS		CONFIG_DISABLE
/* Comment!: Macro Declarations end */

/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _LCD_CONFIG_H_ */