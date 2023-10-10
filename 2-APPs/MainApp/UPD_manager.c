/**
 * @author Ahmed Ferganey
 * @FileName UPD_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-09 02:11:28
 * @modify date 2023-10-09 02:11:28
 * @desc [description]
 */

/* Comment!: Includes */
/**			LIBRARY Includes			**/			
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/**			SERVICE Includes				**/
#include "UPD_manager.h"




/* -------------------------------- APIs Implementation ------------------------------------------*/

/*                              Requirments of Servo                        */
	// 	/* timer1 init */
	// 	TIMER1_vdInit();
	// 	
	// 	TIMER_vdICUInitEnable();
	// 	
	// 	/* to implement duty cycle with 20ms time period (20000*tick_time(==1ms) )	*/
	// 	/*
	// 		The Timer/Counter incorporates an Input Capture unit that can capture 
	// 		external events and give them a timestamp indicating time of occurrence. 
	// 		The external signal indicating an event, or multiple events, can be applied 
	// 		via the ICP1 pin or alternatively, via the Analog Comparator unit. 
	// 		The time-stamps can then be used to calculate frequency, duty-cycle, 
	// 		and other features of the signal applied. Alternatively the time-stamps 
	// 		can be used for creatinga log of the events.
	// 	*/
	// 	
	// 	/* uint32 argument for SETICR1 */
	// 	TIMER1_vdSetICR1(SERVO_MAX);
