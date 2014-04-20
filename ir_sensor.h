/*
 * ir_sensor.h
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include "stm32f10x.h"

#define IR_IRQHandler EXTI0_IRQHandler
#define IR_EXTI_Line EXTI_Line0
#define IR_EXTI_IRQn EXTI0_IRQn


void configureIRSensorInt();


#endif /* IR_SENSOR_H_ */
