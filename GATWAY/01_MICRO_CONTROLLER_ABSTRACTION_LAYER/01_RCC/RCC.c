/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-12 11:02:37
 * @modify date 2023-10-12 11:02:37
 * @desc [description]
 */


#include "BIT_MATH.h"
#include "Std_Types.h"

#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_cfg.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     *******FUNCTIONS DEFINITION******                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief 
/// @param  
void RCC_VoidInitSysClock(void)
{
 #if      (RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)       /*CONFIGURATION OF EXTERNA CLOCK SOURCE*/

 #elif     (RCC_CLOCK_TYPE == RCC_HSE_RC)            /*CONFIGURATION OF EXTERNAL RC CLOCK SOURCE*/

 #elif     (RCC_CLOCK_TYPE == RCC_HSI)               /*CONFIGURATION OF INTERNAL CLOCK SOURCE*/

 #elif     (RCC_CLOCK_TYPE == RCC_PLL)             /*CONFIGURATION OF PLL CLOCK SOURCE*/

		                   /*CHOICES PLL INPUT SOURCE*/
 #if   RCC_PLL_SOURCE == RCC_PLL_HSI_BY2    

#elif RCC_PLL_SOURCE == RCC_PLL_HSE_BY2

#elif RCC_PLL_SOURCE == RCC_PLL_HSE

#else		             
      #error "wrong clock configuration input"  /*if you get here then you choose wrong clock choice*/
							
#endif

                                    /*CHOOSING OUTPUT CLOCK SOURCE ON MCO PIN*/
#if   RCC_MCO_PIN == NO_CLOCK              /*NO OUTPUT*/

#elif RCC_MCO_PIN == SYSTEM_CLOCK

#elif RCC_MCO_PIN == HSI_CLOCK

#elif RCC_MCO_PIN == HSE_CLOCK

#else
		#error "wrong clock configuration input"
		
#endif
                                              /*CHOOSING PRESCALLER OF ADC INPUT CLOCK*/
#if   RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_2    /*CLOCK DEVIDED BY 2*/

#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_4      /*CLOCK DEVIDED BY 4*/

#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_6       /*CLOCK DEVIDED BY 6*/

#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_8       /*CLOCK DEVIDED BY 8*/

#else
	
#error "wrong clock configuration input"
		
	#endif	
	
	                                              /*CHOOSING PRESCALLER OF APB2 BUS INPUT CLOCK*/
#if   RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_0  /*NO PRESCALLER*/

#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_2   /*CLOCK DEVIDED BY 2*/

#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_4   /*CLOCK DEVIDED BY 4*/

#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_8   /*CLOCK DEVIDED BY 8*/

#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_16   /*CLOCK DEVIDED BY 16*/

#else

#error "wrong clock configuration input"
		
	#endif
	
	                  /*CHOOSING PRESCALLER OF APB1 BUS INPUT CLOCK*/

#if   RCC_APB1_PRESCALLER == RCC_PRESCALLER_BY_0   /*NO PRESCALLER*/
		  CLR_BIT(RCC_CFGR , RCC_PPRE1_2);        /*SET 1BITS ACCORDING TO PRESCALE TYPE, OTHER 2 IS NEGLIBALE*/
			                                         
#elif RCC_APB1_PRESCALLER == RCC_PRESCALLER_BY_2    /*CLOCK DEVIDED BY 2*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE1_0);        /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE1_1);       
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_2);       
			                                         
#elif RCC_APB1_PRESCALLER == RCC_PRESCALLER_BY_4    /*CLOCK DEVIDED BY 4*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_0);        /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE1_1);       
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_2);       
			                                         
#elif RCC_APB1_PRESCALLER == RCC_PRESCALLER_BY_8    /*CLOCK DEVIDED BY 8*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE1_0);        /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_1);       
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_2);       
			                                        
#elif RCC_APB1_PRESCALLER == RCC_PRESCALLER_BY_16    /*CLOCK DEVIDED BY 16*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE1_0);         /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
	  	SET_BIT  (RCC_CFGR,RCC_PPRE1_1);
	  	SET_BIT  (RCC_CFGR,RCC_PPRE1_2);
			
#else

	#error "wrong clock configuration input"
		
	#endif


	                   /*CHOOSING PRESCALLER OF AHB BUS INPUT CLOCK*/

#if   RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_0   /*NO PRESCALLER*/
	  	CLR_BIT(RCC_CFGR , RCC_HPRE3);          /*SET 1BITS ACCORDING TO PRESCALE TYPE, OTHER 3 IS NEGLIBALE*/
			                                          
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_2    /*CLOCK DEVIDED BY 2*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE0);          /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE1);          
		  CLR_BIT(RCC_CFGR,RCC_HPRE2);          
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);          
			                                         
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_4     /*CLOCK DEVIDED BY 4*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE0);           /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE1);          
		  CLR_BIT(RCC_CFGR,RCC_HPRE2);          
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);        
			                                        
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_8       /*CLOCK DEVIDED BY 8*/  
		  CLR_BIT(RCC_CFGR,RCC_HPRE0);             /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE15);         
		  CLR_BIT(RCC_CFGR,RCC_HPRE2);            
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);           
			
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_16    /*CLOCK DEVIDED BY 16*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE0);           /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE1);           
		  CLR_BIT(RCC_CFGR,RCC_HPRE2);           
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);           
			                                          
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_64     /*CLOCK DEVIDED BY 64*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE0);            /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE1);           
		  SET_BIT  (RCC_CFGR,RCC_HPRE2);           
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);            
			                                           
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_128   /*CLOCK DEVIDED BY */
		  SET_BIT  (RCC_CFGR,RCC_HPRE0);            /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE1);           
		  SET_BIT  (RCC_CFGR,RCC_HPRE2);          
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);          
			
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_256     /*CLOCK DEVIDED BY 256*/
		  CLR_BIT(RCC_CFGR,RCC_HPRE0);             /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE1);
		  SET_BIT  (RCC_CFGR,RCC_HPRE2);
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);
			
#elif RCC_AHP_PRESCALLER == RCC_PRESCALLER_BY_512    /*CLOCK DEVIDED BY 512*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE0);            /*SET 4BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_HPRE1);
		  SET_BIT  (RCC_CFGR,RCC_HPRE2);
		  SET_BIT  (RCC_CFGR,RCC_HPRE3);
#else

	#error "wrong clock configuration input"
		
	#endif

	                                              /*ADJUST CLOCK SECUITRY*/
#if   CSS_ON == TURN_ON                             /*ENABLE SECRITU BIT*/
		 SET_BIT  (RCC_CR,RCC_CSS_ON);
#elif CSS_ON == TURN_OFF                         /*DISABLE SECRITU BIT*/
		 CLR_BIT(RCC_CR,RCC_CSS_ON);
#endif    

}

/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidEnableClock(uint8 Copy_u8BusId ,  
                         uint8 Copy_u8PerId   )
{


}   

/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidDisableClock(uint8 Copy_u8BusId ,  
                          uint8 Copy_u8PerId   )
{

}   

/// @brief 
/// @param Copy_u8BusId 
/// @param Copy_u8PerId 
void RCC_VoidResetPeriph(uint8 Copy_u8BusId ,  
                         uint8 Copy_u8PerId   )
{

}                         

