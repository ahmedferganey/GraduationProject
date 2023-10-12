/**
 * @author Ahmed Ferganey
 * @FileName SENSOR_manager.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-09 02:35:21
 * @modify date 2023-10-09 02:35:21
 * @desc [description]
 */


#ifndef _SENSOR_MANAGER_H_
#define _SENSOR_MANAGER_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/


/**			HAL Includes				**/
#include "ULTRASONIC_interface.h"

/**			SERVICE Includes				**/


/* -------------------------------- Macro Declarations ------------------------------------------*/
/* 						LCD Macros 						*/
#define 	SENSOR_PORTA_INDEX				DIO_PORT_NUMA		
#define 	SENSOR_PORTB_INDEX				DIO_PORT_NUMB
#define 	SENSOR_PORTC_INDEX				DIO_PORT_NUMC
#define 	SENSOR_PORTD_INDEX				DIO_PORT_NUMD
			
#define 	SENSOR_DIO_PIN0				    DIO_PIN_NUM0			
#define 	SENSOR_DIO_PIN1				    DIO_PIN_NUM1
#define 	SENSOR_DIO_PIN2				    DIO_PIN_NUM2
#define 	SENSOR_DIO_PIN3				    DIO_PIN_NUM3
#define 	SENSOR_DIO_PIN4				    DIO_PIN_NUM4
#define 	SENSOR_DIO_PIN5				    DIO_PIN_NUM5
#define 	SENSOR_DIO_PIN6				    DIO_PIN_NUM6
#define 	SENSOR_DIO_PIN7				    DIO_PIN_NUM7


#define 	SENSOR_DIO_LOW 				    DIO_LOW_LOGIC 
#define     SENSOR_DIO_HIGH                 DIO_HIGH_LOGIC
           
           
#define     SENSOR_DIO_DIRECTION_INPUT      DIO_DIR_INPUT 
#define     SENSOR_DIO_DIRECTION_OUTPUT     DIO_DIR_OUTPUT
         

#define     SENSOR_NUM_ULTRSONIC		    1

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/



/* -------------------------------- Class Declarations ------------------------------------------*/
Std_ReturnType SENSOR_udtSensorsInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig,
uint8 u8NumOfUltrasonic
);


#endif  /* _SENSOR_MANAGER_H_ */

