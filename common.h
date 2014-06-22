/*
 * common.h
 *
 *  Created on: 21/04/2014
 *      Author: raul
 */

#ifndef COMMON_H_
#define COMMON_H_

#include "stm32f10x.h"

extern volatile char DATA_READY;	// Flag para indicar el envio de datos.
extern volatile uint16_t DATA;		// Datos globales de medida.

// Tipo de datos enviado por puerto serie.
typedef struct{
	uint8_t low;
	uint8_t high;
} stUInt16_t;


#endif /* COMMON_H_ */
