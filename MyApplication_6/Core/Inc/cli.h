#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

//COMMANDS
#define DISPLAY_MENU_COMMAND 0
#define GET_TEMP_IN_COMMAND 1
#define GET_TEMP_OUT_COMMAND 2
#define GET_HUMIDITY_COMMAND 3
#define GET_PRESSURE_COMMAND 4
#define GET_AMBIENT_LIGHT_COMMAND 5
#define GET_CB_MONOXIDE_COMMAND 6

//ERROR HANDLING
#define ERR_MSG_LONG 1
#define ERR_MSG_NF 2


void DisplayMenu(UART_HandleTypeDef*);
void ErrMsgLong(UART_HandleTypeDef *);
void ErrMsgNF(UART_HandleTypeDef *);

extern void (*command[])();



#endif
