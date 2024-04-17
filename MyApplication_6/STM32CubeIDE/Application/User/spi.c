#include "spi.h"

SPI_HandleTypeDef hspi5;

uint32_t Spi5Timeout = SPI5_TIMEOUT_MAX; /*<! Value of Timeout when SPI communication fails */

void MX_SPI5_Init(void) {

	/* USER CODE BEGIN SPI5_Init 0 */

	/* USER CODE END SPI5_Init 0 */

	/* USER CODE BEGIN SPI5_Init 1 */

	/* USER CODE END SPI5_Init 1 */
	/* SPI5 parameter configuration*/
	hspi5.Instance = SPI5;
	hspi5.Init.Mode = SPI_MODE_MASTER;
	hspi5.Init.Direction = SPI_DIRECTION_2LINES;
	hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi5.Init.NSS = SPI_NSS_SOFT;
	hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi5.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi5) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN SPI5_Init 2 */

	/* USER CODE END SPI5_Init 2 */

}

uint32_t SPI5_Read(uint8_t ReadSize) {
	HAL_StatusTypeDef status = HAL_OK;
	uint32_t readvalue;

	status = HAL_SPI_Receive(&hspi5, (uint8_t*) &readvalue, ReadSize,
			Spi5Timeout);

	/* Check the communication status */
	if (status != HAL_OK) {
		/* Re-Initialize the BUS */
		SPI5_Error();
	}

	return readvalue;
}

/**
 * @brief  Writes a byte to device.
 * @param  Value: value to be written
 */
void SPI5_Write(uint16_t Value) {
	HAL_StatusTypeDef status = HAL_OK;

	status = HAL_SPI_Transmit(&hspi5, (uint8_t*) &Value, 1, Spi5Timeout);

	/* Check the communication status */
	if (status != HAL_OK) {
		/* Re-Initialize the BUS */
		SPI5_Error();
	}
}

/**
 * @brief  SPI5 error treatment function.
 */
void SPI5_Error(void) {
	/* De-initialize the SPI communication BUS */
	//HAL_SPI_DeInit(&SpiHandle);
	/* Re- Initialize the SPI communication BUS */
	//SPIx_Init();
}
