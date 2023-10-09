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
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/
#include "SERVOMOTOR_interface.h"
#include "SERVOMOTOR_config.h"
#include "SERVOMOTOR_private.h"

/**			SERVICE Includes				**/





/* -------------------------------- Macro Declarations ------------------------------------------*/

	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Class Declarations ------------------------------------------*/
class MOV_MyServo
{
private:
    /*!Comment: private - members cannot be accessed (or viewed) from outside the class */    
    static MOV_MyServo *MyServo;
    /* note this is special case for our constructor, being this a singleton design pattern */
    MOV_MyServo();

public:
    SERVOMOTOR_t udt_ServoOne;        
    static MOV_MyServo* MOVSERVO_pobjGetMyServo(); // static pointer to method to get access to my class in app layer witout creating more than obj
    SERVOMOTOR_t MOV_udtGetServoOne();
    ~MOV_MyServo();
};











#endif  /* _MOV_MANAGER_H_ */

