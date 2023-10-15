/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-10-12 23:40:54
 * @modify date 2023-10-12 23:40:54
 * @desc [description]
 */

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*
	Options : 
		NVIC_GROUPING_16         * sub priority = 0 *
		NVIC_GROUPING_8          * sub priority = 2 *    
		NVIC_GROUPING_4          * sub priority = 4 *     
		NVIC_GROUPING_2          * sub priority = 8 *     
		NVIC_GROUPING_0          * sub priority = 16 *
	
	To disable nesting choose ( NVIC_GROUPING_0 )
*/
#define     NVIC_GROUPING_PRIORITY_TYPE       NVIC_GROUPING_0




#endif