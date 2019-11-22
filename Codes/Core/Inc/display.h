#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "oled.h"
#include "nts.h"
#include "gpio.h"

int setVoltage(void);
void showDistance(int level, float realDis);

#endif
