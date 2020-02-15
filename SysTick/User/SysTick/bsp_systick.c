#include "./SysTick/bsp_systick.h"

#if 0
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	/*reload�Ĵ���Ϊ24λ�����ֵΪ2^24*/
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            
  
	/*��ʼ��reload�Ĵ�����ֵ*/                                                             
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;    

  /*����systick���ж����ȼ�*/
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1); 
	
	/*������ֵ��0*/
  SysTick->VAL   = 0; 

	/*����systick��ʱ��ΪAHB��ʱ��
	ʹ��systick���ж�
	ʹ��systick
	*/
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    
  return (0);                                                  
}

#endif 

void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(720000);
	for(i=0;i<ms;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));
	}
		/*ʧ��systick*/
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}

volatile uint32_t isr_ms;

void SysTick_Delay_ms_INT(uint32_t ms)
{
	isr_ms=ms;
	SysTick_Config(720000);
	
	while(isr_ms);
	
		/*ʧ��systick*/
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}






