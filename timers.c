/*
 * timers.c
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#include "timers.h"
#include "ir_sensor.h"
#include "us_sensor.h"

void CLEAN_TIM_IRQHandler(void) {
	if(TIM_GetITStatus(CLEAN_TIM, TIM_IT_Update) != RESET){

		NVIC_DisableIRQ(US_EXTI_IRQn);
		EXTI_ClearITPendingBit(IR_EXTI_Line);
		NVIC_EnableIRQ(IR_EXTI_IRQn);
		NVIC_DisableIRQ(CLEAN_IRQn);

		GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);

		TIM_ClearITPendingBit(CLEAN_TIM, TIM_IT_Update);
	}
}

void restartCleanTimer(){

	TIM_SetCounter(CLEAN_TIM, 0);
	TIM_ClearITPendingBit(CLEAN_TIM, TIM_IT_Update);
	NVIC_EnableIRQ(CLEAN_IRQn);
}

void _configureCleanTimerInterrupt(){
	NVIC_InitTypeDef NVIC_InitStruct;

	NVIC_InitStruct.NVIC_IRQChannel = CLEAN_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStruct.NVIC_IRQChannelCmd = DISABLE;

	NVIC_Init(&NVIC_InitStruct);
}

void configureCleanTimer(){

	RCC_APB1PeriphClockCmd(CLEAN_RCC_APB1Periph, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;

	TIM_TimeBaseStruct.TIM_Prescaler = (SystemCoreClock / 10000) - 1;
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStruct.TIM_Period = 20000 - 1;
	TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(CLEAN_TIM, &TIM_TimeBaseStruct);
	TIM_Cmd(CLEAN_TIM, ENABLE);

	_configureCleanTimerInterrupt();

	TIM_ITConfig(CLEAN_TIM, TIM_IT_Update, ENABLE);
}
