/*
 * FileName		: TIMER_interface.h
 * Created		: 8/31/2023 1:44:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_


/*-------------------------------- Includes --------------------------------------------------------*/
#include "STD_TYPES.h"

/*-------------------------------- Macro Declarations ----------------------------------------------*/
/* !Comment: array Indexes for array of the global pointer to func for ISR  */
/* !Comment: note that vector # in vector table for timer from 5:12
			 but these macros 0:7 to where as we use these macros as 
			 indexes for array of global pointer not number of ISR */

/* Vector No. of TIMER0 */
#define TIMER0_OVF_VECTOR_ID		11	/* Vector number = 12 */
#define TIMER0_CTC_VECTOR_ID		10   /* Vector number = 11 */
/* Vector No. of TIMER1 */              
#define TIMER1_OVF_VECTOR_ID		9   /* Vector number = 10 */
#define TIMER1_CTCB_VECTOR_ID		8   /* Vector number = 9 */
#define TIMER1_CTCA_VECTOR_ID		7   /* Vector number = 8 */
#define TIMER1_ICU_VECTOR_ID		6   /* Vector number = 7 */
/* Vector No. of TIMER2 */                                  
#define TIMER2_OVF_VECTOR_ID		5   /* Vector number = 6 */
#define TIMER2_CTC_VECTOR_ID		4   /* Vector number = 5 */


/* ICU Macros */
#define	TIMER_u8_ICP_RAISING_EDGE	1	/* change Trigger edge to RAISING */
#define	TIMER_u8_ICP_FALLING_EDGE	0	/* change Trigger edge to FALLING */








/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/
/*------- Timer0 APIs Declerations -------*/
void TIMER0_vdInit
(
void
);
void TIMER0_vdSetPreload 
(
uint8 Copy_u8Preload
);
void TIMER0_vdSetCTC 
(
uint8 Copy_u8CTC
);
uint8 TIMER0_u8GetTimerCounterValue 
(
void
);

/*------- Timer1 APIs Declerations -------*/
void TIMER1_vdInit
(
void
);
void TIMER1_vdSetPreload 
(
uint16 Copy_u16Preload
);
void TIMER1_vdSetCTCA 
(
uint16 Copy_u16CTCA
);
void TIMER1_vdSetCTCB 
(
uint16 Copy_u16CTCB
);
void TIMER1_vdSetICR1 
(
uint16 Copy_u16ICR1
);
uint16 TIMER1_u16GetTimerCounterValue 
(
void
);
/* ICU APIs*/
void TIMER_vdICUInitEnable
(
void
);
Std_ReturnType TIMER_udtICUSetTriggerEdge
(
uint8 Copy_u8Edge
);
void TIMER_vdICUEnableInterrupt
(
void
);
void TIMER_vdICUDisableInterrupt
(
void
);
uint16  TIMER_u16GetICR
(
void
);


/*------- TIMER ISR Declerations -------*/
Std_ReturnType TIMER_udtSetCallBack
(
void (*Copy_pvCallBackFunc)(void), 
uint8 Copy_u8VectorID
);


#endif /* _TIMER_INTERFACE_H_ */