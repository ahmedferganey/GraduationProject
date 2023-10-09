/**
 * @author Ahmed Ferganey
 * @FileName UPD_manager.hpp
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
#include "SENSOR_manager.hpp"



/* -------------------------------- Macro Declarations ------------------------------------------*/


	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Class Declarations ------------------------------------------*/
class UPD_SonicDistance {
    protected:
     /// @brief this create pointer to my obj of ultrasonic
     ULTRASONIC_obj_t* pudt_UltrasonicOne;



    public:
     /// @brief consructor
     UPD_SonicDistance()
     {

     }
     /// @brief destructor
     ~UPD_SonicDistance()
     {

     }
};




#endif  /* _UPD_MANAGER_H_ */

