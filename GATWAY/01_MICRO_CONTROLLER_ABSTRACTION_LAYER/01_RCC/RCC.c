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
	
           SET_BIT(RCC_CR,RCC_HSE_ON);             /*ENABLE EXTERNAL CLOCK SOURCE BIT*/	
	         while(WAIT_HSE_GET_READY); /*WAIT TILL HSE CLOCK IS READY*/
	         CLR_BIT(RCC_CR , RCC_HSE_BYP);	     /*DISABLE EXTERNAL CLOCK BY PASS*/ 
	         SET_BIT  (RCC_CFGR , RCC_SW0 );           /*ADJUST SYSTEM CONTROL SWITCH*/
		       CLR_BIT(RCC_CFGR , RCC_SW1 );
	           
 #elif     (RCC_CLOCK_TYPE == RCC_HSE_RC)            /*CONFIGURATION OF EXTERNAL RC CLOCK SOURCE*/
	
	        SET_BIT(RCC_CR   , RCC_HSE_ON);        /*ENABLE EXTERNAL RC CLOCK SOURCE BIT*/
	        while(WAIT_HSE_GET_READY);      /*WAIT TILL HSE CLOCK IS READY*/
		      SET_BIT  (RCC_CR , RCC_HSE_BYP);	     /*ENABLE EXTERNAL CLOCK BY PASS*/
	      	SET_BIT(RCC_CFGR , RCC_SW0);          /*ADJUST SYSTEM CONTROL SWITCH*/
		      CLR_BIT(RCC_CFGR , RCC_SW1);
	
 #elif     (RCC_CLOCK_TYPE == RCC_HSI)               /*CONFIGURATION OF INTERNAL CLOCK SOURCE*/
	
	          SET_BIT  (RCC_CR   , RCC_HSI_ON);       /*ENABLE INTERNAL CLOCK SOURCE BIT*/
	         	while(WAIT_HSI_GET_READY); /*WAIT TILL HSE CLOCK IS READY*/
		        CLR_BIT(RCC_CFGR , RCC_SW0);          /*ADJUST SYSTEM CONTROL SWITCH*/ 
	         	CLR_BIT(RCC_CFGR , RCC_SW1);
	
 #elif     (RCC_CLOCK_TYPE == RCC_PLL)             /*CONFIGURATION OF PLL CLOCK SOURCE*/
 
	         RCC_CFGR &= ~(PLL_BITS_SHIFT         << RCC_PLL_MUL0);         /*CLEAR 4BITS USED TO ADJUST MUL*/
	         RCC_CFGR |=  ((RCC_PLL_MAL_VAL - 2 ) << RCC_PLL_MUL0);         /* SET NEW MUL 4BITS VALUE*/
					 
		                                      /*CHOICES PLL INPUT SOURCE*/
 #if   RCC_PLL_SOURCE == RCC_PLL_HSI_BY2    
					 
		    	SET_BIT  (RCC_CR, RCC_HSI_ON ); /*ENBLE INTERNAL CLOCK */
		     	CLR_BIT(RCC_CFGR , RCC_PLL_SRC);  /*INTERNAL CLOCK DEVIDED BY 2 AS SOURCE OF PLL*/
					SET_BIT  (RCC_CR,RCC_PLL_ON);    /*ENABLE PLL BIT*/
					
#elif RCC_PLL_SOURCE == RCC_PLL_HSE_BY2

  			 SET_BIT(RCC_CR , RCC_HSE_ON );  /*ENBLE EXTERNAL CLOCK */
	  		 SET_BIT(RCC_CFGR , RCC_PLL_XT_PRE); /*SET THIS BIT TO DEVIDE THE EXTERNAL CLOCK */
		  	 SET_BIT(RCC_CFGR , RCC_PLL_SRC  ); /*CLOCK FROM PREDIV1 SEKECTED AS PL INPUT CLOCK*/
				 SET_BIT(RCC_CR,RCC_PLL_ON);    /*ENABLE PLL BIT*/

					
			
#elif RCC_PLL_SOURCE == RCC_PLL_HSE

   			 SET_BIT(RCC_CR , RCC_HSE_ON );  /*CHOOSE EXTERNAL CLOCK AS INPUT OF PLL*/
		  	 SET_BIT(RCC_CFGR , RCC_PLL_SRC); /*CHOOSE EXTERNAL CLOCK AS PLL INPUT CLOCK*/
				 SET_BIT(RCC_CR,RCC_PLL_ON);    /*ENABLE PLL BIT*/
			
#else		             
      #error "wrong clock configuration input"  /*if you get here then you choose wrong clock choice*/
							
#endif


#endif

                                              /*CHOOSING OUTPUT CLOCK SOURCE ON MCO PIN*/
																							
#if   RCC_MCO_PIN == NO_CLOCK              /*NO OUTPUT*/
		  CLR_BIT(RCC_CFGR , RCC_MCO_2);    /*SET 1BITS ACCORDING TO CLOCK TYPE OTHER 2 IS NEGLIBALE*/
		 		 
#elif RCC_MCO_PIN == SYSTEM_CLOCK
		  CLR_BIT(RCC_CFGR,RCC_MCO_0);     /*SET 3BITS ACCORDING TO SYSTEM CLOCK TYPE*/
		  CLR_BIT(RCC_CFGR,RCC_MCO_1);
		  SET_BIT  (RCC_CFGR,RCC_MCO_2);		 
		
#elif RCC_MCO_PIN == HSI_CLOCK
		  SET_BIT  (RCC_CR,RCC_HSI_ON);  /*ENABLE INTERNAL CLOCK AS INPUT OF MCO*/
		  SET_BIT  (RCC_CFGR,RCC_MCO_0 ); /*SET 3BITS ACCORDING TO INTERNAL CLOCK TYPE*/
		  CLR_BIT(RCC_CFGR,RCC_MCO_1 );
		  SET_BIT  (RCC_CFGR,RCC_MCO_2 );
		
#elif RCC_MCO_PIN == HSE_CLOCK
		SET_BIT  (RCC_CR ,RCC_HSE_ON);   /*ENABLE EXTERNAL CLOCK AS INPUT OF MCO*/
		CLR_BIT(RCC_CFGR,RCC_MCO_0 );  /*SET 3BITS ACCORDING TO EXTERNAL CLOCK TYPE*/
		SET_BIT  (RCC_CFGR,RCC_MCO_1 );
		SET_BIT  (RCC_CFGR,RCC_MCO_2 );
		
#else
		#error "wrong clock configuration input"
		
#endif
                                              /*CHOOSING PRESCALLER OF ADC INPUT CLOCK*/

#if   RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_2    /*CLOCK DEVIDED BY 2*/
  		CLR_BIT(RCC_CFGR,RCC_ADCPRE0);      /*SET 2BIT ACCORDING TO PRESCALE CHOICE*/
	  	CLR_BIT(RCC_CFGR,RCC_ADCPRE2);
		
#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_4      /*CLOCK DEVIDED BY 4*/
		  SET_BIT  (RCC_CFGR,RCC_ADCPRE0);        /*SET 2BIT ACCORDING TO PRESCALE CHOICE*/
 		  CLR_BIT(RCC_CFGR,RCC_ADCPRE2);
		
#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_6       /*CLOCK DEVIDED BY 6*/
	  	CLR_BIT(RCC_CFGR,RCC_ADCPRE0);         /*SET 2BIT ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_ADCPRE2);
		
#elif RCC_ADC_PRESCALLER == RCC_PRESCALLER_BY_8       /*CLOCK DEVIDED BY 8*/
  		SET_BIT  (RCC_CFGR,RCC_ADCPRE0);         /*SET 2BIT ACCORDING TO PRESCALE CHOICE*/
	  	SET_BIT  (RCC_CFGR,RCC_ADCPRE2);
		
#else
	
#error "wrong clock configuration input"
		
	#endif	
	
	                                              /*CHOOSING PRESCALLER OF APB2 BUS INPUT CLOCK*/
																								
#if   RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_0  /*NO PRESCALLER*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE2_2);       /*SET 1BITS ACCORDING TO PRESCALE TYPE OTHER 2 IS NEGLIBALE*/
			
#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_2   /*CLOCK DEVIDED BY 2*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE2_0);       /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE2_1);
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_2);
			
#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_4   /*CLOCK DEVIDED BY 4*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_0);       /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE2_1);
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_2);
			
#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_8   /*CLOCK DEVIDED BY 8*/
		  CLR_BIT(RCC_CFGR,RCC_PPRE2_0);       /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_1);
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_2);
			
#elif RCC_APB2_PRESCALLER == RCC_PRESCALLER_BY_16   /*CLOCK DEVIDED BY 16*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_0);        /*SET 3BITS ACCORDING TO PRESCALE CHOICE*/
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_1);
		  SET_BIT  (RCC_CFGR,RCC_PPRE2_2);
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

