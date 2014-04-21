/*
 * Serial.h
 *
 *  Created on: 08/04/2014
 *      Author: raul
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define SERAIL_GPIOX GPIOA
#define SERIAL_USART USART1
#define SERIAL_BAUDRATE 9600

#define SERIAL_RCC_APB2Periph ( RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1 )

#define SERIAL_Tx_Pin GPIO_Pin_9
#define SERIAL_Rx_Pin GPIO_Pin_10


void openSerialComunication();
void closeSerialComunication();
void serial_putc(int c);
int serial_getc();



#endif /* SERIAL_H_ */
