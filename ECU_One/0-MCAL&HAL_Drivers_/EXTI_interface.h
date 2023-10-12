/*
 * FileName		: EXTI_interface.h
 * Created		: 8/30/2023 4:40:13 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


/*-------------------------------- Includes --------------------------------*/



/*-------------------------------- Macro Declarations --------------------------------*/
/* !Comment: these macros to enable user to cofigure the application */
#define EXTI_0_Enable 		1
#define EXTI_0_Disable		0
#define EXTI_1_Enable       1
#define EXTI_1_Disable      0
#define EXTI_2_Enable       1
#define EXTI_2_Disable      0

/* !Comment: Sensing modes */
#define EXTI_LOW_MODE		1
#define EXTI_ON_MODE		2
#define EXTI_RISING_MODE	3
#define EXTI_FALLING_MODE	4

/* !Comment: to determine which pointer will be used in ISRs */
#define EXTI_INT0 0
#define EXTI_INT1 1
#define EXTI_INT2 2
/* !Comment: these bit responsible for clearing flag in ISRs */
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7




/*
!Comment: if EXTI_<0,1,2> are enable then will generate INT 
#define EXTI_0_State		1
#define EXTI_1_State        1
#define EXTI_2_State        1
*/

/*-------------------------------- Macro Functions Declarations --------------------------------*/


/*-------------------------------- Data Type Declarations --------------------------------*/
/* !Comment: GICR REG Bits */
typedef enum {
	GICR_INT2=5,		/* INT2: External Interrupt Request 2 Enable*/				
	GICR_INT0,			/* INT0: External Interrupt Request 0 Enable*/
	GICR_INT1			/* INT1: External Interrupt Request 1 Enable*/
}EXTI_Request_t;


/* !Comment: EXTI Sense Control Tehnique */
typedef enum {
	EXTI_LOW_LEVEL=0,   
	EXTI_ON_CHANGE,  
	EXTI_RISING_EDGE, 
	EXTI_FALLING_EDGE
}EXTI_SenseMode_t;



/*-------------------------------- Software Interfaces Declarations --------------------------------*/
void EXTI_vdInit              
( 
void
);

/* !Comment: improvment area where as we will call enum by ref not value to save stack */
Std_ReturnType EXTI_udtDisableInterrupt   
( 
const EXTI_Request_t udtRequest_ID
);
/* !Comment: improvment area where as we will call enum by ref not value to save stack */
Std_ReturnType EXTI_udtDisableInterrupt   
( 
const EXTI_Request_t udtRequest_ID
);

/* !Comment: improvment area where as we will call enum by ref not value to save stack */
Std_ReturnType EXTI_udtSetSignalLatch
(
const EXTI_SenseMode_t udtSenseMode, 
EXTI_Request_t copy_udtRequestID
);

/* !Comment: 2 APIs responsible for getting and clearing flag of EXTI */
void EXTI_vdClearFlag 
(
EXTI_Request_t copy_udtRequestID
);
Std_ReturnType EXTI_vdGetFlag 
(
EXTI_Request_t copy_udtRequestID,
uint8* pu8FlagValue
);

/* !Comment: calling back functions */
Std_ReturnType EXTI_udtSetCallBack
(
void (*Copy_pvdCallBack)(void), 
const EXTI_Request_t copy_udtRequestID 
);





#endif /* _EXTI_INTERFACE_H_ */