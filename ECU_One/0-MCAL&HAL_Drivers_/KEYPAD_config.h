/*
 * FileName		: KEYPAD_config.h
 * Created		: 8/7/2023 3:30:34 PM
 * Author		: Ahmed Ferganey
 */ 

#ifndef _KEYPAD_CONFIG_H_
#define _KEYPAD_CONFIG_H_

/* Comment!: Includes */



/*************** Comment!: Macro Declarations ****************/
/* !Comment: KPD_NO_PRESSED_VALUE : any value which indicated no button pressed */
#define KPD_NO_PRESSED_VALUE  0xFF   
/* Comment!: Example */
/*  must use do while not only back-slash because misra
 *  if (x == 0)
 *		KPD_BUTTONS			---> we didnot use {} becaue one line of code 
 *	else
 *		function();
 */
/*
#define KPD_BUTTONS	do{\	---> but in fact it is multi line of code
						{'1', '2', '3', 'A'},\
						{'4', '5', '6', 'B'},\
						{'7', '8', '9', 'C'},\
						{'*', '0', '#', 'D'}\
						}while(0);
*/
#define KPD_BUTTONS	{\
	{'/', '9', '8', '7'},\
	{'*', '6', '5', '4'},\
	{'-', '3', '2', '1'},\
	{'+', '=', '0', '.'}\
}


#define KEYPAD_PORT		PORTD_INDEX

#define KEYPAD_C0_PIN	DIO_PIN4
#define KEYPAD_C1_PIN	DIO_PIN5
#define KEYPAD_C2_PIN	DIO_PIN6
#define KEYPAD_C3_PIN	DIO_PIN7
#define KEYPAD_R0_PIN	DIO_PIN0
#define KEYPAD_R1_PIN	DIO_PIN1
#define KEYPAD_R2_PIN	DIO_PIN2
#define KEYPAD_R3_PIN	DIO_PIN3

/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _KEYPAD_CONFIG_H_ */
