#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./key/bsp_exti_key.h"

void delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	/* �ڳ�������main���������ʱ��ϵͳʱ�������ó�72M*/
	
	LED_GPIO_Config();
	
	EXTI_KEY_Config();
	
	
	while(1)
	{

	}
}
	

