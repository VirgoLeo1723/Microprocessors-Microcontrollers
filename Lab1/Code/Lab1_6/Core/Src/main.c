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
#include "math.h"
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
void clearAllClock(void);
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  clearAllClock();

  int second = 0;
  int minute = 0;
  int hour = 0;

  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
	  clearAllClock();

	  second++;
	  if (second >= 60){
		  second = 0;
		  minute ++;
	  }
	  if (minute >= 60){
		  minute = 0;
		  hour ++;
	  }
	  if (hour == 12){
		  hour = 0;
	 }
	  setNumberOnClock(second/5);
	  setNumberOnClock(minute/5);
	  setNumberOnClock(hour);
	  HAL_Delay(10);
  }
  /* USER CODE END 3 */
}
void clearAllClock(void){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED2_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED3_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED4_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED5_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED6_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED7_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED8_Pin, 1);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED9_Pin, 1);
 	HAL_GPIO_WritePin(LED1_GPIO_Port, LED10_Pin, 1);
 	HAL_GPIO_WritePin(LED1_GPIO_Port, LED11_Pin, 1);
 	HAL_GPIO_WritePin(LED1_GPIO_Port, LED12_Pin, 1);

}
void setNumberOnClock(int num){
	//num = ceil((num+2)/3);
	if (num==0) HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);
	if (num==1) HAL_GPIO_WritePin(LED1_GPIO_Port, LED2_Pin, 0);
	if (num==2) HAL_GPIO_WritePin(LED1_GPIO_Port, LED3_Pin, 0);
	if (num==3) HAL_GPIO_WritePin(LED1_GPIO_Port, LED4_Pin, 0);
	if (num==4) HAL_GPIO_WritePin(LED1_GPIO_Port, LED5_Pin, 0);
	if (num==5) HAL_GPIO_WritePin(LED1_GPIO_Port, LED6_Pin, 0);
	if (num==6) HAL_GPIO_WritePin(LED1_GPIO_Port, LED7_Pin, 0);
	if (num==7) HAL_GPIO_WritePin(LED1_GPIO_Port, LED8_Pin, 0);
	if (num==8) HAL_GPIO_WritePin(LED1_GPIO_Port, LED9_Pin, 0);
	if (num==9) HAL_GPIO_WritePin(LED1_GPIO_Port, LED10_Pin, 0);
	if (num==10) HAL_GPIO_WritePin(LED1_GPIO_Port, LED11_Pin, 0);
	if (num==11) HAL_GPIO_WritePin(LED1_GPIO_Port, LED12_Pin, 0);
}
void clearNumberOnClock(int num){
	if (num==0) HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);
	if (num==1) HAL_GPIO_WritePin(LED1_GPIO_Port, LED2_Pin, 1);
	if (num==2) HAL_GPIO_WritePin(LED1_GPIO_Port, LED3_Pin, 1);
	if (num==3) HAL_GPIO_WritePin(LED1_GPIO_Port, LED4_Pin, 1);
	if (num==4) HAL_GPIO_WritePin(LED1_GPIO_Port, LED5_Pin, 1);
	if (num==5) HAL_GPIO_WritePin(LED1_GPIO_Port, LED6_Pin, 1);
	if (num==6) HAL_GPIO_WritePin(LED1_GPIO_Port, LED7_Pin, 1);
	if (num==7) HAL_GPIO_WritePin(LED1_GPIO_Port, LED8_Pin, 1);
	if (num==8) HAL_GPIO_WritePin(LED1_GPIO_Port, LED9_Pin, 1);
	if (num==9) HAL_GPIO_WritePin(LED1_GPIO_Port, LED10_Pin, 1);
	if (num==10) HAL_GPIO_WritePin(LED1_GPIO_Port, LED11_Pin, 1);
	if (num==11) HAL_GPIO_WritePin(LED1_GPIO_Port, LED12_Pin, 1);
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
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin|LED11_Pin|LED12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin LED7_Pin LED8_Pin
                           LED9_Pin LED10_Pin LED11_Pin LED12_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin|LED7_Pin|LED8_Pin
                          |LED9_Pin|LED10_Pin|LED11_Pin|LED12_Pin;
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
