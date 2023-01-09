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

int counter = 50;
int counter1 = 100;
int counter2 = 10;
int check = 0;

int clk_hour =15, clk_minute = 5, clk_second = 50;

int led_buffer[4] = {1,2,3,4};
int led_index = 0;

uint8_t matrix_buffer[8] = { 0xE7, 0xC3, 0xC3, 0x99, 0x00, 0x00, 0x3C, 0x3C};
int matrix_index = 0;
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int TIMER_CYCLE = 10;

void updateClockBuffer(void);
void updateMatrixBuffer(void);
void resetMatrix(void);
void display7SEG(int num);
void displayMatrixLed(void);
void setTimer0(int duration);
void timer_run(void);
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
  resetMatrix();
  setTimer0(1000);
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if (timer0_flag == 1){
		  HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
		  clk_second++;
		  if (clk_second >=60 ){
			  clk_second = 0;
			  clk_minute++;
		  }
		  if (clk_minute >=60 ){
			  clk_minute = 0;
			  clk_hour++;
		  }
		  if (clk_hour >= 24){
			  clk_hour = 0;
		  }

		  updateClockBuffer();
		  setTimer0(1000);
	  }
	  if (timer1_flag == 1 ){
		  if (led_index == 0) {
				HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 0);
				HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
				HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
				HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
				display7SEG(led_buffer[led_index]);
			}
			else if (led_index == 1){
				HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
				HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 0);
				HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
				HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
				display7SEG(led_buffer[led_index]);

			}
			else if (led_index == 2){
				HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
				HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
				HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 0);
				HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 1);
				display7SEG(led_buffer[led_index]);
			}
			else if (led_index == 3){
				HAL_GPIO_WritePin(ENL1_GPIO_Port, ENL1_Pin, 1);
				HAL_GPIO_WritePin(ENL2_GPIO_Port, ENL2_Pin, 1);
				HAL_GPIO_WritePin(ENL3_GPIO_Port, ENL3_Pin, 1);
				HAL_GPIO_WritePin(ENL4_GPIO_Port, ENL4_Pin, 0);
				display7SEG(led_buffer[led_index]);
			}
			led_index = (led_index+1)%4;
			timer1_flag = 0;
	  }
	  if (timer2_flag == 1){
		  resetMatrix();
		  displayMatrixLed();
		  matrix_index = (matrix_index+1)%8;
		  timer2_flag = 0;
		  if (matrix_index == 0) updateMatrixBuffer();
	  }




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
  htim2.Init.Prescaler = 799;
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
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|LEDR_Pin|DOT_Pin
                          |ENL1_Pin|ENL2_Pin|ENL3_Pin|ENL4_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|d_Pin|e_Pin|f_Pin
                          |g_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin LEDR_Pin DOT_Pin
                           ENL1_Pin ENL2_Pin ENL3_Pin ENL4_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|LEDR_Pin|DOT_Pin
                          |ENL1_Pin|ENL2_Pin|ENL3_Pin|ENL4_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin d_Pin e_Pin f_Pin
                           g_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|d_Pin|e_Pin|f_Pin
                          |g_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void updateClockBuffer(){
	if (clk_hour<9) led_buffer[0] = 0;
	else led_buffer[0] = clk_hour/10;
	if (clk_minute<9) led_buffer[2] = 0;
	else led_buffer[2] = clk_minute/10;

	led_buffer[1] = clk_hour%10;
	led_buffer[3] = clk_minute%10;
}
void updateMatrixBuffer(){
	for (int i=0; i<8; i++){
		uint8_t shift_left = matrix_buffer[i]<<1;
		uint8_t shift_right = matrix_buffer[i]>>7;
		matrix_buffer[i] = shift_left | shift_right;
	}
}
void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag = 0;
	timer1_flag = 0;
}
void timer_run(){
	if (timer0_counter>0){
		timer0_counter--;
		if (timer0_counter == 0) timer0_flag = 1;
		if (timer0_counter % 25 == 0) timer1_flag = 1;
		if (timer0_counter % 50 == 0) timer2_flag = 1;
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
	} else if (num==0){
		HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, b_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, c_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, d_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, e_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, f_Pin, 0);
		HAL_GPIO_WritePin(a_GPIO_Port, g_Pin, 1 );
	}
}
void displayMatrixLedCol(int number, int state){
	if (number == 0) HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, state);
	if (number == 1) HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, state);
	if (number == 2) HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, state);
	if (number == 3) HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, state);
	if (number == 4) HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, state);
	if (number == 5) HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, state);
	if (number == 6) HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, state);
	if (number == 7) HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, state);
}

void displayMatrixLedRow(int number){
	if (number == 0) HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 0);
	if (number == 1) HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 0);
	if (number == 2) HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 0);
	if (number == 3) HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 0);
	if (number == 4) HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 0);
	if (number == 5) HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 0);
	if (number == 6) HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 0);
	if (number == 7) HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 0);
}
void resetMatrix(){
  HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
  HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
  HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
  HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
  HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
  HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
  HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
  HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);

  HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, 1);
  HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, 1);
  HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, 1);
  HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, 1);
  HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, 1);
  HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, 1);
  HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, 1);
  HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, 1);
}

void displayMatrixLed(){
	int bitStatus;
	displayMatrixLedRow(matrix_index);
	for (int nth = 0; nth<8; nth++){
		bitStatus = (matrix_buffer[matrix_index]>>nth)&1;
		displayMatrixLedCol(nth, bitStatus);
	}
}
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	timer_run();
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
