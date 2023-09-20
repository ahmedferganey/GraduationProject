/*
 * FileName		: TIMER_program.c
 * Created		: 8/31/2023 1:42:25 PM
 * Author		: Ahmed Ferganey
 */ 
 
 
/* -------------------------------- Includes -----------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


/* -------------------------------- Global Variables ---------------------------------------*/
/* !Comment: Global Pointer to array of Function to Hold the Call Back Function 
			 Address for Timer, there are 8 sources of interrupt */
static void (*TIMERS_pvCallBackFunc[7])(void) = {NULL};  



/* -------------------------------- APIs Implementation ------------------------------------*/
/*------- Timer0 APIs Implementation -------*/
void TIMER0_vdInit
(
void
)
{
	/* !GENERAL COMMENT: for every timer init our driver separeted into 2 parts
						 Set Configurable Modes & Set the Required Prescaler */
	/*Set Configurable Modes*/
	#if   TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_NORMAL_MODE
		/* 1-Setting Normal Mode*/	
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		/* 2-Set the Required Preload Value "TCNT0 Timer/Counter Register"*/
		/* !Comment:  Writing to the TCNT0 Register blocks (removes) the compare 
					  match on the following timer clock. Modifying the counter 
					  (TCNT0) while the counter is running, introduces a risk of missing 
					  a compare match between TCNT0 and the OCR0 Register*/
		TCNT0 = TIMER0_PRELOAD_VAL;
		/* 3-Timer0 Overflow Interrupt Enable*/
		#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
			CLR_BIT(TIMSK, TIMER0_TIMSK_TOIE0);
		#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
			SET_BIT(TIMSK, TIMER0_TIMSK_TOIE0);
		#else
			#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
		#endif

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_PWM_MODE
		/* 1-Setting PWM_MODE*/	
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);	
		/* 2-Set CTC PWM MODE*/
		/* !Comment: The phase correct PWM mode (WGM0[1:0] = 1) provides a high 
					 resolution phase correct PWM waveform generation option. The 
					 phase correct PWM mode is based on a dual-slope operation. The 
					 counter counts repeatedly from BOTTOM to MAX and then from MAX to 
					 BOTTOM. In non-inverting Compare Output mode, the Output Compare 
					 (OC0) is cleared on the compare match between TCNT0 and OCR0 while
					 upcounting, and set on the compare match while downcounting. 
					 In inverting Output Compare mode, the operation is inverted.*/
		#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR0, TCCR0_COM00) ;
				CLR_BIT(TCCR0, TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR0, TCCR0_COM00) ;
				SET_BIT(TCCR0, TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR0, TCCR0_COM00) ;
				SET_BIT(TCCR0, TCCR0_COM01) ;
		#else
				#error "Wrong TIMER0_CTC_PWM_MODE Config"
		#endif		
		/* 3-Set the Required CTC Value "OCR0 – Output Compare Register"*/
		/* !Comment: The Output Compare Register contains an 8-bit value 
					 that is continuously compared with the counter value
					 (TCNT0). A match can be used to generate an output compare 
					 interrupt, or to generate a waveform output on the OC0 pin.
					 TIMER0_CTC_VAL */
		/* !Comment: note this macro TIMER0_CTC_VAL is common between 3 modes 
					 fast & phase PWM + CTC mode where as only one register */
		OCR0 = TIMER0_CTC_VAL;
		/* 3-Timer0 TIMER0_PWM Interrupt Enable*/
		#if TIMER0_PWM_INTERRUPT == DISABLE
			CLR_BIT(TIMSK, TIMER0_TIMSK_OCIE0);
		#elif TIMER0_PWM_INTERRUPT == ENABLE
			SET_BIT(TIMSK, TIMER0_TIMSK_OCIE0);
		#else
			#error "Wrong TIMER0_PWM_INTERRUPT Config"
		#endif

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_CTC_MODE
		/* 1-Setting CTC_MODE*/	
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);	
		/* 2-Set the Required CTC Value*/
		OCR0 = TIMER0_CTC_VAL;
		/* 3-Timer0 Compare Match Interrupt Enable*/
		#if TIMER0_CTC_INTERRUPT == DISABLE
			CLR_BIT(TIMSK , TIMER0_TIMSK_OCIE0) ;
		#elif TIMER0_CTC_INTERRUPT == ENABLE
			SET_BIT(TIMSK , TIMER0_TIMSK_OCIE0) ;
		#else
			#error "Wrong TIMER0_CTC_INTERRUPT Config"
		#endif
		
	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_FAST_PWM_MODE
		/* 2-Setting FAST_PWM_MODE*/	
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		/* 2-Set CTC FAST PWM MODE*/
		#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TCCR0, TCCR0_COM00) ;
				CLR_BIT(TCCR0, TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TCCR0, TCCR0_COM00) ;
				SET_BIT(TCCR0, TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TCCR0, TCCR0_COM00) ;
				SET_BIT(TCCR0, TCCR0_COM01) ;
		#else
				#error "Wrong TIMER0_CTC_PWM_MODE Config"
		#endif	
		/* 3-Timer0 TIMER0_Fast_PWM Interrupt Enable*/
		#if   TIMER0_FAST_PWM_INTERRUPT == DISABLE
			CLR_BIT(TIMSK, TIMER0_TIMSK_OCIE0);
		#elif TIMER0_FAST_PWM_INTERRUPT == ENABLE
			SET_BIT(TIMSK, TIMER0_TIMSK_OCIE0);
		#else
			#error "Wrong TIMER0_PWM_INTERRUPT Config"
		#endif
		/* 4-Set the Required CTC Value*/
		OCR0 = TIMER0_CTC_VAL;		
	#else
		#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"
	#endif	
	
	/*Set the Required Prescaler*/	
	TCCR0 &= TIMER01_PRESCALER_MASK;
	TCCR0 |= TIMER01_PRESCALER;	
}
/*--- Timer0 SetPreload ---*/
void TIMER0_vdSetPreload 
(
uint8 Copy_u8Preload
)
{
	TCNT0 = Copy_u8Preload;	
}
/*--- Timer0 SetCTC ---*/
void TIMER0_vdSetCTC 
(
uint8 Copy_u8CTC
)
{
	OCR0 = Copy_u8CTC;	
}
/*--- Timer0 GetTimerCounterValue ---*/
uint8 TIMER0_u8GetTimerCounterValue 
(
void
)
{
	return TCNT0 ;
	
}

/*------- Timer1 APIs Implementation -------*/
void TIMER1_vdInit
(
void
)
{
	/* !GENERAL COMMENT: for every timer init our driver separeted into 2 parts
						 Set Configurable Modes & Set the Required Prescaler */
	/*Set Configurable Modes*/
	#if   TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL_MODE
		/* 1-Setting Normal Mode*/	
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
			CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
			CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);
		/* 2-Setting Preload value*/	
			TCNT1 = TIMER1_PRELOAD_VAL;
		/* 3-Timer1 Overflow Interrupt Enable*/	
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif	
			
	#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE)
		/* 1-Setting as CTC modes*/	
		/* TWO states have the same values of the first 3 bits WGM1<0,1,2>*/
			CLR_BIT(TCCR1A,TCCR1A_WGM10);
			CLR_BIT(TCCR1A,TCCR1A_WGM11);
			SET_BIT(TCCR1B,TCCR1B_WGM12);
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif
		/* 2-Set the require CTC Values*/
		/* !Comment: note every macro accsess 16bit Regsiter
					 The double buffered Output Compare Registers (OCR1A/B) are compared 
					 with the Timer/Counter value at all time.The result of the compare 
					 can be used by the Waveform Generator to generate a PWM or variable
					 frequency output on the Output Compare pin (OC1A/B). Refer to 
					 “Output Compare Units” on page 101. The compare match event will 
					 also set the Compare Match Flag (OCF1A/B)which can be used to 
					 generate an output compare interrupt request.*/
		/* !Comment: you can use these two registers to interrupt on OCnA & OCnB*/
			OCR1A = TIMER1_CTCA_VAL;
			OCR1B = TIMER1_CTCB_VAL;
		/* 3-Set ICR1 if TIMER1_WAVEFORM_GENERATION_MODE = TIMER1_CTC_ICR1_MODE*/
		/* !Comment: Bit 6 – ICES1: Input Capture Edge Select    
					 This bit selects which edge on the Input Capture 
					 Pin (ICP1) that is used to trigger a capture event.
					 When the ICES1 bit is written to zero, a falling 
					 (negative) edge is used as trigger, and when the 
					 ICES1 bit is written to one, arising (positive) edge 
					 will trigger the capture*/
		/* !Comment: When a capture is triggered according to the ICES1 
					 setting, the counter value is copied into the Input Capture 
					 Register (ICR1). The event will also set the Input Capture
					 Flag (ICF1), and this can be used to cause an Input 
					 CaptureInterrupt, if this interrupt is enabled.*/
			#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
				(uint16(*(TIMER1->ICR1L))) = TIMER1_ICR1_VAL;
				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif
	
			#else
				/*Do nothing*/
			#endif					 			
		/* 4-Set OCR1A mode*/
			#if   TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);
			#elif TIMER1_OCR1A_MODE == TIMER_OC_TOGGEL
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);		
			#elif TIMER1_OCR1A_MODE == TIMER_OC_LOW
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#elif TIMER1_OCR1A_MODE == TIMER_OC_HIGH
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif			
		/* 5-Set OCR1B mode*/
			#if   TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED	
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#elif TIMER1_OCR1B_MODE == TIMER_OC_TOGGEL
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#elif TIMER1_OCR1B_MODE == TIMER_OC_LOW
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#elif TIMER1_OCR1B_MODE == TIMER_OC_HIGH
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif				
		/* 6-Timer1 CTC Interrupt Enable*/	
			#if TIMER1_CTCA_INTERRUPT == DISABLE			
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);			
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif		
			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);			
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);						
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif			
		
	#elif ((TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE) ||(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_10_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_9_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_8_BIT_MODE))
		/* 1-Setting as PWM modes*/	
			#if TIMER1_WAVEFORM_GENERATION_MODE	  == TIMER1_PWM_8_BIT_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_9_BIT_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_10_BIT_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);			
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif			
		/* 2-Set the required CTC Values*/
			OCR1A = TIMER1_CTCA_VAL;
			OCR1B = TIMER1_CTCB_VAL;		
		/* 3-Set ICR1*/
			#if ((TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE))
				(uint16(*(TIMER1->ICR1L))) = TIMER1_ICR1_VAL;
				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif
			#else
				/*Do nothing*/
			#endif		
		/* 4-Set OCR1A mode*/
			#if   TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);	
			#elif TIMER1_OCR1A_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#elif TIMER1_OCR1A_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif			
		/* 5-Set OCR1B mode*/
			#if   TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED	
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);					
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif			
		/* 6-Timer1 PWM Interrupt Enable*/
		/* !Comment: we can get interrupt for PWM modes (7) whether 
					 - Phase Correct
					 - Phase and Frequency Correct
					 through 4 sources.
		*/
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif

			#if TIMER1_CTCA_INTERRUPT == DISABLE			
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);			
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif	
			
			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);			
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);						
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif
			
			#if TIMER1_ICR_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_TICIE1);
			#elif TIMER1_ICR_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_TICIE1);
			#else
				#error "Wrong TIMER1_ICR1_INTERRUPT Config"
			#endif		
	#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_10_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_9_BIT_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_8_BIT_MODE)
		/* 1-Setting Fast PWM modes*/	
			#if   TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_8_BIT_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_9_BIT_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_10_BIT_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				CLR_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE
				CLR_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM10);
				SET_BIT(TIMER1->TCCR1A, TCCR1A_WGM11);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM12);
				SET_BIT(TIMER1->TCCR1B, TCCR1B_WGM13);				
			#else
				#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
			#endif	
		/* 2-Set the required CTC Values*/
			OCR1A = TIMER1_CTCA_VAL;
			OCR1B = TIMER1_CTCB_VAL;		
		/* 3-Set ICR1*/
			#if ((TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE))
				(uint16(*(TIMER1->ICR1L))) = TIMER1_ICR1_VAL;
				#if TIMER1_ICR_EDGE == RISING_EDGE
					SET_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#elif TIMER1_ICR_EDGE == FALLING_EDGE
					CLR_BIT(TIMER1->TCCR1B , TCCR1B_ICES1);
				#else
				#error "Wrong TIMER1_ICR_EDGE Config"
				#endif
			#else
				/*Do nothing*/
			#endif		
		/* 4-Set OCR1A mode*/
			#if   TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);	
			#elif TIMER1_OCR1A_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#elif TIMER1_OCR1A_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1A1);			
			#else
				#error "Wrong TIMER1_OCR1A_MODE Config"
			#endif			
		/* 5-Set OCR1B mode*/
			#if   TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED	
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);					
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B0);
			SET_BIT(TIMER1->TCCR1A, TCCR1A_COM1B1);			
			#else
				#error "Wrong TIMER1_OCR1B_MODE Config"
			#endif			
		/* 6-Timer1 fast PWM Interrupt Enable*/
		/* !Comment: we can get interrupt for fast PWM modes through 4 sources.*/
			#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
				CLE_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_TOIE1);
			#else
				#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
			#endif

			#if TIMER1_CTCA_INTERRUPT == DISABLE			
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1A);			
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif	
			
			#if TIMER1_CTCA_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);			
			#elif TIMER1_CTCA_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_OCIE1B);						
			#else
				#error "Wrong TIMER1_CTCA_INTERRUPT Config"
			#endif
			
			#if TIMER1_ICR_INTERRUPT == DISABLE
				CLR_BIT(TIMSK, TIMER1_TIMSK_TICIE1);
			#elif TIMER1_ICR_INTERRUPT == ENABLE
				SET_BIT(TIMSK, TIMER1_TIMSK_TICIE1);
			#else
				#error "Wrong TIMER1_ICR1_INTERRUPT Config"
			#endif	
	#else
		#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
	#endif	
	/*Set the Required Prescaler*/	
	((TIMER1->TCCR1B)) &= TIMER01_PRESCALER_MASK;
	((TIMER1->TCCR1B)) |= TIMER01_PRESCALER;
}
/*--- Timer1 SetPreload ---*/
void TIMER1_vdSetPreload 
(
uint16 Copy_u16Preload
)
{
	TCNT1 = Copy_u16Preload ;	
}
/*--- Timer1 SetCTCA ---*/
void TIMER1_vdSetCTCA 
(
uint16 Copy_u16CTCA
)
{
	OCR1A = Copy_u16CTCA ;
}
/*--- Timer1 SetCTCB ---*/
void TIMER1_vdSetCTCB 
(
uint16 Copy_u16CTCB
)
{
	OCR1B = Copy_u16CTCB ;	
}
/*--- Timer1 SetICR1 ---*/
void TIMER1_vdSetICR1 
(
uint16 Copy_u16ICR1
)
{
	ICR1 = Copy_u16ICR1 ;
}
/*--- Timer1 GetTimerCounterValue  ---*/
uint16  TIMER1_u16GetTimerCounterValue 
(
void
)
{
	return TCNT1 ;
}
/*---------- ICU APIs ----------*/
/*------ ICUInitEnable ------*/
/* --- (prebuild) ---*/
void TIMER_vdICUInitEnable
(
void
)
{
	/* Set trigger source as rising edge Initially  */
	#if  (TIMER_ICP_INIT_STATE == TIMER_ICP_RAISING_EDGE)
		SET_BIT(TIMER1->TCCR1B, TCCR1B_ICES1);
	#elif(TIMER_ICP_INIT_STATE == TIMER_ICP_RAISING_EDGE)
		CLR_BIT(TIMER1->TCCR1B, TCCR1B_ICES1);
	#endif
	
	/* Enable Interrupt of ICU */
	SET_BIT(TIMSK, TIMER1_TIMSK_TICIE1);	
}
/*------ ICU_ChangeTriggerEdge ------*/
/*  (postbuild) Func arguments :-
	 1- TIMER_u8_ICP_RAISING_EDGE
	 2- TIMER_u8_ICP_FALLING_EDGE
*/
Std_ReturnType TIMER_udtICUSetTriggerEdge
(
uint8 Copy_u8Edge
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	switch(Copy_u8Edge)
	{
		case TIMER_u8_ICP_RAISING_EDGE: SET_BIT(TIMER1->TCCR1B, TCCR1B_ICES1);
										udtReturnValue = E_OK;
										break;
		case TIMER_u8_ICP_FALLING_EDGE: CLR_BIT(TIMER1->TCCR1B, TCCR1B_ICES1);
										udtReturnValue = E_OK;
										break;
		default:		  				/* !Comment: Do nothing */
										break;		
	}
	return udtReturnValue;	
}	
/*--- ICUEnableInterrupt ---*/
void TIMER_vdICUEnableInterrupt
(
void
)
{
	SET_BIT(TIMSK, TIMER1_TIMSK_TICIE1);	
}
/*--- CUDisableInterrupt ---*/
void TIMER_vdICUDisableInterrupt
(
void
)
{
	CLR_BIT(TIMSK, TIMER1_TIMSK_TICIE1);	
}
/*--- GetICR ---*/
uint16  TIMER_u16GetICR
(
void
)
{
	/* this register is 16 bit register */
	return ICR1;	
}

/*------- Timer2 APIs Implementation -------*/
void TIMER2_vdInit
(
void
)
{
	/* !GENERAL COMMENT: for every timer init our driver separeted into 2 parts
						 Set Configurable Modes & Set the Required Prescaler */
	/*Set Configurable Modes*/
	#if   TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_NORMAL_MODE
		/* 1-Setting Normal Mode*/	
		CLR_BIT(TIMER2->TCCR2, TCCR2_WGM20);
		CLR_BIT(TIMER2->TCCR2, TCCR2_WGM21);
		/* 2-Set the Required Preload Value*/
		((TIMER2->TCNT2)) = TIMER2_PRELOAD_VAL;
		/* 3-Timer2 Overflow Interrupt Enable*/
		#if   TIMER2_OVERFLOW_INTERRUPT == DISABLE
			CLR_BIT(TIMSK, TIMER2_TIMSK_TOIE2);
		#elif TIMER2_OVERFLOW_INTERRUPT == ENABLE
			SET_BIT(TIMSK, TIMER2_TIMSK_TOIE2);
		#else
			#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
		#endif		
	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_PWM_MODE
		/* 1-Setting PWM_MODE*/	
		SET_BIT(TIMER2->TCCR2, TCCR2_WGM20);
		CLR_BIT(TIMER2->TCCR2, TCCR2_WGM21);	
		/* 2-Set CTC PWM MODE*/
		#if   TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM20) ;
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM20) ;
				SET_BIT(TIMER2->TCCR2, TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TIMER2->TCCR2, TCCR2_COM20) ;
				SET_BIT(TIMER2->TCCR2, TCCR2_COM21) ;
		#else
				#error "Wrong TIMER2_CTC_PWM_MODE Config"
		#endif
		/* 3-Set the Required CTC Value*/
		(*(TIMER2->OCR2)) = TIMER2_CTC_VAL;
	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_CTC_MODE
		/* 1-Setting CTC_MODE*/	
		CLR_BIT(TIMER2->TCCR2, TCCR2_WGM20);
		SET_BIT(TIMER2->TCCR2, TCCR2_WGM21);
		/* 2-Set the Required CTC Value*/
		(*(TIMER2->OCR2)) = TIMER2_CTC_VAL;
		/* 3-Timer2 Compare Match Interrupt Enable*/
		#if   TIMER2_CTC_INTERRUPT == DISABLE
			CLR_BIT(TIMSK, TIMER2_TIMSK_OCIE2);
		#elif TIMER2_CTC_INTERRUPT == ENABLE
			SET_BIT(TIMSK, TIMER2_TIMSK_OCIE2);
		#else
			#error "Wrong TIMER2_CTC_INTERRUPT Config"
		#endif	
	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_FAST_PWM_MODE
		/* 1-Setting FAST_PWM_MODE*/	
		SET_BIT(TIMER2->TCCR2, TCCR2_WGM20);
		SET_BIT(TIMER2->TCCR2, TCCR2_WGM21);	
		/* 2-Set CTC Fast PWM MODE*/		
		#if   TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM20);
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM21);
		#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
				CLR_BIT(TIMER2->TCCR2, TCCR2_COM20);
				SET_BIT(TIMER2->TCCR2, TCCR2_COM21);
		#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
				SET_BIT(TIMER2->TCCR2, TCCR2_COM20);
				SET_BIT(TIMER2->TCCR2, TCCR2_COM21);
		#else
				#error "Wrong TIMER2_CTC_PWM_FAST_MODE Config"
		#endif	
		/* 3-Set the Required CTC Value*/
		(*(TIMER2->OCR2)) = TIMER2_CTC_VAL;
	#else
		#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"
	#endif	
	
	/*Set the Required Prescaler*/	
	((TIMER2->TCCR2)) &= TIMER2_PRESCALER_MASK;
	((TIMER2->TCCR2)) |= TIMER2_PRESCALER;	
}
/*--- Timer2 SetPreload  ---*/
void TIMER2_vdSetPreload 
(
uint8 Copy_u8Preload
)
{
	(TIMER2->TCNT2) = Copy_u8Preload;	
}
/*--- Timer2 SetCTC  ---*/
void TIMER2_vdSetCTC 
(
uint8 Copy_u8CTC
)
{
	(TIMER2->OCR2) = Copy_u8CTC;	
}
/*--- Timer2 GetTimerCounterValue  ---*/
uint8 TIMER2_u8GetTimerCounterValue 
(
void
)
{
	return (TIMER2->TCNT2);	
}

/*------- WDT APIs Implementation ----------*/
/*--- WDTSleep"PreBuildFunc" ---*/
void TIMER_vdWDTSleep
(
void
)
{
	/* CLear The Prescaler bits  */
	WDTCR &= WDT_PS_MASKING;
	/* Set The required prescaller */
	WDTCR |= WDT_PRESCALER;
}
/*--- WDTEnable  ---*/
void TIMER_vdWDTEnable 
(
void
)
{
	SET_BIT(WDTCR, WDTCR_WDE); 
}
/*--- WDTDisable  ---*/
void TIMER_vdWDTDisable
(
void
)
{
	/* the following procedure must be followed:
		1. In the same operation, write a logic one to WDTOE and WDE. 
		   A logic one must be written to WDE even though it is set 
		   to one before the disable operation starts.
		2. Within the next four clock cycles, write a logic 0 to WDE. 
		   This disables the Watchdog
	*/
		/* Set Bit 3&4 at the same CLK cycle  */
	WDTCR |= WDT_DISABLE_MASKING;
	/*WDTCR = CLR_BIT(WDTCR, WDTCR_WDE);*/ 
	/* !Comment: cause i donot know number of req clock to implemet this line of code
				 and it required to implemet it through next 4 cycles,
				 I don't care for any value in this Reg Cuz I want to 
				 Disable WDTCR_WDE = 0
	*/
	WDTCR = 0;
	
}

/*------- Common APIs Implementation -------*/


/*------- TIMER ISR Implementation -------*/
/* call back function where app layer can use it to interrupt */
Std_ReturnType TIMER_udtSetCallBack
(
void (*Copy_pvCallBackFunc)(void), 
uint8 Copy_u8VectorID
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if (Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFunc[Copy_u8VectorID]= Copy_pvCallBackFunc;
		udtReturnValue = E_OK;		
	}
	else
	{
		udtReturnValue = E_NOT_OK;
	}
	return udtReturnValue;
}
/* TIMER2 COMP ISR*/
void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID]();
	}	
}
/* TIMER2 OVF ISR*/
void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID]();
	}	
}
/* TIMER1 CAPT ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID]();
	}	
}
/* TIMER1 COMPA ISR*/
void __vector_7 (void)		__attribute__((signal)) ;
void __vector_7 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID]();
	}	
}
/* TIMER1 COMPB ISR*/
void __vector_8 (void)		__attribute__((signal)) ;
void __vector_8 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID]();
	}	
}
/* TIMER1 OVF ISR*/
void __vector_9 (void)		__attribute__((signal)) ;
void __vector_9 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID]();
	}	
}
/* TIMER0 COMP ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID]();
	}	
}
/* TIMER0 OVF ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
	if ( TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID]();
	}
}