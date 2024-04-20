#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include "data_UI_def.h"
#include "date_time_def.h"
#include "utilities.h"
#include <string.h>
#include <stdio.h>

//MENU
#define DISPLAY_HELP_MENU 0
#define DISPLAY_DATA_MENU 1
#define DISPLAY_GET_DATETIME 2
#define DISPLAY_SET_DATETIME 3
#define DISPLAY_ALARMS_MENU 4

//ERROR HANDLING
#define ERR_MSG_LONG 0
#define ERR_MSG_NF 1
//COMMAND
#define GET_TEMP_IN_COMMAND 0
#define GET_TEMP_OUT_COMMAND 1
#define GET_HUMIDITY_COMMAND 2
#define GET_PRESSURE_COMMAND 3
#define GET_AMBIENT_LIGHT_COMMAND 4
#define GET_CB_MONOXIDE_COMMAND 5
#define GET_TIME_COMMAND 6
#define GET_DATE_COMMAND 7


//COMMANDS
void DisplayHelpMenu(UART_HandleTypeDef*);
void DisplayGetDateTime(UART_HandleTypeDef*);
void DisplaySetDateTime(UART_HandleTypeDef*);
void DisplayAlarmsMenu(UART_HandleTypeDef*);
void DisplayDataMenu(UART_HandleTypeDef*);
void GetTempIN(SensData_t*, UART_HandleTypeDef*, char*);
void GetTempOUT(SensData_t*, UART_HandleTypeDef*, char*);
void GetHumidity(SensData_t*, UART_HandleTypeDef*, char*);
void GetPressure(SensData_t*, UART_HandleTypeDef*, char*);
void GetAmbientLight(SensData_t*, UART_HandleTypeDef*, char*);
void GetTempCBMonoxide(SensData_t*, UART_HandleTypeDef*, char*);
void GetTime(DateTime_t*);
void GetDate(DateTime_t*);
//ERRORS
void ErrMsgLong(UART_HandleTypeDef*);
void ErrMsgNF(UART_HandleTypeDef*);
//COMMAND HANDLERS
void CommandMenuHandler(SensData_t*, UART_HandleTypeDef*, char*);
void CommandDataHandler(SensData_t*, UART_HandleTypeDef*, char*);
void CommandGetDTHandler(SensData_t*, UART_HandleTypeDef*, char*);
void CommandSetDTHandler(SensData_t*, UART_HandleTypeDef*, char*);
void CommandAlarmHandler(SensData_t*, UART_HandleTypeDef*, char*);
//MAIN
void CLIHandler(SensData_t*, UART_HandleTypeDef*, char*, short*);

extern void (*command[])();
extern void (*menu[])();
extern void (*error[])();
extern void (*handler[])();
extern char msg[30];
extern short msgIDX;
extern short selectedMenu;

#endif
