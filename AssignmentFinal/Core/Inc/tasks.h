/*
 * tasks.h
 *
 *  Created on: Nov 25, 2022
 *      Author: This PC
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "input_reading.h"
#include "scheduler.h"
#include "main.h"
#include "global.h"

void ADD_TASKS_MODE_AUTO(void);
void ADD_TASKS_MODE_MODIFY_GREEN(void);
void ADD_TASKS_MODE_MODIFY_YELLOW(void);
void ADD_TASKS_MODE_MODIFY_RED(void);

void DEL_TASKS_PREVIOUS_MODE(void);

void button_Mode(void);
void button_Time(void);
void button_Update(void);
void button_Pedes(void);

void RESET_ALL_LED(void);
void RESET_BUZZER(void);
void RESET_UART(void);
void RESET_ALL(void);

// define for MODE
#define AUTO 		1
#define MODI_RED 	2
#define MODI_GREEN 	3
#define MODI_YELLOW 4

// define for BUTTON
#define PEDESTRIAN_BUTTON 	3
#define CHANGE_MODE_BUTTON	0
#define CHANGE_TIME_BUTTON 	1
#define SET_TIME_BUTTON		2

// define for BUZZER
#define BUZZER_ON 	10 // => 10/20 = 50%
#define BUZZER_OFF 	0  // => 0 /20 = 0%

// define for TASKS
#define TASKS_START_POSITION	4
#define NO_TASKS_MODE_AUTO		9
#define NO_TASKS_MODE_MODIFY	1

// define for Time Duration
#define SECOND_DURATION			100
#define DEFAULT_TIME_RED		15
#define DEFAULT_TIME_YELLOW		5
#define DEFAULT_TIME_GREEN		10

#endif /* INC_TASKS_H_ */
