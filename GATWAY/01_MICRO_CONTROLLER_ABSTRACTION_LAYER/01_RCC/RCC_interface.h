/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-12 11:02:24
 * @modify date 2023-10-12 11:02:24
 * @desc [description]
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                       *******CLOCK BUSES MACROS******                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define RCC_AHB_EN        0
#define RCC_APB1_EN       1
#define RCC_APB2_EN       2
#define RCC_APB1_RES      3
#define RCC_APB2_RES      4



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                           *******PERIPHERAL ENABLE AND RESET CLOCK MACROS******                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 RCC_AHBENR  -->ENABLE PERIPHERAL CLOCK
*/
#define RCC_DMA1       0
#define RCC_DMA2       1
#define RCC_SRAM       2
#define RCC_FLITF      4
#define RCC_CRC        6
#define RCC_FSMC       8
#define RCC_SDIO       10




/*
 ARCC_APB2ENR-->ENABLE PERIPHERAL CLOCK
 RCC_APB2RSTR-->RESET  PERIPHERAL
*/                                                              
#define RCC_AFIO       0 
#define RCC_GPIOA      2
#define RCC_GPIOB      3 
#define RCC_GPIOC      4  
#define RCC_GPIOD      5  
#define RCC_GPIOE      6  
#define RCC_GPIOF      7  
#define RCC_GPIOG      8  
#define RCC_ADC1       9  
#define RCC_ADC2       10  
#define RCC_TIM1       11 
#define RCC_SPI1       12 
#define RCC_TIM8       13 
#define RCC_USART1     14  
#define RCC_ADC3       15 
#define RCC_TIM9       19 
#define RCC_TIM10      20 
#define RCC_TIM11      21 
/*
 RCC_APB1ENR-->ENABLE PERIPHERAL CLOCK
 RCC_APB1RSTR-->RESET  PERIPHERAL
*/                                                                
#define RCC_TIM2       0 
#define RCC_TIM3       1 
#define RCC_TIM4       2 
#define RCC_TIM5       3 
#define RCC_TIM6       4 
#define RCC_TIM7       5 
#define RCC_TIM12      6 
#define RCC_TIM13      7 
#define RCC_TIM14      8 
#define RCC_WWD        11
#define RCC_SPI2       14 
#define RCC_SPI3       15 
#define RCC_USART2     17 
#define RCC_USART3     18 
#define RCC_USART4     19 
#define RCC_USART5     20 
#define RCC_I2C1       21 
#define RCC_I2C2       22 
#define RCC_USB        23 
#define RCC_CAN        25 
#define RCC_BKP        27 
#define RCC_PWR        26 
#define RCC_DAC        29 




////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      *******ERROR Macros**********                                     //
//			EACH VALUE REPRESENT ERROR TYPE WHICH INDICATE REASON AND LOCATION OF ITS ERROR               //
////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                               *******ERROR CHECK VARIABLE******                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     *******FUNCTIONS PROTOTYPES******                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief 
/// @param  
void RCC_VoidInitSysClock(void);

/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidEnableClock(uint8 Copy_u8BusId ,  
                         uint8 Copy_u8PerId   );
/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidDisableClock(uint8 Copy_u8BusId ,  
                          uint8 Copy_u8PerId   );
/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidResetPeriph(uint8 Copy_u8BusId ,  
                         uint8 Copy_u8PerId   );





#endif
