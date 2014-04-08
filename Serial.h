/*
 * Serial.h
 *
 *  Created on: 08/04/2014
 *      Author: raul
 */

#ifndef SERIAL_H_
#define SERIAL_H_

void openSerialComunication();
void closeSerialComunication();
void serial_putc(int c);
int serial_getc();



#endif /* SERIAL_H_ */
