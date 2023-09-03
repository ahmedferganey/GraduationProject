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
			 and then select some others configuarations. 
*/
#define TIMER0_WAVEFORM_GENERATION_MODE		TIMER0_NORMAL_MODE

#if   TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_NORMAL_MODE
	/* Set the Req Preload on TIMER0"0:255" Normal Mode according clock source */
	#define TIMER0_PRELOAD_VAL			128
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER0_OVERFLOW_INTERRUPT	ENABLE	

	
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_PWM_MODE
	/* Set the Required Compare Match Value on TIMER0 CTC Mode*/
	#define TIMER0_CTC_VAL				128		
	/*Set PWM Mode*/
	/* select your option:
					TIMER_OC_DISCONNECTED
					TIMER_CLR_ON_CTC_SET_ON_TOP
					TIMER_SET_ON_CTC_CLR_ON_TOP
	*/
	#define TIMER0_CTC_PWM_MODE			TIMER_CLR_ON_CTC_SET_ON_TOP		
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER0_PWM_INTERRUPT		ENABLE	 

	
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_CTC_MODE
	/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
	#define TIMER0_CTC_VAL			128			
	/* select Output Mode at PIN PB3 in ATMEGA32A:
												TIMER_OC_DISCONNECTED
												TIMER_OC_TOGGEL
												TIMER_OC_LOW
												TIMER_OC_HIGH
	*/
	#define TIMER0_OC0_MODE			TIMER_OC_DISCONNECTED
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER0_CTC_INTERRUPT	ENABLE

	
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_FAST_PWM_MODE
	/* Set the Required Compare Match Value on TIMER0 CTC Mode*/
	#define TIMER0_CTC_VAL				0		
	/* select Output Mode at PIN PB3 in ATMEGA32A:
												TIMER_OC_DISCONNECTED
												TIMER_OC_TOGGEL
												TIMER_OC_LOW
												TIMER_OC_HIGH
	*/
	#define TIMER0_CTC_PWM_MODE			TIMER_SET_ON_CTC_CLR_ON_TOP
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER0_FAST_PWM_INTERRUPT	ENABLE
	
#else
	#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"
#endif




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


/* !Comment: select whether you will enable or disable the interrupt for TIMER1
			 Overflow Interrupt Enable
			 Output Compare B Match Interrupt Enable:
			 Output Compare A Match Interrupt Enable:
			 Input Capture Interrupt Enable:
								DISABLE		OR		ENABLE
*/
#define TIMER1_OVERFLOW_INTERRUPT			ENABLE
#define TIMER1_CTCB_INTERRUPT				DISABLE
#define TIMER1_CTCA_INTERRUPT				DISABLE
#define TIMER1_ICR_INTERRUPT				DISABLE


/* !Comment: Set Preload Value for Normal Mode*/
#define TIMER1_PRELOAD_VAL					0


/* !Comment: Set CTCA & CTCB Values*/
#define TIMER1_CTCA_VAL						500
#define TIMER1_CTCB_VAL						0


/* !Comment: Input Capture Edge Select*/
#define TIMER1_ICR1_VAL						20000
/* !Comment: Set Timer1 Input Capture Noise Canceler:
							DISABLE					 ENABLE
*/
#define TIMER1_ICR_NOISE_CANCELER			DISABLE
/* !Comment: Set Timer1 Input Capture Edge:
						FALLING_EDGE				 RISING_EDGE
*/
#define TIMER1_ICR_EDGE						RISING_EDGE


/* !Comment: Compare Output Mode for Compare unit A & B ,controlling 
			 the Output Compare pins (OC1A and OC1B).wheteher you are
			 in CTC Mode OR PWM OR FAST PWM mode. so select one option
			 according to your mode selection. 
				    CTC mode				||			PWM & FAST PWM mode
				-TIMER_OC_DISCONNECTED			    -OC1A/OC1B disconnected
                -TIMER_OC_TOGGEL					-  
                -TIMER_OC_LOW					    -TIMER_CLR_ON_CTC_SET_ON_TOP
				-TIMER_OC_HIGH					    -TIMER_SET_ON_CTC_CLR_ON_TOP
*/
#define TIMER1_OCR1A_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP
#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP
//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:				Timer/Counter2 Config								*/
/* !Comment: Select one of Waveform Generation Modes: 
							TIMER2_NORMAL_MODE
							TIMER2_PWM_MODE
							TIMER2_CTC_MODE
							TIMER2_FAST_PWM_MODE				
*/
#define TIMER2_WAVEFORM_GENERATION_MODE		TIMER2_NORMAL_MODE
/* !Comment: select your configurations */
#if TIMER2_WAVEFORM_GENERATION_MODE   == TIMER2_NORMAL_MODE
	/* Set the Req Preload on TIMER0"0:255" Normal Mode according clock source */
	#define TIMER2_PRELOAD_VAL			128
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER2_OVERFLOW_INTERRUPT	ENABLE	
#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_PWM_MODE
	/* Set the Required Compare Match Value on TIMER2 CTC Mode*/
	#define TIMER2_CTC_VAL				128		
	/*Set PWM Mode*/
	/* select your option:
					TIMER_OC_DISCONNECTED
					TIMER_CLR_ON_CTC_SET_ON_TOP
					TIMER_SET_ON_CTC_CLR_ON_TOP
	*/
	#define TIMER2_CTC_PWM_MODE			TIMER_CLR_ON_CTC_SET_ON_TOP		
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER2_PWM_INTERRUPT		ENABLE	 
#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_CTC_MODE
	/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
	#define TIMER2_CTC_VAL			128			
	/* select Output Mode at PIN PD7 in ATMEGA32A:
												TIMER_OC_DISCONNECTED
												TIMER_OC_TOGGEL
												TIMER_OC_LOW
												TIMER_OC_HIGH
	*/
	#define TIMER2_OC2_MODE			TIMER_OC_DISCONNECTED
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER2_CTC_INTERRUPT	ENABLE
#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_FAST_PWM_MODE
	/* Set the Required Compare Match Value on TIMER0 CTC Mode*/
	#define TIMER2_CTC_VAL				0		
	/* select Output Mode at PIN PD7 in ATMEGA32A:
												TIMER_OC_DISCONNECTED
												TIMER_OC_TOGGEL
												TIMER_OC_LOW
												TIMER_OC_HIGH
	*/
	#define TIMER2_CTC_PWM_MODE			TIMER_SET_ON_CTC_CLR_ON_TOP
	/* DO you need interrupt feature or not in this case??
	  		DISABLE			ENABLE
	*/
	#define TIMER2_FAST_PWM_INTERRUPT	ENABLE
#else
	#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"

#endif
	
	
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
#define TIMER2_PRESCALER					TIMER2_DIVISION_FACTOR_32
	
	
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
/* !Comment: this tehnique will force the user to work on the same prescaler
			 for timer 0,1 but i like to ensure the concept of configuarability */
#define TIMER01_PRESCALER		TIMER01_DIVISION_FACTOR_8



//////////////////////////////////////////////////////////////////////////////////
/*	!COMMENT:						WDT	& ICU									*/
/* !Comment: Set Timer Input Capture Edge:
			 TIMER_ICP_RAISING_EDGE	 	||		TIMER_ICP_FALLING_EDGE
*/
#define TIMER_ICP_INIT_STATE      TIMER_ICP_RAISING_EDGE

/* !Comment: WDT Prescaler select:		
			WDT_PS_16k	   (@VCC 5 for 16.3 ms ) || (@VCC 3 for 17.1 ms )
			WDT_PS_32k     (@VCC 5 for 32.5 ms ) || (@VCC 3 for 34.3 ms )
			WDT_PS_64k     (@VCC 5 for 65   ms ) || (@VCC 3 for 68.5 ms )
			WDT_PS_128k    (@VCC 5 for 0.13  s ) || (@VCC 3 for 0.14  s )
			WDT_PS_256k    (@VCC 5 for 0.26  s ) || (@VCC 3 for 0.27  s )
			WDT_PS_512k    (@VCC 5 for 0.52  s ) || (@VCC 3 for 0.55  s )
			WDT_PS_1024k   (@VCC 5 for 1.0   s ) || (@VCC 3 for 1.1   s )
			WDT_PS_2048k   (@VCC 5 for 2.1   s ) || (@VCC 3 for 2.2   s )
*/
#define WDT_PRESCALER      WDT_PS_1024k









/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _TIMER_CONFIG_H_ */