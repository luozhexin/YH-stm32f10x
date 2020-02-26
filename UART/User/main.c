#include "stm32f10x.h"
#include "./uart/bsp_uart.h"
#include "stdio.h"
int main(void)
{
DEBUG_UART_Config();
//	USART_SendData(DEBUG_USARTx , 'a');
//Usart_SendString( DEBUG_USARTx, "hello world\n");
	printf("hello world");
	//printf->fputc->USART_SendData->电脑上位机
	while(1);
}
	

