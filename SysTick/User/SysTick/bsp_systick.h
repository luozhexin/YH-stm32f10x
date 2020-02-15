#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32f10x.h"
void SysTick_Delay_ms(uint32_t ms);

void SysTick_Delay_ms_INT(uint32_t ms);
#endif /*__BSP_SYSTICK_H*/


