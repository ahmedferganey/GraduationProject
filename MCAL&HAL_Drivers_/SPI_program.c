/*
 * FileName		: SPI_program.c
 * Created		: 9/16/2023 8:35:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"


/* -------------------------------- Global Variables -----------------------------------*/


/* -------------------------------- APIs Implementation --------------------------------*/
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
Std_ReturnType SPI_u8InitConfig 
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
      