/*
 * FileName		: SSD_interface.h
 * Created		: 9/19/2023 12:48:14 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_




/*

		https://www.youtube.com/watch?v=Po9iTF4FGSU

*/

/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
/* SSD Mode */
#define SSD_4PIN_MODE  4
#define SSD_8PIN_MODE  8

#define SSD_PIN0 	  0
#define SSD_PIN1 	  1
#define SSD_PIN2 	  2
#define SSD_PIN3 	  3
#define SSD_PIN4 	  4
#define SSD_PIN5 	  5
#define SSD_PIN6 	  6
#define SSD_PIN7 	  7	
	
/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}SSD_type_t;

typedef struct{
    pin_config_t SSD_pins[SSD_PIN_MODE];
    SSD_type_t SSD_type;
}SSD_t;



/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType SSD_udtInitialize  
( 
const SSD_t* SSD_pudtstructCfg 
);

/*
Std_ReturnType SSD_udtEnable           
( 
const SSD_t* SSD_pudtstructCfg 
);


Std_ReturnType SSD_udtDisable          
( 
const SSD_t* SSD_pudtstructCfg 
);
*/

Std_ReturnType SSD_udtSendData       
( 
const SSD_t* SSD_pudtstructCfg 
uint8 Copy_u8Number 
);


#endif  /* _SSD_INTERFACE_H_ */