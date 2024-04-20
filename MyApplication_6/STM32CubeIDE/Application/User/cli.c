#include "cli.h"

char msg[30];
short msgIDX = 0;
short selectedMenu = DISPLAY_HELP_MENU;
//DO NOT FORMAT THIS FILE
void (*menu[])()=
{
DisplayHelpMenu,
DisplayDataMenu,
DisplayGetDateTime,
DisplaySetDateTime,
DisplayAlarmsMenu
};

void (*command[])() =
{
GetTempIN,			//0
GetTempOUT,			//1
GetHumidity,		//2
GetPressure,		//3
GetAmbientLight,	//4
GetTempCBMonoxide,	//5
GetDate,			//6
GetTime				//7

};

void (*error[])()=
{
ErrMsgLong,
ErrMsgNF
};
void (*handler[])()=
{
CommandMenuHandler,
CommandDataHandler,
CommandGetDTHandler,
CommandSetDTHandler,
CommandAlarmHandler
};
//WHY?!??!?!
//WHY DOES IT FORMAT IT LIKE THIS??
//ECLIPSE YOU MONSTER

//MENUS TO DISPLAY
void DisplayHelpMenu(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "\n\rHELP MENU\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Data Menu\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Get Date and Time\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Set Date and Time\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Alarms Menu\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
void DisplayGetDateTime(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "\n\rDATE TIME ACCESS MENU\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Get Date\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Get Time\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Get Day\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Get Month\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "5. Get Year\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "6. Get Seconds\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "7. Get Minutes\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "8. Get Hours\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "9. Back\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
void DisplaySetDateTime(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "\n\rDATE TIME CHANGE MENU\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Set Day\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Set Month\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Set Year\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Set Seconds\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "5. Set Minutes\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "6. Set Hours\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "7. Back\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
void DisplayAlarmsMenu(UART_HandleTypeDef *huart1) {
	char msg[55];
	sprintf(msg, "\n\rALARMS MENU\n\r"
			"TO STOP ALARM TYPE ALARM NUMBER AGAIN\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Alarm1\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Alarm2\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Alarm3\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Alarm4\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "5. Alarm5\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "6. Alarm6\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "7. Back\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
void DisplayDataMenu(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "\n\rDATA MENU\n\r");
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
	sprintf(msg, "7. Back\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}

//ERROR HANDLING
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

//COMMANDS FOR MCU
void GetTempIN(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Temperature Inside: %dC\n\r",
			(int) SelectedSensor->tempIN);
}
void GetTempOUT(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Temperature Outside: %dC\n\r",
			(int) SelectedSensor->tempOUT);
}
void GetHumidity(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Humidity: %d%%\n\r", (int) SelectedSensor->humidity);
}
void GetPressure(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Pressure: %dhPa\n\r", SelectedSensor->pressure);
}
void GetAmbientLight(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Ambient Light: %d%%\n\r", SelectedSensor->ambientLight);
}
void GetTempCBMonoxide(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg) {
	sprintf(msg, "\n\r Carbon Monoxide: %d\n\r",
			SelectedSensor->carbonMonoxide);
}
void GetDate(DateTime_t *t) {
}
void GetTime(DateTime_t *t) {
}

//COMMAND HANDLERS FOR DIFFERENT MENUS
void CommandDataHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '1':
		(command[GET_TEMP_IN_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '2':
		(command[GET_TEMP_OUT_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '3':
		(command[GET_HUMIDITY_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '4':
		(command[GET_PRESSURE_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '5':
		(command[GET_AMBIENT_LIGHT_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '6':
		(command[GET_CB_MONOXIDE_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '7':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CommandMenuHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msgRec) {
	switch (msgRec[0]) {
	case '1':
		selectedMenu = DISPLAY_DATA_MENU;
		(menu[selectedMenu])(huart1);
		break;
	case '2':
		selectedMenu = DISPLAY_GET_DATETIME;
		(menu[selectedMenu])(huart1);
		break;
	case '3':
		selectedMenu = DISPLAY_SET_DATETIME;
		(menu[selectedMenu])(huart1);
		break;
	case '4':
		selectedMenu = DISPLAY_ALARMS_MENU;
		(menu[selectedMenu])(huart1);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		break;
	}

}
void CommandGetDTHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '1':
		(command[GET_DATE_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '2':
		(command[GET_TIME_COMMAND])(SelectedSensor, huart1, msg);
		break;
	case '9':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CommandSetDTHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	break;
case '7':
	selectedMenu = DISPLAY_HELP_MENU;
	(menu[DISPLAY_HELP_MENU])(huart1);
	break;
default:
	(error[ERR_MSG_NF])(huart1);
	clearMSG(msg, NULL);
	break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CommandAlarmHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '7':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CLIHandler(SensData_t *SelectedSensor, UART_HandleTypeDef *huart1,
		char *msg, short *msgIDX) {
	if (*msgIDX >= 24) {
		(error[ERR_MSG_LONG])(huart1);
		clearMSG(msg, msgIDX);
	}
	if (msg[*msgIDX] == '\r') {
		lowerString(msg);
		if (*msgIDX > 0 && strncmp(msg, "help", *msgIDX) == 0) {
			(menu[selectedMenu])(huart1);
			clearMSG(msg, msgIDX);
		} else {
			if (*msgIDX > 1) {
				(error[ERR_MSG_NF])(huart1);
				clearMSG(msg, msgIDX);
			} else {
				(handler[selectedMenu])(SelectedSensor, huart1, msg);
				clearMSG(msg, msgIDX);
			}
		}
	} else {
		*msgIDX = *msgIDX + 1;
	}

	HAL_UART_Receive_IT(huart1, (uint8_t*) &msg[*msgIDX], 1);
}
