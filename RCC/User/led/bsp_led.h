#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED1_GPIO_CLK			RCC_APB2Periph_GPIOC
#define LED1_GPIO_PORT			GPIOC
#define LED1_GPIO_PIN			GPIO_Pin_2

#define LED2_GPIO_CLK			RCC_APB2Periph_GPIOC
#define LED2_GPIO_PORT			GPIOC
#define LED2_GPIO_PIN			GPIO_Pin_3


void LED_GPIO_Config(void);


#endif /*__BSP_LED_H*/



