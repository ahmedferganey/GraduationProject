/**
 * @author Ahmed Ferganey
 * @FileName UPD_manager.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-09 02:11:24
 * @modify date 2023-10-09 02:11:24
 * @desc [description]
 */

#ifndef _UPD_MANAGER_H_
#define _UPD_MANAGER_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/


/**			HAL Includes				**/
#include "SENSOR_manager.h"



/* -------------------------------- Macro Declarations ------------------------------------------*/
#define UPD_STARTUP_MODE            0
#define UPD_MANUAL_MODE             1
#define UPD_AUTONOMOUS_MODE         2	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef enum 
{
STARTUPMODE=0,
MANUALMODE,
AUTONOMOUSMODE,
}upd_vehiclemode_t;

/* -------------------------------- Class Declarations ------------------------------------------*/
Std_ReturnType UPD_udtModeUpadte
(
void
);

Std_ReturnType UPD_udtServoUpadte
(
void
);











#endif  /* _UPD_MANAGER_H_ */

