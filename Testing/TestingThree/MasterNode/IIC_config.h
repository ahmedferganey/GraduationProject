/*
 * FileName		: IIC_config.h
 * Created		: 9/16/2023 3:16:20 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _IIC_CONFIG_H_
#define _IIC_CONFIG_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
#define CPU_CLOCK_FREQUENCY 		8000000UL

/*
	$ Options :-
		1-PRESCALLER_BY_1
		2-PRESCALLER_BY_4
		3-PRESCALLER_BY_16
		4-PRESCALLER_BY_64
*/
		/*
			we will use only no prescaler to use this function instead of 
			using the complex equation of datasheat
		
		*/
#define TWI_PRESCALLER  			PRESCALLER_BY_1

/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_FREQUENCY 				400000UL 

/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/


#endif  /* _IIC_CONFIG_H_ */