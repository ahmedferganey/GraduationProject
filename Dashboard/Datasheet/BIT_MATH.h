/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-14 08:39:13
 * @modify date 2023-10-14 08:39:13
 * @desc [description]
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit)     reg|=(1<<bit)
#define CLR_BIT(reg,bit)     reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)     reg^=(1<<bit)
#define GET_BIT(reg,bit)     (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)


#endif //BIT_MATH_H_