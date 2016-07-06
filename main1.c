#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"

int main(void)
{
	GPIO_InitTypeDef GPIO_STRUCT;
  HAL_Init();                      //if wanna use HAL_Delay() then need initial HAL.
	__HAL_RCC_GPIOD_CLK_ENABLE();    //rcc give time drive to gpio before configure it.

	
	GPIO_STRUCT.Pin = GPIO_PIN_12;
	GPIO_STRUCT.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_STRUCT.Pull = GPIO_PULLDOWN;
	GPIO_STRUCT.Speed = GPIO_SPEED_FREQ_LOW;
	
	HAL_GPIO_Init(GPIOD, &GPIO_STRUCT);

  while(1)
	{
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);

		HAL_Delay(1000);
	}

}

