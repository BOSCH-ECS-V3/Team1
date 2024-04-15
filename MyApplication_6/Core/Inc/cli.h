#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include "data_UI_def.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//COMMANDS
#define DISPLAY_MENU_COMMAND 0
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



//COMMANDS
void DisplayMenu(UART_HandleTypeDef*);
void GetTempIN(SensData_t*,UART_HandleTypeDef *);
void GetTempOUT(SensData_t*,UART_HandleTypeDef *);
void GetHumidity(SensData_t*,UART_HandleTypeDef *);
void GetPressure(SensData_t*,UART_HandleTypeDef *);
void GetAmbientLight(SensData_t*,UART_HandleTypeDef *);
void GetTempCBMonoxide(SensData_t*,UART_HandleTypeDef *);
//ERRORS
void ErrMsgLong(UART_HandleTypeDef *);
void ErrMsgNF(UART_HandleTypeDef *);
//UTILITY
void lowerString(char*);
void CommandHandler(SensData_t*,UART_HandleTypeDef*,char*);



extern void (*command[])();



#endif
