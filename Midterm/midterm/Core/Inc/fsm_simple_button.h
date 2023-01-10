/*
 * fsm_mode.h
 *
 *  Created on: Nov 2, 2022
 *      Author: htn23
 */

#ifndef INC_FSM_MODE_H_
#define INC_FSM_MODE_H_


#include "global.h"



void fsm_simple_button_run(void);

void updateButtonInfor(int index);

int isPressed(int index);
int isPressed3s(int index);
int isTimeout(int *flag);


void display7SEG(int num);


#endif /* INC_FSM_MODE_H_ */
