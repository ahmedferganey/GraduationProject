/*
 * FileName		: SPI_program.c
 * Created		: 9/16/2023 8:35:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"


/* -------------------------------- Global Variables ---------------------------------------*/
/*Global flag for the SPI Busy State*/
static uint8 SPI_u8State= STD_IDLE;

/* !Comment:  Global Static Variables for Asycnh Function*/
/*Global variable to carry the Transmit Data*/
static uint8* SPI_pu8TData = NULL ;
/*Global variable to carry the Receive Data*/
static uint8* SPI_pu8RData = NULL ;
/*Global variable to carry the buffer size*/
static uint8 SPI_u8BufferSize;
/*Global variable to indicate for the current Data index of the buffer*/
static uint8 SPI_u8Index;
/*Global pointer to function to carry the notification function called by ISR*/
static void (* SPI_PvdNotificationFunc)(void) = NULL ;



/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : Set Complete Port Direction 				@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void SPI_VdInit
(
void
)
{
	/*Data Order*/
	#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
		SET_BIT(SPCR , SPCR_DORD) ;
	#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
		CLR_BIT(SPCR , SPCR_DORD) ;
	#else
		#error "wrong SPI_DATA_ORDER config"
	#endif	
	
	/*Master/Slave Select*/
	#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR) ;
	#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
		CLR_BIT(SPCR , SPCR_MSTR) ;
	#else
		#error "wrong SPI_MASTER_SLAVE_SELECT config"
	#endif	
	
	/*Clock Polarity*/
	#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
		CLR_BIT(SPCR , SPCR_CPOL) ;
	#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
		SET_BIT(SPCR , SPCR_CPOL) ;
	#else
		#error "wrong SPI_CLOCK_POLARITY config"
	#endif	
	
	/*Clock Phase*/
	#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
		CLR_BIT(SPCR , SPCR_CPHA) ;

	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
		SET_BIT(SPCR , SPCR_CPHA) ;
	#else
		#error "wrong SPI_CLOCK_PHASE config"
	#endif

	/*Clock Rate*/
	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
		SET_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#else
		#error "wrong SPI_CLOCK_RATE config"
	#endif

	/*SPI Interrupt Enable*/
	#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR , SPCR_SPIE) ;
	#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR , SPCR_SPIE) ;
	#else
		#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
	#endif

	/*SPI Enable*/
	#if SPI_ENABLE_MODE == SPI_DISABLE
		CLR_BIT(SPCR , SPCR_SPE) ;
	#elif SPI_ENABLE_MODE == SPI_ENABLE
		SET_BIT(SPCR , SPCR_SPE) ;
	#else
		#error "wrong SPI_ENABLE_MODE config"
	#endif	
}

/********************************************************************************************/
/*  @brief				  : Set config in run time "post build" 		@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
/*
	Hint : This Func For Postbuild Config
	
	The Options For The Element Of The Struct :-
	
		$ SPI_u8InterruptEnable :
			1-SPI_INTERRUPT_DISABLE
			2-SPI_INTERRUPT_ENABLE:
			
		$ SPI_u8SPIEnable :
			1-SPI_DISABLE
			2-SPI_ENABLE
			
		$ SPI_u8DataOrder :
			1-SPI_DATA_MSP_FIRST
			2-SPI_DATA_LSB_FIRST
			
		$ SPI_u8MasterSlaveSelect :
			1-SPI_MASTER
			2-SPI_SLAVE
			
		$ SPI_u8ClockPolarity :
			1-SPI_RISING_LEADING_FALLING_TRAILING
			2-SPI_FALLING_LEADING_RISING_TRAILING
			
		$ SPI_u8ClockPhase :
			1-SPI_SAMPLE_LEADING_SETUP_TRAILING
			2-SPI_SETUP_LEADING_SAMPLE_TRAILING
			
		$ SPI_u8ClockRate :
			1-SPI_FREQ_DIVIDED_BY_2
			2-SPI_FREQ_DIVIDED_BY_4
			3-SPI_FREQ_DIVIDED_BY_8
			4-SPI_FREQ_DIVIDED_BY_16
			5-SPI_FREQ_DIVIDED_BY_32
			6-SPI_FREQ_DIVIDED_BY_64
			7-SPI_FREQ_DIVIDED_BY_128		
*/
Std_ReturnType SPI_udtInitConfig 
(
SPI_CONFIG_t* pudtSPINewConfig
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if ((((((((pudtSPINewConfig == NULL) && 
		(pudtSPINewConfig->SPI_u8ClockPhase != NULL)) && 
		(pudtSPINewConfig->SPI_u8ClockPolarity != NULL)) && 
		(pudtSPINewConfig->SPI_u8ClockRate != NULL)) && 
		(pudtSPINewConfig->SPI_u8DataOrder != NULL)) && 
		(pudtSPINewConfig->SPI_u8InterruptEnable != NULL)) && 
		(pudtSPINewConfig->SPI_u8MasterSlaveSelect != NULL)) && 
		(pudtSPINewConfig->SPI_u8SPIEnable != NULL))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/* First new config*/
		switch (pudtSPINewConfig->SPI_u8ClockPhase)
		{
			case SPI_SAMPLE_LEADING_SETUP_TRAILING: CLR_BIT(SPCR , SPCR_CPHA);
													udtReturnValue = E_OK;			
													break;
			case SPI_SETUP_LEADING_SAMPLE_TRAILING: SET_BIT(SPCR , SPCR_CPHA); 
													udtReturnValue = E_OK;			
													break;
			default: 
													udtReturnValue = E_NOT_OK; 
													break;				
		}
	
		/* Second new config*/		
		switch (pudtSPINewConfig->SPI_u8ClockPolarity)
		{
			
			case SPI_RISING_LEADING_FALLING_TRAILING: CLR_BIT(SPCR , SPCR_CPOL) ; 
													  udtReturnValue = E_OK;			
													  break ;
			case SPI_FALLING_LEADING_RISING_TRAILING: SET_BIT(SPCR , SPCR_CPOL) ;
													  udtReturnValue = E_OK;			
													  break ;
			default:								  udtReturnValue = E_NOT_OK ; 
													  break ;				
		}		
				
		/* Third new config*/		
		switch (pudtSPINewConfig->SPI_u8ClockRate)
		{
			case SPI_FREQ_DIVIDED_BY_2:
										CLR_BIT(SPCR , SPCR_SPR0) ;
										CLR_BIT(SPCR , SPCR_SPR1) ;
										SET_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;			
										break ;
			case SPI_FREQ_DIVIDED_BY_4:
										CLR_BIT(SPCR , SPCR_SPR0) ;
										CLR_BIT(SPCR , SPCR_SPR1) ;
										CLR_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;													
										break ;
			case SPI_FREQ_DIVIDED_BY_8:
										SET_BIT(SPCR , SPCR_SPR0) ;
										CLR_BIT(SPCR , SPCR_SPR1) ;
										SET_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;												
										break ;
			case SPI_FREQ_DIVIDED_BY_16:
										SET_BIT(SPCR , SPCR_SPR0) ;
										CLR_BIT(SPCR , SPCR_SPR1) ;
										CLR_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;													
										break ;
			case SPI_FREQ_DIVIDED_BY_32:
										CLR_BIT(SPCR , SPCR_SPR0) ;
										SET_BIT(SPCR , SPCR_SPR1) ;
										SET_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;			
										break ;
			case SPI_FREQ_DIVIDED_BY_64:
										CLR_BIT(SPCR , SPCR_SPR0) ;
										SET_BIT(SPCR , SPCR_SPR1) ;
										CLR_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;			
										break ;
			case SPI_FREQ_DIVIDED_BY_128:
										SET_BIT(SPCR , SPCR_SPR0) ;
										SET_BIT(SPCR , SPCR_SPR1) ;
										CLR_BIT(SPSR , SPSR_SPI2X) ;
									    udtReturnValue = E_OK;			
										break ;
			default:
										udtReturnValue = E_NOT_OK ;
										break ;				
		}		
				
		/* Fourth new config*/		
		switch (pudtSPINewConfig->SPI_u8DataOrder)
		{
			case SPI_DATA_MSP_FIRST: CLR_BIT(SPCR , SPCR_DORD) ; 
									 udtReturnValue = E_OK;						
									 break ;
			case SPI_DATA_LSB_FIRST: SET_BIT(SPCR , SPCR_DORD) ; 
									 udtReturnValue = E_OK;						
									 break ;
			default:				 udtReturnValue = E_NOT_OK ; 
									 break ;						
		}		
				
		/* Fifth new config*/		
		switch (pudtSPINewConfig->SPI_u8MasterSlaveSelect)
		{
			case SPI_MASTER: SET_BIT(SPCR , SPCR_MSTR) ;
							 udtReturnValue = E_OK;						
							 break ;

			case SPI_SLAVE : CLR_BIT(SPCR , SPCR_MSTR) ; 
							 udtReturnValue = E_OK;						
							 break ;
			default:		 udtReturnValue = E_NOT_OK ; 
							 break ;
		}		
				
		/* Sixth new config*/
		switch (pudtSPINewConfig->SPI_u8InterruptEnable)
		{
			case SPI_INTERRUPT_DISABLE: CLR_BIT(SPCR , SPCR_SPIE) ;
										udtReturnValue = E_OK;
										break ;
			case SPI_INTERRUPT_ENABLE:  SET_BIT(SPCR , SPCR_SPIE) ;
										udtReturnValue = E_OK; 
										break ;
			default:		 			udtReturnValue = E_NOT_OK ;
										break ;					
		}		
				
		/* Seventh new config*/
		switch (pudtSPINewConfig->SPI_u8SPIEnable)
		{
			case SPI_DISABLE: CLR_BIT(SPCR , SPCR_SPE) ; 
							  udtReturnValue = E_OK;
							  break ;
			case SPI_ENABLE:  SET_BIT(SPCR , SPCR_SPE) ; 
							  udtReturnValue = E_OK;
							  break ;
			default:		  udtReturnValue = E_NOT_OK ; 
							  break ;						
		}		
	}	
	return udtReturnValue;	
}

/********************************************************************************************/
/*  @brief				  : Set config in run time "post build" 		@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/   
/********************************************************************************************/
Std_ReturnType SPI_udtTranceive 
(
const uint8 Copy_u8TData, 
uint8* Copy_u8RData
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (STD_IDLE == SPI_u8State)
	{
		uint32 Local_uint32TimeoutCounter = 0;
		/* 1- set state of SPI ---> Busy */
		SPI_u8State = STD_ACTIVE;
		
		/* 2- The SPI Data Register is a read/write register used for 
			  data transfer between the Register File and the SPI Shift 
			  Register
			  case in SPI is Transmitter.
		*/
		SPDR = Copy_u8TData;
		
		/* 3- check if flag = 0, refering to completion of transmitting */		
		while(((LOGIC_ZERO == (GET_BIT(SPSR , SPSR_SPIF))) && 
			   (SPI_uint32TIMEOUT > Local_uint32TimeoutCounter)))
		{
			Local_uint32TimeoutCounter++ ;
		}
		if (SPI_uint32TIMEOUT == Local_uint32TimeoutCounter)
		{
			udtReturnValue = E_TIMEOUT ;
		}
		else
		{
		/* 4- Recieveing Data*/
			if (Copy_u8RData != NULL)
			{
				*Copy_u8RData  = SPDR ;
				udtReturnValue = E_OK ;				
			}
			else
			{
				udtReturnValue = E_NOT_OK ;
			}

		}	
		/* 5- To enable the new operation to transmit data by if condition*/
		SPI_u8State = STD_IDLE;
	}
	else
	{
		udtReturnValue = E_PENDING;
	}
	return udtReturnValue;	
}
/********************************************************************************************/
/*  @brief				  : Set config in run time "post build" 		@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/   
/********************************************************************************************/
Std_ReturnType SPI_udtBufferTranceiverSynch 
(
uint8 * Copy_u8TData, 
uint8 * Copy_u8RData, 
uint8 Copy_u8BufferSize
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint8 Local_u8Counter = 0;
	
	if (((Copy_u8TData == NULL) && (Copy_u8RData == NULL)))
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		while (Copy_u8BufferSize > Local_u8Counter)
		{
			/* note, inside this func, we have check on SPI IDLE OR BUSY */
			udtReturnValue = SPI_udtTranceive(Copy_u8TData[Local_u8Counter], 
											  &Copy_u8RData[Local_u8Counter]);
			Local_u8Counter++;
		}		
	}	
	return udtReturnValue;		
}


/********************************************************************************************/
/*  @brief				  : Set config in run time "post build" 		@ref port_index_t	*/
/*  @param	 udtPortIndex : to determine the required port				@ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				@ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/   
/********************************************************************************************/
Std_ReturnType SPI_udtBufferTranceiverAsynch 
(
SPI_Buffer_t* pudtSPIBuffer
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if (STD_IDLE == SPI_u8State)
	{
		if (((((pudtSPIBuffer 				 != NULL) && 
			(pudtSPIBuffer->Copy_u8TData 	 != NULL)) &&
			(pudtSPIBuffer->Copy_u8RData 	 != NULL)) &&
			(pudtSPIBuffer->NotificationFunc != NULL)))
		{
			/* 1- Set SPI is Busy*/
			SPI_u8State = STD_ACTIVE;
			
			/* 2- Assign the SPI data globally*/
			SPI_pu8TData 			= pudtSPIBuffer->Copy_u8TData;	
			SPI_pu8RData 			= pudtSPIBuffer->Copy_u8RData;	
			SPI_u8BufferSize 		= pudtSPIBuffer->Copy_u8BufferSize;
			SPI_PvdNotificationFunc = pudtSPIBuffer->NotificationFunc;
			
			/* 3- Set Index to first element*/
			SPI_u8Index = 0;
	
			/* 4- Transmit first Data */
			SPDR = SPI_pu8TData[SPI_u8Index];
	
			/* 5- SPI Interrupt Enable*/
			/* !Important Comment-1 :
				note after step 5 will context switch to ISR Implementation 
			*/		
			SET_BIT(SPCR , SPCR_SPIE);
			
			/* !Important Comment-6 :	E_OK */	
			udtReturnValue = E_OK;			

		}
		else
		{
			udtReturnValue = E_NOT_OK;			
		}
	}
	else
	{				
		udtReturnValue = E_PENDING;	
	}	
	return udtReturnValue;		
}


/* -------------------------------- ISR Implementation -------------------------------------*/
void __vector_12 (void)		__attribute__ ((signal)) ;
void __vector_12 (void)
{
	/* !Important Comment-2 :
		this area of code is reachable cause the calling from 
		enabling entrrupt from BufferTranceiverAsynch  API 
		where as start to transmit and recieve.
	*/
	
	/* !Important Comment-3 :
		SPDR Register : 
		Writing to the register initiates data transmission. 
		Reading the register causes the Shift Register Receive buffer 
		to be read.
	*/
	
	/* !Important Comment-4 :
		note we wrote before setting interrupt so the transmitting process
		it supposed, it will be completed so we start ISR With Recieving */
	   
	/*Receive Data*/
	SPI_pu8RData[SPI_u8Index] = SPDR;	
	
	/*Increment Data index of the buffer*/
	SPI_u8Index++;
	if (SPI_u8Index == SPI_u8BufferSize)
	{
		/*Buffer Complete*/
		/*SPI is now IDLE*/
		SPI_u8State = IDLE ;
		
		/*SPI Interrupt Disable*/
		CLR_BIT(SPCR , SPCR_SPIE) ;
		/*Call Notification Function*/
		SPI_PvdNotificationFunc() ;
		/* after calling this function and execute it will context
		   to SPI_udtBufferTranceiverAsynch and return E_OK */
	}
	else
	{
		/*Buffer not Complete*/
		
		/*Transmit next Data*/
		SPDR = SPI_pu8TData[SPI_u8Index] ;
		/* !Important Comment-5 :
			note at the end of ISR will transmit next data, if and nly if 
			the bufffer still not completed. where is if SPI_u8Index == SPI_u8BufferSize
			will exexute if and will not execute else.
			also, when transmit next data. now interrupt still enable so will execute
			another ISR and start with recieving the new data and increment index
			then if index == buffer will execute if and at the end will disable interrupt
			and make SPI is IDLE.
			and then call back the APP function.
		*/

	}			
}