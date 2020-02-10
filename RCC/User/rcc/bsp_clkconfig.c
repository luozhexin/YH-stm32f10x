#include "./rcc/bsp_clkconfig.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul)
{
	__IO uint32_t StartUpCounter = 0, HSEStatus = 0;
	
	/*复位RCC寄存器到默认值*/
	RCC_DeInit();
	
	/*使能HSE*/
	RCC_HSEConfig(RCC_HSE_ON);
	
	/*等待HSE稳定*/
	HSEStatus = RCC_WaitForHSEStartUp();
	/*HSE启动成功*/
	
	if(HSEStatus == SUCCESS)
	{
		/*----------------------------------------*/
		    /* 使能预取指 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* Flash 的等待时间 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
		/*----------------------------------------*/
		
		 RCC_HCLKConfig(RCC_SYSCLK_Div1);
		 RCC_PCLK1Config(RCC_HCLK_Div2);
		 RCC_PCLK2Config(RCC_HCLK_Div1);
		
		/*选择PLL的时钟源，配置PLL的倍频因子*/
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul);
		
		/*使能PLL*/
		RCC_PLLCmd(ENABLE);
		
		/*等待PLL稳定*/
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		/*选择PLLCLK作为系统时钟*/
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/*等待系统时钟切换完成*/
		while(RCC_GetSYSCLKSource() != 0x08);
	}
	else
	{
		/*HSE 启动失败，用户可以在这里添加错误的处理代码*/
	}
}





