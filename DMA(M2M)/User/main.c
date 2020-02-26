#include "stm32f10x.h"
#include "./uart/bsp_uart_dma.h"
#include "stdio.h"
#include "./led/bsp_led.h"

extern uint32_t aDST_Buffer[BUFFER_SIZE];
extern uint32_t aSRC_Const_Buffer[BUFFER_SIZE];

uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength);

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}
int main(void)
{
  /* 定义存放比较结果变量 */
  uint8_t TransferStatus;
  
	/* LED 端口初始化 */
	LED_GPIO_Config();    
  
  /* 简单延时函数 */
  Delay(0xFFFFFF);  
  
  /* DMA传输配置 */
  DMA_Config(); 
  
  /* 等待DMA传输完成 */
  while(DMA_GetFlagStatus(DMA_FLAG_TC)==RESET)
  {
    
  }   
  
  /* 比较源数据与传输后数据 */
  TransferStatus=Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
  
  /* 判断源数据与传输后数据比较结果*/
  if(TransferStatus==0)  
  {
    /* 源数据与传输后数据不相等时LED1亮 */
    LED1_ON;
  }
  else
  { 
    /* 源数据与传输后数据相等时LED2亮 */
    LED2_ON;
  }

	while (1)
	{		
	}
}

uint8_t Buffercmp(const uint32_t* pBuffer, 
                  uint32_t* pBuffer1, uint16_t BufferLength)
{
  /* 数据长度递减 */
  while(BufferLength--)
  {
    /* 判断两个数据源是否对应相等 */
    if(*pBuffer != *pBuffer1)
    {
      /* 对应数据源不相等马上退出函数，并返回0 */
      return 0;
    }
    /* 递增两个数据源的地址指针 */
    pBuffer++;
    pBuffer1++;
  }
  /* 完成判断并且对应数据相对 */
  return 1;  
}

