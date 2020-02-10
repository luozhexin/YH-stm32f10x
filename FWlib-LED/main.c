#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
//&=~ 用于清0
// |= 用于写1

void soft_delay(unsigned int count)
{
	for(;count!=0;count--);
}
int main(void)
{
		GPIO_InitTypeDef GPIO_InitSturct;
	
	
/*配置RCC寄存器，使能GPIO的时钟*/
	*(unsigned int *)0X40021018 |=(1<<4);
	
	GPIO_InitSturct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitSturct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitSturct.GPIO_Speed = GPIO_Speed_10MHZ;
	GPIO_Init(GPIOC, &GPIO_InitSturct);
	
	
//	/*配置CRL寄存器，配置为推挽输出*/
//	GPIOC->CRL |=(1<<(4*3));
//	
//		/*配置CRL寄存器，配置为推挽输出*/
//	GPIOC->CRL|=(1<<(4*2));
//	
//	/*配置ODR寄存器*/
//	GPIOC->ODR &=~(1<<2); 
		while(1)
		{
				GPIOC->ODR &=~(1<<3); 
				soft_delay(0xfffff);
			
				GPIOC->ODR |=(1<<3); 
				soft_delay(0xfffff);
			
	//			GPIOC->ODR &=~(1<<2); 
			GPIO_ResetBits ( GPIOC,GPIO_Pin_2);
				soft_delay(0xfffff);
			
//				GPIOC->ODR |=(1<<2); 
			  GPIO_SetBits ( GPIOC,GPIO_Pin_2);
				soft_delay(0xfffff);
		}
		
}
void SystemInit(void)
{
	/*函数体为空，目的是为了骗过编译器不报错*/
}
