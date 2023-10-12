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
#define NUM_PINS                    3
/* Set JOYSTICK Port*/
#define JOYSTICK_PORTA              PORTA_INDEX
#define JOYSTICK_PORTB              PORTB_INDEX
#define JOYSTICK_PORTC              PORTC_INDEX
#define JOYSTICK_PORTD              PORTD_INDEX

/* Set JOYSTICK Pin*/           
#define JOYSRICK_PIN0               DIO_PIN0
#define JOYSRICK_PIN1               DIO_PIN1
#define JOYSRICK_PIN2               DIO_PIN2
#define JOYSRICK_PIN3               DIO_PIN3
#define JOYSRICK_PIN4               DIO_PIN4
#define JOYSRICK_PIN5               DIO_PIN5
#define JOYSRICK_PIN6               DIO_PIN6
#define JOYSRICK_PIN7               DIO_PIN7

/* Set JOYSTICK Direction*/
#define JOYSTICK_DIRECTION_INPUT    DIO_DIR_INPUT
#define JOYSTICK_DIRECTION_OUTPUT   DIO_DIR_OUTPUT

/* Set JOYSTICK Direction*/
#define JOYSTICK_LOGIC_HIGH         DIO_HIGH_LOGIC
#define JOYSTICK_LOGIC_LOW          DIO_LOW_LOGIC


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef struct
{
    /* data */
    pin_config_t JOYSTICK_pins_t[NUM_PINS];
}JOYSTICK_interface_t;



/* -------------------------------- Function Declarations ---------------------------------------*/
/// @brief 
/// @param  
/// @return 
Std_ReturnType JOYSTICK_Init
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Left_Pressed
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

Std_ReturnType Joystick_Down_Pressed
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Up_Pressed
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Center_Pressed
(
void
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType Joystick_Right_Pressed
(
void
);




#endif  /* _JOYSTICK_INTERFACE_H_ */