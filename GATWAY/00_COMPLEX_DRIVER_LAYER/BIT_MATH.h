/*
 * FileName		: BIT_MATH.h
 * Created		: 8/5/2023 8:37:28 PM
 * Author		: Ahmed Ferganey
 */ 


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

/* Comment!: Includes */
#define BIT_MASK	1


/* Comment!: Macro Declarations */


/* Comment!: Macro Functions Declarations */

#define SET_BIT(REG,BIT_NUM)    ((REG)  |=  (BIT_MASK   << BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)  	((REG)   ^= (BIT_MASK << BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)    ((REG)  &= ~(BIT_MASK   << BIT_NUM))
#define GET_BIT(REG,BIT_NUM)    ((REG >> BIT_NUM) & (BIT_MASK))


#define IS_BIT_SET(REG,BIT_NUM)    (REG&(BIT_MASK<<BIT_NUM))>>BIT_NUM
#define IS_BIT_CLEAR(REG,BIT_NUM)  !((REG&(BIT_MASK<<BIT_NUM))>>BIT_NUM)



#define ACCESS_REG_8BIT(REG)         (*(volatile u8  * )REG)
#define ACCESS_REG_16BIT(REG)        (*(volatile u16 * )REG)
#define ACCESS_REG_32BIT(REG)        (*(volatile u32 * )REG)

 
/* Comment!: Data Type Declarations */


/* Comment!: Function Declarations */


#endif	/* _BIT_MATH_H_ */