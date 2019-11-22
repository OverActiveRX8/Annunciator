#include "stdio.h"
#include "usartio.h"
#include "stdint.h"

extern UART_HandleTypeDef huart1;
uint8_t ch;
uint8_t ch_r;

/*fputc*/
int fputc(int c, FILE *f)
{
  ch=c;
  HAL_UART_Transmit(&huart1,&ch,1,1000);
	return c;
}

/*fgetc*/
int fgetc(FILE *f) 
{
	HAL_UART_Receive(&huart1,&ch_r,1,0xffff);
	return ch_r;
}
