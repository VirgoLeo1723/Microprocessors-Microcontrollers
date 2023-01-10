#include "tasks.h"

int fixed_position	= TASKS_START_POSITION ;

//Variable used for TRAFFIC LIGHT
int MODE			= AUTO;
int NO_TASKS		= NO_TASKS_MODE_MODIFY;

int TIME_RED		= DEFAULT_TIME_RED;
int TIME_GREEN		= DEFAULT_TIME_GREEN;
int TIME_YELLOW		= DEFAULT_TIME_YELLOW;

int NEW_TIME		= 0;
int NEW_TIME_RED	= 0;
int NEW_TIME_GREEN	= 0;
int NEW_TIME_YELLOW	= 0;

int TL1_VAL 		= 0;
int TL2_VAL 		= 0;

//Variable used for PEDESTRIAN
int Pedes			= 0;
int PEDES_BEGIN 	= 0;

int BUZZER_VOL 		= BUZZER_OFF;
int CHANGE_TIMER 	= 50;
int COUNTER_PEDES 	= 0 ;
int INCHZ_PEDES 	= 0 ;

// RESET
void RESET_ALL_LED(void){
	  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
	  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
	  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
	  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
	  HAL_GPIO_WritePin(Ped_D6_GPIO_Port, Ped_D6_Pin,0);
	  HAL_GPIO_WritePin(Ped_D7_GPIO_Port, Ped_D7_Pin,0);
}
void RESET_BUZZER(void){
	BUZZER_VOL  = 0;
	INCHZ_PEDES = 0;
	__HAL_TIM_SET_AUTORELOAD(&htim3, 20);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0);
}
void RESET_UART(void){
	char str[100];
	TL1_VAL = 0;
	TL2_VAL = 0;
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "*7SEG:%d/\r\n", 0), 1000);
}
void RESET_ALL(void){
	RESET_ALL_LED();
	RESET_BUZZER();
	RESET_UART();
}

// TRAFFIC LIGHT 1
void TL1_GREEN_AUTO(void){
	if(Pedes==0){
		  PEDES_BEGIN = 0;
		  RESET_BUZZER();
	  }
	  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,1);
	  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
	  TL1_VAL = TIME_GREEN;
}
void TL1_RED_AUTO(void){
	  if(Pedes!=0){
		  PEDES_BEGIN = 1;
		  RESET_BUZZER();
		  Pedes--;
	  }
	  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
	  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,1);
	  TL1_VAL = TIME_RED;
}
void TL1_YELLOW_AUTO(void){
	  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,1);
	  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,1);
	  TL1_VAL = TIME_YELLOW;
}
void TL1_COUNT_DOWN(void){
	char str[100];
	TL1_VAL -= 1;
	if (TL1_VAL>=0)
		HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "*7SEG:%d/\r\n", TL1_VAL), 1000);
	else TL1_VAL = 0;
}

// TRAFFIC LIGHT 2
void TL2_GREEN_AUTO(void){
	  if(Pedes==0){
		  PEDES_BEGIN = 0;
		  RESET_BUZZER();
	  }
	  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
	  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,1);
	  //TL2_VAL = TIME_GREEN;
}
void TL2_RED_AUTO(void){
	  if(Pedes!=0){
		  PEDES_BEGIN = 1;
		  RESET_BUZZER();
		  Pedes--;
	  }
	  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,1);
	  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
	  //TL2_VAL = TIME_RED;
}
void TL2_YELLOW_AUTO(void){
	  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,1);
	  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,1);
	  //TL2_VAL = TIME_YELLOW;
}
void TL2_COUNT_DOWN(void){
	char str[100];
	TL2_VAL -= 1;
	if (TL1_VAL>=0)
		HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "*7SEG:%d/\r\n", TL2_VAL), 1000);
	else TL2_VAL = 0;
}

// BLINKY THE LIGHT
int TURN=1;
void BLINKY_GREEN(void){
	if(TURN==1){
		  // Green light for TL1
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,1);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
		  // Green light for TL2
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,1);
		  TURN++;
	}else{
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
		  TURN=1;
	}
}
void BLINKY_RED(void){
	if(TURN==1){
		// Red light for TL1
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,1);
		  // Red light for TL2
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,1);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
		  TURN++;
	}else{
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
		  TURN=1;
	}
}
void BLINKY_YELLOW(void){
	if(TURN==1){
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,1);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,1);
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,1);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,1);
		  TURN++;
	}else{
		  HAL_GPIO_WritePin(TL1_D2_GPIO_Port, TL1_D2_Pin,0);
		  HAL_GPIO_WritePin(TL1_D3_GPIO_Port, TL1_D3_Pin,0);
		  HAL_GPIO_WritePin(TL2_D4_GPIO_Port, TL2_D4_Pin,0);
		  HAL_GPIO_WritePin(TL2_D5_GPIO_Port, TL2_D5_Pin,0);
		  TURN=1;
	}
}

// TRAFFIC SIGNAL FOR PEDESTRIAN
void TL_PEDES(void){
	if (PEDES_BEGIN==1){
		  HAL_GPIO_WritePin(Ped_D7_GPIO_Port, Ped_D7_Pin,1);
		  HAL_GPIO_WritePin(Ped_D6_GPIO_Port, Ped_D6_Pin,0);
	} else {
		 HAL_GPIO_WritePin(Ped_D7_GPIO_Port, Ped_D7_Pin,0);
		 HAL_GPIO_WritePin(Ped_D6_GPIO_Port, Ped_D6_Pin,1);
	}
}
void BUZZ_PEDES_CHANGE_DURATION(int time){
	COUNTER_PEDES = time;

	INCHZ_PEDES += 1;
	if (INCHZ_PEDES <= 2*TIME_GREEN)
		CHANGE_TIMER = 50;
	else if (INCHZ_PEDES <= 2*TIME_GREEN + 4*TIME_YELLOW)
		CHANGE_TIMER = 25;
}
void BUZZ_PEDES_CHANGE_HZ(void){
	if (BUZZER_VOL == BUZZER_ON) BUZZER_VOL = BUZZER_OFF;
	else BUZZER_VOL = BUZZER_ON;
}
void BUZZ_PEDES(void){
	if (PEDES_BEGIN == 1){
		if (COUNTER_PEDES <= 0){
			BUZZ_PEDES_CHANGE_DURATION(CHANGE_TIMER);
			BUZZ_PEDES_CHANGE_HZ();
		} else COUNTER_PEDES --;
	}
	else BUZZER_VOL  = 0;
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, BUZZER_VOL);
}

//DELETE TASKS OF PREVIOUS MODE
void DEL_TASKS_PREVIOUS_MODE(void){
	for (int i=1; i<=NO_TASKS; i++){
		SCH_Delete_Task(fixed_position+i);
	}
}

//ADD TASKS FOR CURRENT MODE
void ADD_TASKS_MODE_AUTO(void){
	//ADD TASK OF AUTO
	SCH_Add_Task(	/*TASK*/ 	TL1_GREEN_AUTO,
					/*DELAY*/	SECOND_DURATION,
					/*PERIOD*/	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);
	SCH_Add_Task(	/*TASK*/	TL2_GREEN_AUTO,
					/*DELAY*/	(1+TIME_RED)*SECOND_DURATION,
					/*PERIOD*/	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);

	SCH_Add_Task(	/*TASK*/	TL1_YELLOW_AUTO,
					/*DELAY*/	(1+TIME_GREEN)*SECOND_DURATION,
					/*PERIOD*/	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);
	SCH_Add_Task(	/*TASK*/	TL2_YELLOW_AUTO,
					/*DELAY*/	(1+TIME_GREEN+TIME_RED)*SECOND_DURATION,
					/*PERIOD*/	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);

	SCH_Add_Task(	/*TASK*/	TL1_RED_AUTO,
					/*DELAY*/	(1 + TIME_GREEN + TIME_YELLOW) * SECOND_DURATION ,
					/*PERIOD*/	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);
	SCH_Add_Task(	/*TASK*/	TL2_RED_AUTO,
					/*DELAY*/	SECOND_DURATION,
					/*PERIOD*/ 	(TIME_YELLOW + TIME_RED + TIME_GREEN) * SECOND_DURATION
				);

	SCH_Add_Task(	/*TASK*/	TL_PEDES,
					/*DELAY*/	0,
					/*PERIOD*/	0
				);
	SCH_Add_Task(	/*TASK*/	BUZZ_PEDES,
					/*DELAY*/	0,
					/*PERIOD*/	0
				);

	SCH_Add_Task(	/*TASK*/	TL1_COUNT_DOWN,
					/*DELAY*/	0 ,
					/*PERIOD*/	SECOND_DURATION);
	//SCH_Add_Task(TL2_COUNT_DOWN, 0, 100);

	NEW_TIME	= 0;
	MODE 		= AUTO;
	NO_TASKS 	= NO_TASKS_MODE_AUTO;
}
void ADD_TASKS_MODE_MODIFY_GREEN(void){
	// ADD Task OF GREEN;
	SCH_Add_Task(BLINKY_GREEN, 50, 25);
	TURN		= 1;
	NEW_TIME	= 0;
	MODE		= MODI_GREEN;
	NO_TASKS	= NO_TASKS_MODE_MODIFY;
}
void ADD_TASKS_MODE_MODIFY_RED(void){
	// ADD TASK OF RED
	SCH_Add_Task(BLINKY_RED, 50, 25);
	TURN		= 1;
	NEW_TIME	= 0;
	MODE		= MODI_RED;
	NO_TASKS	= NO_TASKS_MODE_MODIFY;
}
void ADD_TASKS_MODE_MODIFY_YELLOW(void){
	// ADD TASK OF YELLOW
	SCH_Add_Task(BLINKY_YELLOW,50, 25);
	TURN		= 1;
	NEW_TIME	= 0;
	MODE		= MODI_YELLOW;
	NO_TASKS	= NO_TASKS_MODE_MODIFY;
}

// MODIFY TIME FOR EACH LIGHT
void SHOW_MODIFY_TIME(void){
	char str[50];
	NEW_TIME++;
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "*7SEG:%d/\r\n", NEW_TIME), 1000);
	if(NEW_TIME>99){
		NEW_TIME=0;
	}
}
void SET_MODIFY_TIME(void){
	//SET MODIFIED TIME
	TIME_GREEN	= NEW_TIME_GREEN;
	TIME_RED	= NEW_TIME_RED;
	TIME_YELLOW	= NEW_TIME_YELLOW;
	//RESET VALUE
	NEW_TIME_GREEN	= 0;
	NEW_TIME_YELLOW = 0;
	NEW_TIME_RED 	= 0;
	//RESET
	RESET_ALL();
	DEL_TASKS_PREVIOUS_MODE();
	ADD_TASKS_MODE_AUTO();
}
void SET_DEFAULT_TIME(void){
	//SET DEFAULT TIME
	TIME_GREEN	= DEFAULT_TIME_GREEN;
	TIME_RED	= DEFAULT_TIME_RED;
	TIME_YELLOW	= DEFAULT_TIME_YELLOW;
	//RESET VALUE
	NEW_TIME_GREEN	= 0;
	NEW_TIME_YELLOW = 0;
	NEW_TIME_RED 	= 0;
}
int IS_TIME_MODIFIED(void){
	if (NEW_TIME_GREEN>0 && NEW_TIME_RED>0 && NEW_TIME_YELLOW>0) return 1;
	else return 0;
}
int IS_TIME_SATISFIED(void){
	if (NEW_TIME_RED==NEW_TIME_GREEN+NEW_TIME_YELLOW) return 1;
	else return 0;
}

//BUTTON PROCESSING
void button_Mode(void){
	if(is_button_pressed(CHANGE_MODE_BUTTON)){		// Check if button for change mode is pressed
		RESET_ALL();								// reset system to init setup
		DEL_TASKS_PREVIOUS_MODE();					// delete all tasks of the previous mode
		switch(MODE){
		case(AUTO):
			ADD_TASKS_MODE_MODIFY_GREEN();			// add all tasks for the current mode
			break;
		case(MODI_GREEN):
			ADD_TASKS_MODE_MODIFY_RED();
			break;
		case(MODI_RED):
			ADD_TASKS_MODE_MODIFY_YELLOW();
			break;
		case(MODI_YELLOW):
			ADD_TASKS_MODE_AUTO();
			break;
		default:
			break;
		}
	}
}
void button_Time(void){
	if(is_button_pressed(CHANGE_TIME_BUTTON)){		// check if button for change time is pressed
		if(MODE != AUTO){
			SHOW_MODIFY_TIME();
		}
	}
}
void button_Update(void){
	if(is_button_pressed(SET_TIME_BUTTON)){
		switch(MODE){
			case(AUTO):
				if(IS_TIME_MODIFIED()) { 		// Check if there is any new value to update
					if(IS_TIME_SATISFIED()){	// Check if (time_green + time_yellow) = time_red
						SET_MODIFY_TIME();
					}else{
						SET_DEFAULT_TIME();
					}
				}
				break;
			case(MODI_GREEN):
					NEW_TIME_GREEN	=	NEW_TIME;
					break;
			case(MODI_RED):
					NEW_TIME_RED	=	NEW_TIME;
					break;
			case(MODI_YELLOW):
					NEW_TIME_YELLOW	=	NEW_TIME;
					break;
			default:
					break;
		}
	}
}
void button_Pedes(void){
	if(is_button_pressed(PEDESTRIAN_BUTTON)){		// check if button for pedestrian is pressed
		Pedes=2;
	}
}




