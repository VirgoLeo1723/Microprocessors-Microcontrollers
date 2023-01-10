/*
 * fsm_simple_button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: htn23
 */

#ifndef INC_FSM_SIMPLE_BUTTON_H_
#define INC_FSM_SIMPLE_BUTTON_H_

#include "input_reading.h"

void fsm_simple_button_run(void);
int isPressed(int index);
void updateButtonInfor(int index);

#endif /* INC_FSM_SIMPLE_BUTTON_H_ */
