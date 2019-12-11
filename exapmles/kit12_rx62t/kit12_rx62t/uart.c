/*
 * uart.c
 *
 *  Created on: 17.12.2018
 *      Author: Nutzer
 */

#include "uart.h"
#include "iodefine.h"

char debugEnabled = 1;

void SCI2_Asyn_initial(void) {
	if (PORTB.PORT.BIT.B4) {
		debugEnabled = 1;
	}


	// Cancel the module stop state.
	MSTP(SCI0) = 0;

	// TXD0 is output
	PORTB.DDR.BIT.B6 = 1;
	// RxD0 is input
	PORTB.DDR.BIT.B5 = 0;
	// Enable Input Buffer on RXD0
	PORTB.ICR.BIT.B5 = 1;

	// Disable SCI
	SCI0.SCR.BYTE = 0x00;

	SCI0.SMR.BYTE = 0x00;
	/*  Set mode register
	 -Asynchronous Mode
	 -8 bits
	 -no parity
	 -1 stop bit
	 -PCLK clock (n = 0)
	 */

	// Enable RXI and TXI first to enable IR bits for checking as flags
	SCI0.SCR.BIT.RIE = 1;
	SCI0.SCR.BIT.TIE = 1;

	// Clear IR bits for TIE and RIE
	IR(SCI0,RXI0) = 0;
	IR(SCI0,TXI0) = 0;

	/* RXI and TXI interrupts in ICU. Disable (0) if polling. */
	IEN(SCI0, RXI0) = 0;
	IEN(SCI0, TXI0) = 0;

	/* Set interrupt prio for SCI. */
	IPR(SCI0, TXI0) = 2;
	IPR(SCI0, RXI0) = 2;

	SCI0.SEMR.BIT.NFEN = 1;


	// SCI0.BRR = 80;
	//SCI0.BRR = 12;
	SCI0.BRR = 39;
	//SCI0.BRR = 0x09;

	// Enable SCI2
	SCI0.SCR.BYTE |= 0x30;
}

void SCI2_PullString(char * msg_string) //transmit strings
{
	unsigned char i;
	if (!debugEnabled)
		return;


	for (i=0; msg_string[i]; i++)
	{
	        /* Wait for transmit buffer to be empty */
	  while(IR(SCI0, TXI0) == 0);

	        /* Clear TXI IR bit */
	        IR(SCI0, TXI0) = 0;  /* Write the character out */
		SCI0.TDR = msg_string[i];
	}
}


char SCI2_GetChar( void )   //recive byte
{
	char data;
	data = SCI0.RDR;

	IR(SCI0, RXI0) = 0;
	if (SCI0.RDR) {
		IR(SCI0, TXI0) = 0;  /* Write the character out */
		SCI0.TDR = data;
	}

	return data;
}

void intToString(int number, char* msg_string)
{
	int i;

	for(i = 32; i >= 0; i--)
	{
		msg_string[i] = (number % 10) + '0';
		number /= 10;
	}
}
