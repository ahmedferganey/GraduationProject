/*
 * FileName		: HC05_interface.h
 * Created		: 9/18/2023 1:46:41 PM
 * Author		: Ahmed Ferganey
 */ 
 
#ifndef _HC05_INTERFACE_H_
#define _HC05_INTERFACE_H_


/* -------------------------------- Includes ----------------------------------------------------*/


/* -------------------------------- Macro Declarations ------------------------------------------*/


/* -------------------------------- Macro Functions Declarations --------------------------------*/


/* -------------------------------- Data Type Declarations --------------------------------------*/


/* -------------------------------- Function Declarations ---------------------------------------*/
/******	   Char RX/TX API		******/
Std_ReturnType HC05_udtTx_Char
(
uint8 Copy_u8Data
);

Std_ReturnType HC05_udtRx_Char
(
uint8* HC05_pu8RXChar
);

/******	   String RX/TX API		******/
Std_ReturnType HC05_udtTx_String
(
uint8* HC05_pu8TXString
);

Std_ReturnType HC05_pu8Rx_String
(
uint8* HC05_pu8RXString, 
uint32  HC05_u32BufferSize
);


/*
	https://www.electronicwings.com/sensors-modules/bluetooth-module-hc-05-
	https://www.electronicwings.com/avr-atmega/hc-05-bluetooth-module-interfacing-with-atmega1632
	
	Introduction:
		- It is used for many applications like wireless headset, game controllers, wireless mouse, 
			wireless keyboard, and many more consumer applications.
		- It has range up to <100m which depends upon transmitter and receiver, atmosphere, 
			geographic & urban conditions. 
		- It is IEEE 802.15.1 standardized protocol, through which one can build wireless Personal 
			Area Network (PAN). It uses frequency-hopping spread spectrum (FHSS) radio technology 
			to send data over air.
		- It uses serial communication to communicate with devices. It communicates with
			microcontroller using serial port (USART).
			
	/////////////////////////////////////////////////////////////////////////////////////////////
	
	HC-05 Bluetooth Module:
		HC-05 is a Bluetooth module which is designed for wireless communication. This module can 
		be used in a master or slave configuration.
		
	////////////////////////////////////////////////////////////////////////////////////////////

	Bluetooth serial modules allow all serial enabled devices to communicate with each other 
	using Bluetooth.

		It has 6 pins,
		
		1.  Key/EN: It is used to bring Bluetooth module in AT commands mode. If Key/EN pin 
			is set to high, then this module will work in command mode. Otherwise by default it 
			is in data mode. The default baud rate of HC-05 in command mode is 38400bps and 9600 
			in data mode.
		
			HC-05 module has two modes,
		
				a.  Data mode: Exchange of data between devices.
		
				b.  Command mode: It uses AT commands which are used to change setting of 
					HC-05. To send these commands to module serial (USART) port is used.
		
		2.  VCC: Connect 5 V or 3.3 V to this Pin.
		
		3.  GND: Ground Pin of module.
		
		4.  TXD: Transmit Serial data (wirelessly received data by Bluetooth module 
				 transmitted out serially on TXD pin)
		
		5.  RXD: Receive data serially (received data will be transmitted wirelessly by 
			     Bluetooth module).
		
		6.  State: It tells whether module is connected or not.
		
	////////////////////////////////////////////////////////////////////////////////////////////
		
	HC-05 module Information
	
		HC-05 has red LED which indicates connection status, whether the Bluetooth is connected or not. 
		Before connecting to HC-05 module this red LED blinks continuously in a periodic manner.
		When it gets connected to any other Bluetooth device, its blinking slows down to two seconds.
		This module works on 3.3V. We can connect 5V supply voltage as well since the module has on 
		board 5 to 3.3 V regulator.
		As HC-05 Bluetooth module has 3.3V level for RX/TX and microcontroller can detect 3.3 V level,
		so, no need to shift transmit level of HC-05 module. But we need to shift the transmit voltage 
		level from microcontroller to RX of HC-05 module.
		The data transfer rate of HC-05 module can vary up to 1Mbps is in the range of 10 meters. 

	////////////////////////////////////////////////////////////////////////////////////////////

	Specification of HC-05 Bluetooth Module
		
		Operating voltage: 3.3V to 5V DC
		Operating current: less than 50mA
		Standby current: less than 2.5mA
		Sleep current: less than 1mA
		Interface: UART (Universal Asynchronous Receiver/Transmitter)
		Baud rates: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, and 460800
		Operating temperature: -20°C to 75°C (-4°F to 167°F)		
		
	////////////////////////////////////////////////////////////////////////////////////////////	
		
*/

#endif  /* _HC05_INTERFACE_H_ */