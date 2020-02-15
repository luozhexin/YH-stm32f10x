#include "stm32f10x.h"
#include "./led/bsp_led.h"
#include "./SysTick/bsp_systick.h"

void delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	/* �ڳ�������main���������ʱ��ϵͳʱ�������ó�72M*/
	
	LED_GPIO_Config();
	while(1)
	{
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
	//	delay(0xfffff);
		//SysTick_Delay_ms(500);
		SysTick_Delay_ms_INT(500);
		GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
	//	delay(0xfffff);
		//SysTick_Delay_ms(500);
		SysTick_Delay_ms_INT(500);
		
//		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
//		delay(0xfffff);
//		GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
//		delay(0xfffff);
	}
}
	

