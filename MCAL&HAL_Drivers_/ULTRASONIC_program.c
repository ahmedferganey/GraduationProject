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
Std_ReturnType Ultrasonic_udtInit
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtobj
)
{

	/*
			The HC­SR04 has 4 pins: VCC, GND, TRIG and ECHO.
				1. VCC is a 5v power supply. This should come from the microcontroller
				2. GND is a ground pin. Attach to ground on the microcontroller.
				3. TRIG should be attached to a GPIO pin that can be set to HIGH
				4. ECHO is a little more difficult. The HC­SR04 outputs 5v, which could destroy
				many microcontroller GPIO pins (the maximum allowed voltage varies). In order
				to step down the voltage use a single resistor or a voltage divider circuit. Once
				again this depends on the specific microcontroller you are using, you will need to
				find out its GPIO maximum voltage and make sure you are below that.
	
	*/

	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	
	if (NULL == ULTRASONIC_pudtconfig)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
	udtReturnValue = DIO_udtSetPinDirection(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_pudtobj->udtTriggerPin.direction
											= ULTRASONIC_TRIG_OUTPUT
											);
	udtReturnValue = DIO_udtSetPinDirection(ULTRASONIC_pudtobj->udtEchoPin.port,
											ULTRASONIC_pudtobj->udtEchoPin.pin,
											ULTRASONIC_pudtobj->udtEchoPin.direction
											= ULTRASONIC_ECHO_INPUT											
											);



	udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
										ULTRASONIC_pudtobj->udtTriggerPin.pin,
										ULTRASONIC_pudtobj->udtTriggerPin.logic
										= ULTRASONIC_TRIG_LOW
										);										
	}
	
	return udtReturnValue;	
}

/***********************************************************************************************************/
/*  @brief				  : This Function initialize the pins which connected 							   */
/*							to stepper motor as output pins												   */
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t				   */
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8						   */
/*  @return	 Std_ReturnType																				   */
/*           (E_OK)		  : The function done successfully												   */
/*           (E_NOT_OK)   : The function has issue to perform this action								   */                                                                   
/***********************************************************************************************************/
Std_ReturnType Ultrasonic_udtCalculateDistance
(
const ULTRASONIC_obj_t* ULTRASONIC_pudtconfig, 
uint16* ULTRASONIC_pu8Distance
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    logic_t EchoPinLogic = DIO_LOW;
	uint16 Timer_Value = 0;
	
	if (NULL == ULTRASONIC_pudtconfig)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
        /* Send Trigger Signal to the Ultrasonic Trigger Pin */
		udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_pudtobj->udtTriggerPin.logic
											= ULTRASONIC_TRIG_HIGH
											);
        __delay_us(10);
		udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_pudtobj->udtTriggerPin.logic
											= ULTRASONIC_TRIG_LOW
											);		
	
        /* Wait the Echo pin to be High */
		while (DIO_LOW == EchoPinLogic)
		{
			udtReturnValue = DIO_udtGetPinValue(ULTRASONIC_pudtobj->udtEchoPin.port,
												ULTRASONIC_pudtobj->udtEchoPin.pin,
												&EchoPinLogic);
		}


        /* Clear Timer0 Ticks -> Already Enabled */
        //ret = Timer0_Write_Value(&timer0_timer_obj, 0);
		
        /* Wait the Echo pin to be Low */
		while (DIO_LOW == EchoPinLogic)
		{
			udtReturnValue = DIO_udtGetPinValue(ULTRASONIC_pudtobj->udtEchoPin.port,
												ULTRASONIC_pudtobj->udtEchoPin.pin,
												&EchoPinLogic);
		}

        /* Read the time */
        //ret = Timer0_Read_Value(&timer0_timer_obj, &Timer_Value);
        
		
		/*
			Now, here we have selected an internal 8 MHz oscillator frequency 
			for ATmega16, 
			with No-presale for timer frequency. Then time to execute 1 instruction 
			is 0.125 us.
	
			So, the timer gets incremented after 0.125 us time elapse.
	
						= 17150 x (TIMER value) x 0.125 x 10^-6 cm
			
						= 0.125 x (TIMER value)/58.30 cm
			
						= (TIMER value) / 466.47 cm
		*/
        /* Calculate the distance */
		*ULTRASONIC_pu8Distance = (uint16)(Timer_Value/58.8f);
		
	}
	
	return udtReturnValue;	
}
