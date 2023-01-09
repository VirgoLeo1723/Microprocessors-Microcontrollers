/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define a1_Pin GPIO_PIN_1
#define a1_GPIO_Port GPIOA
#define b1_Pin GPIO_PIN_2
#define b1_GPIO_Port GPIOA
#define c1_Pin GPIO_PIN_3
#define c1_GPIO_Port GPIOA
#define d1_Pin GPIO_PIN_4
#define d1_GPIO_Port GPIOA
#define e1_Pin GPIO_PIN_5
#define e1_GPIO_Port GPIOA
#define f1_Pin GPIO_PIN_6
#define f1_GPIO_Port GPIOA
#define g1_Pin GPIO_PIN_7
#define g1_GPIO_Port GPIOA
#define LED1_R_Pin GPIO_PIN_1
#define LED1_R_GPIO_Port GPIOB
#define LED1_Y_Pin GPIO_PIN_2
#define LED1_Y_GPIO_Port GPIOB
#define a2_Pin GPIO_PIN_8
#define a2_GPIO_Port GPIOA
#define b2_Pin GPIO_PIN_9
#define b2_GPIO_Port GPIOA
#define c2_Pin GPIO_PIN_10
#define c2_GPIO_Port GPIOA
#define d2_Pin GPIO_PIN_11
#define d2_GPIO_Port GPIOA
#define e2_Pin GPIO_PIN_12
#define e2_GPIO_Port GPIOA
#define f2_Pin GPIO_PIN_13
#define f2_GPIO_Port GPIOA
#define g2_Pin GPIO_PIN_14
#define g2_GPIO_Port GPIOA
#define LED1_G_Pin GPIO_PIN_3
#define LED1_G_GPIO_Port GPIOB
#define LED2_R_Pin GPIO_PIN_4
#define LED2_R_GPIO_Port GPIOB
#define LED2_Y_Pin GPIO_PIN_5
#define LED2_Y_GPIO_Port GPIOB
#define LED2_G_Pin GPIO_PIN_6
#define LED2_G_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
