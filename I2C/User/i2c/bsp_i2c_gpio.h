#ifndef __BSP_I2C_GPIO_H
#define	__BSP_I2C_GPIO_H


#include "stm32f10x.h"


/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
#define I2C_SCL_GPIO_PORT    	GPIOC		              /* GPIO端口 */
#define I2C_SCL_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define I2C_SCL_GPIO_PIN			GPIO_Pin_2			        

#define I2C_SDA_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define I2C_SDA_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define I2C_SDA_GPIO_PIN		GPIO_Pin_3			        

/*控制引脚电平*/
#if 0
#define EEPROM_I2C_SDA_1()		GPIO_SetBits(I2C_SDA_GPIO_PORT,I2C_SDA_GPIO_PIN)
#define EEPROM_I2C_SDA_0()		GPIO_ResetBits(I2C_SDA_GPIO_PORT,I2C_SDA_GPIO_PIN)

#define EEPROM_I2C_SCL_1()		GPIO_SetBits(I2C_SCL_GPIO_PORT,I2C_SCL_GPIO_PIN)
#define EEPROM_I2C_SCL_0()		GPIO_ResetBits(I2C_SCL_GPIO_PORT,I2C_SCL_GPIO_PIN)

#define EEPROM_I2C_SDA_READ()	GPIO_ReadInputDataBit(I2C_SDA_GPIO_PORT,I2C_SDA_GPIO_PIN);

#else
#define EEPROM_I2C_SDA_1()		I2C_SDA_GPIO_PORT->BSRR = I2C_SDA_GPIO_PIN;
#define EEPROM_I2C_SDA_0()		I2C_SDA_GPIO_PORT->BRR = I2C_SDA_GPIO_PIN;

#define EEPROM_I2C_SCL_1()		I2C_SCL_GPIO_PORT->BSRR = I2C_SCL_GPIO_PIN;
#define EEPROM_I2C_SCL_0()		I2C_SCL_GPIO_PORT->BRR = I2C_SCL_GPIO_PIN;

#define EEPROM_I2C_SDA_READ()	(I2C_SDA_GPIO_PORT->IDR & I2C_SDA_GPIO_PIN) != (uint32_t)Bit_RESET

#endif
void i2c_GPIO_Config(void);
void i2c_START(void);
void i2c_STOP(void);
void i2c_ASK(void);
void i2c_NASK(void);
uint8_t i2c_WAIT_ASK(void);
void i2c_WRITE_BYTE(uint8_t data);
uint8_t i2c_READ_BYTE(void);

#endif /*__BSP_I2C_GPIO_H*/
