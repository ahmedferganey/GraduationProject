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
#define LCD_DATA_PORT        				DIO->PORTA
#define LCD_DATA_DIRECTION   				DIO->DDRA
/* !Comment: Control Pins of LCD */
#define LCD_RS								PORTC_INDEX,DIO_PIN5
#define LCD_RW								PORTC_INDEX,DIO_PIN6
#define LCD_E								PORTC_INDEX,DIO_PIN7


/* !Comment: configuration of LCD Mode */
/*
	select: 
			CONFIG_ENABLE			CONFIG_DISABLE	
*/
#define	LCD_4_BIT_MODE_CONFIGURATIONS		CONFIG_ENABLE
#define	LCD_8_BIT_MODE_CONFIGURATIONS		CONFIG_DISABLE



/* Comment!: Macro Declarations end */

/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _LCD_CONFIG_H_ */