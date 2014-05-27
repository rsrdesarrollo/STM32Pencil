/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "serial.h"
#include "ir_sensor.h"
#include "us_sensor.h"
#include "timers.h"
#include "common.h"

void setSavePowerMode();
void initPintOutput(GPIO_TypeDef * GPIOX, uint16_t pin);

int main(void) {

	setSavePowerMode();

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	initPintOutput(GPIOC, GPIO_Pin_8 | GPIO_Pin_9);

	configureIRSensorInt();
	configureUltrasonicSensorInt();
	configureCleanTimer();
	configureCountTimer();
	openSerialComunication();


	/*
	char string[] = "hola mundo!\n";
	char *aux = string;
	while(1){
		aux = string;
		while(*aux)
			serial_putc(*aux++);

	}
	/*/
	int failed = 0;
	while(1){
		if(DATA_READY){
			DATA_READY = 0;
			uint16_t data = DATA;
			stUInt16_t *sdata = (stUInt16_t *)&data;

			if(data != 0xffff){
				if(!failed){
					GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_RESET);
				}else
					failed--;
			}else{
				failed = 30;
				GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_SET);
			}

			serial_putc(sdata->high);
			serial_putc(sdata->low);
		}
	}

	/**/

}

void setSavePowerMode() {

	/* Set al the pins on Analog input mode and unable Clock.
	 * */

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
	RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
	RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
	RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
	RCC_APB2Periph_GPIOE, DISABLE);
}

void initPintOutput(GPIO_TypeDef * GPIOX, uint16_t pin) {

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOX, &GPIO_InitStructure);
}




