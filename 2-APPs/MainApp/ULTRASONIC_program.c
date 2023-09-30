/*
 * FileName		: ULTRASONIC_program.c
 * Created		: 9/19/2023 7:15:56 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes --------------------------------------------------------------*/

/**			HAL Includes				**/
#include "ULTRASONIC_interface.h"




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
	
	
	if (NULL == ULTRASONIC_pudtobj)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
	udtReturnValue = DIO_udtSetPinDirection(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_TRIG_OUTPUT
											);
	udtReturnValue = DIO_udtSetPinDirection(ULTRASONIC_pudtobj->udtEchoPin.port,
											ULTRASONIC_pudtobj->udtEchoPin.pin,
											ULTRASONIC_ECHO_INPUT											
											);



	udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
										ULTRASONIC_pudtobj->udtTriggerPin.pin,
										ULTRASONIC_TRIG_LOW
										);

	udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtEchoPin.port,
										ULTRASONIC_pudtobj->udtEchoPin.pin,
										ULTRASONIC_TRIG_LOW
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
const ULTRASONIC_obj_t* ULTRASONIC_pudtobj, 
uint16* ULTRASONIC_pu16Distance
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
    logic_t EchoPinLogic = DIO_LOW;
	uint16 Timers_u16IcuValue = 0;
	
	if (NULL == ULTRASONIC_pudtobj)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
        /* Send Trigger Signal to the Ultrasonic Trigger Pin */
		udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_TRIG_HIGH
											);
		_delay_us(10);
		udtReturnValue = DIO_udtSetPinValue(ULTRASONIC_pudtobj->udtTriggerPin.port,
											ULTRASONIC_pudtobj->udtTriggerPin.pin,
											ULTRASONIC_TRIG_LOW
											);		
	
        /* Wait the Echo pin to be High */
		while (DIO_LOW == EchoPinLogic)
		{
			udtReturnValue = DIO_udtGetPinValue(ULTRASONIC_pudtobj->udtEchoPin.port,
												ULTRASONIC_pudtobj->udtEchoPin.pin,
												&EchoPinLogic);
		}


        /* Clear Timer1 Ticks TCNT1 */
		TIMER1_vdSetPreload(Timers_u16IcuValue);
		
        /* Wait the Echo pin to be Low */
		while (DIO_HIGH == EchoPinLogic)
		{
			udtReturnValue = DIO_udtGetPinValue(ULTRASONIC_pudtobj->udtEchoPin.port,
												ULTRASONIC_pudtobj->udtEchoPin.pin,
												&EchoPinLogic);
		}

        /* Read the time */
        //ret = Timer0_Read_Value(&timer0_timer_obj, &Timer_Value);
        
		Timers_u16IcuValue = TIMER_u16GetICR();
		
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
		
		/*
		
		
			Calculations to be performed by your Host microcontroller:
			
			Speed of ultrasonic wave is 347 m/s equivalent to 0.0347cm/µsec
			(Temperature dependent)Timer count multiplied with 200nsec (0.2µsec ), 
			internal clock period gives the echo time (say, Et).
			As per the eqn: Speed = distance/time => echo distance 
			(Ed) = echo speed(Ev) *echo time(Et) ie, distance (Ed) = 0.0347cm per µsec (Ev) * Et µsec
			The obtained distance will be twice the actual distance since it gives the to and fro 
			distance of the object as per the to and fro time equated to the equation: 
			(ie, Et stands for 2Et).
			Thus the obtained distance divided by 2 gives actual distance of the obstacle.
			ie, Actual distance = Ed/2.As per the above illustration your equation is,
			
			Ed = Ev *(Et/2) implies Et = 2 * Ed /Ev equivalent to Et = (2/0.0347) *Ed
			Implies Et = 58 *Ed equivalent to Ed (in cm) = Et(in µsec)/58		
	
		*/
		/* https://www.rhydolabz.com/wiki/?p=895 */
		/* 
			distance = time * speed = Timers_u16IcuValue * time of tick us * 34000cm/sec 
									= Timers_u16IcuValue * (0.125 * 10^-6 * 34000)
									= Timers_u16IcuValue * (4.25 * 10^-3)
		*/
		/*
		
			from data sheet 
							distance = time / 58 where where us & 58us/cm
		*/
		
		//*ULTRASONIC_pu8Distance = (uint16)((f32)Timers_u16IcuValue*(4.25f/1000));
		*ULTRASONIC_pu16Distance = (uint16)(((d64)Timers_u16IcuValue*ULTRASONIC_TIME_TICK)/58.3);
		
	}
	
	return udtReturnValue;	
}
