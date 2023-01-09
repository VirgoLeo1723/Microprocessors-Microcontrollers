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
#define ENM0_Pin GPIO_PIN_2
#define ENM0_GPIO_Port GPIOA
#define ENM1_Pin GPIO_PIN_3
#define ENM1_GPIO_Port GPIOA
#define LEDR_Pin GPIO_PIN_4
#define LEDR_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_5
#define DOT_GPIO_Port GPIOA
#define ENL1_Pin GPIO_PIN_6
#define ENL1_GPIO_Port GPIOA
#define ENL2_Pin GPIO_PIN_7
#define ENL2_GPIO_Port GPIOA
#define a_Pin GPIO_PIN_0
#define a_GPIO_Port GPIOB
#define b_Pin GPIO_PIN_1
#define b_GPIO_Port GPIOB
#define c_Pin GPIO_PIN_2
#define c_GPIO_Port GPIOB
#define ROW2_Pin GPIO_PIN_10
#define ROW2_GPIO_Port GPIOB
#define ROW3_Pin GPIO_PIN_11
#define ROW3_GPIO_Port GPIOB
#define ROW4_Pin GPIO_PIN_12
#define ROW4_GPIO_Port GPIOB
#define ROW5_Pin GPIO_PIN_13
#define ROW5_GPIO_Port GPIOB
#define ROW6_Pin GPIO_PIN_14
#define ROW6_GPIO_Port GPIOB
#define ROW7_Pin GPIO_PIN_15
#define ROW7_GPIO_Port GPIOB
#define ENL3_Pin GPIO_PIN_8
#define ENL3_GPIO_Port GPIOA
#define ENL4_Pin GPIO_PIN_9
#define ENL4_GPIO_Port GPIOA
#define ENM2_Pin GPIO_PIN_10
#define ENM2_GPIO_Port GPIOA
#define ENM3_Pin GPIO_PIN_11
#define ENM3_GPIO_Port GPIOA
#define ENM4_Pin GPIO_PIN_12
#define ENM4_GPIO_Port GPIOA
#define ENM5_Pin GPIO_PIN_13
#define ENM5_GPIO_Port GPIOA
#define ENM6_Pin GPIO_PIN_14
#define ENM6_GPIO_Port GPIOA
#define ENM7_Pin GPIO_PIN_15
#define ENM7_GPIO_Port GPIOA
#define d_Pin GPIO_PIN_3
#define d_GPIO_Port GPIOB
#define e_Pin GPIO_PIN_4
#define e_GPIO_Port GPIOB
#define f_Pin GPIO_PIN_5
#define f_GPIO_Port GPIOB
#define g_Pin GPIO_PIN_6
#define g_GPIO_Port GPIOB
#define ROW0_Pin GPIO_PIN_8
#define ROW0_GPIO_Port GPIOB
#define ROW1_Pin GPIO_PIN_9
#define ROW1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
