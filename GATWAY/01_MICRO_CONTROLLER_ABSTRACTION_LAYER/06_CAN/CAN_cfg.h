/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-13 05:18:38
 * @modify date 2023-10-13 05:18:38
 * @desc [description]
 */

#ifndef CAN_CFG_H
#define CAN_CFG_H


#include "Std_Types.h"
#include "CAN_Interface.h"


/***********************************************************************************/
                      /*** HW Macros***/
/***********************************************************************************/						

#define MAX_CONTROLLERS_NUMBER    (2U)                  
#define USED_CONTROLLERS_NUMBER   (1U)
#define USED_FILTERS_NUMBERS      (2U)




/*
Description: CAN Init structure configuration
*/
typedef struct
{
  uint16 CAN_Prescaler;  //describe time quantum length                             
  
  uint8 CAN_MODE;     // describe the operation mode of can driver                                                          

  uint8 CAN_SJW;  // describe max number of time quantum                                    
                                                                           
  uint8 CAN_BS1;   // describe time quantum in segment 1                                   
                         
  uint8 CAN_BS2;   // describe time quantum in seqment 2                                  
                                                       
  FunctionalState CAN_TTCM; //enable  or disable time trigger communication mode                            
                             
  FunctionalState CAN_ABOM; //Enable or disable the automatic bus-off  management                                                      

  FunctionalState CAN_AWUM;  //Enable or disable the automatic wake-up mode                                                      

  FunctionalState CAN_NART; //Enable or disable the no-automatic retransmission mode                                                      

  FunctionalState CAN_RFLM;  // Enable or disable the Receive FIFO Locked mode                                                    

  FunctionalState CAN_TXFP;  // Enable or disable the transmit FIFO priority                           
														
} CAN_InitTypeDef;













#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
