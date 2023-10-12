/*
 * FileName		: ADC_interface.h
 * Created		: 8/29/2023 3:56:20 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_


/*-------------------------------- Includes --------------------------------*/
#include "STD_TYPES.h"


/*-------------------------------- Macro Declarations --------------------------------*/
/* !Comment: enable or disable this peripheral */
#define ADC_DISABLE             0
#define ADC_ENABLE              1
/* !Comment: Interrupt enable or disable */
#define ADC_INT_DISABLE         0
#define ADC_INT_ENABLE          1
/* !Comment:  Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits */
/* 		!Comment:  Bits 4:0 – MUX4:0: single ended selection "Pin configuration" */
#define ADC_CHANNEL0			0
#define ADC_CHANNEL1			1
#define ADC_CHANNEL2			2
#define ADC_CHANNEL3			3
#define ADC_CHANNEL4			4
#define ADC_CHANNEL5			5
#define ADC_CHANNEL6			6
#define ADC_CHANNEL7			7
/* !Comment: Voltage Reference Selections for ADC "Bit 7:6 – REFS1:0:" */
#define ADC_AREF      			0
#define ADC_AVCC      			1
#define ADC_INT_2_56_EXT_CAP	3	
/* !Comment: Bit 5 – ADLAR: ADC Left Adjust Result */
#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1
/* !Comment: Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits */
#define ADC_PRE_2               1
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7
/* !Comment:  Bit 7:5 – ADTS2:0: ADC Auto Trigger Source */
#define ADC_FREE_RUNNING        0
#define ADC_ANALOG_COMPARATOR   1
#define ADC_EXTI0               2
#define ADC_TIM0_CTC            3
#define ADC_TIM0_OVF            4
#define ADC_TIM1_CTC_CHANNEL_B  5
#define ADC_TIM1_OVF            6
#define ADC_TIM1_ICU            7

/*-------------------------------- Macro Functions Declarations --------------------------------*/


/*-------------------------------- Data Type Declarations --------------------------------*/
typedef struct 
{
	uint8*  Channel;
	uint16* Result;
	uint8   Size;
	void (*NotificationFunc)(void);
}ADC_chain_t;

/*-------------------------------- Software Interfaces Declarations --------------------------------*/
void ADC_vdEnable           
(
void
);
void ADC_vdDisable          
(
void
);
void ADC_vdInterruptEnable  
(
void
);
void ADC_vdInterruptDisable 
(
void
);

Std_ReturnType ADC_udtSetPrescaler 
(
uint8 Copy_u8Prescaler
);


Std_ReturnType ADC_udtInit
(
void
);

Std_ReturnType ADC_udtSelectDefaultChannel
(
void
);

Std_ReturnType ADC_udtGetResultSync
(
const uint8 Copy_uint8Channel, 
uint16* Copy_pu16Result
);


Std_ReturnType ADC_udtStartConversionAsynch
( 
uint8 Copy_u8Channel, 
uint16* Copy_pu16Result, 
void(*Copy_pvNotificationFunc)(void) 
);

Std_ReturnType ADC_udtStartChainAsynch     
( 
ADC_chain_t * Copy_ADC_Chain
);

Std_ReturnType ADC_udtSetCallBack
(
void (*Copy_pvCallBackFunc)(void)
);


#endif  /* _ADC_INTERFACE_H_ */