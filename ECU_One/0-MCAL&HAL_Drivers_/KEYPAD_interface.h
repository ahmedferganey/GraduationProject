/*
 * FileName		: KEYPAD_interface.h
 * Created		: 8/7/2023 3:31:34 PM
 * Author		: Ahmed Ferganey
 */ 

#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_

/* Comment!: Includes */
#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

/* Comment!: Macro Declarations */


/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */
typedef struct{
	pin_config_t keypad_row_pins[ROW_NUM];
	pin_config_t keypad_columns_pins[COL_NUM];
}keypad_t;

/* Comment!: Function Declarations */
Std_ReturnType KEYPAD_udtInit(const keypad_t * pudtKeypadTarget);
Std_ReturnType KEYPAD_udtGetPressedKey(const keypad_t *pudtKeypadTarget, uint8 *value);


#endif	/* _KEYPAD_INTERFACE_H_ */
