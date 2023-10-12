/*
 * FileName		: AutonomousVehicle..hpp
 * Created		: 8/5/2023 8:37:28 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _APP_H_
#define _APP_H_

/* Comment!: Includes */
#include "DISPLAY_manager.h"
#include "SENSOR_manager.h"
#include "UPD_manager.h"
#include "SYS_manager.h"
#include "MOV_manager.h"

/*************************** Comment!: Macro Declarations ******************************/


/*************************** Comment!: Macro Functions Declarations ********************/


/*************************** Comment!: Data Type Declarations **************************/


/*************************** Comment!: Function Declarations ***************************/
/// @brief 
/// @param  
/// @return 
Std_ReturnType AUTONOMOUSVEHICLE_udtAppInit
(
void
);

/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType AUTONOMOUSVEHICLE_udtAppInput
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType AUTONOMOUSVEHICLE_udtAppUpdate
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType AUTONOMOUSVEHICLE_udtAppOutput
(
void
);

#endif	/* _APP_H_ */