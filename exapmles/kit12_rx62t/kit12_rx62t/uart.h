/*
 * uart.h
 *
 *  Created on: 06.11.2019
 *      Author: Adrian Laug
 */

#ifndef UART_H_
#define UART_H_

void SCI2_Asyn_initial(void);
void SCI2_PullString(char * msg_string);
char SCI2_GetChar( void );
void intToString(int number, char* msg_string);

#endif /* UART_H_ */
