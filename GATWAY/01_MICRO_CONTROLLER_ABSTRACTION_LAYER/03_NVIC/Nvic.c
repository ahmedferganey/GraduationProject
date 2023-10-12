/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-12 23:44:46
 * @modify date 2023-10-12 23:44:46
 * @desc [description]
 */


/* Library includes */
#include "BIT_MATH.h"
#include "Std_Types.h"

/* Module includes */
#include "Nvic_Interface.h"
#include "Nvic_Private.h"
#include "Nvic_Cfg.h"




////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     *******FUNCTIONS DEFINITION******                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param  
void NVIC_voidInit(void)
{
	/* Choose configurations */	
	#if   NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_16
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_16 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_8
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_8 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_4
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_4 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_2
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_2 << GROUPING_BIT) )  ;
		
	#elif NVIC_GROUPING_PRIORITY_TYPE == NVIC_GROUPING_0
		SCB_AIRCR = ( VECTKEY | (NVIC_GROUPING_0 << GROUPING_BIT) )  ;      //[10:8]PRIGROUPInterrupt priority grouping field:
	
	#else 
		#error (" Configuration error ")
	#endif

}

/// @brief 
/// @param copyIRQn 
void NVIC_voidEnableIRQ(NVIC_IRQn_t copyIRQn)
{
	/* Devided by 32 to write to the right regsiter index         */
	/* Anding (copyIRQn) with 31 so value will always be under 32 */
	uint8 reg_index = copyIRQn / 32 ;  //if copyIRQn --> from the first 31 bit will be index 0 
	NVIC->ISER[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

/// @brief 
/// @param copyIRQn 
void NVIC_voidDisableIRQ(NVIC_IRQn_t copyIRQn)
{
	uint8 reg_index = copyIRQn / 32 ;
	NVIC->ICER[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

/// @brief 
/// @param copyIRQn 
/// @return 
uint8   NVIC_u8GetPendingIRQ (NVIC_IRQn_t copyIRQn)
{
	uint8 reg_index = copyIRQn / 32 ;
	uint8 bit = GET_BIT(NVIC->ISPR[ reg_index ] , (copyIRQn & 31 ) ) ;
	return bit ; 
}

/// @brief 
/// @param copyIRQn 
void NVIC_voidSetPendingIRQ (NVIC_IRQn_t copyIRQn)
{
	uint8 reg_index = copyIRQn / 32 ;
	NVIC->ISPR[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

/// @brief 
/// @param copyIRQn 
void NVIC_voidClearPendingIRQ (NVIC_IRQn_t copyIRQn)
{
	uint8 reg_index = copyIRQn / 32 ;
	NVIC->ICPR[ reg_index ] = (1 << (copyIRQn & 31 )) ;
}

/// @brief 
/// @param copyIRQn 
/// @return 
uint8  NVIC_u8GetActive (NVIC_IRQn_t copyIRQn)
{
	uint8 reg_index = copyIRQn / 32 ;
	uint8 bit = GET_BIT(NVIC->IABR[ reg_index ] , (copyIRQn & 31 ) ) ;
	return bit ;
}

/// @brief 
/// @param copyIRQn 
/// @param copy_u8Priority 
void NVIC_voidSetPriority (NVIC_IRQn_t copyIRQn, uint8 copy_u8Priority)
{
	/* Writing into the four bit the periority */
	NVIC->IPR[ copyIRQn ] = (copy_u8Priority << 4);
}

/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/					