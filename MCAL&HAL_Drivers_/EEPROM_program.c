/*
 * FileName		: EEPROM_program.c
 * Created		: 9/16/2023 2:57:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 16000000UL
#include "util/delay.h"
#include "IIC_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"



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
void EEPROM_vdSendDataByte
(
uint16 Copy_u16LocationAddress,
uint8 Copy_u8DataByte
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | ((uint8)(Copy_u16LocationAddress >>8));
	/*
		if 24C02 :
			Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	*/
	/*
		The 24C08 only uses the A2 input for hardwire addressing 
		and a total of two 8K devices may be addressed on a single 
		bus system. The A0 and A1 pins are no connects and can be 
		connected to ground.	
	*/
	
	/* 1- Send start condition*/
	udtReturnValue = IIC_udtSendStartCondition();
		
	/* 2- Send the address packet*/
	udtReturnValue = IIC_udtSendSlaveAddressWrite(Local_u8AddressPacket);

	/* 3- Send the rest 8bits of the location address*/
	udtReturnValue = IIC_udtSendSlaveAddressWrite((uint8)Copy_u16LocationAddress);

	/* 4- Send the data byte to the memory location*/
	udtReturnValue = IIC_MasterWriteDataByte(Copy_u8DataByte);

	/* 5- Send stop condition*/
	IIC_vdSendStopCondition();

	/* 6- Delay until the write cycle is finished*/
	_delay_ms(10);
	
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
Std_ReturnType EEPROM_udtReadDataByte
(
uint16 Copy_u16LocationAddress,
uint8* Local_u8StoreData
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	uint8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(Copy_u16LocationAddress >>8);

	/* if 24C02 :
	 	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */	
	 
	/* 1- Send start condition*/
	udtReturnValue = IIC_udtSendStartCondition();	
	
	/* 2- Send the address packet with write request */
	udtReturnValue = IIC_udtSendSlaveAddressWrite(Local_u8AddressPacket);

	/* 3- Send the rest 8bits of the location address*/
	udtReturnValue = IIC_udtSendSlaveAddressWrite((uint8)Copy_u16LocationAddress);
	
	/* 4- Send repeated start to change write request into read request*/
	udtReturnValue = IIC_udtSendRepeatedStart();

	/* 5- Send the address packet with read request*/
	udtReturnValue = IIC_udtSendSlaveAddressRead(Local_u8AddressPacket);

	/* 6- Get the data from memory*/
	udtReturnValue = IIC_MasterReadDataByte(Local_u8StoreData);

	/* 7- Send stop condition*/
	IIC_vdSendStopCondition();
		
	return udtReturnValue;
	
}