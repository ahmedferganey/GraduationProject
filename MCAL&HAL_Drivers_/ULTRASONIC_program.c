/*
 * FileName		: ULTRASONIC_program.c
 * Created		: 9/19/2023 7:15:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes --------------------------------------------------------------*/
/**			LIBRARY Includes			**/																								
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"

/**			HAL Includes				**/
#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"



/* -------------------------------- Global Variables ------------------------------------------------------*/


/* -------------------------------- APIs Implementation ---------------------------------------------------*/
/***********************************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 							   */
/*							to stepper motor as output pins												   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
