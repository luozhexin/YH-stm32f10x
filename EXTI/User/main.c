#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./key/bsp_exti_key.h"

void delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	/* 在程序来到main函数这里的时候，系统时钟已配置成72M*/
	
	LED_GPIO_Config();
	
	EXTI_KEY_Config();
	
	
	while(1)
	{

	}
}
	

