#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include "data_UI_def.h"
#include "date_time_def.h"
#include "utilities.h"
#include <string.h>
#include <stdio.h>

//COMMANDS
#define DISPLAY_MENU_COMMAND 0
#define DISPLAY_GET_DATETIME 11
#define DISPLAY_SET_DATETIME 22
//ERROR HANDLING
#define ERR_MSG_LONG 1
#define ERR_MSG_NF 2
//
#define GET_TEMP_IN_COMMAND 3
#define GET_TEMP_OUT_COMMAND 4
#define GET_HUMIDITY_COMMAND 5
#define GET_PRESSURE_COMMAND 6
#define GET_AMBIENT_LIGHT_COMMAND 7
#define GET_CB_MONOXIDE_COMMAND 8
#define GET_TIME_COMMAND 9
#define GET_DATE_COMMAND 10

//COMMANDS
void DisplayMenu(UART_HandleTypeDef*);
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
//UTILITY
void CommandHandler(SensData_t*, UART_HandleTypeDef*, char*);
void CLIHandler(SensData_t*, UART_HandleTypeDef*, char*, short*);

extern void (*command[])();
extern char msg[30];
extern short msgIDX;
extern char selectedMenu;

#endif
