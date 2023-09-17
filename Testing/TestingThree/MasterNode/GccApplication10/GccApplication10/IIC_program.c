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
/******************************* Init Master & Slave *******************************/

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

/******************************* Start & Stop **************************************/

/********************************************************************************************/
/*  @brief				  : this function uses pooling technique "Sync". @ref port_index_t	*/
/*							to get the result, TimeoutCounter is used						*/
/*  @param	 udtPortIndex : to determine the required port				 @ref port_index_t	*/
/*  @param	 u8Direction  : to Set the required Direction				 @ref uint8			*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/                                                                   
/********************************************************************************************/	
Std_ReturnType IIC_udtSendStartCondition
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*
		The TWINT Flag is set in the following situations:
			• After the TWI has transmitted a START/REPEATED START condition
			• After the TWI has transmitted SLA+R/W
			• After the TWI has transmitted an address byte
			• After the TWI has lost arbitration
			• After the TWI has been addressed by own slave address or general call
			• After the TWI has received a data byte
			• After a STOP or REPEATED START has been received while still 
			  addressed as a slave
			• When a bus error has occurred due to an illegal START or STOP condition
	*/
	
					/******		Page(180) for more details 	  ******/
	
	/* 1- Send start condition*/
		/*
			TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWEN);
		*/
	SET_BIT(TWCR, TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	
	/* 2- wait until the operation finishes and the flag is raised*/
		/*
			while (!(TWCR & (1<<TWINT)));
		*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/* 3- Check the operation status (Bit Masking) */
		/* bit mask 0x1111 1000 */
		/*
			 Bits 7:3 – TWS: TWI Status		
		
		*/
		/*
			These five bits reflect the status of the TWI logic 
			and the Two-wire Serial Bus. The different status codes 
			are described later in this section. Note that the value 
			read from TWSR contains both the 5-bit status value and 
			the 2-bit prescaler value. The application designer should
			mask the prescaler bits to zero when checking the Status
			bits. This makes status checking independent of prescaler 
			setting. This approach is used in this datasheet, unless 
			otherwise noted.
								Page 183
		*/
	if ((TWSR & MASTER_TRANS_MASK) != START_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}
	/*
		TWSTA must be cleared by software when the START condition has been
		transmitted.
		but this process will be executed after sending slave address.
		so, will be cleared in SendSlaveAddress API
					page 195
	*/
	return udtReturnValue;	
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
Std_ReturnType IIC_udtSendRepeatedStart
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/* 1- Send start condition*/
	SET_BIT(TWCR, TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	/* 2- wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/* 3- Check the operation status (Bit Masking) */
	if ((TWSR & MASTER_TRANS_MASK) != REP_START_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}
	
	return udtReturnValue;
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
void IIC_vdSendStopCondition
(
void
)
{
	/*Sent a stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);		
	
	/*Clear the interrupt flag to start the previous operation*/
		/*
			The TWINT Flag must be cleared by software by 
			writing a logic one to it. 
			
			Note that this flag is not automatically cleared 
			by hardware when executing the interrupt routine.
			
			Also note that clearing this flag starts the 
			operation of the TWI, so all accesses to the 
				TWI Address Register (TWAR),
				TWI Status Register (TWSR), 
				and TWI Data Register (TWDR) 
			must be complete before clearing this flag	
		*/
	SET_BIT(TWCR,TWCR_TWINT);	
	
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
Std_ReturnType IIC_udtSendSlaveAddressWrite
(
uint8 Copy_u8SlaveAddress
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/*send the 7bit slave address to the bus*/
	TWDR = (Copy_u8SlaveAddress<<1);

	/*set the write request in the LSB in the data register*/
	CLR_BIT(TWDR, TWDR_SLARW);

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}

	return udtReturnValue;		
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
Std_ReturnType IIC_udtSendSlaveAddressRead
(
uint8 Copy_u8SlaveAddress
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	/*send the 7bit slave address to the bus*/
	TWDR = (Copy_u8SlaveAddress<<1);

	/*set the read request in the LSB in the data register*/
	SET_BIT(TWDR, TWDR_SLARW);

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}

	return udtReturnValue;				
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
Std_ReturnType IIC_MasterWriteDataByte
(
uint8 Copy_u8DataByte
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*Write the data byte on the bus*/
	TWDR = Copy_u8DataByte;	
	
	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);	
	
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);	
	
	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) != MSTR_WR_BYTE_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}
	
	return udtReturnValue;					
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
Std_ReturnType IIC_MasterReadDataByte
(
uint8* pu8DataByte
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);	
	
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);	
	
	/*Check the operation status*/	
	if((TWSR & MASTER_TRANS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/* Read the recieved data */
		*pu8DataByte = TWDR;		
		udtReturnValue = E_OK;
	}	
	
	return udtReturnValue;					
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
Std_ReturnType IIC_SlaveWriteDataByte
(
uint8 Copy_u8DataByte
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*Write the data byte on the bus*/
	TWDR = Copy_u8DataByte;	
	
	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);	
	
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) != SLAVE_BYTE_TRANSMITTED)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		udtReturnValue = E_OK;
	}	
	
	return udtReturnValue;					
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
Std_ReturnType IIC_SlaveReadDataByte
(
uint8* pu8DataByte
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);
	SET_BIT(TWCR,TWCR_TWEN);
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);	
		
	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) !=  SLAVE_ADD_RCVD_WR_REQ)
	{
		udtReturnValue = E_NOT_OK;
	}
	SET_BIT(TWCR,TWCR_TWINT);	
	SET_BIT(TWCR,TWCR_TWEN);
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);
	
	/*Check the operation status*/
	if((TWSR & MASTER_TRANS_MASK) !=  SLAVE_DATA_RECEIVED)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/*Read the received data*/
		*pu8DataByte = TWDR;
		udtReturnValue = E_OK;
	}
	
	return udtReturnValue;					
}
/*------------------------------------------------------------------------------------------*/
