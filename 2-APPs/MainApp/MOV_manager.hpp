/**
 * @author Ahmed Ferganey
 * @FileName MOV_manager.hpp
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


/**			HAL Includes				**/
#include "SERVOMOTOR_interface.h"

/**			SERVICE Includes				**/


/* -------------------------------- Macro Declarations ------------------------------------------*/

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Class Declarations ------------------------------------------*/
class MOV_servo
{
private:
    /* data */
    /*!Comment: private - members cannot be accessed (or viewed) from outside the class */    
    SERVOMOTOR_t udt_ServoOne;
    /* note this is special case for our constructor, being this a singleton design pattern */
    MOV_servo()
    {
        udt_ServoOne = (SERVOMOTOR_t)SERVOMOTOR_PIN;     
    };
public:
    ~MOV_servo();

};











#endif  /* _MOV_MANAGER_H_ */

