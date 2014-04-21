/*
 * timers.h
 *
 *  Created on: 20/04/2014
 *      Author: raul
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "stm32f10x.h"


#define CLEAN_TIM_IRQHandler TIM3_IRQHandler
#define CLEAN_TIM TIM3
#define CLEAN_RCC_APB1Periph (RCC_APB1Periph_TIM3)

#define CLEAN_IRQn TIM3_IRQn

void configureCleanTimer();
void restartCleanTimer();

#endif /* TIMERS_H_ */
