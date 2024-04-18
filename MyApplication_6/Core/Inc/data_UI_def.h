#ifndef __DATA_UI_DEF_H
#define __DATA_UI_DEF_H

#define AMBIENT_UNPLUGED 0
#define GAS_UNPLUGED 1000
#define GAS_ADC_BORDER 120


typedef struct
{
    int ambientLight;
    float tempIN;
    float tempOUT;
    int pressure;
    int carbonMonoxide;
    float humidity;
}SensData_t;


#endif /*__DATA_UI_DEF_H*/
