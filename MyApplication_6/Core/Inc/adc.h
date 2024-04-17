#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"

extern ADC_HandleTypeDef hadc1;

void MX_ADC1_Init(void);
void ADC_Select_CH5(void);
void ADC_Select_CH7(void);


#endif /*__ADC_H__*/