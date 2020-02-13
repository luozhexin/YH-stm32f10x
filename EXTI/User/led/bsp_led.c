//bsp  board support package  板级支持包  针对某开发板的驱动文件 自己写的 需要修改

#include "./led/bsp_led.h"
#include "./key/bsp_exti_key.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*第一步：打开外设的时钟*/
	
	RCC_APB2PeriphClockCmd(KEY1_EXTI_GPIO_CLK|KEY2_EXTI_GPIO_CLK, ENABLE);
	
	/*第二步：配置外设初始化结构体*/
	GPIO_InitStruct.GPIO_Pin = KEY1_EXTI_GPIO_PIN	;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	/*第三步：调用外设初始化函数，把配置好的结构体成员写到寄存器里面*/
	GPIO_Init(KEY1_EXTI_GPIO_PORT, &GPIO_InitStruct);
	
}








