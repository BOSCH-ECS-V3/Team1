#ifndef __SPI_H__
#define __SPI_H__

#include "main.h"

#define SPI5_TIMEOUT_MAX                    0x1000

extern SPI_HandleTypeDef hspi5;

void MX_SPI5_Init(void);

void SPI5_Write(uint16_t Value);
uint32_t SPI5_Read(uint8_t ReadSize);
void SPI5_Error(void);


#endif /*__SPI_H__*/
