#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include "data_UI_def.h"
#include "date_time_def.h"
#include "utilities.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//MENU
#define DISPLAY_HELP_MENU 0
#define DISPLAY_DATA_MENU 1
#define DISPLAY_DATETIME 2
#define DISPLAY_ALARMS_MENU 3

//ERROR HANDLING
#define ERR_MSG_LONG 0
#define ERR_MSG_NF 1
#define ERR_MSG_ICC 2
//COMMAND
#define GET_TEMP_IN_COMMAND 0
#define GET_TEMP_OUT_COMMAND 1
#define GET_HUMIDITY_COMMAND 2
#define GET_PRESSURE_COMMAND 3
#define GET_AMBIENT_LIGHT_COMMAND 4
#define GET_CB_MONOXIDE_COMMAND 5
#define GET_DATE_COMMAND 6
#define GET_TIME_COMMAND 7
#define SET_DATE_DAY 8
#define SET_DATE_MONTH 9
#define SET_DATE_YEAR 10
#define SET_TIME_SECONDS 11
#define SET_TIME_MINUTES 12
#define SET_TIME_HOURS 13

//MENUS
void DisplayHelpMenu(UART_HandleTypeDef*);
void DisplayDateTime(UART_HandleTypeDef*);
void DisplayAlarmsMenu(UART_HandleTypeDef*);
void DisplayDataMenu(UART_HandleTypeDef*);
//COMMANDS
void GetTempIN(SensData_t*, char*);
void GetTempOUT(SensData_t*, char*);
void GetHumidity(SensData_t*, char*);
void GetPressure(SensData_t*, char*);
void GetAmbientLight(SensData_t*, char*);
void GetTempCBMonoxide(SensData_t*, char*);
void GetTime(DateTime_t*,char*);
void GetDate(DateTime_t*,char*);
void SetDay(DateTime_t*,int,UART_HandleTypeDef*);
void SetMonth(DateTime_t*,int,UART_HandleTypeDef*);
void SetYear(DateTime_t*,int,UART_HandleTypeDef*);
void SetSeconds(DateTime_t*,int,UART_HandleTypeDef*);
void SetMinutes(DateTime_t*,int,UART_HandleTypeDef*);
void SetHours(DateTime_t*,int,UART_HandleTypeDef*);
void SetAlert(DateTime_t*);
//ERRORS
void ErrMsgLong(UART_HandleTypeDef*);
void ErrMsgNF(UART_HandleTypeDef*);
void ErrMsgICC(UART_HandleTypeDef*);
//COMMAND HANDLERS
void CommandMenuHandler(DateTime_t*,SensData_t*, UART_HandleTypeDef*, char*);
void CommandDataHandler(DateTime_t*,SensData_t*, UART_HandleTypeDef*, char*);
void CommandDTHandler(DateTime_t*,SensData_t*, UART_HandleTypeDef*, char*);
void CommandAlarmHandler(DateTime_t*,SensData_t*, UART_HandleTypeDef*, char*);
//MAIN
void CLIHandler(SensData_t*, UART_HandleTypeDef*, char*, short*);

extern void (*command[])();
extern void (*menu[])();
extern void (*error[])();
extern void (*handler[])();
extern short changed;
extern char msg[30];
extern short msgIDX;
extern short selectedMenu;
extern DateTime_t dateTime;
extern short finished;

#endif
