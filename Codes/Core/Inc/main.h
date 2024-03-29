/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "config.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Buzzer_Pin GPIO_PIN_1
#define Buzzer_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_10
#define SCL_GPIO_Port GPIOC
#define SDA_Pin GPIO_PIN_12
#define SDA_GPIO_Port GPIOC
#define RES_Pin GPIO_PIN_1
#define RES_GPIO_Port GPIOD
#define DC_Pin GPIO_PIN_3
#define DC_GPIO_Port GPIOD
#define CS_Pin GPIO_PIN_5
#define CS_GPIO_Port GPIOD
#define TRIG_Pin GPIO_PIN_6
#define TRIG_GPIO_Port GPIOD
#define Button1_Pin GPIO_PIN_7
#define Button1_GPIO_Port GPIOD
#define ECHO_Pin GPIO_PIN_3
#define ECHO_GPIO_Port GPIOB
#define WakeUp_Pin GPIO_PIN_4
#define WakeUp_GPIO_Port GPIOB
#define WakeUp_EXTI_IRQn EXTI4_IRQn
#define Button2_Pin GPIO_PIN_0
#define Button2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
