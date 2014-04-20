/*
 * timers.h
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "stm32f10x.h"


#define CLEAN_TIM_IRQHandler TIM2_IRQHandler
#define CLEAN_TIM TIM2

void configureCleanTimer();

#endif /* TIMERS_H_ */
