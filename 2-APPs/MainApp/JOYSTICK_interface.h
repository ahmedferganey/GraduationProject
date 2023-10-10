/**
 * @author Ahmed Ferganey
 * FileName JOYSTICK_interface.h
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-10 20:59:52
 * @modify date 2023-10-10 20:59:52
 * @desc [description]
 */



#ifndef _JOYSTICK_INTERFACE_H_
#define _JOYSTICK_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/



/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType JOYSTICK_Init
(
void
);

Std_ReturnType Joystick_Left_Pressed
(
void
);

Std_ReturnType Joystick_Down_Pressed
(
void
);

Std_ReturnType Joystick_Up_Pressed
(
void
);

Std_ReturnType Joystick_Center_Pressed
(
void
);

Std_ReturnType Joystick_Right_Pressed
(
void
);




#endif  /* _JOYSTICK_INTERFACE_H_ */