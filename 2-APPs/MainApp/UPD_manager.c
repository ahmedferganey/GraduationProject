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
/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemInput
(
upd_vehiclemode_t* pudt_currentmode
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if (pudt_currentmode != NULL)
	{
		/* startup mode */
		if ((UPD_STARTUP_MODE == (*pudt_currentmode)))
		{
			/*  */


		}
		/* manual mode */
		else if((UPD_MANUAL_MODE == (*pudt_currentmode)))
		{

		}
		/* autonomous mode */
		else if((UPD_AUTONOMOUS_MODE == (*pudt_currentmode)))
		{

		}
		/* error handling */
		else
		{
			udtReturnValue = E_NOT_OK;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}

	return udtReturnValue;
}

/////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemUpadte
(
upd_vehiclemode_t* pudt_currentmode
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if (pudt_currentmode != NULL)
	{
		/* startup mode */
		if ((UPD_STARTUP_MODE == (*pudt_currentmode)))
		{

			/* Sleep Mode "Decrease System clock" */



		}
		/* manual mode */
		else if((UPD_MANUAL_MODE == (*pudt_currentmode)))
		{
			/* change clock Mode "increase System clock" */



		}
		/* autonomous mode */
		else if((UPD_AUTONOMOUS_MODE == (*pudt_currentmode)))
		{
			/* change clock Mode "increase System clock" */



		}
		/* error handling */
		else
		{
			udtReturnValue = E_NOT_OK;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}

	return udtReturnValue;


}


/////////////////////////////////////////////////////////////////////////////////////


/// @brief 
/// @param pudt_currentmode 
/// @return 
Std_ReturnType UPD_udtSystemOutput
(
upd_vehiclemode_t* pudt_currentmode
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if (pudt_currentmode != NULL)
	{
		/* startup mode */
		if ((UPD_STARTUP_MODE == (*pudt_currentmode)))
		{
			/* Blink All Leds, Display "select mode" on LCD */
			udtReturnValue = DISPLAY_udtDiplayStartup();
			/* turn off All Motors "servo and DC" */

		}
		/* manual mode */
		else if((UPD_MANUAL_MODE == (*pudt_currentmode)))
		{
			udtReturnValue = DISPLAY_udtDiplayManual();

		}
		/* autonomous mode */
		else if((UPD_AUTONOMOUS_MODE == (*pudt_currentmode)))
		{
			udtReturnValue = DISPLAY_udtDiplayAutonomous();

		}
		/* error handling */
		else
		{
			udtReturnValue = E_NOT_OK;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}

	return udtReturnValue;
}


/////////////////////////////////////////////////////////////////////////////////////


/// @brief 
/// @param  
/// @return 
Std_ReturnType UPD_udtServoUpadte
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;


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






/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/







/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/











/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/











/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/