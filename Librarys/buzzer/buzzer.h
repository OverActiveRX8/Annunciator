#ifndef _BUZZER_H_
#define _BUZZER_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_gpio.h"
#include "gpio.h"
#include "tim.h"

void freqAdjust(int level, float distance);
void silent(void);
void beep(void);

#endif

