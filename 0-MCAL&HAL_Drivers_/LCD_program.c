/*
 * FileName		: LCD_program.c
 * Created		: 8/6/2023 3:28:47 PM
 * Author		: Ahmed Ferganey
 */ 

/* Comment!: Includes */
#include "LCD_interface.h"







/*************************** Comment!: Static APIs Decleration ******************************/
static Std_ReturnType  LCD_udt4bit_send_enable_signal(void);



/***************************** Comment!: APIs Implementation ********************************/
								/* Comment!: 4 BIT-Mode */
/********************************************************************************************/
/*  @brief				  : initialization lcd												*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udt4BitInitialize
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	/* !Comment: initialization of data pins control pins */
	//LCD_DATA_DIRECTION = 0xFF;
	_delay_ms(10);	
	udtReturnValue = DIO_udtSetPinDirection(CLCD_DATA_PORT, CLCD_D4, DIO_DIR_OUTPUT);
	udtReturnValue = DIO_udtSetPinDirection(CLCD_DATA_PORT, CLCD_D5, DIO_DIR_OUTPUT);
	udtReturnValue = DIO_udtSetPinDirection(CLCD_DATA_PORT, CLCD_D6, DIO_DIR_OUTPUT);
	udtReturnValue = DIO_udtSetPinDirection(CLCD_DATA_PORT, CLCD_D7, DIO_DIR_OUTPUT);
	
	udtReturnValue = DIO_udtSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS, DIO_DIR_OUTPUT);
	udtReturnValue = DIO_udtSetPinDirection(CLCD_CONTROL_PORT, CLCD_RW, DIO_DIR_OUTPUT);
	udtReturnValue = DIO_udtSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN, DIO_DIR_OUTPUT);
	_delay_ms(10);	
	
	/* !Comment: initialization of some command from data sheet */	
		//udtReturnValue = LCD_udt4BitSendCommand(0x33);
		//udtReturnValue = LCD_udt4BitSendCommand(0x32);
	udtReturnValue = LCD_udt4BitSendCommand(LCD_RETURN_HOME);
	_delay_us(2000);
	
	udtReturnValue = LCD_udt4BitSendCommand(LCD_4BIT_MODE_2_LINE_5_IN_7);
	_delay_us(500);
	
	udtReturnValue = LCD_udt4BitSendCommand(LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF); 
	_delay_us(500);
	
	udtReturnValue = LCD_udtClearScreen();
	
	udtReturnValue = LCD_udt4BitSendCommand(LCD_ENTRY_MODE_INC_SHIFT_OFF);
	_delay_ms(2);	
	
	return udtReturnValue;	
}	
#endif



/********************************************************************************************/
/*  @brief				  : send command to lcd												*/
/*  @return	 Std_ReturnType																	*/
/*  @param	 u8Command	  : the required operation we need to implement it	 @ref uint8	    */
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udt4BitSendCommand
(
uint8 u8Command
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	/* !Comment: Clearing Rs to send command */
	udtReturnValue = DIO_udtSetPinValue(LCD_RS, DIO_LOW);
	
	/* !Comment: Clearing Rw to write data */
	udtReturnValue = DIO_udtSetPinValue(LCD_RW, DIO_LOW);
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Command & 0xF0;
	
	/* !Comment: Generate pulse on En pin */
	udtReturnValue = LCD_udt4bit_send_enable_signal();
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Command << 4;
	
	/* !Comment: Generate pulse on En pin */
	udtReturnValue = LCD_udt4bit_send_enable_signal();

	_delay_ms(1);	
	return udtReturnValue;
}
#endif


/********************************************************************************************/
/*  @brief				  : send data to lcd"Characters"									*/
/*  @param	 u8Data		  : the required operation we need to implement it	 @ref uint8	    */
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udt4BitSendData
(
uint8 u8Data
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	/* !Comment: Clearing Rs to send command */
	udtReturnValue = DIO_udtSetPinValue(CLCD_CONTROL_PORT, CLCD_RS, DIO_HIGH);
	
	/* !Comment: Clearing Rw to write data */
	udtReturnValue = DIO_udtSetPinValue(CLCD_CONTROL_PORT, CLCD_RW, DIO_LOW);
	
	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Data & 0xF0;		// send the most 4 bits of data to high nibbles
	
	/* !Comment: Generate pulse on En pin */
	udtReturnValue = LCD_udt4bit_send_enable_signal();

	/* !Comment: Writing the data on the data pins */
	LCD_DATA_PORT = u8Data << 4;		// send the least 4 bits of data to high nibbles
	
	/* !Comment: Generate pulse on En pin */
	udtReturnValue = LCD_udt4bit_send_enable_signal();
	
	_delay_ms(1);	
	return udtReturnValue;	
}
#endif



/********************************************************************************************/
/*  @brief				  : print a sentence of characters on lcd							*/
/*  @param				  : name of array of string							 @ref uint8*	*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udt4BitPrintString
(
uint8* pu8Word
)
{
	Std_ReturnType udtReturnValue = E_OK;
	uint8 u8Counter = ZERO_INIT;
	if(NULL == pu8Word)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		while(pu8Word[u8Counter] != '\0')
		{
			udtReturnValue = LCD_udt4BitSendData(pu8Word[u8Counter]);
			u8Counter++;		
		} 
	}
	return udtReturnValue;
}
#endif



/********************************************************************************************/
/*  @brief				  : go to particular cell in lcd.									*/
/*							SET DDRAM address COMMAND, there is 1 at bit number 7 			*/
/*							so we add 128 + my address.										*/
/*							00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F					*/
/*							40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F					*/
/*  @param	 u8Row		  : the location at particular row				     @ref uint8	    */
/*  @param	 u8Column	  : the location at particular column				 @ref uint8 	*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udtGoTo
(
uint8 u8Row, 
uint8 u8Column
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	if(u8Row == 0)
	{
		udtReturnValue = LCD_udt4BitSendCommand(u8Column + (LCD_BIT7_SET_DDRAM_ADDRESS));
	}
	else if(u8Row == 1)
	{
		udtReturnValue = LCD_udt4BitSendCommand((u8Column + (LCD_START_ADDRESS_COL_TWO)) + (LCD_BIT7_SET_DDRAM_ADDRESS));
	}
	else
	{
		udtReturnValue = E_PENDING;
	}
	return udtReturnValue;
}
#endif



/********************************************************************************************/
/*  @brief				  : store new char on CGRAM											*/
/*							0 0 0 1 AC5 AC4 AC3 AC2 AC1 AC0 Set CGRAM address				*/
/*  @param pu8CharArr	  : array of 8 bytes for particular shape			    @ref uint8*	*/
/*  @param u8CGRAMLocation: the location of shape in CGRAM					    @ref uint8	*/
/*  @param u8DDRAMRow	  : required row to display our char 					@ref uint8	*/
/*  @param u8DDRAMColumn  : required column to display our char					@ref uint8	*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
extern Std_ReturnType LCD_udtCreateSpecialChar
(
uint8* pu8CharArr, 
uint8 u8CGRAMLocation, 
uint8 u8DDRAMRow, 
uint8 u8DDRAMColumn
)
{
	Std_ReturnType udtReturnValue = E_OK;
	uint8 u8Counter;
	if(NULL == pu8CharArr)
	{
		udtReturnValue = E_NOT_OK;
	}
	else
	{
		/* !Comment: Switch to CGRAM */
		udtReturnValue = LCD_udt4BitSendCommand((u8CGRAMLocation*8) + (LCD_BIT6_SET_CGRAM_ADDRESS));
		/* !Comment: Write on CGRAM */
		for (u8Counter = 0; u8Counter < 8; u8Counter++)
		{
			udtReturnValue = LCD_udt4BitSendData(pu8CharArr[u8Counter]);
		}
		/* !Comment: Go to DDRAM */
		udtReturnValue = LCD_udtGoTo(u8DDRAMRow, u8DDRAMColumn);
		/* !Comment: Print CGRAM data */
		udtReturnValue = LCD_udt4BitSendData(u8CGRAMLocation);
	}
	return udtReturnValue;
}
#endif


/********************************************************************************************/
/*  @brief				  : generate pulse on LCD_EN pin									*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
Std_ReturnType LCD_udtClearScreen
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	udtReturnValue = LCD_udt4BitSendCommand(LCD_CLEAR_DISPLAY);
	_delay_ms(3); //wait more than 1.53 ms
	
	return udtReturnValue;
}


/***************************** Comment!: Static APIs Implementation ********************************/
/********************************************************************************************/
/*  @brief				  : generate pulse on LCD_EN pin									*/
/*  @return	 Std_ReturnType																	*/
/*           (E_OK)		  : The function done successfully									*/
/*           (E_NOT_OK)   : The function has issue to perform this action					*/
/********************************************************************************************/
#if LCD_4_BIT_MODE_CONFIGURATIONS==CONFIG_ENABLE
static Std_ReturnType  LCD_udt4bit_send_enable_signal
(
void
)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	udtReturnValue = DIO_udtSetPinValue(LCD_E, DIO_HIGH);
	_delay_ms(1);
	udtReturnValue = DIO_udtSetPinValue(LCD_E, DIO_LOW);
	_delay_ms(1);
	return udtReturnValue;
}
#endif

