/*
 * common.c
 *
 *  Created on: 21/04/2014
 *      Author: raul
 */

#include "stm32f10x.h"

volatile char DATA_READY = 0;
volatile uint16_t DATA = 0xffff;
