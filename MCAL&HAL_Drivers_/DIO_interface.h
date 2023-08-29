/*
 * FileName		: DIO_interface.h
 * Created		: 8/5/2023 9:54:48 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/* Comment!: Includes */
#include "STD_TYPES.h"
#include "DIO_config.h"
#include "DIO_private.h"

/* Comment!: Macro Declarations */
/* !Comment: PORT Directions */
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0x00
// !Comment: PORT Value Options 
#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0x00

/* Comment!: Macro Functions Declarations */

/* Comment!: Data Type Declarations */
typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
}port_index_t;

typedef enum
{
	DIO_LOW = 0,
    DIO_HIGH
}logic_t;

typedef enum
{
    DIO_DIRECTION_INPUT = 0,
    DIO_DIRECTION_OUTPUT	
}direction_t;

typedef enum
{
    DIO_PIN0 = 0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7	
}pin_index_t;


/* !Comment: size of enum not constant, it depends on Processor, 
			 but we know that size of all our register 
			 8bit for DIO registers */
typedef struct{
	uint8 port		: 3;	/* @ref port_index_t */
	uint8 pin		: 3;	/* @ref pin_index_t */
	uint8 direction	: 1;	/* @ref direction_t */
	uint8 logic		: 1;	/* @ref logic_t */
}pin_config_t;


/* Comment!: Function Declarations Start */
	/* Comment!: PINS APIs */
extern Std_ReturnType DIO_udtSetPinDirection
(
port_index_t 	udtPort,
pin_index_t 	udtPin,
direction_t 	udtDirection
);

extern Std_ReturnType DIO_udtSetPinValue
(
port_index_t 	udtPort,
pin_index_t 	udtPin,
logic_t 		udtValue
);

extern Std_ReturnType DIO_udtGetPinValue
(
port_index_t 	udtPort,
pin_index_t 	udtPin,
logic_t* 		pudtValue
);

extern Std_ReturnType DIO_udtTogglePinValue       
(
port_index_t 	udtPort,
pin_index_t 	udtPin                         
);



	/* Comment!: PORT APIs */
extern Std_ReturnType DIO_udtSetPortDirection
(
port_index_t udtPortIndex,
const uint8	 u8Direction
);

extern Std_ReturnType DIO_udtSetPortValue
(
port_index_t udtPortIndex,
const uint8  u8Value
);

extern Std_ReturnType DIO_udtGetPortValue
(
port_index_t udtPortIndex,
uint8* 		 u8tValue
);

