#include "cli.h"
#define MAX_ALLOWED_STRING 24
char msg[30];
short msgIDX = 0;
short changed = 0;
short selectedMenu = DISPLAY_HELP_MENU;
//DO NOT FORMAT THIS FILE
void (*menu[])()=
{
DisplayHelpMenu,
DisplayDataMenu,
DisplayDateTime,
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
GetTime,			//7
SetDay,				//8
SetMonth,			//9
SetYear,			//10
SetSeconds,			//11
SetMinutes,			//12
SetHours			//13
};

void (*error[])()=
{
ErrMsgLong,
ErrMsgNF,
ErrMsgICC
};
void (*handler[])()=
{
CommandMenuHandler,
CommandDataHandler,
CommandDTHandler,
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
	sprintf(msg, "2. Date and Time\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Alarms Menu\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
}
void DisplayDateTime(UART_HandleTypeDef *huart1) {
	char msg[40];
	sprintf(msg, "\n\rDATE & TIME MENU\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "1. Get Date\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "2. Get Time\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "3. Set Day\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "4. Set Month\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "5. Set Year\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "6. Set Seconds\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "7. Set Minutes\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "8. Set Hours\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	sprintf(msg, "9. Back\n\r");
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
void ErrMsgICC(UART_HandleTypeDef *huart1)
{
	char msg[60];
	sprintf(msg, "\n\rMESSAGE INCORRECT!\n\r"
			"TRY AGAIN!\n\r");
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	(menu[selectedMenu])(huart1);
}
//COMMANDS FOR MCU
void GetTempIN(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Temperature Inside: %dC\n\r",
			(int)SelectedSensor->tempIN);
}
void GetTempOUT(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Temperature Outside: %dC\n\r",
			(int) SelectedSensor->tempOUT);
}
void GetHumidity(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Humidity: %d%%\n\r", (int) SelectedSensor->humidity);
}
void GetPressure(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Pressure: %dhPa\n\r", SelectedSensor->pressure);
}
void GetAmbientLight(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Ambient Light: %d%%\n\r", SelectedSensor->ambientLight);
}
void GetTempCBMonoxide(SensData_t *SelectedSensor, char *msg) {
	sprintf(msg, "\n\r Carbon Monoxide: %d\n\r",
			SelectedSensor->carbonMonoxide);
}
void GetDate(DateTime_t *dateTime, char *msg) {
	sprintf(msg, "\n\r Date:%d.%d.%d\n\r", (int) dateTime->day, dateTime->month,
			dateTime->year);
}
void GetTime(DateTime_t *dateTime, char *msg) {
	sprintf(msg, "\n\r Time:%d:%d:%d\n\r", (int) dateTime->hours, dateTime->minutes,
			dateTime->seconds);
}
void SetDay(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 1 || Input > 30)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->day = Input;
}
void SetMonth(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 1 || Input > 12)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->month = Input;
}
void SetYear(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 1 || Input > 2040)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->year = Input;
}
void SetSeconds(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 1 || Input > 59)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->seconds = Input;
}
void SetMinutes(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 1 || Input > 59)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->minutes = Input;
}
void SetHours(DateTime_t *dateTime, int Input, UART_HandleTypeDef *huart1)
{
	if (Input < 0 || Input > 23)
	{
		(error[ERR_MSG_ICC])(huart1);
	}
	else dateTime->hours = Input;
}
//COMMAND HANDLERS FOR DIFFERENT MENUS
void CommandDataHandler(DateTime_t *dateTime, SensData_t *SelectedSensor,
		UART_HandleTypeDef *huart1, char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '1':
		(command[GET_TEMP_IN_COMMAND])(SelectedSensor,msg);
		break;
	case '2':
		(command[GET_TEMP_OUT_COMMAND])(SelectedSensor,msg);
		break;
	case '3':
		(command[GET_HUMIDITY_COMMAND])(SelectedSensor,msg);
		break;
	case '4':
		(command[GET_PRESSURE_COMMAND])(SelectedSensor,msg);
		break;
	case '5':
		(command[GET_AMBIENT_LIGHT_COMMAND])(SelectedSensor,msg);
		break;
	case '6':
		(command[GET_CB_MONOXIDE_COMMAND])(SelectedSensor,msg);
		break;
	case '7':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		clearMSG(msg, NULL);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CommandMenuHandler(DateTime_t *dateTime, SensData_t *SelectedSensor,
		UART_HandleTypeDef *huart1, char *msgRec) {
	switch (msgRec[0]) {
	case '1':
		selectedMenu = DISPLAY_DATA_MENU;
		(menu[selectedMenu])(huart1);
		break;
	case '2':
		selectedMenu = DISPLAY_DATETIME;
		(menu[selectedMenu])(huart1);
		break;
	case '3':
		selectedMenu = DISPLAY_ALARMS_MENU;
		(menu[selectedMenu])(huart1);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		break;
	}

}
void CommandDTHandler(DateTime_t *dateTime, SensData_t *SelectedSensor,
		UART_HandleTypeDef *huart1, char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '1':
		(command[GET_DATE_COMMAND])(dateTime,msg);
		break;
	case '2':
		(command[GET_TIME_COMMAND])(dateTime,msg);
		break;
	case '3':
		changed = SET_DATE_DAY;
		sprintf(msg, "\n\r ENTER DAY:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '4':
		changed = SET_DATE_MONTH;
		sprintf(msg, "\n\r ENTER MONTH:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '5':
		changed = SET_DATE_YEAR;
		sprintf(msg, "\n\r ENTER YEAR:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '6':
		changed = SET_TIME_SECONDS;
		sprintf(msg, "\n\r ENTER SECONDS:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '7':
		changed = SET_TIME_MINUTES;
		sprintf(msg, "\n\r ENTER MINUTES:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '8':
		changed = SET_TIME_HOURS;
		sprintf(msg, "\n\r ENTER HOURS:\n\r");
		HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
		clearMSG(msg, NULL);
		break;
	case '9':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		clearMSG(msg, NULL);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CommandAlarmHandler(DateTime_t *dateTime, SensData_t *SelectedSensor,
		UART_HandleTypeDef *huart1, char *msgRec) {
	char msg[60];

	switch (msgRec[0]) {
	case '7':
		selectedMenu = DISPLAY_HELP_MENU;
		(menu[DISPLAY_HELP_MENU])(huart1);
		clearMSG(msg, NULL);
		break;
	default:
		(error[ERR_MSG_NF])(huart1);
		clearMSG(msg, NULL);
		break;
	}
	HAL_UART_Transmit(huart1, (uint8_t*) msg, strlen(msg), 1000);
	clearMSG(msg, NULL);
}
void CLIHandler(DateTime_t *dateTime, SensData_t *SelectedSensor,
		UART_HandleTypeDef *huart1, char *msg, short *msgIDX) {
	if (*msgIDX >= MAX_ALLOWED_STRING) {
		(error[ERR_MSG_LONG])(huart1);
		clearMSG(msg, msgIDX);
	}
	if (msg[*msgIDX] == '\r') {
		lowerString(msg);
		if(changed!=0)
		{
			int Input = atoi(msg);
			(command[changed])(dateTime,Input,huart1);
			changed = 0;
			clearMSG(msg, msgIDX);
		}
		else{
			if (*msgIDX > 0 && strncmp(msg, "help", *msgIDX) == 0) {
			(menu[selectedMenu])(huart1);
			clearMSG(msg, msgIDX);
		} else {
			if (*msgIDX > 1) {
				(error[ERR_MSG_NF])(huart1);
				clearMSG(msg, msgIDX);
			} else {
				(handler[selectedMenu])(dateTime, SelectedSensor, huart1, msg);
				clearMSG(msg, msgIDX);
			}
		}
		}
	} else {
		*msgIDX = *msgIDX + 1;
	}

	HAL_UART_Receive_IT(huart1, (uint8_t*) &msg[*msgIDX], 1);
}
