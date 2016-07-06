#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"
#include "LED.h"
#include "BUTTON.h"
int main(void)
{
	
  HAL_Init();                      //if wanna use HAL_Delay() then need initial HAL.
	led_init();
	button_init();
	

  while(1)
	{
		if(button_detect() == 1)
		{
				HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
				button_release();
			
		}	
	}

}

