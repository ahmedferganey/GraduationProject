/*
 * FileName		: STD_TYPES.h
 * Created		: 8/5/2023 9:11:45 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/* Section: Includes */


/* Section: Macro Declarations */
#define	STD_HIGH		0X01
#define	STD_LOW			0X00

#define	STD_ON			0X01
#define	STD_OFF			0X00

#define	STD_ACTIVE		0X01
#define	STD_IDLE		0X00
#define NULL			0
#define	ZERO_INIT		0
#define	LOGIC_ZERO		0


/* Comment!: Macro Functions Declarations */


/* Comment!: Data Type Declarations */
typedef	unsigned char 	uint8;
typedef	unsigned short 	uint16;
typedef	unsigned long 	uint32;
typedef	signed   char 	sint8;
typedef	signed   short 	sint16;
typedef	signed   long 	sint32;

typedef	enum 
{
	E_OK,
	E_NOT_OK,
	E_PENDING,
	E_TIMEOUT
}Std_ReturnType;

/* Comment!: Function Declarations */


#endif	/* _STD_TYPES_H_ */