#include "./SysTick/bsp_systick.h"

#if 0
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
	/*reload寄存器为24位，最大值为2^24*/
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            
  
	/*初始化reload寄存器的值*/                                                             
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;    

  /*配置systick的中断优先级*/
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1); 
	
	/*计数器值清0*/
  SysTick->VAL   = 0; 

	/*配置systick的时钟为AHB的时钟
	使能systick的中断
	使能systick
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
		/*失能systick*/
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}

volatile uint32_t isr_ms;

void SysTick_Delay_ms_INT(uint32_t ms)
{
	isr_ms=ms;
	SysTick_Config(720000);
	
	while(isr_ms);
	
		/*失能systick*/
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
}






