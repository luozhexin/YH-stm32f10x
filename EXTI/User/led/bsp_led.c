//bsp  board support package  �弶֧�ְ�  ���ĳ������������ļ� �Լ�д�� ��Ҫ�޸�

#include "./led/bsp_led.h"
#include "./key/bsp_exti_key.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*��һ�����������ʱ��*/
	
	RCC_APB2PeriphClockCmd(KEY1_EXTI_GPIO_CLK|KEY2_EXTI_GPIO_CLK, ENABLE);
	
	/*�ڶ��������������ʼ���ṹ��*/
	GPIO_InitStruct.GPIO_Pin = KEY1_EXTI_GPIO_PIN	;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	/*�����������������ʼ�������������úõĽṹ���Աд���Ĵ�������*/
	GPIO_Init(KEY1_EXTI_GPIO_PORT, &GPIO_InitStruct);
	
}








