/*
 * FileName		: IIC_program.c
 * Created		: 9/16/2023 3:15:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IIC_interface.h"
#include "IIC_config.h"
#include "IIC_private.h"



/* -------------------------------- Global Variables ---------------------------------------*/






/* -------------------------------- APIs Implementation ------------------------------------*/
/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
/*Set master address to 0 if master will not be addressed*/
void IIC_vdInitMaster
(
uint8 Copy_u8Address
)
{
	/*********************************** Setting **************************************/
		/*
			• TWBR = Value of the TWI Bit Rate Register
			• TWPS = Value of the prescaler bits in the TWI Status Register
			• See “Bit Rate Generator Unit” on page 177 for calculating bit rates.
		*/
		/*
			Pull-up resistor values should be selected according to the SCL 
			frequency and the capacitive bus line load. See Table 28-4
			on page 290 for value of pull-up resistor
		*/
		
	/* 1- Set SCL frequency to 400kHz, with 16 Mhz system frequency*/
			/*
				we will use only no prescaler to use this function instead of 
				using the complex equation of datasheat
			
			*/
	TWBR = (uint8) (((CPU_CLOCK_FREQUENCY/SCL_FREQUENCY)-16) / (2*TWI_PRESCALLER));
	


	/* 2- Set the prescaler */
			/*
				TWSR – TWI Status Register 
					Bits 1:0 – TWPS: TWI Prescaler Bits
			*/
			/* Clear the prescaler bits (TWPS) */
	if (TWI_PRESCALLER == PRESCALLER_BY_1)
	{
		TWSR=0;		
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_4)
	{
		TWSR=1;		
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_16) 
	{
		TWSR=2;		
	}
	else if (TWI_PRESCALLER == PRESCALLER_BY_64)
	{
		TWSR=3;		
	}

	/* 3- Check if the master node will be addressed & set the Slave Address */
	if (Copy_u8Address != NULL)
	{
		/*
			The TWAR should be loaded with the 7-bit slave address 
			(in the seven most significant bits of TWAR) to which the
			TWI will respond when programmed as a slave
			transmitter or receiver. In multimaster systems, 
			WAR must be set in masters which can be addressed 
			as slaves by other masters		
		*/
		TWAR = Copy_u8Address<<1;		
	}
	else
	{
		/*Do nothing*/		
	}

	/*********************************** Enable ***************************************/
	/* 1- • Bit 6 – TWEA: TWI Enable Acknowledge Bit */
			/*
				By writing the TWEA bit to zero, 
				the device can be virtually disconnected 
				from the Two-wire Serial Bus temporarily.
				Address recognition can then be resumed by 
				writing the TWEA bit to one again.			
			*/
	SET_BIT(TWCR,TWCR_TWEA);
	
	/* 2- Enable TWI Peripheral*/
			/*
				When TWEN is written to one, the TWI
				takes control over the I/O pins connected 
				to the SCL and SDA pins			
			*/
	SET_BIT(TWCR,TWCR_TWEN);
}

/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/
void IIC_vdInitSlave
(
uint8 Copy_u8Address
)
{
	/*********************************** Setting **************************************/
	/*Set the slave address*/
		/*
			• Bits 7:1 – TWA: TWI (Slave) Address Register 
			These seven bits constitute the slave 
			address of the TWI unit.
		*/
	TWAR = Copy_u8Address<<1;	

	/*********************************** Enable ***************************************/
	/*Enable Acknowledge bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);		
}	
	