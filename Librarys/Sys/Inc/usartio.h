#ifndef _USARTIO_H_
#define	_USARTIO_H_
#include "stdint.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"

extern UART_HandleTypeDef huart1;

int fputc(int c, FILE *f);

int fgetc(FILE *f) ;

#endif
