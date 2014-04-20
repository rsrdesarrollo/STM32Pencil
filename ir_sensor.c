/*
 * ir_sensor.c
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */
#include "ir_sensor.h"
#include "us_sensor.h"
#include "timers.h"

void IR_IRQHandler(void) {

	if (EXTI_GetITStatus(IR_EXTI_Line) != RESET) {

		// Disable IRSensor interrupt and enable Ultrasonic one.

		NVIC_DisableIRQ(IR_EXTI_IRQn);
		EXTI_ClearITPendingBit(US_EXTI_Line);
		NVIC_EnableIRQ(US_EXTI_IRQn);

		//TODO: Set timer to reenable IRSensor interrupt when its safe.
		//TODO: Set timer to start counting ultrasonic delay
		//TODO: Set timer to

		GPIO_WriteBit(GPIOC, GPIO_Pin_9, Bit_SET);

		EXTI_ClearITPendingBit(IR_EXTI_Line);
	}
}


void configureIRSensorInt() {
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Configure IRSensor pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Connect IRSensor EXTI Line to Button GPIO Pin */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

	/* Configure IRSensor EXTI line */
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	/* Enable and set IRSensor EXTI Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}
