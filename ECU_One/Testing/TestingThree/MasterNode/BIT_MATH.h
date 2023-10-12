/*
 * FileName		: BIT_MATH.h
 * Created		: 8/5/2023 8:37:28 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

/* Comment!: Includes */
#define BIT_MASK	(uint8)1


/* Comment!: Macro Declarations */


/* Comment!: Macro Functions Declarations */
#define REGISTER_SIZE 8

#define	SET_BIT(REG, BIT_POSN)	(REG |=  (BIT_MASK << BIT_POSN))
#define	TOG_BIT(REG, BIT_POSN)	(REG ^=  (BIT_MASK << BIT_POSN)) 
#define	CLR_BIT(REG, BIT_POSN)	(REG &=  (~(BIT_MASK << BIT_POSN)))
#define	GET_BIT(REG, BIT_POSN)	((REG >> BIT_POSN) & BIT_MASK) 

#define IS_BIT_SET(REG,bit)  (REG&(1<<BIT_POSN))>>BIT_POSN
#define IS_BIT_CLR(REG,bit)  !((REG&(1<<BIT_POSN))>>BIT_POSN)

/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _BIT_MATH_H_ */