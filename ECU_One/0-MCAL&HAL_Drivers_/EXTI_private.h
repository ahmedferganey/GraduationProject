/*
 * FileName		: EXTI_private.h
 * Created		: 8/30/2023 4:36:15 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_


/*-------------------------------- Includes --------------------------------*/



/*-------------------------------- Macro Declarations --------------------------------*/
/* !Comment: Register Summary */
#define MCUCSR		*((volatile uint8*)0x54)
#define MCUCR		*((volatile uint8*)0x55)
#define GIFR        *((volatile uint8*)0x5A)
#define GICR        *((volatile uint8*)0x5B)

/* !Comment: MCUCR Bits */
#define MCUCR_ISC11			3   /* ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0*/
#define MCUCR_ISC10			2   /* ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0*/
#define MCUCR_ISC01			1   /* ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0*/
#define MCUCR_ISC00			0   /* ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0*/

/* !Comment: MCUCSR Bits */
#define MCUCSR_ISC2			6   /* ISC2: Interrupt Sense Control 2*/

/* !Comment: GIFR Bits */
#define GIFR_INTF1			7   /* INTF1: External Interrupt Flag 1*/
#define GIFR_INTF0			6   /* INTF0: External Interrupt Flag 0*/
#define GIFR_INTF2			5   /* INTF2: External Interrupt Flag 2*/


/*
 !Comment: GICR Bits 
#define GICR_INT1			7    INT1: External Interrupt Request 1 Enable
#define GICR_INT0			6    INT0: External Interrupt Request 0 Enable
#define GICR_INT2			5    INT2: External Interrupt Request 2 Enable
*/

/*-------------------------------- Macro Functions Declarations --------------------------------*/


/*-------------------------------- Data Type Declarations --------------------------------*/


/*-------------------------------- Software Interfaces Declarations --------------------------------*/


#endif /* _EXTI_PRIVATE_H_ */