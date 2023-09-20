/*
 * FileName		: GIE_program.c
 * Created		: 8/30/2023 4:34:25 PM
 * Author		: Ahmed Ferganey
 */ 


/* -------------------------------- Includes --------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"

/* -------------------------------- Global Variables --------------------------------*/



/* -------------------------------- APIs Implementation --------------------------------*/
/********************************************************************************************/
/*  @brief	 : This Function used to enable General Interrupt Enable (GIE) 					*/
/*  @param	 : void																			*/  
/*  @return	 : void																			*/                                                                  
/********************************************************************************************/
void GIE_VoidEnable  
(
void
)
{
	SET_BIT (SREG, SREG_I_BIT);
}


/********************************************************************************************/
/*  @brief	 : This Function used to disable General Interrupt Enable (GIE) 				*/
/*  @param	 : void																			*/  
/*  @return	 : void																			*/                                                                  
/********************************************************************************************/
void GIE_VoidDisable 
(
void
)
{
	CLR_BIT (SREG, SREG_I_BIT);	
}
