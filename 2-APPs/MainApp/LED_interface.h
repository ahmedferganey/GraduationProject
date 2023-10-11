/*
 * FileName		: LED_interface.h
 * Created		: 9/19/2023 12:51:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"

/**			HAL Includes				**/
#include "LED_config.h"
#include "LED_private.h"


/* -------------------------------- Macro Declarations ------------------------------------------*/
// Port Defines
#define  LED_PORTA      0
#define  LED_PORTB      1
#define  LED_PORTC      2
#define  LED_PORTD      3


// PIN Defines
#define LED_PIN0        0
#define LED_PIN1        1
#define LED_PIN2        2
#define LED_PIN3        3
#define LED_PIN4        4
#define LED_PIN5        5
#define LED_PIN6        6
#define LED_PIN7        7
// PIN Direction
#define LED_OUTPUT      1
#define LED_INPUT       0

// PIN state
#define LED_HIGH        1
#define LED_LOW         0
	
	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef enum
{
    LED_ACTIVE_LOW,
    LED_ACTIVE_HIGH
}LED_active_t;

/* for future to get logic */
typedef enum
{
    LED_OFF,
    LED_ON
}LED_status_t;

typedef struct
{
    pin_config_t LED_pin;
    LED_active_t LED_connection;
	LED_status_t LED_status;
}LED_t;


/* -------------------------------- Function Declarations ---------------------------------------*/
/// @brief 
/// @param LED_pudtCfg 
/// @return 
Std_ReturnType LED_udtInit        
( 
const LED_t* LED_pudtCfg
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtCfg 
/// @return 
Std_ReturnType LED_udtOn          
( 
const LED_t* LED_pudtCfg
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtCfg 
/// @return 
Std_ReturnType LED_udtOff         
( 
const LED_t* LED_pudtCfg
);


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param LED_pudtCfg 
/// @return 
Std_ReturnType LED_udtToggle      
( 
const LED_t* LED_pudtCfg
);



#endif  /* _LED_INTERFACE_H_ */