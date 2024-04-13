

#include "cli.h"

void (*command[])() =
{
	DisplayMenu
};


void DisplayMenu(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "HELP MENU\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Get TemperatureIN Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Get TemperatureOUT Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Get Humidity Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Get Pressure Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "5. Get Ambient Light Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "6. Get Carbon Monoxide Data\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
