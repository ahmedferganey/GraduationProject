/**
 * @author Ahmed Ferganey
 * @FileName SYS_manager.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-08 20:07:51
 * @modify date 2023-10-08 20:07:51
 * @desc [description]
 */

#ifndef _SYS_MANAGER_H_
#define _SYS_MANAGER_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/


/* -------------------------------- Macro Declarations ------------------------------------------*/


	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/



/* -------------------------------- APIs Declarations ------------------------------------------*/
Std_ReturnType SYS_udtClockInit
(
void
);




#endif  /* _SYS_MANAGER_H_ */
