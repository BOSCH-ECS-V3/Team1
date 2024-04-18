#include <string.h>
#include "temp_sens.h"
#include "stm32f4xx_hal.h"
#include  "data_UI_def.h"
#include "cmsis_os.h"
#include <semphr.h>

extern I2C_HandleTypeDef hi2c3;
extern SensData_t data_UI;
extern xSemaphoreHandle i2c_semaphore;

struct bme680_dev sensor_In;
struct bme680_dev sensor_Out;
struct bme680_field_data data_In;
struct bme680_field_data data_Out;
uint16_t meas_period_In;
uint16_t meas_period_Out;


int8_t SensorInit(struct bme680_dev *sensor, uint16_t *meas_period, uint8_t sens_num){


	if(sens_num == SENS_IN_NUM){ // 0-> sens_In
		sensor->dev_id = BME680_I2C_ADDR_SECONDARY;
	}else{
		sensor->dev_id = BME680_I2C_ADDR_PRIMARY;
	}
	sensor->intf = BME680_I2C_INTF;
	sensor->read = user_i2c_read;
	sensor->write = user_i2c_write;
	sensor->delay_ms = user_delay_ms;
	sensor->amb_temp = 25;

	int8_t rslt = bme680_init(&sensor_In);
	uint8_t set_required_settings;

	sensor->tph_sett.os_hum = BME680_OS_2X;
	sensor->tph_sett.os_pres = BME680_OS_4X;
	sensor->tph_sett.os_temp = BME680_OS_8X;

	sensor->power_mode = BME680_FORCED_MODE;
	set_required_settings = (BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL);

	if((bme680_set_sensor_settings(set_required_settings, sensor) || bme680_set_sensor_mode(sensor)) != BME680_OK){

		rslt = -1;

	}

	bme680_get_profile_dur(meas_period, sensor);

	return rslt;
}


int8_t CollectSensorData(struct bme680_dev *sensor, struct bme680_field_data *data){

	int8_t rslt;
	rslt = bme680_get_sensor_data(data, sensor);

	return rslt;

}

int8_t user_i2c_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){

	int8_t result = BME680_OK;

	if(xSemaphoreTake(i2c_semaphore, (TickType_t) 50) == pdPASS){
		if(HAL_I2C_Master_Transmit(&hi2c3, (dev_id << 1), &reg_addr, 1, 50) != HAL_OK){

			result = -1;
		}else if(HAL_I2C_Master_Receive (&hi2c3, (dev_id << 1) | 0x01, reg_data, len, 50) != HAL_OK){

			result = -1;
		}

		xSemaphoreGive(i2c_semaphore);
	}


	return result;
}


int8_t user_i2c_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len){


	int8_t result = BME680_OK;
	int8_t buf[len+1];

	buf[0] = reg_addr;
	memcpy(buf + 1, reg_data, len);

	if(xSemaphoreTake(i2c_semaphore, (TickType_t) 50) == pdPASS){

		if (HAL_I2C_Master_Transmit(&hi2c3, (dev_id << 1), (uint8_t *) buf, len + 1, HAL_MAX_DELAY) != HAL_OK) {
			result = -1;
		}

		xSemaphoreGive(i2c_semaphore);
	}




	return result;
}

void GetBMEdata() {

	user_delay_ms(meas_period_In);

	if (CollectSensorData(&sensor_In, &data_In) == BME680_OK) {

		data_UI.tempIN = data_In.temperature / 100.0f;
		data_UI.humidity = data_In.humidity / 1000.0f;
		data_UI.pressure = data_In.pressure / 100.0f;

		if (sensor_In.power_mode == BME680_FORCED_MODE) {

			bme680_set_sensor_mode(&sensor_In);
		}

	} else {

		SensorInit(&sensor_In, &meas_period_In, SENS_IN_NUM);
		data_UI.tempIN = 201;
	}

}

void user_delay_ms(uint32_t period){

	HAL_Delay(period);
}



