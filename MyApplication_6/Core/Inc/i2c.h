#ifndef __I2C_H__
#define __I2C_H__

#include "main.h"

#define I2C3_TIMEOUT_MAX                    0x80 /*<! The value of the maximal timeout for I2C waiting loops */

extern I2C_HandleTypeDef hi2c3;

void MX_I2C3_Init(void);

uint8_t I2C3_ReadData(uint8_t Addr, uint8_t Reg);
void I2C3_WriteData(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t I2C3_ReadBuffer(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
		uint16_t Length);


#endif /*__I2C_H__*/
