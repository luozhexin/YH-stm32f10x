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
	*(unsigned int*)0X40011000 |=(1<<(4*3));
	
		/*����CRL�Ĵ���������Ϊ�������*/
	*(unsigned int*)0X40011000 |=(1<<(4*2));
	
//	/*����OCR�Ĵ���*/
//	*(unsigned int*)0X4001100C &=~(1<<3); 
		while(1)
		{
				*(unsigned int*)0X4001100C &=~(1<<3); 
				soft_delay(0xfffff);
			
				*(unsigned int*)0X4001100C |=(1<<3); 
				soft_delay(0xfffff);
			
							*(unsigned int*)0X4001100C &=~(1<<2); 
				soft_delay(0xfffff);
			
				*(unsigned int*)0X4001100C |=(1<<2); 
				soft_delay(0xfffff);
		}
		
}
void SystemInit(void)
{
	/*������Ϊ�գ�Ŀ����Ϊ��ƭ��������������*/
}