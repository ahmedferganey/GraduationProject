/*
 * FileName		: ADC_config.h
 * Created		: 8/29/2023 3:55:32 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_


/* -------------------------------- Includes --------------------------------*/


/* -------------------------------- Macro Declarations --------------------------------*/
/* !Comment: select one of three options: 
			 ADC_AREF      		
			 ADC_AVCC      		
			 ADC_INT_2_56_EXT_CAP			 
*/
#define ADC_VREF  ADC_AVCC
/* !Comment: select one of two options: 
			 RIGHT_ADJUSTMENT      		
			 LEFT_ADJUSTMENT      		
*/
#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT
/* !Comment: select one of 7 options: 
			 ADC_PRE_2      		
			 ADC_PRE_4
			 ADC_PRE_8
			 ADC_PRE_16
			 ADC_PRE_32
			 ADC_PRE_64
			 ADC_PRE_128		 
*/
#define ADC_PRESCALLER	ADC_PRE_128
/* !Comment: select one of two options: 
			 ADC_ENABLE      		
			 ADC_Disable      		
*/
#define ADC_STATUS   ADC_ENABLE
/* !Comment: select one of two options: 
			 ADC_INT_ENABLE      		
			 ADC_INT_DISABLE      		
*/
#define ADC_INT_STATUS   ADC_INT_ENABLE

/* !Comment: select one of 8 options: 
				ADC_CHANNEL0
				ADC_CHANNEL1
				ADC_CHANNEL2
				ADC_CHANNEL3
				ADC_CHANNEL4
				ADC_CHANNEL5
				ADC_CHANNEL6
				ADC_CHANNEL7
 */
#define ADC_CHANNEL  ADC_CHANNEL0

/* !Comment: select calculated conversion time where as it is expected to finish conversion
			 this macro is used in sync fun to get the result of conversion
 */
#define  ADC_TIMEOUT      50000


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------*/


/* -------------------------------- Function Declarations --------------------------------*/


#endif  /* _ADC_CONFIG_H_ */