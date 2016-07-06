#include "LED.h"
#include "stm32f4xx_hal.h"

void button_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Pull = GPIO_PULLUP;             //Pullup pulldown is more important for input, because it's like the reset value of this port.
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int button_detect(void)
{
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
	{
			HAL_Delay(10);
			if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
			{		
				return 1;
			}
	}
	return 0;
}

void button_release(void)
{
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET){}
}