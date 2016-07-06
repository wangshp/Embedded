#include "LED.h"
#include "stm32f4xx_hal.h"

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pin = GPIO_PIN_12;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
}