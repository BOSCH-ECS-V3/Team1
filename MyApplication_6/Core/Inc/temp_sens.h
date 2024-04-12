#ifndef __TEMP_SENS_H
#define __TEMP_SENS_H

#include "bme680.h"

#define BME680_ERR 200

int8_t SensorInit(struct bme680_dev *sensor, uint16_t *meas_period);

int8_t SensorConfig(struct bme680_dev *sensor);

void SetMeasurementPeriod(struct bme680_dev *sensor, uint16_t *meas_period);

int8_t CollectSensorData(struct bme680_dev *sensor, struct bme680_field_data *data);

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);


int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

void user_delay_ms(uint32_t period);



#endif /*__TEMP_SENS_H*/
