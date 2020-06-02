#include "bsp_i2c_ee.h"
#include "bsp_i2c_gpio.h"
//���EEPROM�Ƿ����
//1��ʾû��⵽EEPROM
//0��ʾ��⵽EEPROM
uint8_t ee_CHECK_DEVICE(uint8_t addr)
{
	uint8_t result;
	i2c_START();
	//����EEPROM�豸��ַ
		i2c_WRITE_BYTE(addr);
	
	if(i2c_WAIT_ASK()==1)
	{
		result=1;
	}
	else
	{
		result=0;
	}
	i2c_NASK();
	
	i2c_STOP();
	
	return result;
}
//�ȴ�EEPROM�ڲ�ʱ�����
//1��ʾ��ʱ
//0��ʾ���
uint8_t ee_WAIT_STANDBY(void)
{
	uint16_t  cycle=0;
	while(ee_CHECK_DEVICE(EEPROM_ADDR|EEPROM_WRITE_DIR))
	{
		cycle++;
		if(cycle>=1000)
			return 1;
	}
	return 0;
}
//��EEPROMд��һ���ֽ�
uint8_t ee_WRITE_BYTE(uint8_t w_addr,uint8_t data)
{
	
	if(ee_WAIT_STANDBY())
	goto w_fail;
	
	
	i2c_START();
	//����EEPROM�豸��ַ
	i2c_WRITE_BYTE(EEPROM_ADDR|EEPROM_WRITE_DIR);
	
	if(i2c_WAIT_ASK())
	{
		goto w_fail;
	}
	else
	{
		//����Ҫд��Ĵ洢��Ԫ���ַ
		i2c_WRITE_BYTE(w_addr);
				if(i2c_WAIT_ASK()) //δ��Ӧ
				{
					goto w_fail;
				}
				else
				{
					//д������
					i2c_WRITE_BYTE(data);
				
				if(i2c_WAIT_ASK()) //δ��Ӧ
				{
					goto w_fail;
				}
				else
				{}
				}
	}

	
	i2c_STOP();
	
	if(ee_WAIT_STANDBY())
	goto w_fail;
	
	return 1;
	
	w_fail:
	i2c_STOP();
	return 0;

}
//��EEPROM��ȡһ���ֽ�
//������1 ����0
uint8_t ee_READ_BYTE(uint8_t r_addr,uint8_t *data)
{
	if(ee_WAIT_STANDBY())
	goto r_fail;
	
	
	i2c_START();
	//����EEPROM�豸��ַ
	i2c_WRITE_BYTE(EEPROM_ADDR|EEPROM_WRITE_DIR);
	
	if(i2c_WAIT_ASK())
	{
		goto r_fail;
	}
	else
	{
		//����Ҫ��ȡ�Ĵ洢��Ԫ���ַ
		i2c_WRITE_BYTE(r_addr);
				if(i2c_WAIT_ASK()) //δ��Ӧ
				{
					goto r_fail;
				}
				else
				{
					i2c_START();
					
					//���͵ڶ����豸��ַ������ʽ
					i2c_WRITE_BYTE(EEPROM_ADDR|EEPROM_READ_DIR);
					if(i2c_WAIT_ASK()) //δ��Ӧ
					{
						goto r_fail;
					}
					else
					{
						*data=i2c_READ_BYTE();						
					}
				}

	}
  i2c_NASK();
	
	i2c_STOP();
	
	return 1;
	
	r_fail:
	i2c_STOP();
	return 0;

}

