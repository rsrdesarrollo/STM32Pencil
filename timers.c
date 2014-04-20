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

		GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);

		TIM_ClearITPendingBit(CLEAN_TIM, TIM_IT_Update);
	}
}
