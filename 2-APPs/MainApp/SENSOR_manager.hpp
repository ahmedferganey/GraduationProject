/**
 * @author Ahmed Ferganey
 * @FileName SENSOR_manager.hpp
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


/**			SERVICE Includes				**/
#include "UPD_manager.hpp"


/* -------------------------------- Macro Declarations ------------------------------------------*/


	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Class Declarations ------------------------------------------*/
class SENSOR_sonic
{
private:
    /* data */
    ULTRASONIC_obj_t udt_UltrasonicOne;
public:
    SENSOR_sonic(/* args */);
    ~SENSOR_sonic();
};


class SENSOR_ldr
{
private:
    /* data */
public:
    SENSOR_ldr(/* args */);
    ~SENSOR_ldr();
};



#endif  /* _SENSOR_MANAGER_H_ */

