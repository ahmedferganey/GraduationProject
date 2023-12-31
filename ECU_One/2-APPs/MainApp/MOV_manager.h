/**
 * @author Ahmed Ferganey
 * @FileName MOV_manager.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-08 20:07:43
 * @modify date 2023-10-08 20:07:43
 * @desc [description]
 */




#ifndef _MOV_MANAGER_H_
#define _MOV_MANAGER_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/
#include "SERVOMOTOR_interface.h"
#include "DCMOTOR_interface.h"
#include "DCMOTOR_interface.h"
#include "JOYSTICK_interface.h"

/**			SERVICE Includes				**/





/* -------------------------------- Macro Declarations ------------------------------------------*/

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Class Declarations ------------------------------------------*/
Std_ReturnType MOV_udtMotorInit
(
void
);




#endif  /* _MOV_MANAGER_H_ */

