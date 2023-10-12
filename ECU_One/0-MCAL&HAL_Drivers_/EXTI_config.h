/*
 * FileName		: EXTI_config.h
 * Created		: 8/30/2023 4:39:17 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_


/*-------------------------------- Includes --------------------------------------------------------*/


/*-------------------------------- Macro Declarations ----------------------------------------------*/
/*
   !Comment: select whether enable int on int0, 1, 2 or disable:
			 EXTI_0_Enable / EXTI_0_Disable
			 EXTI_1_Enable / EXTI_1_Disable
			 EXTI_2_Enable / EXTI_2_Disable
*/
#define EXTI_State   EXTI_INT2



/*
   !Comment: select one of these options 
				EXTI_LOW_MODE
				EXTI_ON_MODE
				EXTI_RISING_MODE
				EXTI_FALLING_MODE					
*/
/* !Comment: there is a special case if EXTI_2 is enabled where as the interrupt
			 must be only one of two cases (EXTI_RISING_MODE, EXTI_FALLING_MODE)  
*/
#define EXTI_SENSE_MODE  EXTI_FALLING_MODE

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _EXTI_CONFIG_H_ */