/*
 * FileName		: SWITCH_interface.h
 * Created		: 9/19/2023 12:03:37 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SWITCH_INTERFACE_H_
#define _SWITCH_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/

/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef enum
{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}SWITCH_state_t;


typedef enum
{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}SWITCH_active_t;


typedef struct
{
    pin_config_t button_pin;
    SWITCH_state_t button_state;
    SWITCH_active_t button_connection;
}SWITCH_t;



/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType SWITCH_udtInitialize
(
const SWITCH_t* SWITCH_pudtBtn
);


Std_ReturnType SWITCH_udtReadState
(
const SWITCH_t* SWITCH_pudtBtn,
SWITCH_state_t* SWITCH_state
);


#endif  /* _SWITCH_INTERFACE_H_ */