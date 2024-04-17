#ifndef __TEMP_SENS_H__
#define __TEMP_SENS_H__

#include "bme680.h"

#define BME680_ERR 200
#define SENS_IN_NUM 0
#define SENS_OUT_NUM 1

extern struct bme680_dev sensor_In;
extern struct bme680_dev sensor_Out;
extern struct bme680_field_data data_In;
extern struct bme680_field_data data_Out;
extern uint16_t meas_period_In;
extern uint16_t meas_period_Out;

int8_t SensorInit(struct bme680_dev *sensor, uint16_t *meas_period, uint8_t sens_num);


int8_t CollectSensorData(struct bme680_dev *sensor, struct bme680_field_data *data);

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);


int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

void user_delay_ms(uint32_t period);

void GetBMEdata();



#endif /*__TEMP_SENS_H__*/
