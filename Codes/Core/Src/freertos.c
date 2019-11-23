/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "stdbool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SLEEP_TIME 40
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern bool icState;
extern int voltageLevel;
extern float distance;
extern int buzzerPeriod;
extern float distanceArray[4];
float temp  = 0.0f;
int sleepCounter = 0;

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId buzzerTaskHandle;
osThreadId distanceTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartBuzzer(void const * argument);
void StartDistance(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of buzzerTask */
  osThreadDef(buzzerTask, StartBuzzer, osPriorityIdle, 0, 128);
  buzzerTaskHandle = osThreadCreate(osThread(buzzerTask), NULL);

  /* definition and creation of distanceTask */
  osThreadDef(distanceTask, StartDistance, osPriorityIdle, 0, 128);
  distanceTaskHandle = osThreadCreate(osThread(distanceTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		showDistance(voltageLevel, distance);
		temp = distance / distanceArray[voltageLevel];
		if(temp > 1.0f)
		{	
			buzzerPeriod = 0;
			sleepCounter ++;
		}
		else
		{
			buzzerPeriod = (int)(554.44f * temp + 54.444f);
			sleepCounter = 0;
		}
		if(sleepCounter == SLEEP_TIME)
		{	
			sleep();
			wakeup();
			sleepCounter = 0;
		}
    osDelay(500);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartBuzzer */
/**
* @brief Function implementing the buzzerTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBuzzer */
void StartBuzzer(void const * argument)
{
  /* USER CODE BEGIN StartBuzzer */
  /* Infinite loop */
  for(;;)
  {
		if(!buzzerPeriod) 
			continue;
		else if(temp < 0.1f)
		{
			HAL_GPIO_WritePin(buzzer,GPIO_PIN_SET);
			delay_us(250);
			HAL_GPIO_WritePin(buzzer,GPIO_PIN_RESET);
			delay_us(250);
			continue;
		}
		for(int i = 0;i < 100;i++)
		{
			HAL_GPIO_WritePin(buzzer,GPIO_PIN_SET);
			delay_us(250);
			HAL_GPIO_WritePin(buzzer,GPIO_PIN_RESET);
			delay_us(250);
		}
    osDelay(buzzerPeriod);
  }
  /* USER CODE END StartBuzzer */
}

/* USER CODE BEGIN Header_StartDistance */
/**
* @brief Function implementing the distanceTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDistance */
void StartDistance(void const * argument)
{
  /* USER CODE BEGIN StartDistance */
	extern int i;
	extern int icValue;
	extern float averageDistance;
  /* Infinite loop */
  for(;;)
  {
		if(!icState)
		{
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			delay_us(10);
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
			delay_us(100);
			HAL_TIM_IC_Start_IT(&htim2,TIM_CHANNEL_2); 
		}				 
		if(i == 5)
		{
			distance = averageDistance/5;
			i = 0;
			averageDistance = 0;        
		}
    osDelay(10);
  }
  /* USER CODE END StartDistance */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
  
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
