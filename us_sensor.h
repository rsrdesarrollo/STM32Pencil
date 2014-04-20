/*
 * us_sensor.h
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "stm32f10x.h"

#define ULTRASONIC_IRQHandler EXTI1_IRQHandler
#define US_EXTI_Line EXTI_Line1
#define US_EXTI_IRQn EXTI1_IRQn

#define US_GPIO_Pin GPIO_Pin_1
#define US_GPIOX GPIOA

#define US_PortSourceGPIOX GPIO_PortSourceGPIOA
#define US_PinSource GPIO_PinSource1

void configureUltrasonicSensorInt();

#endif /* US_SENSOR_H_ */
