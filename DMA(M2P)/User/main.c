#include "stm32f10x.h"
#include "./uart/bsp_uart_dma.h"
#include "stdio.h"
#include "./led/bsp_led.h"

extern uint8_t SendBuff[SENDBUFF_SIZE];

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main(void)
{
 uint32_t i;
DEBUG_UART_Config();
LED_GPIO_Config();
USARTx_DMA_Config();
	  /*填充将要发送的数据*/
  for(i=0;i<SENDBUFF_SIZE;i++)
  {
    SendBuff[i]	 = 'P';
    
  }

USART_DMACmd(DEBUG_USARTx, USART_DMAReq_Tx, ENABLE);
  while(1)
  {
    LED1_TOGGLE
    Delay(0xFFFFF);
  }

}
	

