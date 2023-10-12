/*
 * FileName		: EEPROM_interface.h
 * Created		: 9/16/2023 2:56:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/
Std_ReturnType EEPROM_udtSendDataByte
(
uint16 Copy_u16LocationAddress,
uint8 Copy_u8DataByte
);


Std_ReturnType EEPROM_udtReadDataByte
(
uint16 Copy_u16LocationAddress,
uint8* Local_u8StoreData
);

#endif  /* _EEPROM_INTERFACE_H_ */