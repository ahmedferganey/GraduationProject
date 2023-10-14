/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-14 08:40:10
 * @modify date 2023-10-14 08:40:10
 * @desc [description]
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#define E_OK 		0x00u
#define E_NOT_OK 	0x01u
#define STD_HIGH 	0x01u   /* Physical state 5V or 3.3V */
#define STD_LOW  	0x00u   /* Physical state 0V */
#define STD_ACTIVE 	0x01u 	/* Logical state active */
#define STD_IDLE   	0x00u 	/* Logical state idle */
#define STD_ON  	0x01u
#define STD_OFF 	0x00u


typedef unsigned char           u8 ;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;
typedef signed char	            s8 ;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;
typedef float                   f32;
typedef double                  f64;
typedef enum
	{
		fasle,
		true,
	}bool;

/* The data type Std_TransformerError is a struct which contains the error code and the
transformer class to which the error belongs */
typedef struct {
	uint8            errorCode ;
	Std_TransformerClass transformerClass ;

}Std_TransformerError;

typedef enum{

	OK,
	NOK,
	OUT_OF_RANGE,
	NULL_POINTER

}ErrorStatus;


#define NULL 0


	
#endif // STD_TYPES_H_ 