#ifndef __LTDC_H__
#define __LTDC_H__

#include "main.h"
#include "Components/ili9341/ili9341.h"

extern LTDC_HandleTypeDef hltdc;
extern LCD_DrvTypeDef *LcdDrv;

void MX_LTDC_Init(void);


#endif /*__LTDC_H__*/