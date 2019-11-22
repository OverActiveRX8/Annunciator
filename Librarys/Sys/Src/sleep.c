#include "sleep.h"

void sleep(void)
{
	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}

void wakeup(void)
{
	HAL_ResumeTick();
}
