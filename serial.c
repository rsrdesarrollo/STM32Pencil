/*
 * Serial.c
 *
 *  Created on: 08/04/2014
 *      Author: raul
 */
#include "stm32f10x.h"
#include "serial.h"

void openSerialComunication(){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_StructInit(&GPIO_InitStruct);

	RCC_APB2PeriphClockCmd(SERIAL_RCC_Periph, ENABLE);

	// Init USART3_Tx
	GPIO_InitStruct.GPIO_Pin = SERIAL_Tx_Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(SERAIL_GPIOX, &GPIO_InitStruct);

	// Init USART3_Rx
	GPIO_InitStruct.GPIO_Pin = SERIAL_Rx_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(SERAIL_GPIOX, &GPIO_InitStruct);

	USART_InitTypeDef USART_IniitStructture;

	USART_StructInit(&USART_IniitStructture);

	USART_IniitStructture.USART_BaudRate = SERIAL_BAUDRATE;
	USART_IniitStructture.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(SERIAL_USART, &USART_IniitStructture);
	USART_Cmd(SERIAL_USART, ENABLE);
}

void serial_putc(int c){
	while (USART_GetFlagStatus(SERIAL_USART, USART_FLAG_TXE) == RESET);
	SERIAL_USART->DR = (c & 0xff);
}

int serial_getc(){
	while (USART_GetFlagStatus(SERIAL_USART, USART_FLAG_TXE) == RESET);
	return SERIAL_USART->DR & 0xff;
}
