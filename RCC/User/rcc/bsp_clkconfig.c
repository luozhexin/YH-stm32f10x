#include "./rcc/bsp_clkconfig.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul)
{
	__IO uint32_t StartUpCounter = 0, HSEStatus = 0;
	
	/*��λRCC�Ĵ�����Ĭ��ֵ*/
	RCC_DeInit();
	
	/*ʹ��HSE*/
	RCC_HSEConfig(RCC_HSE_ON);
	
	/*�ȴ�HSE�ȶ�*/
	HSEStatus = RCC_WaitForHSEStartUp();
	/*HSE�����ɹ�*/
	
	if(HSEStatus == SUCCESS)
	{
		/*----------------------------------------*/
		    /* ʹ��Ԥȡָ */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* Flash �ĵȴ�ʱ�� */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
		/*----------------------------------------*/
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		/*ѡ��PLL��ʱ��Դ������PLL�ı�Ƶ����*/
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul);
		
		/*ʹ��PLL*/
		RCC_PLLCmd(ENABLE);
		
		/*�ȴ�PLL�ȶ�*/
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		/*ѡ��PLLCLK��Ϊϵͳʱ��*/
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/*�ȴ�ϵͳʱ���л����*/
		while(RCC_GetSYSCLKSource() != 0x08);
	}
	else
	{
		/*HSE ����ʧ�ܣ��û�������������Ӵ���Ĵ������*/
	}
}





