/*
 * FileName		: IIC_private.h
 * Created		: 9/16/2023 3:14:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _IIC_PRIVATE_H_
#define _IIC_PRIVATE_H_

/* -------------------------------- Includes ----------------------------------------------------*/
/* Register Accessing */
#define TWBR		*((volatile uint8*)0x20)       /*TWI Bit Rate Register*/
#define TWCR		*((volatile uint8*)0x56)	   /*TWI Control Register*/
#define TWSR		*((volatile uint8*)0x21)       /*TWI Status Register*/
#define TWDR 		*((volatile uint8*)0x23)       /*TWI Data Register*/
#define	TWAR		*((volatile uint8*)0x22)       /*TWI Address Register*/


/* Bits Location "R/W" */
#define TWCR_TWINT					7			   /*Interrupt Flag*/
#define TWCR_TWEA					6              /*Enable Acknowledge*/
#define TWCR_TWSTA					5              /*Start Condition*/
#define TWCR_TWSTO					4              /*Stop Condition*/
#define TWCR_TWWC					3              /*Write Collision "Read Only"*/
#define TWCR_TWEN					2              /*Enable*/
#define TWCR_TWIE					0              /*Interrupt Enable*/
												   
#define TWSR_TWPS0					0			   /*Prescaler Bit0*/
#define TWSR_TWPS1					1			   /*Prescaler Bit1*/
												   
#define TWAR_TWGCE					0			   /*General Call recognition Enable*/


/* Prescalers */
#define PRESCALLER_BY_1   		   1
#define PRESCALLER_BY_4   		   4
#define PRESCALLER_BY_16  		   16
#define PRESCALLER_BY_64  		   64


/* Status Codes for Master Transmitter Mode */
#define MASTER_TRANS_MASK		   0xF8
#define START_ACK                  0x08 		   /* start has been sent */
#define REP_START_ACK              0x10 		   /* repeated start */
#define SLAVE_ADD_AND_WR_ACK       0x18 		   /* Master transmit ( slave address + Write request ) ACK */
#define MSTR_WR_BYTE_ACK           0x28 		   /* Master transmit data ACK */










/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/


#endif  /* _IIC_PRIVATE_H_ */