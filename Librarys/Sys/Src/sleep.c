#include "sleep.h"
#include "OLED.h"
#include "FREERTOS.H"
#include "CMSIS_OS.H"
#include "task.h"

extern void SystemClock_Config(void);

void sleep(void)
{
	OLED_Clear();
	HAL_SuspendTick();
	portDISABLE_INTERRUPTS();
	HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}

void wakeup(void)
{
	HAL_ResumeTick();
	SystemClock_Config();
	portENABLE_INTERRUPTS();
	OLED_ShowString(0,0,(u8 *)"Alarm System");
	OLED_ShowString(0,2,(u8 *)"Vol: N/A");
	OLED_ShowString(0,4,(u8 *)"Dis: N/A");
	OLED_ShowString(0,6,(u8 *)"Sta: N/A");
}
