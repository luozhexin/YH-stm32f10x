#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./key/bsp_key.h"

void delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	/* �ڳ�������main���������ʱ��ϵͳʱ�������ó�72M*/
	
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	
	while(1)
	{
		if (KEY_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
		{
			/*LED1 TOGGLE*/
			LED1_TOGGLE;
		}
		if (KEY_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON)
		{
			/*LED2 TOGGLE*/
			LED2_TOGGLE;
		}
	}
}
	

