#include "stm32f10x.h"
#include "./led/bsp_led.h"


void delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	/* 在程序来到main函数这里的时候，系统时钟已配置成72M*/
	
	LED_GPIO_Config();
	while(1)
	{
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);
		GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		delay(0xfffff);
		
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);
		GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
		delay(0xfffff);
	}
}
	

