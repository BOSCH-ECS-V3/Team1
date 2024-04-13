#ifndef __CLI_H
#define __CLI_H

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

void DisplayMenu(UART_HandleTypeDef*);

extern void (*command[])();



#endif
