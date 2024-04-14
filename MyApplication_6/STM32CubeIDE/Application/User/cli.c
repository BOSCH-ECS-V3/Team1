#include "cli.h"

void (*command[])() =
{
	DisplayMenu,
	ErrMsgLong,
	ErrMsgNF
};
	void DisplayMenu(UART_HandleTypeDef *huart1) {
		char msg[40];
		sprintf(msg, "\n\rHELP MENU\n\r");
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

	void ErrMsgLong(UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\rMESSAGE TOO LONG!\n\r"
				"TRY 'HELP' TO SEE LIST OF COMMANDS!\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);

	}
	void ErrMsgNF(UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\rMESSAGE NOT FOUND!\n\r"
				"TRY 'HELP' TO SEE LIST OF COMMANDS!\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);

	}
