/*****************************************************/
 /* Author      : mosad                              */
 /* Version     : v01                                */
 /* date        : 9/10/2020                          */
/*****************************************************/

		
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

#define    WRITE_DONE    1
#define    WRITE_ERROR   0


/// @brief 
/// @param copy_u32Address 
/// @param copy_u16Data 
/// @return 
uint8 FPEC_WriteHalfWord( uint32 copy_u32Address, uint16 copy_u16Data);

/// @brief 
/// @param copy_u8PageNumber 
void FPEC_voidErasePage( uint8 copy_u8PageNumber );

/// @brief 
/// @param  
void FPEC_voidMassErase(void);





#endif
