#include "i2c.h"
#include "cmsis_os.h"
#include <semphr.h>


I2C_HandleTypeDef hi2c3;

uint32_t I2c3Timeout = I2C3_TIMEOUT_MAX; /*<! Value of Timeout when I2C communication fails */

extern xSemaphoreHandle i2c_semaphore;

void MX_I2C3_Init(void) {

	/* USER CODE BEGIN I2C3_Init 0 */

	/* USER CODE END I2C3_Init 0 */

	/* USER CODE BEGIN I2C3_Init 1 */

	/* USER CODE END I2C3_Init 1 */
	hi2c3.Instance = I2C3;
	hi2c3.Init.ClockSpeed = 100000;
	hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c3.Init.OwnAddress1 = 0;
	hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c3.Init.OwnAddress2 = 0;
	hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c3) != HAL_OK) {
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_DISABLE)
			!= HAL_OK) {
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN I2C3_Init 2 */

	/* USER CODE END I2C3_Init 2 */

}

void I2C3_WriteData(uint8_t Addr, uint8_t Reg, uint8_t Value) {
	HAL_StatusTypeDef status = HAL_OK;

	if(xSemaphoreTake(i2c_semaphore, (TickType_t) 50) == pdPASS){

		status = HAL_I2C_Mem_Write(&hi2c3, Addr, (uint16_t) Reg,
				I2C_MEMADD_SIZE_8BIT, &Value, 1, I2c3Timeout);

		/* Check the communication status */
		if (status != HAL_OK) {
			/* Re-Initialize the BUS */
			//I2Cx_Error();
		}

		xSemaphoreGive(i2c_semaphore);
	}

}

/**
 * @brief  Reads a register of the device through BUS.
 * @param  Addr: Device address on BUS Bus.
 * @param  Reg: The target register address to write
 * @retval Data read at register address
 */
uint8_t I2C3_ReadData(uint8_t Addr, uint8_t Reg) {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t value = 0;

	if(xSemaphoreTake(i2c_semaphore, (TickType_t) 50) == pdPASS){

		status = HAL_I2C_Mem_Read(&hi2c3, Addr, Reg, I2C_MEMADD_SIZE_8BIT, &value,
				1, I2c3Timeout);

		/* Check the communication status */
		if (status != HAL_OK) {
			/* Re-Initialize the BUS */
			//I2Cx_Error();
		}

		xSemaphoreGive(i2c_semaphore);
	}

	return value;
}

/**
 * @brief  Reads multiple data on the BUS.
 * @param  Addr: I2C Address
 * @param  Reg: Reg Address
 * @param  pBuffer: pointer to read data buffer
 * @param  Length: length of the data
 * @retval 0 if no problems to read multiple data
 */
uint8_t I2C3_ReadBuffer(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
		uint16_t Length) {
	HAL_StatusTypeDef status = HAL_OK;

	if(xSemaphoreTake(i2c_semaphore, (TickType_t) 50) == pdPASS){
		status = HAL_I2C_Mem_Read(&hi2c3, Addr, (uint16_t) Reg,
				I2C_MEMADD_SIZE_8BIT, pBuffer, Length, I2c3Timeout);

		xSemaphoreGive(i2c_semaphore);
	}



	/* Check the communication status */
	if (status == HAL_OK) {
		return 0;
	} else {
		/* Re-Initialize the BUS */
		//I2Cx_Error();
		return 1;
	}
}
