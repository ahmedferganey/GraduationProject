/**
 * @author Ahmed Ferganey
 * @FileName SYS_manager.c
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-08 20:07:47
 * @modify date 2023-10-08 20:07:47
 * @desc [description]
 */


/* Comment!: Includes */
/**			SERVICE Includes				**/
#include "SYS_manager.h"


/* -------------------------------- GLOBAL Variable ------------------------------------------*/









/* -------------------------------- APIs Implementation ------------------------------------------*/
/// @brief 
/// @param  
/// @return 
Std_ReturnType SYS_udtClockIntrerruptInit
(
void    
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    /* CLOCK INIT Section */
    TIMER0_vdInit();
	    /* Init TIMERS & ICU */
	    	/*
	    		The Input Capture unit is easy to use in Normal mode. However, observe 
	    		that the maximum interval between the
	    		external events must not exceed the resolution of the counter. If the 
	    		interval between events are too long, the timer
	    		overflow interrupt or the prescaler must be used to extend the resolution 
	    		for the capture unit.	
	    	*/
	    	/*
	    		No Prescaler +  Normal Mode + 8MHZ + ICU + Rising ----->  .125 Sec for 1 Tick		
	    	*/
	TIMER1_vdInit();
    TIMER2_vdInit();


    /* INTERRUPT INIT Section */
	GIE_VoidEnable();
	EXTI_vdInit();
	
    udtReturnValue= E_OK;

	return udtReturnValue;
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType SYS_udtCommunicationInit
(
void    
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    /* COMMUNICATION INIT Section */
    USART_voidInit();
    udtReturnValue= E_OK;

	return udtReturnValue;
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType SYS_udtCommunicationInput
(
void    
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

    /* COMMUNICATION Input Section */


	return udtReturnValue;
}


/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
/// @return 
Std_ReturnType SYS_udtChangeRequest
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;



	return udtReturnValue;
}
/////////////////////////////////////////////////////////////////////////////////////