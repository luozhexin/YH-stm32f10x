/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "./i2c/bsp_i2c_gpio.h"  
#include "./i2c/bsp_i2c_ee.h"
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	i2c_GPIO_Config();
	printf("欢迎使用野火STM32开发板\n");
	
  if(ee_CHECK_DEVICE(EEPROM_ADDR|EEPROM_READ_DIR)==0)
	{
		printf("\r\n检测到EEPROM\r\n");
	}
	else
	{
		printf("\r\n未检测到EEPROM\r\n");
	}
	if(ee_WRITE_BYTE(1,10)==1)
	{
		printf("\r\n写入正常\r\n");
	}
	else
	{
		printf("\r\n写入异常\r\n");
	}
}
/*********************************************END OF FILE**********************/
