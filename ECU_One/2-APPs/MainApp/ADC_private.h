/*
 * FileName		: ADC_private.h
 * Created		: 8/29/2023 3:54:41 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_


/* -------------------------------- Includes --------------------------------*/


/* -------------------------------- Macro Declarations --------------------------------*/
/* !Comment: Register Summary */
#define SFIOR   		*((volatile uint8*)0x50)
#define ADMUX			*((volatile uint8*)0x27)
#define ADCSRA  		*((volatile uint8*)0x26)
#define ADCH    		*((volatile uint8*)0x25)
#define ADCL    		*((volatile uint8*)0x24)
#define ADC_L_H         *((volatile uint16*)0x24)

/* !Comment: ADMUX Bits */
#define ADMUX_REFS1		7   /* Reference Selection Bits*/
#define ADMUX_REFS0		6   /* Reference Selection Bits*/
#define ADMUX_ADLAR		5   /* ADC Left Adjust Result by writing one*/
#define ADMUX_MUX4		4   /* Analog Channel and Gain Selection Bits*/
#define ADMUX_MUX3		3   /* Analog Channel and Gain Selection Bits*/
#define ADMUX_MUX2		2   /* Analog Channel and Gain Selection Bits*/
#define ADMUX_MUX1		1   /* Analog Channel and Gain Selection Bits*/
#define ADMUX_MUX0		0   /* Analog Channel and Gain Selection Bits*/

/* !Comment: ADCSRA Bits */
#define ADCSRA_ADEN		7	/* Bit 7 	– ADEN: ADC Enable*/
#define ADCSRA_ADSC		6	/* Bit 6 	– ADSC: ADC Start Conversion*/
#define ADCSRA_ADATE	5   /* Bit 5 	– ADATE: ADC Auto Trigger Enable*/
#define ADCSRA_ADIF		4   /* Bit 4 	– ADIF: ADC Interrupt Flag, is used in sync fun in polling*/
#define ADCSRA_ADIE		3   /* Bit 3	– ADIE: ADC Interrupt Enable*/
#define ADCSRA_ADPS2	2   /* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits*/
#define ADCSRA_ADPS1	1   /* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits*/
#define ADCSRA_ADPS0    0   /* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits*/

/* !Comment: SFIOR Bits */
/* !Comment: the bits from 0:3 not for this periperal, 4 is reserved */
#define SFIOR_ADTS2		7   /*  Bit 7:5 – ADTS2:0: ADC Auto Trigger Source*/
#define SFIOR_ADTS1		6   /*  Bit 7:5 – ADTS2:0: ADC Auto Trigger Source*/
#define SFIOR_ADTS0		5   /*  Bit 7:5 – ADTS2:0: ADC Auto Trigger Source*/

/* !comment: Masking group of bits for Prescaler */
/* !comment: firstly, we check on bit 0,1,2 by clearing them, bit 4:7 not changed
			 then select our config by setting target prescaler */
#define ADC_PRE_MASK	0b11111000

/* !comment: Masking group of bits for selected channel */
/* !comment: Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits */
#define ADC_CH_MASK		0b11100000

/* !comment: Values of the global var (ADC_u8ISRSource)  */
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1

/* !comment: index of first element in struct object  */
#define first_element_channel 0

/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------*/


/* -------------------------------- Function Declarations --------------------------------*/


#endif  /* _ADC_PRIVATE_H_ */