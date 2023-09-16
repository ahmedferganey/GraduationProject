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
void EEPROM_voidSendDataByte
(
uint16 Copy_u16LocationAddress, 
uint8 Copy_u8DataByte
);


uint8 EEPROM_u8ReadDataByte
(
uint16 Copy_u16LocationAddress
);

#endif  /* _EEPROM_INTERFACE_H_ */