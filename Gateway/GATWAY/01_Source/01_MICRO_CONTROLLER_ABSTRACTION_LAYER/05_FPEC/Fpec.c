/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-13 00:38:46
 * @modify date 2023-10-13 00:38:46
 * @desc [description]
 */


/* Library includes */
#include "BIT_MATH.h"
#include "Std_Types.h"

/* Module includes */
#include "Fpec_Interface.h"
#include "Fpec_Cfg.h"
#include "Fpec_Private.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     *******FUNCTIONS DEFINITION******                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief 
/// @param copy_u32Address 
/// @param copy_u16Data 
/// @return 
uint8 FPEC_WriteHalfWord( uint32 copy_u32Address, uint16 copy_u16Data)
{
	Std_ReturnType local_u8Error ; 
	/* Wait if read or write operation is under execution */
	while (GET_BIT ((FPEC -> FLASH_SR ), BSY ));
	
	/* Check on the lock bit */
	if (GET_BIT ((FPEC -> FLASH_CR ), LOCK )){
		/* if FPEC locked perform a lock sequence */
		FPEC -> FLASH_KEYR = FPEC_KEY1 ;
		FPEC -> FLASH_KEYR = FPEC_KEY2 ;
	}
	
	/* Enable program */
	SET_BIT ((FPEC -> FLASH_CR ), PG );
	
	/* Write byte at the desired place */
	 (*(uint16 *)copy_u32Address) = copy_u16Data ;
	
	/* Wait till the wirte is done */
	while (GET_BIT ((FPEC -> FLASH_SR ), BSY ));
	
	/* Disable PG */
	CLR_BIT ((FPEC -> FLASH_CR ), PG );
	
	/* End of Operation*/
	SET_BIT ((FPEC -> FLASH_SR ), EOP);

	/* Check on Data */
	if ((*(uint16 *)copy_u32Address) == copy_u16Data){
		local_u8Error = WRITE_DONE ;
	}
	else {
		local_u8Error = WRITE_ERROR ;
	}
	
	return local_u8Error ;
}

/// @brief 
/// @param copy_u8PageNumber 
void FPEC_voidErasePage( uint8 copy_u8PageNumber )
{
	/* Wait if read or write operation is under execution */
	while (GET_BIT ((FPEC -> FLASH_SR ), BSY ));
	
	/* Check on the lock bit */
	if (GET_BIT ((FPEC -> FLASH_CR ), LOCK )){
		/* if FPEC locked perform a lock sequence */
		FPEC -> FLASH_KEYR = FPEC_KEY1 ;
		FPEC -> FLASH_KEYR = FPEC_KEY2 ;
	}
	
	/* Enable erase for page */
	SET_BIT ((FPEC -> FLASH_CR ), PER );
	
	/* Set Address for page */
	FPEC -> FLASH_AR = FPEC_FLASH_START_ADDRESS + (uint32) (copy_u8PageNumber * FPEC_FLASH_PAGE_SIZE) ;
	
	/* Start erase */
	SET_BIT ((FPEC -> FLASH_CR ), STRT );

	/* Wait till the erase is done */
	while (GET_BIT ((FPEC -> FLASH_SR ), BSY ));

	/* End of Operation*/
	SET_BIT ((FPEC -> FLASH_SR ), EOP);
	
	/* Disable erase for page */
	CLR_BIT ((FPEC -> FLASH_CR ), PER );
	
	/* Lock Flash */
	SET_BIT ((FPEC -> FLASH_CR ),LOCK);
}

/// @brief 
/// @param  
void FPEC_voidMassErase(void)
{
	/* Check on the lock bit */
	if (GET_BIT ((FPEC -> FLASH_CR ), LOCK )){
		/* if FPEC locked perform a lock sequence */
		FPEC -> FLASH_KEYR = FPEC_KEY1 ;
		FPEC -> FLASH_KEYR = FPEC_KEY2 ;
	}
	
	/* Enable erase for page */
	SET_BIT ((FPEC -> FLASH_CR ), MER );
	
	/* Start erase */
	SET_BIT ((FPEC -> FLASH_CR ), STRT );

	/* Wait till the erase is done */
	while (GET_BIT ((FPEC -> FLASH_SR ), BSY ));
}



/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/					