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
#define CLEAN_RCC_APB1Periph (RCC_APB1Periph_TIM2)

#define CLEAN_IRQn TIM2_IRQn

#define COUNT_TIM TIM3
#define COUNT_RCC_APB1Periph (RCC_APB1Periph_TIM3)


void configureCleanTimer();
void configureCountTimer();

__INLINE void restartCleanTimer();
__INLINE void restartCountTimer();

#endif /* TIMERS_H_ */
