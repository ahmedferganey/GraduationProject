/*
 * FileName		: DISPLAY_interface.h
 * Created		: 9/19/2023 11:19:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _DISPLAY_INTERFACE_H_
#define _DISPLAY_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"
#include "TIMER_Interface.h"

/**			HAL Includes				**/
#include "LCD_interface.h"
#include "ULTRASONIC_interface.h"

/* -------------------------------- Macro Declarations ------------------------------------------*/
#define 	DISPLAY_PORTA_INDEX				DIO_PORT_NUMA		
#define 	DISPLAY_PORTB_INDEX				DIO_PORT_NUMB
#define 	DISPLAY_PORTC_INDEX				DIO_PORT_NUMC
#define 	DISPLAY_PORTD_INDEX				DIO_PORT_NUMD
			
#define 	DISPLAY_DIO_PIN0				DIO_PIN_NUM0			
#define 	DISPLAY_DIO_PIN1				DIO_PIN_NUM1
#define 	DISPLAY_DIO_PIN2				DIO_PIN_NUM2
#define 	DISPLAY_DIO_PIN3				DIO_PIN_NUM3
#define 	DISPLAY_DIO_PIN4				DIO_PIN_NUM4
#define 	DISPLAY_DIO_PIN5				DIO_PIN_NUM5
#define 	DISPLAY_DIO_PIN6				DIO_PIN_NUM6
#define 	DISPLAY_DIO_PIN7				DIO_PIN_NUM7


#define 	DISPLAY_DIO_LOW 				DIO_LOW_LOGIC 
#define     DISPLAY_DIO_HIGH                DIO_HIGH_LOGIC
           
           
#define     DISPLAY_DIO_DIRECTION_INPUT     DIO_DIR_INPUT 
#define     DISPLAY_DIO_DIRECTION_OUTPUT    DIO_DIR_OUTPUT
         

#define     DISPLAY_NUM_ULTRSONIC		    4

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef struct 
{
	ULTRASONIC_obj_t udtDispObjs[DISPLAY_NUM_ULTRSONIC];
	/*
	ULTRASONIC_obj_t  udtDispObj1;
	ULTRASONIC_obj_t  udtDispObj2;
	ULTRASONIC_obj_t  udtDispObj3;
	ULTRASONIC_obj_t  udtDispObj4;
	*/
}DISPLAY_t;           

/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType DISPLAY_udtUltrasonicLcdInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
uint8 u8NumOfUltrasonic
);

Std_ReturnType DISPLAY_udtUltrasonicDispLcd
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig
);










#endif  /* _DISPLAY_INTERFACE_H_ */