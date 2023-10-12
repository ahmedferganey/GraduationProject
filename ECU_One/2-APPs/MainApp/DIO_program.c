/*
 * FileName		: DIO_program.c
 * Created		: 8/5/2023 9:36:46 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "BIT_MATH.h"


/* Comment!: APIs Implementation */
/********************************************************************************************/
/*  @brief				  : Set Pin Direction of a specific pin			@ref direction_t	*/
/*  @param	 udtPort      : to determine the required port				@ref port_index_t	*/
/*  @param	 udtPin       : to determine the required pin				@ref pin_index_t	*/
/*  @param	 udtDirection : to determine the required direction			@ref direction_t	*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
#if DIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType DIO_udtSetPinDirection
(
	port_index_t 	udtPort,
	pin_index_t 	udtPin,
	direction_t 	udtDirection
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (udtDirection == (DIO_DIRECTION_OUTPUT))
	{
		switch(udtPort)
		{
			case PORTA_INDEX: SET_BIT(DIO->DDRA, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTB_INDEX: SET_BIT(DIO->DDRB, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTC_INDEX: SET_BIT(DIO->DDRC, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTD_INDEX: SET_BIT(DIO->DDRD, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			default:		  /*	!Comment: Do nothing	*/
			                  break;
		}
	}
	else if (udtDirection == (DIO_DIRECTION_INPUT))
	{
		switch(udtPort)
		{
			case PORTA_INDEX: CLR_BIT(DIO->DDRA, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTB_INDEX: CLR_BIT(DIO->DDRB, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTC_INDEX: CLR_BIT(DIO->DDRC, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTD_INDEX: CLR_BIT(DIO->DDRD, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			default:		  /*	!Comment: Do nothing	*/
			                  break;
		}
	}
	else
	{
		/*	!Comment: Do nothing	*/
	}
	return udtReturnValue;
}
#endif

/********************************************************************************************/
/*  @brief				  : Set Pin Value of a specific pin				@ref logic_t		*/
/*  @param	 udtPort      : to determine the required port				@ref port_index_t	*/
/*  @param	 udtPin       : to determine the required pin				@ref pin_index_t	*/
/*  @param	 logic_t	  : to determine the required Logic				@ref logic_t		*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/  
/********************************************************************************************/
#if DIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType DIO_udtSetPinValue
(
	port_index_t 	udtPort,
	pin_index_t 	udtPin,
	logic_t 		udtValue
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (udtValue == DIO_HIGH)
	{
		switch(udtPort)
		{
			case PORTA_INDEX: SET_BIT(DIO->PORTA, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTB_INDEX: SET_BIT(DIO->PORTB, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTC_INDEX: SET_BIT(DIO->PORTC, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			case PORTD_INDEX: SET_BIT(DIO->PORTD, udtPin);
			                  udtReturnValue = E_OK;
			                  break;
			default:          /* !Comment: Do nothing */
			                  break;
		}
		
	}
	else if(udtValue == DIO_LOW)
	{
		switch(udtPort)
		{
			case PORTA_INDEX: CLR_BIT(DIO->PORTA, udtPin);
							  udtReturnValue = E_OK;
							  break;
			case PORTB_INDEX: CLR_BIT(DIO->PORTB, udtPin);
							  udtReturnValue = E_OK;
							  break;
			case PORTC_INDEX: CLR_BIT(DIO->PORTC, udtPin);
						      udtReturnValue = E_OK;
							  break;
			case PORTD_INDEX: CLR_BIT(DIO->PORTD, udtPin);
							  udtReturnValue = E_OK;
							  break;
			default:          /* !Comment: Do nothing */
							  break;
		}
	}
	else
	{
		/* !Comment: Do nothing */
	}
	return udtReturnValue;
}

#endif

/********************************************************************************************/
/*  @brief				  : Get Pin Logic of a specific pin				@ref logic_t*		*/
/*  @param	 udtPort      : to determine the required port				@ref port_index_t	*/
/*  @param	 udtPin       : to determine the required pin				@ref pin_index_t	*/
/*  @param	 pudtValue	  : to return the value							@ref logic_t*		*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
#if DIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType DIO_udtGetPinValue
(
	port_index_t 	udtPort,
	pin_index_t 	udtPin,
	logic_t* 		pudtValue
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	switch(udtPort)
	{
		case PORTA_INDEX: *pudtValue = GET_BIT(DIO->PINA, udtPin);
						  udtReturnValue = E_OK;
						  break;
		case PORTB_INDEX: *pudtValue = GET_BIT(DIO->PINB, udtPin);
						  udtReturnValue = E_OK;
						  break;
		case PORTC_INDEX: *pudtValue = GET_BIT(DIO->PINC, udtPin);
						  udtReturnValue = E_OK;
						  break;
		case PORTD_INDEX: *pudtValue = GET_BIT(DIO->PIND, udtPin);
					      udtReturnValue = E_OK;
					      break;
		default:		  /* !Comment: Do nothing */
					      break;
		
	}
	return udtReturnValue;
}
#endif

/********************************************************************************************/
/*  @brief				  : This Function Toggle the Value of the Pin	@ref logic_t*		*/
/*  @param	 udtPort      : to determine the required port				@ref port_index_t	*/
/*  @param	 udtPin       : to determine the required pin				@ref pin_index_t	*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
#if DIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType DIO_udtTogglePinValue       
(
port_index_t 	udtPort,
pin_index_t 	udtPin                         
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (udtPin <= DIO_PIN7)
	{
		switch (udtPort)
		{
			case PORTA_INDEX: TOG_BIT(DIO->PORTA, udtPin);
							  udtReturnValue = E_OK;
							  break;			
			case PORTB_INDEX: TOG_BIT(DIO->PORTB, udtPin);
							  udtReturnValue = E_OK;
							  break;
			case PORTC_INDEX: TOG_BIT(DIO->PORTC, udtPin);
							  udtReturnValue = E_OK;
							  break;
			case PORTD_INDEX: TOG_BIT(DIO->PORTD, udtPin);
							  udtReturnValue = E_OK;
							  break;
			default:		  /* !Comment: Do nothing */
							  break;
		}
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}		
	return udtReturnValue;
}
#endif
