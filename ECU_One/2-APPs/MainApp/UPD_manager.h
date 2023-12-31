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
#include "USART_interface.h"

/**			HAL Includes				**/
#include "SENSOR_manager.h"
#include "DISPLAY_manager.h"


/* -------------------------------- variable Declarations ------------------------------------------*/
extern DISPLAY_Led_t 	  udt_Leds; 			    //must be 4 but for lack of leds, will use 3 pins

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
/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemInput
(
const upd_vehiclemode_t* pudt_currentmode
);
/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemUpadte
(
const upd_vehiclemode_t* pudt_currentmode
);
/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemOutput
(
const upd_vehiclemode_t* pudt_currentmode
);
/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType UPD_udtServoUpadte
(
void
);










#endif  /* _UPD_MANAGER_H_ */

