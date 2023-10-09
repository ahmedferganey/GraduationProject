/*
 * FileName		: SERVOMOTOR_program.c
 * Created		: 9/18/2023 3:54:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_interface.h"
#include "TIMER_interface.h"

/**			HAL Includes				**/
#include "SERVOMOTOR_interface.h"
#include "SERVOMOTOR_config.h"
#include "SERVOMOTOR_private.h"



/* -------------------------------- Global Variables ---------------------------------------*/


/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
Std_ReturnType ServoMotor_udtInit
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/* Set servo pin as output pin */
	udtReturnValue = DIO_udtSetPinDirection(SERVOMOTOR_PORT,
										    SERVOMOTOR_PIN, 
										    SERVOMOTOR_DIR_PIN_OUT);
	/* timer1 init */
	TIMER1_vdInit();
	
	TIMER_vdICUInitEnable();
	
	/* to implement duty cycle with 20ms time period (20000*tick_time(==1ms) )	*/
	/*
		The Timer/Counter incorporates an Input Capture unit that can capture 
		external events and give them a timestamp indicating time of occurrence. 
		The external signal indicating an event, or multiple events, can be applied 
		via the ICP1 pin or alternatively, via the Analog Comparator unit. 
		The time-stamps can then be used to calculate frequency, duty-cycle, 
		and other features of the signal applied. Alternatively the time-stamps 
		can be used for creatinga log of the events.
	*/
	
	/* uint32 argument for SETICR1 */
	TIMER1_vdSetICR1(SERVO_MAX);
	
	return udtReturnValue;
}

/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void ServoMotor_vdRotate
(
uint8 SERVOMOTOR_u8Angle,
SERVOMOTOR_t SERVOMOTOR_udtTarget
)
{
    uint16 SERVOMOTOR_u16Time = 0;
    	
	/*
		note: 
				90  deg ----->	300 in OCR at f = 8MHZ, Prescaler = 64  
			    -90 deg ----->	65  in OCR at f = 8MHZ, Prescaler = 64  
		so by interpolation you can calculate any value in between.
	*/
	/* SERVOMOTOR_u16Time is u16 cause value will be in between 300 : 65 */
	SERVOMOTOR_u16Time = ((300 - ((1.305555*(90-(d64)SERVOMOTOR_u8Angle)))));  
		
	
	switch (SERVOMOTOR_udtTarget)
	{
		case ATMEGA32A_PIN4_PORTD_OCR1A:    TIMER1_vdSetCTCA(SERVOMOTOR_u16Time);
					   					     break;
		
		case ATMEGA32A_PIN4_PORTD_OCR1B:	TIMER1_vdSetCTCB(SERVOMOTOR_u16Time);	
					  					    break;	
					
		default   :    /* Nothing */
					  					    break;
	}

}

