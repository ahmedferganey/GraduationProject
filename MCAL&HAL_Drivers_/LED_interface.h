/*
 * FileName		: LED_interface.h
 * Created		: 9/19/2023 12:51:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/

	
	
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
Std_ReturnType LED_udtInit        
( 
const LED_t* LED_pudtCfg
);


Std_ReturnType LED_udtOn          
( 
const LED_t* LED_pudtCfg
);


Std_ReturnType LED_udtOff         
( 
const LED_t* LED_pudtCfg
);
 
 
Std_ReturnType LED_udtToggle      
( 
const LED_t* LED_pudtCfg
);



#endif  /* _LED_INTERFACE_H_ */