/*
 * FileName		: STEPMOTOR_program.c
 * Created		: 9/19/2023 12:42:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
/**			LIBRARY Includes			**/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**			MCAL Includes				**/
#include "DIO_Interface.h"

/**			HAL Includes				**/
#include "STEPMOTOR_interface.h"
#include "STEPMOTOR_config.h"
#include "STEPMOTOR_private.h"



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
