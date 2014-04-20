/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "serial.h"
#include "ir_sensor.h"
#include "us_sensor.h"
#include "timers.h"

void setSavePowerMode();
void initPintOutput(GPIO_TypeDef * GPIOX, uint16_t pin);

int main(void) {

	setSavePowerMode();

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC |
			               RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO, ENABLE);

	initPintOutput(GPIOC, GPIO_Pin_8 | GPIO_Pin_9);

	configureIRSensorInt();
	configureUltrasonicSensorInt();
	NVIC_DisableIRQ(EXTI1_IRQn);
	openSerialComunication();


	char string[] = "hola mundo!\n";
	char *aux = string;
	//STM32vldiscovery_LEDOn(LED3);
	while(1){
		aux = string;
		while(*aux)
			serial_putc(*aux++);

	}
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




