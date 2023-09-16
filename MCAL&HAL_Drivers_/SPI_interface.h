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
/* macro for postbuild init function*/
#define SPI_INTERRUPT_DISABLE					0
#define SPI_INTERRUPT_ENABLE 					1

#define SPI_DISABLE								0
#define SPI_ENABLE 								1

#define SPI_DATA_LSB_FIRST 						0
#define SPI_DATA_MSP_FIRST 						1

#define SPI_MASTER								0
#define SPI_SLAVE 								1

#define SPI_RISING_LEADING_FALLING_TRAILING 	0
#define SPI_FALLING_LEADING_RISING_TRAILING		1

#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

#define SPI_FREQ_DIVIDED_BY_2					0
#define SPI_FREQ_DIVIDED_BY_4					1
#define SPI_FREQ_DIVIDED_BY_8					2
#define SPI_FREQ_DIVIDED_BY_16					3
#define SPI_FREQ_DIVIDED_BY_32					4
#define SPI_FREQ_DIVIDED_BY_64					5
#define SPI_FREQ_DIVIDED_BY_128					6
/*-------------------------------- Macro Functions Declarations ------------------------------------*/


/*-------------------------------- Data Type Declarations ------------------------------------------*/
/* !Comment: for init another config in run time*/
	/* note control registers have 7 principles so 
	   we create struct with 7 features */
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

/* !Comment: for Ayscnh Transiev API */
typedef struct
{
	uint8* Copy_u8TData;
	uint8* Copy_u8RData;
	uint8  Copy_u8BufferSize;
	void (* NotificationFunc)(void);
}SPI_Buffer_t;



/*-------------------------------- Software Interfaces Declarations --------------------------------*/
void SPI_VdInit
(
void
);



Std_ReturnType SPI_udtInitConfig 
(
SPI_CONFIG_t* pudtSPINewConfig
);



Std_ReturnType SPI_udtTranceive 
(
const uint8 Copy_u8TData, 
uint8* Copy_u8RData
);



Std_ReturnType SPI_udtBufferTranceiverSynch 
(
uint8* Copy_u8TData, 
uint8* Copy_u8RData, 
uint8 Copy_u8BufferSize
);



Std_ReturnType SPI_udtBufferTranceiverAsynch 
(
SPI_Buffer_t* pudtSPIBuffer
);



#endif  /* _SPI_INTERFACE_H_ */