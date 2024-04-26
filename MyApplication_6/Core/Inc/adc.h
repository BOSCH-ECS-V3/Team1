#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"
#include "data_UI_def.h"

extern ADC_HandleTypeDef hadc1;

void MX_ADC1_Init(void);
void ADC_Select_CH5(SensData_t *);
void ADC_Select_CH7(SensData_t *);


#endif /*__ADC_H__*/
