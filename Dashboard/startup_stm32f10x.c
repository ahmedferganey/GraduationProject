/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @file startup_stm32f10x.c
 * @create date 2023-10-13 09:54:45
 * @modify date 2023-10-13 09:54:45
 * @desc [this is startup code for STM32f10x]
 */

/* -------------------------------- macros & data types declerations  --------------------------------------------------------------*/
#define NULL 0
typedef unsigned long uint32_t;

/* -------------------------------- Global  decleration --------------------------------------------------------------*/
extern uint32_t _estack, _etext, _sdata, _edata, _sbss, _ebss,_sidata;
uint32_t* const MSP_Value = (uint32_t *)&_estack;               //_estack is a symbol this means referance not pointer

/* -------------------------------- functions declerations  --------------------------------------------------------------*/

extern void main(void);

 
void Reset_Handler                  (void);                                                             /*   */
void NMI_Handler                    (void) __attribute__ ((alias ("Default_Handler")));                         /*   */
void HardFault_Handler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void MemManage_Handler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void BusFault_Handler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void UsageFault_Handler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void SVC_Handler                    (void) __attribute__ ((alias ("Default_Handler")));                          /*   */
void DebugMon_Handler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void PendSV_Handler                 (void) __attribute__ ((alias ("Default_Handler")));                       /*   */
void SysTick_Handler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void WWDG_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void PVD_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));                       /*   */
void TAMP_STAMP_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));               /*   */
void RTC_WKUP_IRQHandler            (void) __attribute__ ((alias ("Default_Handler")));                  /*   */
void FLASH_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void RCC_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));                       /*   */
void EXTI0_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void EXTI1_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void EXTI2_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void EXTI3_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void EXTI4_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void DMA1_Channel1_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel2_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel3_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel4_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel5_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel6_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA1_Channel7_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void ADC1_2_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void USB_HP_CAN_TX_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void USB_LP_CAN_RX0_IRQHandler      (void) __attribute__ ((alias ("Default_Handler")));            /*   */
void CAN_RX1_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void CAN_SCE_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void EXTI9_5_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void TIM1_BRK_TIM9_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void TIM1_UP_TIM10_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void TIM1_TRG_COM_TIM11_IRQHandler  (void) __attribute__ ((alias ("Default_Handler")));        /*   */
void TIM1_CC_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void TIM2_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void TIM3_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void TIM4_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void I2C1_EV_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void I2C1_ER_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void I2C2_EV_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void I2C2_ER_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void SPI1_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void SPI2_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void USART1_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void USART2_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void USART3_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));                    /*   */
void EXTI15_10_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));                 /*   */
void RTC_Alarm_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));                 /*   */
void USB_Wakeup_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));                /*   */
void TIM8_BRK_IRQHandler            (void) __attribute__ ((alias ("Default_Handler")));                  /*   */
void TIM8_UP_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void TIM8_TRG_COM_IRQHandler        (void) __attribute__ ((alias ("Default_Handler")));              /*   */
void TIM8_CC_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));                   /*   */
void ADC3_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void FSMC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void SDIO_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void TIM5_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void SPI3_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void UART4_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));                     /*   */
void TIM6_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void TIM7_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));                      /*   */
void DMA2_Channel1_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA2_Channel2_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA2_Channel3_IRQHandler       (void) __attribute__ ((alias ("Default_Handler")));             /*   */
void DMA2_Channel4_5_IRQHandler     (void) __attribute__ ((alias ("Default_Handler")));           /*   */    



/* -------------------------------- IVT   --------------------------------------------------------------*/

uint32_t* Vector_Table[] __attribute__ ((section (".isr_vector "))) = {
    (uint32_t*)MSP_Value,                            /*   */
    (uint32_t*)&Reset_Handler,                        /*   */
    (uint32_t*)NMI_Handler,                          /*   */
    (uint32_t*)HardFault_Handler,                    /*   */
    (uint32_t*)MemManage_Handler,                    /*   */
    (uint32_t*)BusFault_Handler,                     /*   */
    (uint32_t*)UsageFault_Handler,                   /*   */
    0,
    0,
    0,
    0,
    (uint32_t*)SVC_Handler,                          /*   */
    (uint32_t*)DebugMon_Handler,                     /*   */
    0,
    (uint32_t*)PendSV_Handler,                       /*   */
    (uint32_t*)SysTick_Handler,                      /*   */
    (uint32_t*)WWDG_IRQHandler,                      /*   */
    (uint32_t*)PVD_IRQHandler,                       /*   */
    (uint32_t*)TAMP_STAMP_IRQHandler,                /*   */
    (uint32_t*)RTC_WKUP_IRQHandler,                  /*   */
    (uint32_t*)FLASH_IRQHandler,                     /*   */
    (uint32_t*)RCC_IRQHandler,                       /*   */
    (uint32_t*)EXTI0_IRQHandler,                     /*   */
    (uint32_t*)EXTI1_IRQHandler,                     /*   */
    (uint32_t*)EXTI2_IRQHandler,                     /*   */
    (uint32_t*)EXTI3_IRQHandler,                     /*   */
    (uint32_t*)EXTI4_IRQHandler,                     /*   */
    (uint32_t*)DMA1_Channel1_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel2_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel3_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel4_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel5_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel6_IRQHandler,             /*   */
    (uint32_t*)DMA1_Channel7_IRQHandler,             /*   */
    (uint32_t*)ADC1_2_IRQHandler,                    /*   */
    (uint32_t*)USB_HP_CAN_TX_IRQHandler,             /*   */
    (uint32_t*)USB_LP_CAN_RX0_IRQHandler,            /*   */
    (uint32_t*)CAN_RX1_IRQHandler,                   /*   */
    (uint32_t*)CAN_SCE_IRQHandler,                   /*   */
    (uint32_t*)EXTI9_5_IRQHandler,                   /*   */
    (uint32_t*)TIM1_BRK_TIM9_IRQHandler,             /*   */
    (uint32_t*)TIM1_UP_TIM10_IRQHandler,             /*   */
    (uint32_t*)TIM1_TRG_COM_TIM11_IRQHandler,        /*   */
    (uint32_t*)TIM1_CC_IRQHandler,                   /*   */
    (uint32_t*)TIM2_IRQHandler,                      /*   */
    (uint32_t*)TIM3_IRQHandler,                      /*   */
    (uint32_t*)TIM4_IRQHandler,                      /*   */
    (uint32_t*)I2C1_EV_IRQHandler,                   /*   */
    (uint32_t*)I2C1_ER_IRQHandler,                   /*   */
    (uint32_t*)I2C2_EV_IRQHandler,                   /*   */
    (uint32_t*)I2C2_ER_IRQHandler,                   /*   */
    (uint32_t*)SPI1_IRQHandler,                      /*   */
    (uint32_t*)SPI2_IRQHandler,                      /*   */
    (uint32_t*)USART1_IRQHandler,                    /*   */
    (uint32_t*)USART2_IRQHandler,                    /*   */
    (uint32_t*)USART3_IRQHandler,                    /*   */
    (uint32_t*)EXTI15_10_IRQHandler,                 /*   */
    (uint32_t*)RTC_Alarm_IRQHandler,                 /*   */
    (uint32_t*)USB_Wakeup_IRQHandler,                /*   */
    (uint32_t*)TIM8_BRK_IRQHandler,                  /*   */
    (uint32_t*)TIM8_UP_IRQHandler,                   /*   */
    (uint32_t*)TIM8_TRG_COM_IRQHandler,              /*   */
    (uint32_t*)TIM8_CC_IRQHandler,                   /*   */
    (uint32_t*)ADC3_IRQHandler,                      /*   */
    (uint32_t*)FSMC_IRQHandler,                      /*   */
    (uint32_t*)SDIO_IRQHandler,                      /*   */
    (uint32_t*)TIM5_IRQHandler,                      /*   */
    (uint32_t*)SPI3_IRQHandler,                      /*   */
    (uint32_t*)UART4_IRQHandler,                     /*   */
    (uint32_t*)TIM6_IRQHandler,                      /*   */
    (uint32_t*)TIM7_IRQHandler,                      /*   */
    (uint32_t*)DMA2_Channel1_IRQHandler,             /*   */
    (uint32_t*)DMA2_Channel2_IRQHandler,             /*   */
    (uint32_t*)DMA2_Channel3_IRQHandler,             /*   */
    (uint32_t*)DMA2_Channel4_5_IRQHandler,           /*   */    
};


/* -------------------------------- function implementation   --------------------------------------------------------------*/
void Reset_Handler(void){
    uint32_t Section_Size =0;
    uint32_t *MemSourceAddr = NULL;
    uint32_t *MemDestAddr = NULL;

    /* 1) Copy the data segment initializers from flash to SRAM */
    Section_Size  = &_edata - &_sdata;               /* Length of .data segment */
    MemSourceAddr = (uint32_t *) &_sidata;           /* Start address of .data sengement (LMA) -> Load Memory Address */
    MemDestAddr   = (uint32_t *) &_sdata;            /* Start address of .data sengement (VMA) -> Virtual Memory Address */
	
    /* 2) load .data & Initialize the .bss segment with zero */    
    for(uint32_t MemCounter= 0; MemCounter < Section_Size; MemCounter++)
    {
        *MemDestAddr++ = *MemSourceAddr++;
    }

    Section_Size = &_ebss - &_sbss;             /* Length of .bss segment */
    MemDestAddr = (uint32_t *) &_sbss;          /* Start address of .bss sengement */
    for(uint32_t MemCounter= 0; MemCounter < Section_Size; MemCounter++)
    {
        *MemDestAddr++ = 0;
    }

	/* 3) Call the system intitialization function */
        // write your API which will be called in your app for init system if you want. 

	/* 4) Call the main function */
    main();

}

void Default_Handler(void)
{

}