#include "stm32f10x.h"
#include "./uart/bsp_uart.h"
#include "stdio.h"
#include "./led/bsp_led.h"
int main(void)
{
	uint8_t temp;
DEBUG_UART_Config();
LED_GPIO_Config();
//	USART_SendData(DEBUG_USARTx , 'a');
//Usart_SendString( DEBUG_USARTx, "hello world\n");
//	printf("hello world");
	//printf->fputc->USART_SendData->������λ��
	while(1)
	{
		temp=getchar();
		printf("���ܵ����ַ�Ϊ��%c\n",temp);
		
		switch(temp)
		{
			case '1':
				LED1_ON;
				LED2_OFF;
				break;
			
			case '2':
				LED1_OFF;
				LED2_ON;
				break;
			
			default:
				LED1_OFF;
				LED2_OFF;
			break;
				
		}
	}
}
	

