/*
 * Serial.c
 *
 *  Created on: 08/04/2014
 *      Author: raul
 */
#include "stm32f10x.h"
#include "Serial.h"

void openSerialComunication(){
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_StructInit(&GPIO_InitStruct);

	// Init USART3_Tx
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	// Init USART3_Rx
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	USART_InitTypeDef USART_IniitStructture;

	USART_StructInit(&USART_IniitStructture);

	USART_IniitStructture.USART_BaudRate = 9600;
	USART_IniitStructture.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART3, &USART_IniitStructture);
	USART_Cmd(USART3, ENABLE);
}

void serial_putc(int c){
	while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	USART3->DR = (c & 0xff);
}

int serial_getc(){
	while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	return USART3->DR & 0xff;
}
