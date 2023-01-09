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
#include "string.h"
#include "softTimer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_BUFFER_SIZE 30
#define STATE_INIT	  0
#define STATE_REQUEST 1
#define STATE_SENDING 2

#define REQUEST_LEN	 5
#define SENDING_LEN	 5
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int mode = STATE_INIT;
int len = REQUEST_LEN;
int ADC_val;
int ADC_val1;

char str[50];
char *init_char = (char*)"!RST#";
char *send_char = (char*)"!OK#";
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void ADC_Select_CH0(void);
void ADC_Select_CH1(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void command_parser_fsm();
void uart_communiation_fsm();
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
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart2, &temp, 1);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_ADC_Start(&hadc1);

  //HAL_ADC_Start(&hadc2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,1);
  HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,1);

  while (1){
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	if (buffer_flag == 1){
		command_parser_fsm();
		buffer_flag = 0;
	}
	uart_communiation_fsm();

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, LEDR_Pin|LEDY_Pin|LEDG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LEDR_Pin LEDY_Pin LEDG_Pin */
  GPIO_InitStruct.Pin = LEDR_Pin|LEDY_Pin|LEDG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	uint8_t *stop_character = (uint8_t*)"s";
	if (huart->Instance == USART2){

		if (temp == *stop_character){
			HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
			buffer_flag = 1;
		} else {
			buffer[index_buffer] = temp;
			index_buffer = (index_buffer + 1) % MAX_BUFFER_SIZE;
		}

		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    //HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
	timerRun();
}

void command_parser_fsm(){
	char *string_translate;

	string_translate = (char*)buffer;
	HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
	switch (mode){
		case STATE_INIT:
			if (strcmp(string_translate, init_char) == 0) mode = STATE_REQUEST;
			break;
		case STATE_SENDING:
			if (strcmp(string_translate, send_char) == 0) mode = STATE_INIT;
			break;
		default: break;
	}
	for (int i=0; i<MAX_BUFFER_SIZE; i++){
		buffer[i] = 0;
		index_buffer = 0;
	}

}
void uart_communiation_fsm(){
	switch (mode){
		case STATE_INIT:
			HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin, 0);
			HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, 1);

			//ADC_val = HAL_ADC_GetValue(&hadc1);

			//read adc value
			ADC_Select_CH0();
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, 1000);
			ADC_val = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			//HAL_Delay(10);

			ADC_Select_CH1();
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, 1000);
			ADC_val1 = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);

			break;
		case STATE_REQUEST:
			HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin, 1);
			HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, 1);

			//send adc value
			HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "*LIGHT:%d/*TEMP:%d/\r\n", ADC_val, ADC_val1), 1000);

			//set waiting time
			timerSet(50);
			timerFlag = 0;
			mode = STATE_SENDING;
			break;
		case STATE_SENDING:
			HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin, 1);
			HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, 0);

			// time out, send again
			if (isTimeOut()) mode = STATE_REQUEST;
		default: break;
	}

}
void ADC_Select_CH0(void){
	  ADC_ChannelConfTypeDef sConfig = {0};
	 sConfig.Channel = ADC_CHANNEL_0;
	 sConfig.Rank = ADC_REGULAR_RANK_2;
	 sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
	 if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	 {
		 Error_Handler();
	 }
}
void ADC_Select_CH1(void){
	  ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = ADC_CHANNEL_1;
	 sConfig.Rank = ADC_REGULAR_RANK_1;
	 sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
	 if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	 {
		 Error_Handler();
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
