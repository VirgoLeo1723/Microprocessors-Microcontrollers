/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void display7SEG(int num);
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  int count=0;
  while (1)
  {
	  if( count >= 10)
		  count = 0;

	  display7SEG ( count ++) ;
	  HAL_Delay (1000) ;
  }
}
void display7SEG(int num){
	if (num==1){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 1);
	}
	else if (num==2){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	}
	else if (num==3){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);

	}
	else if (num==4){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	}
	else if (num==5){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	}
	else if (num==6){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	}
	else if (num==7){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 1);
	}
	else if (num==8){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	}
	else if (num==9){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 1);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 0);
	} else{
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 1 );
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
