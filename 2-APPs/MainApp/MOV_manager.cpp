/**
 * @author Ahmed Ferganey
 * @FileName MOV_manager.cpp
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-08 20:06:21
 * @modify date 2023-10-08 20:06:21
 * @desc [description]
 */

/* Comment!: Includes */
/**			LIBRARY Includes			**/			
#include <stdlib.h>																					
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			SERVICE Includes				**/
#include "MOV_manager.hpp"




/* -------------------------------- Classes Implementation ------------------------------------------*/
/*                          Servo Manager                            */ 
MOV_MyServo* MOV_MyServo::MyServo = NULL;

/// @brief constructor
MOV_MyServo::MOV_MyServo()
{
    //MOV_MyServo::ServoMotor_udtInit();
}

/// @brief this method get onle one instance of my class servo
/// @return instance"Myservo" pointer to my class servo
MOV_MyServo* MOV_MyServo::MOVSERVO_pobjGetMyServo()
{

    if (MyServo == 0)
    {
        if (MyServo == 0)
        {
            //error handling
        }
    }

    return MyServo;
}

/// @brief to get access on location of servo pins 
/// @return 
SERVOMOTOR_t MOV_MyServo::MOV_udtGetServoOne()
{
    return udt_ServoOne;
}


/// @brief destructor
MOV_MyServo::~MOV_MyServo()
{

}



