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


/***************************************************************************************/
/*

  Options:-
 	 1-DIO_PORT_NUMA
 	 2-DIO_PORT_NUMB
 	 3-DIO_PORT_NUMC
 	 4-DIO_PORT_NUMD
 */
/***************************************************************************************/
#define CLCD_DATA_PORT      DIO_PORT_NUMA
/* RS,RW,EN */
#define CLCD_CONTROL_PORT   DIO_PORT_NUMC




/***************************************************************************************/
/*

 Options:-
 	 1-DIO_PIN_NUM0
 	 2-DIO_PIN_NUM1
 	 3-DIO_PIN_NUM2
 	 4-DIO_PIN_NUM3
 	 5-DIO_PIN_NUM4
 	 6-DIO_PIN_NUM5
 	 7-DIO_PIN_NUM6
 	 8-DIO_PIN_NUM7
*/
#define CLCD_RS             DIO_PIN_NUM5
#define CLCD_RW             DIO_PIN_NUM6
#define CLCD_EN             DIO_PIN_NUM7

#define CLCD_D4             DIO_PIN_NUM4
#define CLCD_D5             DIO_PIN_NUM5
#define CLCD_D6             DIO_PIN_NUM6
#define CLCD_D7             DIO_PIN_NUM7




/***************************************************************************************/

/* Comment!: Macro Declarations end */

/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _LCD_CONFIG_H_ */