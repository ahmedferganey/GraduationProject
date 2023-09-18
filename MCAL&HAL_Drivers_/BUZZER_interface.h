/*
 * FileName		: BUZZER_interface.h
 * Created		: 9/18/2023 8:48:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _BUZZER_INTERFACE_H_
#define _BUZZER_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef struct
{	
	pin_config_t BUZZER_info;
}BUZZER_t;


/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType BUZ_udtInit
(
BUZZER_t* BUZZER_pudtBuzzerConfig
);

Std_ReturnType BUZ_udtTurnON
(
BUZZER_t* BUZZER_pudtBuzzerConfig
);

Std_ReturnType BUZ_udtTurnOFF
(
BUZZER_t* BUZZER_pudtBuzzerConfig
);

Std_ReturnType BUZ_udtToggle 
( 
BUZZER_t* BUZZER_pudtBuzzerConfig
);


#endif  /* _BUZZER_INTERFACE_H_ */