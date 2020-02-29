/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
 
 
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "./i2c/bsp_i2c_gpio.h"  
#include "./i2c/bsp_i2c_ee.h"
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	i2c_GPIO_Config();
	printf("��ӭʹ��Ұ��STM32������\n");
	
  if(ee_CHECK_DEVICE(EEPROM_ADDR|EEPROM_READ_DIR)==0)
	{
		printf("\r\n��⵽EEPROM\r\n");
	}
	else
	{
		printf("\r\nδ��⵽EEPROM\r\n");
	}
	if(ee_WRITE_BYTE(1,10)==1)
	{
		printf("\r\nд������\r\n");
	}
	else
	{
		printf("\r\nд���쳣\r\n");
	}
}
/*********************************************END OF FILE**********************/
