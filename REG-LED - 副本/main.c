#include "stm32f10x.h"
//&=~ ������0
// |= ����д1

void soft_delay(unsigned int count)
{
	for(;count!=0;count--);
}
int main(void)
{
/*����RCC�Ĵ�����ʹ��GPIO��ʱ��*/
	*(unsigned int *)0X40021018 |=(1<<4);
	
	/*����CRL�Ĵ���������Ϊ�������*/
	*(unsigned int*)GPIOC_CRL |=(1<<(4*3));
	
		/*����CRL�Ĵ���������Ϊ�������*/
	*(unsigned int*)GPIOC_CRL |=(1<<(4*2));
	
	/*����ODR�Ĵ���*/
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
	/*������Ϊ�գ�Ŀ����Ϊ��ƭ��������������*/
}