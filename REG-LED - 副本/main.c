#include "stm32f10x.h"
//&=~ 用于清0
// |= 用于写1

void soft_delay(unsigned int count)
{
	for(;count!=0;count--);
}
int main(void)
{
/*配置RCC寄存器，使能GPIO的时钟*/
	*(unsigned int *)0X40021018 |=(1<<4);
	
	/*配置CRL寄存器，配置为推挽输出*/
	*(unsigned int*)GPIOC_CRL |=(1<<(4*3));
	
		/*配置CRL寄存器，配置为推挽输出*/
	*(unsigned int*)GPIOC_CRL |=(1<<(4*2));
	
	/*配置ODR寄存器*/
	*(unsigned int*)GPIOC_ODR &=~(1<<2); 
		while(1)
		{
				*(unsigned int*)GPIOC_ODR &=~(1<<3); 
				soft_delay(0xfffff);
			
				*(unsigned int*)GPIOC_ODR |=(1<<3); 
				soft_delay(0xfffff);
			
				*(unsigned int*)GPIOC_ODR &=~(1<<2); 
				soft_delay(0xfffff);
			
				*(unsigned int*)GPIOC_ODR |=(1<<2); 
				soft_delay(0xfffff);
		}
		
}
void SystemInit(void)
{
	/*函数体为空，目的是为了骗过编译器不报错*/
}