/*
 * us_sensor.c
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */
#include "us_sensor.h"
#include "ir_sensor.h"
#include "timers.h"

void ULTRASONIC_IRQHandler(void) {

	if (EXTI_GetITStatus(US_EXTI_Line) != RESET) {

		NVIC_DisableIRQ(US_EXTI_IRQn);
		EXTI_ClearITPendingBit(IR_EXTI_Line);
		NVIC_EnableIRQ(IR_EXTI_IRQn);

		GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_RESET);

		EXTI_ClearITPendingBit(US_EXTI_Line);
	}
}


void configureUltrasonicSensorInt(){
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(US_RCC_APB2Periph, ENABLE);

	/* Configure IRSensor pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = US_GPIO_Pin;
	GPIO_Init(US_GPIOX, &GPIO_InitStructure);

	/* Connect IRSensor EXTI Line to Button GPIO Pin */
	GPIO_EXTILineConfig(US_PortSourceGPIOX, US_PinSource);

	/* Configure IRSensor EXTI line */
	EXTI_InitStructure.EXTI_Line = US_EXTI_Line;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set IRSensor EXTI Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = US_EXTI_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;

	NVIC_Init(&NVIC_InitStructure);
}
