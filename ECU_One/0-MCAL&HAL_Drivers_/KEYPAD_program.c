/*
 * FileName		: KEYPAD_program.c
 * Created		: 8/7/2023 3:28:28 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#define F_CPU 16000000UL
#include "util/delay.h"

/******************************* Comment!: Global variables *********************************/
/* this var is 4 bytes, 4bit for every pin"port,pin,direction,logic",and we have 8 pins */
keypad_t udtKeypadTarget = {
		.keypad_row_pins[0].port		= KEYPAD_PORT,
		.keypad_row_pins[0].pin			= KEYPAD_R0_PIN,
		.keypad_row_pins[0].direction	= DIO_DIRECTION_OUTPUT,
		.keypad_row_pins[0].logic		= DIO_LOW,
		.keypad_row_pins[1].port		= KEYPAD_PORT,
		.keypad_row_pins[1].pin			= KEYPAD_R1_PIN,
		.keypad_row_pins[1].direction	= DIO_DIRECTION_OUTPUT,
		.keypad_row_pins[1].logic		= DIO_LOW,	
		.keypad_row_pins[2].port		= KEYPAD_PORT,
		.keypad_row_pins[2].pin			= KEYPAD_R2_PIN,
		.keypad_row_pins[2].direction	= DIO_DIRECTION_OUTPUT,
		.keypad_row_pins[2].logic		= DIO_LOW,
		.keypad_row_pins[3].port		= KEYPAD_PORT,
		.keypad_row_pins[3].pin			= KEYPAD_R3_PIN,
		.keypad_row_pins[3].direction	= DIO_DIRECTION_OUTPUT,
		.keypad_row_pins[3].logic		= DIO_LOW,
		.keypad_columns_pins[0].port		= KEYPAD_PORT,
		.keypad_columns_pins[0].pin			= KEYPAD_C0_PIN,
		.keypad_columns_pins[0].direction	= DIO_DIRECTION_INPUT,
		.keypad_columns_pins[0].logic		= DIO_LOW,
		.keypad_columns_pins[1].port		= KEYPAD_PORT,
		.keypad_columns_pins[1].pin			= KEYPAD_C1_PIN,
		.keypad_columns_pins[1].direction	= DIO_DIRECTION_INPUT,
		.keypad_columns_pins[1].logic		= DIO_LOW,
		.keypad_columns_pins[2].port		= KEYPAD_PORT,
		.keypad_columns_pins[2].pin			= KEYPAD_C2_PIN,
		.keypad_columns_pins[2].direction	= DIO_DIRECTION_INPUT,
		.keypad_columns_pins[2].logic		= DIO_LOW,
		.keypad_columns_pins[3].port		= KEYPAD_PORT,
		.keypad_columns_pins[3].pin			= KEYPAD_C3_PIN,
		.keypad_columns_pins[3].direction	= DIO_DIRECTION_INPUT,
		.keypad_columns_pins[3].logic		= DIO_LOW
		};



/***************************** Comment!: APIs Implementation ********************************/
/********************************************************************************************/
/* @brief				    : this function have an argument, must called "udtKeypadTarget"	*/
/* @param   pudtKeypadTarget: pointer to created struct in Keypad.c		 @ref keypad_t*		*/
/* @return  Std_ReturnType																	*/
/*           (E_OK)		    : The function done successfully								*/
/*           (E_NOT_OK)     : The function has issue to perform this action					*/
/********************************************************************************************/
Std_ReturnType KEYPAD_udtInit
(
const keypad_t * pudtKeypadTarget
)
{
	Std_ReturnType udtReturnValue = E_OK;
    uint8 rows_counter		= ZERO_INIT; 
	uint8 columns_counter	= ZERO_INIT;
	
	if(NULL == pudtKeypadTarget)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
        for(rows_counter=ZERO_INIT; rows_counter<ROW_NUM; rows_counter++)
		{
			udtReturnValue = DIO_udtSetPinDirection(KEYPAD_PORT,
													((pudtKeypadTarget->keypad_row_pins[rows_counter].pin)),
													DIO_DIRECTION_INPUT);	
			udtReturnValue = DIO_udtSetPinValue(KEYPAD_PORT, 
												((pudtKeypadTarget->keypad_row_pins[rows_counter].pin)), 
												DIO_HIGH);
		}
        for(columns_counter=ZERO_INIT; columns_counter<COL_NUM; columns_counter++)
        {
	        udtReturnValue = DIO_udtSetPinDirection(KEYPAD_PORT,
													((pudtKeypadTarget->keypad_columns_pins[columns_counter].pin)),
													DIO_DIRECTION_OUTPUT);
	        udtReturnValue = DIO_udtSetPinValue(KEYPAD_PORT,
											    ((pudtKeypadTarget->keypad_columns_pins[columns_counter].pin)),
											    DIO_HIGH);
        }	
	}
	return udtReturnValue;
}


/********************************************************************************************/
/*  @brief				  : send command to lcd												*/
/*  @return	 Std_ReturnType																	*/
/*  @param	 u8Command	  : the required operation we need to implement it	 @ref uint8	    */
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
Std_ReturnType KEYPAD_udtGetPressedKey
(
const keypad_t *pudtKeypadTarget, 
uint8 *value
)
{
	Std_ReturnType udtReturnValue = E_OK;
	uint8 u8ColumnID = ZERO_INIT;
	uint8 u8RowID	 = ZERO_INIT;
	logic_t udtPinValue;
	uint8 u8PressedKey = KPD_NO_PRESSED_VALUE;				/* !Comment: KPD_NO_PRESSED_VALUE = 0xff */
	uint8 u8KpdMatrix[ROW_NUM][COL_NUM]	=  KPD_BUTTONS;		/* !Comment: Actual values of KPD Button */
	uint8 u8LocalCounter = ZERO_INIT;
	
	if((NULL == pudtKeypadTarget) || (NULL == value))
	{
		udtReturnValue = E_NOT_OK;		
	}
	else
	{
		for (u8ColumnID = 0u; u8ColumnID < COL_NUM; u8ColumnID++)
		{
			/* !comment: logic high by default for input pins of columns*/			
			for(u8LocalCounter = ZERO_INIT; u8LocalCounter < COL_NUM; u8LocalCounter++)
			{
				udtReturnValue = DIO_udtSetPinValue(KEYPAD_PORT,
													((pudtKeypadTarget->keypad_columns_pins[u8LocalCounter].pin)),
													DIO_HIGH);				
			}
			/* !comment: enable column X, it is logic high by default */
			udtReturnValue = DIO_udtSetPinValue(KEYPAD_PORT, 
												((pudtKeypadTarget->keypad_columns_pins[u8ColumnID].pin)), 
												DIO_LOW);			
			/* !comment: iterate on the rows to get the pressed button */
			for(u8RowID = 0u; u8RowID < ROW_NUM; u8RowID++)
			{
				/* !comment: read row y */
				udtReturnValue = DIO_udtGetPinValue(KEYPAD_PORT,
													((pudtKeypadTarget->keypad_row_pins[u8RowID].pin)),
													&udtPinValue);
				/* !comment: if row pin value is low */
				if(0 == udtPinValue)
				{
					/* !comment: Our key is found Row and column  */
					u8PressedKey = u8KpdMatrix[u8RowID][u8ColumnID];
					/* !comment: Key is found, to prevent printing selected number a lot of 
								 times so we wait here until released button & debouncing */
					while(0 == udtPinValue)
					{
						udtReturnValue =  DIO_udtGetPinValue(KEYPAD_PORT,
															 ((pudtKeypadTarget->keypad_row_pins[u8RowID].pin)),
															 &udtPinValue);
					}
					/* !comment:   */
					*(value) = (uint8)u8PressedKey;
				}				
			}
		}
	}
	return udtReturnValue;	
}
