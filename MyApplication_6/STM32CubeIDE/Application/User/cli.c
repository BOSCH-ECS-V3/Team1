#include "cli.h"

char msg[30];
short msgIDX = 0;


void (*command[])() =
{
	DisplayMenu, 		//0
	ErrMsgLong,			//1
	ErrMsgNF,			//2
	GetTempIN,			//3
	GetTempOUT,			//4
	GetHumidity,		//5
	GetPressure,		//6
	GetAmbientLight,	//7
	GetTempCBMonoxide	//8

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
	void lowerString(char *stringToLower) {
		for (int i = 0; i < strlen(stringToLower); i++) {
			stringToLower[i] = tolower(stringToLower[i]);
		}
	}
	void GetTempIN(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Temperature Inside: %dC\n\r",
				(int)SelectedSensor->tempIN);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void GetTempOUT(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Temperature Outside: %Cd\n\r",
				(int)SelectedSensor->tempOUT);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void GetHumidity(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Humidity: %d%%\n\r", (int)SelectedSensor->humidity);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void GetPressure(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Pressure: %dhPa\n\r", SelectedSensor->pressure);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void GetAmbientLight(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Ambient Light: %d%%\n\r",
				SelectedSensor->ambientLight);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void GetTempCBMonoxide(SensData_t *SelectedSensor,UART_HandleTypeDef *huart1) {
		char msg[60];
		sprintf(msg, "\n\r Carbon Monoxide: %d\n\r",
				SelectedSensor->carbonMonoxide);
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	}
	void CommandHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,char *msg) {
		switch (msg[0]) {
		case '1':
			(command[GET_TEMP_IN_COMMAND])(SelectedSensor, huart1);
			break;
		case '2':
			(command[GET_TEMP_OUT_COMMAND])(SelectedSensor, huart1);
			break;
		case '3':
			(command[GET_HUMIDITY_COMMAND])(SelectedSensor, huart1);
			break;
		case '4':
			(command[GET_PRESSURE_COMMAND])(SelectedSensor, huart1);
			break;
		case '5':
			(command[GET_AMBIENT_LIGHT_COMMAND])(SelectedSensor, huart1);
			break;
		case '6':
			(command[GET_CB_MONOXIDE_COMMAND])(SelectedSensor, huart1);
			break;

		default:
			(command[ERR_MSG_NF])(huart1);
			break;
		}
	}
	void CLIHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
			char *msg, short *msgIDX) {
		if (*msgIDX >= 24) {
			(command[ERR_MSG_LONG])(huart1);
			clearMSG(msg, msgIDX);
		} else {
			if (msg[*msgIDX] == '\r') {
				lowerString(msg);
				if (strncmp(msg, "help", *msgIDX) == 0) {
					(command[DISPLAY_MENU_COMMAND])(huart1);
					clearMSG(msg, msgIDX);
				} else {
					if (*msgIDX > 1){
						(command[ERR_MSG_NF])(huart1);
						clearMSG(msg, msgIDX);
					}

					else {
						CommandHandler(SelectedSensor, huart1, msg);
						clearMSG(msg, msgIDX);
					}
				}
			} else {
				*msgIDX = *msgIDX + 1;
			}
		}
		HAL_UART_Receive_IT(huart1, (uint8_t*) &msg[*msgIDX], 1);
	}
