/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-13 05:18:41
 * @modify date 2023-10-13 05:18:41
 * @desc [description]
 */

#ifndef CAN_INTERFACE_H
#define CAN_INTERFACE_H

/*****************************************************************************************/
/*                                   Include headres                                     */
/*****************************************************************************************/
#include "Std_Types.h"
#include "CAN_Private.h"
#include "CAN_cfg.h"


/******************************************************************************************/
/*                                    Macro Definition                                    */
/*******************************************************************************************/

/************************************************can status**********************************/

#define CAN_InitStatus_Failed             ((uint8)0x00) /* CAN initialization failed */
#define CAN_InitStatus_Success            ((uint8)0x01) /* CAN initialization OK */

/**************************************************can mode *********************************/	

#define CAN_Mode_Normal                   ((uint8)0x00)  /* normal mode */
#define CAN_Mode_LoopBack                 ((uint8)0x01)  /* loopback mode */
#define CAN_Mode_Silent                   ((uint8)0x02)  /* silent mode */
#define CAN_Mode_Silent_LoopBack          ((uint8)0x03)  /* loopback combined with silent mode */

/*********************************************can operating mode******************************/

#define CAN_OperatingMode_Init            ((uint8)0x00) /* Initialization mode */
#define CAN_OperatingMode_Normal          ((uint8)0x01) /* Normal mode */
#define CAN_OperatingMode_Sleep           ((uint8)0x02) /* sleep mode */

/*************************************************can mode input status************************/

#define CAN_ModeStatus_Failed             ((uint8)0x00)                     /* CAN entering the specific mode failed */
#define CAN_ModeStatus_Success            ((uint8)!CAN_ModeStatus_Failed)   /* CAN entering the specific mode Succeed */

/******************************************CAN_synchronisation_jump_width*********************/

#define CAN_SJW_1tq                       ((uint8)0x00)  /* 1 time quantum */
#define CAN_SJW_2tq                       ((uint8)0x01)  /* 2 time quantum */
#define CAN_SJW_3tq                       ((uint8)0x02)  /* 3 time quantum */
#define CAN_SJW_4tq                       ((uint8)0x03)  /* 4 time quantum */
													 
/*****************************************CAN_filter bank scale types**************************/

#define CAN_FilterScale_16bit             ((uint8)0x00) /* Two 16-bit filters */
#define CAN_FilterScale_32bit             ((uint8)0x01) /* One 32-bit filter */

/****************************************************can filer mode****************************/

#define CAN_FilterMode_IdMask            ((uint8)0x00)  /* identifier/mask mode */
#define CAN_FilterMode_IdList            ((uint8)0x01)  /* identifier list mode */

/****************************************************CAN_filter_FIFO**************************/	

#define CAN_Filter_FIFO0             ((uint8)0x00)  /* Filter FIFO 0 assignment for filter x */
#define CAN_Filter_FIFO1             ((uint8)0x01)  /* Filter FIFO 1 assignment for filter x */

/*************************************************CAN transmit_constants***********************/

#define CAN_TxStatus_Failed          ((uint8)0x00) /*  CAN transmission failed */
#define CAN_TxStatus_Ok              ((uint8)0x01) /* CAN transmission succeeded */
#define CAN_TxStatus_Pending         ((uint8)0x02) /* CAN transmission pending */
#define CAN_TxStatus_NoMailBox       ((uint8)0x04) /* CAN cell did not provide an empty mailbox */

/*********************************************CAN receive FIFO numbers***********************/

#define CAN_FIFO0                   ((uint8)0x00) /* CAN FIFO 0 used to receive */
#define CAN_FIFO1                   ((uint8)0x01) /* CAN FIFO 1 used to receive */		

/**********************************************CAN jump width constants *********************/

#define CAN_SJW_1tq                 ((uint8)0x00)  /* 1 time quantum */
#define CAN_SJW_2tq                 ((uint8)0x01)  /* 2 time quantum */
#define CAN_SJW_3tq                 ((uint8)0x02)  /* 3 time quantum */
#define CAN_SJW_4tq                 ((uint8)0x03)  /* 4 time quantum */

/********************************************CAN time quantum in bit segment_1* *****************/
#define CAN_BS1_1tq                 ((uint8)0x00)  /* 1 time quantum */
#define CAN_BS1_2tq                 ((uint8)0x01)  /* 2 time quantum */
#define CAN_BS1_3tq                 ((uint8)0x02)  /* 3 time quantum */
#define CAN_BS1_4tq                 ((uint8)0x03)  /* 4 time quantum */
#define CAN_BS1_5tq                 ((uint8)0x04)  /* 5 time quantum */
#define CAN_BS1_6tq                 ((uint8)0x05)  /* 6 time quantum */
#define CAN_BS1_7tq                 ((uint8)0x06)  /* 7 time quantum */
#define CAN_BS1_8tq                 ((uint8)0x07)  /* 8 time quantum */
#define CAN_BS1_9tq                 ((uint8)0x08)  /* 9 time quantum */
#define CAN_BS1_10tq                ((uint8)0x09)  /* 10 time quantum */
#define CAN_BS1_11tq                ((uint8)0x0A)  /* 11 time quantum */
#define CAN_BS1_12tq                ((uint8)0x0B)  /* 12 time quantum */
#define CAN_BS1_13tq                ((uint8)0x0C)  /* 13 time quantum */
#define CAN_BS1_14tq                ((uint8)0x0D)  /* 14 time quantum */
#define CAN_BS1_15tq                ((uint8)0x0E)  /* 15 time quantum */
#define CAN_BS1_16tq                ((uint8)0x0F)  /* 16 time quantum */

/*******************************************CAN time quantum In bit segment_2*******************/	

#define CAN_BS2_1tq                 ((uint8)0x00)  /* 1 time quantum */									
#define CAN_BS2_2tq                 ((uint8)0x01)  /* 2 time quantum */									
#define CAN_BS2_3tq                 ((uint8)0x02)  /* 3 time quantum */									
#define CAN_BS2_4tq                 ((uint8)0x03)  /* 4 time quantum */									
#define CAN_BS2_5tq                 ((uint8)0x04)  /* 5 time quantum */									
#define CAN_BS2_6tq                 ((uint8)0x05)  /* 6 time quantum */
#define CAN_BS2_7tq                 ((uint8)0x06)  /* 7 time quantum */
#define CAN_BS2_8tq                 ((uint8)0x07)  /* 8 time quantum */

/*****************************************************CAN Error Types*****************************/       

#define CAN_NoError                 ((uint8)0x00) /* No Error */ 
#define	CAN_StuffError              ((uint8)0x10) /* Stuff Error */ 
#define	CAN_FormError               ((uint8)0x20) /* Form Error */ 
#define	CAN_ACKError                ((uint8)0x30) /* Acknowledgment Error */ 
#define	CAN_BitRecessiveError       ((uint8)0x40) /* Bit Recessive Error */ 
#define	CAN_BitDominantError        ((uint8)0x50) /* Bit Dominant Error */ 
#define	CAN_CRCError                ((uint8)0x60) /* CRC Error  */ 
#define	CAN_SoftwareSetError        ((uint8)0x70) /* Software Set Error */

/*************************************can interrupts for " Transmit , Receive , Error and Modes Ack "*****/																			
#define  CAN_TMEIE                       ((uint32)0x00000001) /*transmit mail box empt*/
#define  CAN_FMPIE0                      ((uint32)0x00000002) /*FIFO 0 pending interrupt*/
#define  CAN_FFIE0                       ((uint32)0x00000004) /*FIFO 0 full interrupt*/
#define  CAN_FOVIE0                      ((uint32)0x00000008) /*FIFO 0 oveeun interrupt*/
#define  CAN_FMPIE1                      ((uint32)0x00000010) /*FIFO 1 pending interrupt*/
#define  CAN_FFIE1                       ((uint32)0x00000020) /*FIFO 1 full interrupt*/
#define  CAN_FOVIE1                      ((uint32)0x00000040) /*FIFO 1 overun interrupt*/
#define  CAN_EWGIE                       ((uint32)0x00000100) /*Error Warning interrupt*/
#define  CAN_EPVIE                       ((uint32)0x00000200) /*error passive interrupt*/
#define  CAN_BOFIE                       ((uint32)0x00000400) /*bus off interupt*/
#define  CAN_LECIE                       ((uint32)0x00000800) /*code type error interrupt*/
#define  CAN_ERRIE                       ((uint32)0x00008000) /*error interrupt*/
#define  CAN_WKUIE                       ((uint32)0x00010000) /*Wake up mode interrupt*/
#define  CAN_SLKIE                       ((uint32)0x00020000) /*Sleep   mode interrupt*/









/***********************************************************************************/
                      /***FUNCTIONS PROTOTYPES***/
/***********************************************************************************

*Name       :   CAN_VoidInit

*Description: * Initializes the CAN peripheral according 
                 to the specified parameters in the init struct  
							
*Pre-Cond   :	None				
							
*pos-Cond   : None

*Input      : -canx struct "x=1,2,..."  according to how many can in controller
              CAN InitStruct to specifiy the configuration
             fifo number we want to receive the message located on itvoid
               message fram struct address that will contain reveived message	
*Output     :


*Return     : void

************************************************************************************/
void CAN_VoidInit(CAN_TypeDef* CANx, CAN_InitTypeDef* CANInitStruct) ;
/************************************************************************************




#endif
/******************************************END OF FILE************************************/
