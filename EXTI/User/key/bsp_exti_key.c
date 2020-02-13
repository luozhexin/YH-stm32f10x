#include "./key/bsp_exti_key.h"

static void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitTStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitTStruct.NVIC_IRQChannel = KEY1_EXTI_IRQN;
	NVIC_InitTStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitTStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitTStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitTStruct);
	
	NVIC_InitTStruct.NVIC_IRQChannel = KEY2_EXTI_IRQN;
	NVIC_InitTStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitTStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitTStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitTStruct);
}

void EXTI_KEY_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStruct;
		EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_Config();
	
	
	RCC_APB2PeriphClockCmd(KEY1_EXTI_GPIO_CLK|KEY2_EXTI_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = KEY1_EXTI_GPIO_PIN	;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_EXTI_GPIO_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = KEY2_EXTI_GPIO_PIN;
	GPIO_Init(KEY2_EXTI_GPIO_PORT, &GPIO_InitStruct);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(KEY1_EXTI_GPIO_PORTSOURCE,KEY1_EXTI_GPIO_PinSOURCE);
	EXTI_InitStruct.EXTI_Line = KEY1_EXTI_LINE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	GPIO_EXTILineConfig(KEY2_EXTI_GPIO_PORTSOURCE,KEY2_EXTI_GPIO_PinSOURCE);
	EXTI_InitStruct.EXTI_Line = KEY2_EXTI_LINE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
}

