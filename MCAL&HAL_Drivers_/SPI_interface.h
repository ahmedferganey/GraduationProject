/*
 * FileName		: SPI_interface.h
 * Created		: 9/16/2023 8:34:11 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_


/*-------------------------------- Includes --------------------------------------------------------*/
#include "STD_TYPES.h"


/*-------------------------------- Macro Declarations ----------------------------------------------*/

/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/
/* !Comment: for init another config in run time*/
	/* note control registers have 7 principles so 
	   we create struct with 7 prnciples */
typedef struct
{
	uint8 SPI_u8InterruptEnable;
	uint8 SPI_u8SPIEnable;
	uint8 SPI_u8DataOrder;
	uint8 SPI_u8MasterSlaveSelect;
	uint8 SPI_u8ClockPolarity;
	uint8 SPI_u8ClockPhase;
	uint8 SPI_u8ClockRate;	
}SPI_CONFIG_t;

/*-------------------------------- Software Interfaces Declarations --------------------------------*/
void SPI_VdInit
(
void
);

Std_ReturnType SPI_u8InitConfig 
(
SPI_CONFIG_t* pudtSPINewConfig
);

#endif  /* _SPI_INTERFACE_H_ */