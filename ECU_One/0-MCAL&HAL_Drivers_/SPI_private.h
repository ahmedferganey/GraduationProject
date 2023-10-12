/*
 * FileName		: SPI_private.h
 * Created		: 9/16/2023 8:33:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_


/*-------------------------------- Includes --------------------------------------------------------*/



/*-------------------------------- Macro Declarations ----------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////
/* Registers Definition  */
#define SPCR	*((volatile uint8*)0X2D)
#define SPSR	*((volatile uint8*)0X2E)
#define SPDR	*((volatile uint8*)0X2F)

/* Bit Position SPCR */
#define SPCR_SPIE			7
#define SPCR_SPE			6
#define SPCR_DORD			5
#define SPCR_MSTR			4
#define SPCR_CPOL			3
#define SPCR_CPHA			2
#define SPCR_SPR1			1
#define SPCR_SPR0			0
/* Bit Position SPSR */
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0
//////////////////////////////////////////////////////////////////////////////////

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _SPI_PRIVATE_H_ */