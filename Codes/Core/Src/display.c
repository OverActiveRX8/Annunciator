#include "display.h"

extern int voltageArray[4];
extern float distanceArray[4];

//Voltage Init
int setVoltage()
{
	int level = 0;         
	int voltage = 110;
	u8 *temp;
	OLED_ShowString(0,0,(u8 *)"System Init");
	OLED_ShowString(0,2,(u8 *)"Set Vol Level:");
	while(HAL_GPIO_ReadPin(s2) == GPIO_PIN_RESET)
	{
		if(HAL_GPIO_ReadPin(s1) == GPIO_PIN_SET)
			level++;
		voltage = voltageArray[level % 4];
		temp = (u8 *)int2String(voltage,3,"kV");
		OLED_ShowString(0,4,temp);
		free(temp);
		HAL_Delay(200);
	}
	OLED_Clear();
	OLED_ShowString(0,0,(u8 *)"Success!");
	HAL_Delay(1000);
	return (level % 4);
}

//Show Distance
void showDistance(int volLevel, float realDis)
{
	u8 *tempString;
	int voltage = voltageArray[volLevel];
	float distance = distanceArray[volLevel];
	
	//Show Voltage Level & Distance
	tempString = (u8 *)float2string(realDis, 1, "m ");
	OLED_ShowString(40,4,tempString);
	free(tempString);
	tempString = (u8 *)int2String(voltage,3,"kV ");
	OLED_ShowString(40,2,tempString);
	free(tempString);
	
	//Show Danger Level
	float temp = realDis/distance;
	if(temp >= 2.0f)
		OLED_ShowString(40,6,(u8 *)"Safe  ");
	else if(temp >= 1.5f)
		OLED_ShowString(40,6,(u8 *)"Risk  ");
	else if(temp >= 1.0f)
		OLED_ShowString(40,6,(u8 *)"Danger");
	else 
		OLED_ShowString(40,6,(u8 *)"Hazard");
}

