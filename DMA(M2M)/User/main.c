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
  /* �����űȽϽ������ */
  uint8_t TransferStatus;
  
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();    
  
  /* ����ʱ���� */
  Delay(0xFFFFFF);  
  
  /* DMA�������� */
  DMA_Config(); 
  
  /* �ȴ�DMA������� */
  while(DMA_GetFlagStatus(DMA_FLAG_TC)==RESET)
  {
    
  }   
  
  /* �Ƚ�Դ�����봫������� */
  TransferStatus=Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);
  
  /* �ж�Դ�����봫������ݱȽϽ��*/
  if(TransferStatus==0)  
  {
    /* Դ�����봫������ݲ����ʱLED1�� */
    LED1_ON;
  }
  else
  { 
    /* Դ�����봫����������ʱLED2�� */
    LED2_ON;
  }

	while (1)
	{		
	}
}

uint8_t Buffercmp(const uint32_t* pBuffer, 
                  uint32_t* pBuffer1, uint16_t BufferLength)
{
  /* ���ݳ��ȵݼ� */
  while(BufferLength--)
  {
    /* �ж���������Դ�Ƿ��Ӧ��� */
    if(*pBuffer != *pBuffer1)
    {
      /* ��Ӧ����Դ����������˳�������������0 */
      return 0;
    }
    /* ������������Դ�ĵ�ַָ�� */
    pBuffer++;
    pBuffer1++;
  }
  /* ����жϲ��Ҷ�Ӧ������� */
  return 1;  
}

