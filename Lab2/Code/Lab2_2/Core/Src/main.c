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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
  HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
  HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
  HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
  HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LEDR_Pin|DOT_Pin|ENL1_Pin|ENL2_Pin
                          |ENL3_Pin|ENL4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LEDR_Pin DOT_Pin ENL1_Pin ENL2_Pin
                           ENL3_Pin ENL4_Pin */
  GPIO_InitStruct.Pin = LEDR_Pin|DOT_Pin|ENL1_Pin|ENL2_Pin
                          |ENL3_Pin|ENL4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
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
	else if (num==0){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 1 );
	}
}
int counter = 50;
int counter1 = 100;
int counter2 = 10;
int check = 0;
int number = 1;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	counter --;
	counter1--;
	if (counter1<=0){
		counter1 = 100;
		check = 1;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	if (check == 1) counter2--;
	if (counter2 <=0){
		counter2 = 10;
		check = 0;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
	if( counter <= 0) {
		counter = 50;

		HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
		if (number == 1) {
			HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 0);
			HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
			HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
			HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
			display7SEG(number);
			number = 2;
		}
		else if (number == 2){
			HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
			HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 0);
			HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
			HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
			display7SEG(number);
			number = 3;

		}
		else if (number == 3){
			HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
			HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
			HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 0);
			HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
			display7SEG(number);
			number = 0;
		}
		else if (number ==0 ){
			HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
			HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
			HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
			HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 0);
			display7SEG(number);
			number = 1;
		}
	}
}
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
