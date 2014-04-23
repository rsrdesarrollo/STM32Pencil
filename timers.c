/*
 * timers.c
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#include "timers.h"
#include "ir_sensor.h"
#include "us_sensor.h"
#include "common.h"

void CLEAN_TIM_IRQHandler(void) {
	if(TIM_GetITStatus(CLEAN_TIM, TIM_IT_Update) != RESET){

		DATA_READY = 1;

		NVIC_DisableIRQ(US_EXTI_IRQn);
		EXTI_ClearITPendingBit(IR_EXTI_Line);
		NVIC_EnableIRQ(IR_EXTI_IRQn);
		NVIC_DisableIRQ(CLEAN_IRQn);

		GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);

		TIM_ClearITPendingBit(CLEAN_TIM, TIM_IT_Update);
	}
}

__INLINE void restartCleanTimer(){

	CLEAN_TIM->CNT = (uint16_t) 0;
	CLEAN_TIM->SR = (uint16_t) ~TIM_IT_Update; // Clean IT Pending Bit
	NVIC_EnableIRQ(CLEAN_IRQn);
}

__INLINE void restartCountTimer(){
	COUNT_TIM->CNT = (uint16_t) 0;
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

	/* Descomentar para versión final

	TIM_TimeBaseStruct.TIM_Prescaler = (SystemCoreClock / 10000) - 1;
	TIM_TimeBaseStruct.TIM_Period = 20000 - 1;

	/*/

	// Contador a 3KHz (100 veces más rápido que tren de pulsos)
	TIM_TimeBaseStruct.TIM_Prescaler = (SystemCoreClock / 3000) - 1;
	// Al 70% del pulso de 30Hz realizar el limpiado.
	//   Recordar quel ciclo de trabajo del tren es del 20%
	TIM_TimeBaseStruct.TIM_Period = 70 - 1;

	/**/
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(CLEAN_TIM, &TIM_TimeBaseStruct);
	TIM_Cmd(CLEAN_TIM, ENABLE);

	_configureCleanTimerInterrupt();
	TIM_ITConfig(CLEAN_TIM, TIM_IT_Update, ENABLE);
}


void configureCountTimer(){

	RCC_APB1PeriphClockCmd(COUNT_RCC_APB1Periph, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;

	/* Descomentar para versión final

	TIM_TimeBaseStruct.TIM_Prescaler = 0xffff; // Aproximadamente 380Hz
	TIM_TimeBaseStruct.TIM_Period = 0xffff; // Mide max 172 segundos aprox.

	/*/

	// Contador a 343KHz (Un segundo de vuelo son aprox 343 metros)
	TIM_TimeBaseStruct.TIM_Prescaler = (SystemCoreClock / 343000) - 1;
	// Distancia máxima medible 2^16 - 1 milímetros: aprox 65 metros
	TIM_TimeBaseStruct.TIM_Period = 0xffff;

	/**/
	TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(COUNT_TIM, &TIM_TimeBaseStruct);
	TIM_Cmd(COUNT_TIM, ENABLE);

}
