#include "BUTTON.h"
#include "stm32f4xx_hal.h"
extern uint32_t uwTick;
void button_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;             //Pullup pulldown is more important for input, because it's like the reset value of this port.
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int button_detect(void)
{
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
	{
			my_delay2(10);
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

void my_delay(int delay_time)
{
	int time1 = uwTick;
	time1 = uwTick + delay_time;
	while(time1 > uwTick)
	{}
}

void my_delay2(int delay_time)   //ms
{ //systick configure
	delay_time = delay_time * HAL_RCC_GetHCLKFreq()/1000U;
	SysTick->LOAD  = (uint32_t)(delay_time - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
	while(((SysTick->CTRL & 0x10000)==0)&&(SysTick->VAL != 0))
	{}
	//PLEASE TEST
}
	