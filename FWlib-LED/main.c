#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
//&=~ ������0
// |= ����д1

void soft_delay(unsigned int count)
{
	for(;count!=0;count--);
}
int main(void)
{
		GPIO_InitTypeDef GPIO_InitSturct;
	
	
/*����RCC�Ĵ�����ʹ��GPIO��ʱ��*/
	*(unsigned int *)0X40021018 |=(1<<4);
	
	GPIO_InitSturct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitSturct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitSturct.GPIO_Speed = GPIO_Speed_10MHZ;
	GPIO_Init(GPIOC, &GPIO_InitSturct);
	
	
//	/*����CRL�Ĵ���������Ϊ�������*/
//	GPIOC->CRL |=(1<<(4*3));
//	
//		/*����CRL�Ĵ���������Ϊ�������*/
//	GPIOC->CRL|=(1<<(4*2));
//	
//	/*����ODR�Ĵ���*/
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
	/*������Ϊ�գ�Ŀ����Ϊ��ƭ��������������*/
}
