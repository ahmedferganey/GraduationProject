/**
 * @author Ahmed Ferganey
 * @FileName MOV_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-08 20:06:21
 * @modify date 2023-10-08 20:06:21
 * @desc [description]
 */

/* Comment!: Includes */
/**			LIBRARY Includes			**/			
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/**			SERVICE Includes				**/
#include "MOV_manager.h"


/* -------------------------------- Global variables ------------------------------------------*/





/* -------------------------------- APIs Implementation ------------------------------------------*/
Std_ReturnType MOV_udtMotorInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    udtReturnValue = ServoMotor_udtInit();
    //udtReturnValue = Joystick_Init();
    //udtReturnValue = DCMotor_Controller_Init();

	return udtReturnValue;		
}


