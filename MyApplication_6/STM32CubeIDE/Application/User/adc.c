#include "adc.h"
#include "utilities.h"

ADC_HandleTypeDef hadc1;


void MX_ADC1_Init(void) {

	/* USER CODE BEGIN ADC1_Init 0 */

	/* USER CODE END ADC1_Init 0 */

	/* USER CODE BEGIN ADC1_Init 1 */

	/* USER CODE END ADC1_Init 1 */

	/** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	 */
	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	hadc1.Init.ScanConvMode = ENABLE;
	hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 2;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	if (HAL_ADC_Init(&hadc1) != HAL_OK) {
		Error_Handler();
	}


}

void ADC_Select_CH5(SensData_t *data) {

	uint32_t adcVal_ch5;
	ADC_ChannelConfTypeDef sConfig = { 0 };
	/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	 */
	sConfig.Channel = ADC_CHANNEL_5;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
		Error_Handler();
	}

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adcVal_ch5 = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	if(adcVal_ch5 == AMBIENT_UNPLUGGED){

		data->ambientLight = 0;
	}else{
		data->ambientLight = map(adcVal_ch5, 0, 4095, 1, 100);
	}


}


void ADC_Select_CH7(SensData_t *data) {

	uint32_t adcVal_ch7;

	ADC_ChannelConfTypeDef sConfig = { 0 };
	/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	 */
	sConfig.Channel = ADC_CHANNEL_7;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
		Error_Handler();
	}

	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adcVal_ch7 = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	if (adcVal_ch7 < GAS_ADC_BORDER) {

		adcVal_ch7 = GAS_ADC_BORDER;
	}

	if(adcVal_ch7 > GAS_UNPLUGGED){
		data->carbonMonoxide = 601;
	}
	else{
		data->carbonMonoxide = map(adcVal_ch7, 120, 500, 20, 1000);
	}

}
