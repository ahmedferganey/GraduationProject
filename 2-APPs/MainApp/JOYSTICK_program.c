/**
 * @author Ahmed Ferganey
 * FileName JOYSTICK_program.c 
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-10 20:59:56
 * @modify date 2023-10-10 20:59:56
 * @desc [description]
 */


/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"

/**			HAL Includes				**/
#include "JOYSTICK_interface.h"





/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/// @brief 
/// @param  
/// @return 
Std_ReturnType JOYSTICK_Init
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = DIO_udtSetPinDirection(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);
	udtReturnValue = DIO_udtSetPinValue(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);
 
	udtReturnValue = DIO_udtSetPinDirection(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);
	udtReturnValue = DIO_udtSetPinValue(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);
 
	udtReturnValue = DIO_udtSetPinDirection(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);
	udtReturnValue = DIO_udtSetPinValue(JOYSTICK_PORTA, JOYSRICK_PIN1, JOYSTICK_DIRECTION_INPUT);

	
	return udtReturnValue;
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Left_Pressed
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	
	return udtReturnValue;	
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Down_Pressed
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	
	return udtReturnValue;	
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Up_Pressed
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	
	return udtReturnValue;	
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Center_Pressed
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	
	return udtReturnValue;	
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Right_Pressed
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;


	return udtReturnValue;		
}
