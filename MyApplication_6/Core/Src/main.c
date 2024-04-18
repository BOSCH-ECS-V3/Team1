/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
//#define DISPLAY_MENU_COMMAND 0
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"
#include "crc.h"
#include "i2c.h"
#include "spi.h"
#include "ltdc.h"
#include "dma.h"
#include "adc.h"
#include "uart.h"
#include "fmc.h"
#include "clock.h"
#include "cmsis_os.h"
#include "app_touchgfx.h"
#include "semphr.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "temp_sens.h"
#include "data_UI_def.h"
#include "cli.h"
#include "utilities.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* USER CODE BEGIN PV */
TaskHandle_t GUI_TaskHandle;
TaskHandle_t GetSensData_TaskHandle;
TaskHandle_t CLI_TaskHandle;

BaseType_t GUI_TaskFlag;
BaseType_t GetSensData_TaskFlag;
BaseType_t CLI_TaskFlag;

xSemaphoreHandle i2c_semaphore;

SensData_t data_UI;

char msg[30];
short msgIDX = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void CLI_Task(void *argument);
void GetSensDataTask(void *argument);
extern void TouchGFX_Task(void *argument);

/* Link function for LCD peripheral */
void LCD_IO_Init(void);
void LCD_IO_WriteData(uint16_t RegValue);
void LCD_IO_WriteReg(uint8_t Reg);
uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize);
void LCD_Delay(uint32_t delay);

/* IOExpander IO functions */
void IOE_Init(void);
void IOE_ITConfig(void);
void IOE_Delay(uint32_t Delay);
void IOE_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t IOE_Read(uint8_t Addr, uint8_t Reg);
uint16_t IOE_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
		uint16_t Length);

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

	/* USER CODE BEGIN 1 */
	i2c_semaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(i2c_semaphore); //After creation to be free

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_CRC_Init();
	MX_I2C3_Init();
	MX_SPI5_Init();
	MX_FMC_Init();
	MX_LTDC_Init();
	MX_DMA2D_Init();
	MX_ADC1_Init();
	MX_USART1_UART_Init();
	MX_TouchGFX_Init();
	/* Call PreOsInit function */
	MX_TouchGFX_PreOSInit();
	/* USER CODE BEGIN 2 */

	/* Init BME680*/

	/*Task creation*/
	GUI_TaskFlag = xTaskCreate(TouchGFX_Task, "TouchGFX_Task", 8192, NULL, osPriorityNormal,
			&GUI_TaskHandle);

	GetSensData_TaskFlag = xTaskCreate(GetSensDataTask, "GetSensDataTask", 128, NULL, osPriorityNormal,
			&GetSensData_TaskHandle);

	CLI_TaskFlag = xTaskCreate(CLI_Task, "Command Line Interface", 128, NULL, osPriorityNormal,
			&CLI_TaskHandle);


	/*Check if task and semaphore creation is successful*/
	if(GUI_TaskFlag != pdPASS){
		vTaskDelete(GUI_TaskHandle);
	}
	if(GetSensData_TaskFlag != pdPASS){
		vTaskDelete(GetSensData_TaskHandle);
	}
	if(CLI_TaskFlag != pdPASS){
		vTaskDelete(CLI_TaskHandle);
	}
	if(i2c_semaphore == NULL){

		/* Indicates semaphore creation failed*/
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
	}



	/*Start freeRTOS scheduler*/
	vTaskStartScheduler();
	/* USER CODE END 2 */

	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief  IOE Low Level Initialization.
 */
void IOE_Init(void) {
	//Dummy function called when initializing to stmpe811 to setup the i2c.
	//This is done with cubmx and is therfore not done here.
}

/**
 * @brief  IOE Low Level Interrupt configuration.
 */
void IOE_ITConfig(void) {
	//Dummy function called when initializing to stmpe811 to setup interupt for the i2c.
	//The interupt is not used in our case, therefore nothing is done here.
}

/**
 * @brief  IOE Writes single data operation.
 * @param  Addr: I2C Address
 * @param  Reg: Reg Address
 * @param  Value: Data to be written
 */
void IOE_Write(uint8_t Addr, uint8_t Reg, uint8_t Value) {
	I2C3_WriteData(Addr, Reg, Value);
}

/**
 * @brief  IOE Reads single data.
 * @param  Addr: I2C Address
 * @param  Reg: Reg Address
 * @retval The read data
 */
uint8_t IOE_Read(uint8_t Addr, uint8_t Reg) {
	return I2C3_ReadData(Addr, Reg);
}

/**
 * @brief  IOE Reads multiple data.
 * @param  Addr: I2C Address
 * @param  Reg: Reg Address
 * @param  pBuffer: pointer to data buffer
 * @param  Length: length of the data
 * @retval 0 if no problems to read multiple data
 */
uint16_t IOE_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t *pBuffer,
		uint16_t Length) {
	return I2C3_ReadBuffer(Addr, Reg, pBuffer, Length);
}

/**
 * @brief  IOE Delay.
 * @param  Delay in ms
 */
void IOE_Delay(uint32_t Delay) {
	HAL_Delay(Delay);
}


void LCD_IO_Init(void) {
	/* Set or Reset the control line */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
}

/**
 * @brief  Writes register value.
 */
void LCD_IO_WriteData(uint16_t RegValue) {
	/* Set WRX to send data */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);

	/* Reset LCD control line(/CS) and Send data */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	SPI5_Write(RegValue);

	/* Deselect: Chip Select high */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
}

/**
 * @brief  Writes register address.
 */
void LCD_IO_WriteReg(uint8_t Reg) {
	/* Reset WRX to send command */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);

	/* Reset LCD control line(/CS) and Send command */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	SPI5_Write(Reg);

	/* Deselect: Chip Select high */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
}

/**
 * @brief  Reads register value.
 * @param  RegValue Address of the register to read
 * @param  ReadSize Number of bytes to read
 * @retval Content of the register value
 */
uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize) {
	uint32_t readvalue = 0;

	/* Select: Chip Select low */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);

	/* Reset WRX to send command */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);

	SPI5_Write(RegValue);

	readvalue = SPI5_Read(ReadSize);

	/* Set WRX to send data */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);

	/* Deselect: Chip Select high */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);

	return readvalue;
}

/**
 * @brief  Wait for loop in ms.
 * @param  Delay in ms.
 */
void LCD_Delay(uint32_t Delay) {
	HAL_Delay(Delay);
}

void GetSensDataTask(void *argument) {

	SensorInit(&sensor_In, &meas_period_In, SENS_IN_NUM);

	for (;;) {

		ADC_Select_CH5(); //get ADC value from PA5 <Ambient light>

		ADC_Select_CH7(); //get ADC value from PA7 <Gas sensor>

		GetBMEdata();

		osDelay(500);
	}
}


void CLI_Task(void *argument) {
	HAL_UART_Receive_IT(&huart1, (uint8_t*) &msg[msgIDX], 1);
	for (;;) {

		xTaskNotifyWait(0, 1, NULL, portMAX_DELAY);

		CLIHandler(&data_UI, &huart1, msg, &msgIDX);

	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	xTaskNotifyFromISR(CLI_TaskHandle, 0, eNoAction, NULL);
	HAL_UART_Transmit(&huart1, (uint8_t*)&msg[msgIDX], 1, 100);
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM6 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM6) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
