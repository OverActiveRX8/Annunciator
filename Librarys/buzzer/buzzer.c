#include "buzzer.h"

extern float distanceArray[4];
extern int buzzerPeriod;
extern int buzzerCounter;

void freqAdjust(int level, float distance)
{
	HAL_TIM_Base_Start_IT(&htim14);
	float last = buzzerPeriod;
	float temp = distance/distanceArray[level];
	if(temp >= 2.0f)     		
		silent();
	else if(temp >= 1.5f)		
		buzzerPeriod = 50;
	else if(temp >= 1.25f)		
		buzzerPeriod = 40;
	else if(temp >= 1.0f)   
		buzzerPeriod = 30;						
	else if(temp >= 0.75f)								
		buzzerPeriod = 25;
	else if(temp >= 0.5f)
		buzzerPeriod = 20;
	else
		buzzerPeriod = 15;
	if(last != buzzerPeriod)
		__HAL_TIM_SetCounter(&htim14, 0);
}

void silent(void)
{
	HAL_GPIO_WritePin(buzzer,GPIO_PIN_RESET);
	HAL_TIM_Base_Stop_IT(&htim14);
	__HAL_TIM_SetCounter(&htim14, 0);
}

void beep(void)
{
	buzzerCounter++;
	if(buzzerCounter == buzzerPeriod)   			
	{
		HAL_GPIO_TogglePin(buzzer);		
		buzzerCounter = 0;		                    
	}
}
