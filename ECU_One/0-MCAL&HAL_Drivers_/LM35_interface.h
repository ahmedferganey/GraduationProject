/*
 * FileName		: LM35_interface.h
 * Created		: 9/17/2023 11:13:37 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _LM35_INTERFACE_H_
#define _LM35_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/
#define ADC_RESOLUTION_10_BIT	 	0
#define ADC_RESOLUTION_8_BIT  		1

/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
typedef struct
{
	uint8 Copy_u8LM35Channel;		/* For ADC_GetResult API */
	uint8 Copy_u8ADCVoltageRef;		/* Vref = 5 , 2.56 , External  */
	uint8 Copy_u8ADCResolution;		/* ADC_RESOLUTION_10_BIT or ADC_RESOLUTION_8_BIT  */
}LM35_Config_t;

/* -------------------------------- Function Declarations ---------------------------------------*/
/*
	- The sensitivity of LM35 is 10 mV/degree Celsius. As temperature increases, o
	  utput voltage also increases.
	- 250 mV means 25°C.
	- It is a 3-terminal sensor used to measure surrounding temperature 
	  ranging from -55 °C to 150 °C.
*/
/*
	- Specification of LM35 Temperature Sensor
	- Operating Voltage: 4 V to 30 V
	- Output Voltage: 10mV/°C
	- Sensitivity: 10mV/°C
	- Linearity Error: ±1°C (for 0°C to +100°C)
	- Operating Temperature: -55°C to +150°C
	- Output Impedance: 100 Ω
	- Power Consumption: 60 μA (typical)
	- Package Type: TO-92, TO-220, SOIC
	- Output Type: Analog
	- Accuracy: ±1°C (typical)
*/
Std_ReturnType LM35_udtGetTemp 
(
LM35_Config_t* LM35_pudtConfig, 			
uint8* LM35_pu8TempValue
);


#endif  /* _LM35_INTERFACE_H_ */