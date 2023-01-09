/*
 * task.h
 *
 *  Created on: Nov 12, 2022
 *      Author: htn23
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_
#include "global.h"
#include "input_reading.h"
#include "main.h"


void LedR_Display(void);
void LedG_Display(void);
void LedY_Display(void);
void LedR2_Display(void);
void LedG2_Display(void);
void LedY2_Display(void);
void incTime(void);
void display7SEG_1(void);
void display7SEG_2(void);
void Led1_end(void);
void Led2_end(void);
void button_processing(void);
extern int second;

#endif /* INC_TASK_H_ */
