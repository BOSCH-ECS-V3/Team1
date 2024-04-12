
#include "temp_sens.h"
#include <string.h>
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c3;

extern struct bme680_dev sensor_In;
extern struct bme680_dev sensor_Out;


int8_t SensorInit(struct bme680_dev *sensor, uint16_t *meas_period){

	sensor->dev_id = BME680_I2C_ADDR_SECONDARY;
	sensor->intf = BME680_I2C_INTF;
	sensor->read = user_i2c_read;
	sensor->write = user_i2c_write;
	sensor->delay_ms = user_delay_ms;
	sensor->amb_temp = 25;

	int8_t rslt = bme680_init(sensor);
	rslt = SensorConfig(sensor);

	SetMeasurementPeriod(sensor, meas_period);
	return rslt;
}


int8_t SensorConfig(struct bme680_dev *sensor){

	uint8_t set_required_settings;
	int8_t rslt = BME680_OK;

	sensor->tph_sett.os_hum = BME680_OS_2X;
	sensor->tph_sett.os_pres = BME680_OS_4X;
	sensor->tph_sett.os_temp = BME680_OS_8X;

	sensor->power_mode = BME680_FORCED_MODE;
	set_required_settings = (BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL);

	if((bme680_set_sensor_settings(set_required_settings, sensor) || bme680_set_sensor_mode(sensor)) != BME680_OK){

		rslt = -1;

	}

	return rslt;

}


void SetMeasurementPeriod(struct bme680_dev *sensor, uint16_t *meas_period){

	bme680_get_profile_dur(meas_period, sensor);

}

int8_t CollectSensorData(struct bme680_dev *sensor, struct bme680_field_data *data){

	int8_t rslt;
	rslt = bme680_get_sensor_data(data, sensor);

	return rslt;

}

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){

	int8_t result;

	if (HAL_I2C_Master_Transmit(&hi2c3, (dev_id << 1), &reg_addr, 1, HAL_MAX_DELAY) != HAL_OK) {
		result = -1;
	} else if (HAL_I2C_Master_Receive (&hi2c3, (dev_id << 1) | 0x01, reg_data, len, HAL_MAX_DELAY) != HAL_OK) {
		result = -1;
	} else {
		result = 0;
	}

	return result;
}


int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){

	int8_t result;
	int8_t buf[BME680_TMP_BUFFER_LENGTH];

	buf[0] = reg_addr;
	memcpy(buf + 1, reg_data, len);

	if (HAL_I2C_Master_Transmit(&hi2c3, (dev_id << 1), (uint8_t *) buf, len + 1, HAL_MAX_DELAY) != HAL_OK) {
		result = -1;
	} else {
		result = 0;
	}

	return result;
}

void user_delay_ms(uint32_t period){

	HAL_Delay(period);
}



