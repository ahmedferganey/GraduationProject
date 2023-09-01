/*
 * FileName		: TIMER_config.h
 * Created		: 8/31/2023 1:46:11 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_


/*-------------------------------- Includes --------------------------------------------------------*/


/*-------------------------------- Macro Declarations ----------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:				Timer/Counter0 Config								*/
/* !Comment: Select one of Waveform Generation Modes: 
							TIMER0_NORMAL_MODE
							TIMER0_PWM_MODE
							TIMER0_CTC_MODE
							TIMER0_FAST_PWM_MODE				
*/
#define TIMER0_WAVEFORM_GENERATION_MODE		TIMER0_NORMAL_MODE





//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:				Timer/Counter1 Config								*/
/* !Comment: Select one of Waveform Generation Modes: 
							TIMER1_NORMAL_MODE
							TIMER1_PWM_8_BIT_MODE
							TIMER1_PWM_9_BIT_MODE
							TIMER1_PWM_10_BIT_MODE
							TIMER1_CTC_OCR1A_MODE
							TIMER1_FAST_PWM_8_BIT_MODE
							TIMER1_FAST_PWM_9_BIT_MODE
							TIMER1_FAST_PWM_10_BIT_MODE
							TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
							TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
							TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
							TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
							TIMER1_CTC_ICR1_MODE
							TIMER1_FAST_PWM_ICR1_MODE
							TIMER1_FAST_PWM_OCR1A_MODE
*/
#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_NORMAL_MODE




//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:				Timer/Counter2 Config								*/
/* !Comment: Select one of Waveform Generation Modes: 
							TIMER2_NORMAL_MODE
							TIMER2_PWM_MODE
							TIMER2_CTC_MODE
							TIMER2_FAST_PWM_MODE				
*/
#define TIMER2_WAVEFORM_GENERATION_MODE		TIMER2_NORMAL_MODE
/* !Comment: Select Required Prescaler:
				TIMER2_NO_CLOCK_SOURCE
				TIMER2_NO_PRESCALER_FACTOR
				TIMER2_DIVISION_FACTOR_8
				TIMER2_DIVISION_FACTOR_32				
				TIMER2_DIVISION_FACTOR_64
				TIMER2_DIVISION_FACTOR_256
				TIMER2_DIVISION_FACTOR_1024
				TIMER2_T0_EXTERNAL_CLOCK_SOURCE_FALLING
				TIMER2_T0_EXTERNAL_CLOCK_SOURCE_RISING
*/
#define TIMER2_PRESCALER		TIMER2_DIVISION_FACTOR_32



//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						COMMON										*/
/* !Comment: Note that Timer/Counter1 and Timer/Counter0 share 
			 the same prescaler and a reset of thisprescaler will 
			 affect both timers. Select Required Prescaler:
				TIMER01_NO_CLOCK_SOURCE                 
				TIMER01_NO_PRESCALER_FACTOR             
				TIMER01_DIVISION_FACTOR_8               
				TIMER01_DIVISION_FACTOR_64              
				TIMER01_DIVISION_FACTOR_256             
				TIMER01_DIVISION_FACTOR_1024            
				TIMER01_T0_EXTERNAL_CLOCK_SOURCE_FALLING
				TIMER01_T0_EXTERNAL_CLOCK_SOURCE_RISING 
*/
#define TIMER01_PRESCALER		TIMER01_DIVISION_FACTOR_8



//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						WDT											*/













/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _TIMER_CONFIG_H_ */