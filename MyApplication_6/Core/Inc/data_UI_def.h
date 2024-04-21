#ifndef __DATA_UI_DEF_H
#define __DATA_UI_DEF_H

/*Ambient light sensor defines*/
#define AMBIENT_UNPLUGGED 0

/*Gas sensor defines*/
#define GAS_DANGER_VALUES 180
#define GAS_UNPLUGGED 1000
#define GAS_ADC_BORDER 120

/*Temp sensor IN defines*/
#define TEMP_IN_MIN_VALUE 15
#define TEMP_IN_MAX_VALUE 35
#define TEMP_IN_UNPLUGGED 201

/*Temp sensor OUT defines*/
#define TEMP_OUT_MIN_VALUE -10
#define TEMP_OUT_MAX_VALUE 40
#define TEMP_OUT_UNPLUGGED 301

/*Humidity defines*/
#define HUMIDITY_MIN_VALUE 25
#define HUMIDITY_MAX_VALUE 60
#define HUMIDITY_UNPLUGGED 0

/*Pressure defines*/
#define PRESSURE_UNPLUGGED 0

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
