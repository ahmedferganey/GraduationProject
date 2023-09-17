/*
 * FileName		: IIC_interface.h
 * Created		: 9/16/2023 3:16:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _IIC_INTERFACE_H_
#define _IIC_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/
/******************************* Init Master & Slave *******************************/
void IIC_vdInitMaster
(
uint8 Copy_u8Address
);

void IIC_vdInitSlave
(
uint8 Copy_u8Address
);


/******************************* Start & Stop **************************************/
Std_ReturnType IIC_udtSendStartCondition
(
void
);

Std_ReturnType IIC_udtSendRepeatedStart
(
void
);

void IIC_vdSendStopCondition
(
void
);


/******************************* Slave Address (R/W) *******************************/
Std_ReturnType IIC_udtSendSlaveAddressWrite
(
uint8 Copy_u8SlaveAddress
);

Std_ReturnType IIC_udtSendSlaveAddressRead
(
uint8 Copy_u8SlaveAddress
);




#endif  /* _IIC_INTERFACE_H_ */