/*
 * FileName		: LDR_interface.h
 * Created		: 9/18/2023 10:52:7 AM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _LDR_INTERFACE_H_
#define _LDR_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/



/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/
/*
	for this struct,
			Copy_u8LDRPort :       	PORTA = 0,
									PORTB =	1,
									PORTC =	2,
									PORTD =	3,
									
			Copy_u8LDRPin  :       	PIN0 =  0,
									PIN1 =	1,
									PIN2 =	2,
									PIN3 =	3,
									PIN4 =	4,
									PIN5 =	5,
									PIN6 =	6,
									PIN7 =	7
	Note You must select only the port which has ADC.								
*/

typedef struct 
{
	uint8 Copy_u8LDRPort:4 ;
	uint8 Copy_u8LDRPin :4 ;
}LDR_Config_t;

/* -------------------------------- Function Declarations ---------------------------------------*/
/*
	LDR (Light Dependent Resistor) as the name states is a special type of resistor 
	that works on the photoconductivity principle means that resistance changes according 
	to the intensity of light. Its resistance decreases with an increase in the intensity 
	of light.
*/
/*
	the amount of light entering the LDR the inversely proportional to the resistance of 
	the sensor, and the graph is hyperbolic in nature.
*/
/*
	LDR Applications
		- The photoresistor is generally used in detecting the presence and intensity of light
		- Used in automatic lights that switch on and off according to light
		- Simple Smoke Detector Alarm, Clock with automatic light
		- Optical circuit design
		- Photo proximity switch
		- Laser-based security systems
		- Solar Street Lamps
		- Camera light meters
		- Clock radios
		- Can be used in Dynamic Compressors, some compressors use LDR and LED connected to the 
			signal source to create changes in signal gain.
*/
/*
	Limitation:
		LDRs require a few milliseconds or more to respond fully to the changes in 
		light intensity, i.e. they require a few seconds to return to their normal 
		resistance once the light source is removed.
		The sensitivity of a Light-dependent resistor varies with the light wavelength. 
		If the wavelength is outside a certain range, it will not affect the resistance at all.
		Light-dependent resistors have lower sensitivity than photodiodes and phototransistors.
*/
/*
	https://www.youtube.com/watch?v=4fN1aJMH9mM
	https://www.youtube.com/watch?v=SkGmtsA69ts
*/
//////////////////////////////////////////////////////////////////////////////////////////////
/***********************	 				APIs						***********************/
Std_ReturnType LDR_udtInit
(
LDR_Config_t* pudtLDRConfig
);


Std_ReturnType LDR_udtReadValue
(
uint16* pu16LDRValue,
LDR_Config_t* pudtLDRConfig
);























#endif  /* _LDR_INTERFACE_H_ */