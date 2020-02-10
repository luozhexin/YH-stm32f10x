#ifndef _STM32F10X_H 
#define _STM32F10X_H 
/* 
用于存放寄存器映射的代码
*/
/*外设基地址*/
#define PERIPH_BASE ((unsigned int)0X40000000)
	//peripheral 外设

/*总线基地址*/
#define APB1PERIPH_BASE  PERIPH_BASE
#define APB2PERIPH_BASE  (PERIPH_BASE+0X00010000)
#define AHBPERIPH_BASE   (PERIPH_BASE+0X00018000)

/*GPIO外设基地址*/
#define GPIOA_BASE		(APB2PERIPH_BASE+0X0800)
#define GPIOB_BASE		(APB2PERIPH_BASE+0X0C00)
#define GPIOC_BASE		(APB2PERIPH_BASE+0X1000)
#define GPIOD_BASE		(APB2PERIPH_BASE+0X1400)

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIO_TypeDef;



#define GPIOA    ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOB    ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOC    ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD    ((GPIO_TypeDef*)GPIOC_BASE)

#endif  /*_STM32F10X_H */
