/*
 * fsm_mode.c
 *
 *  Created on: Nov 2, 2022
 *      Author: htn23
 */

#include "main.h"
#include "global.h"
#include "softTimer.h"
#include "input_reading.h"
#include "fsm_simple_button.h"


enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState butList[N0_OF_BUTTONS]={BUTTON_RELEASED,BUTTON_RELEASED,BUTTON_RELEASED};

int checkPress[N0_OF_BUTTONS] = {0,0,0};
int checkPress1s[N0_OF_BUTTONS] = {0,0,0};
int checkPress3s[N0_OF_BUTTONS] = {0,0,0};

int isPressed(int index){
	if (checkPress[index] == 1) {
		checkPress[index] = 0;
		return 1;
	} else return 0;
}
int isPressed1s(int index){
	if (checkPress1s[index] == 1) {
		checkPress1s[index] = 0;
		return 1;
	} else return 0;
}
int isPressed3s(int index){
	if (checkPress3s[index] == 1) {
		return 1;
	} else return 0;
}
int isTimeout(int *flag){
	if (*flag == 1) {
		*flag = 0;
		return 1;
	} else return 0;
}

// Update value of button
void updateButtonInfor(int index){
	switch ( butList[index] ){
		case BUTTON_RELEASED :
			if( is_button_pressed(index) ) {
				butList[index] = BUTTON_PRESSED;
				checkPress[index] = 1;
			} break ;
		case BUTTON_PRESSED :
			if (! is_button_pressed(index) ) {
				butList[index] = BUTTON_RELEASED ;
			} else {
				if(is_button_pressed_3s(index)) {
					butList[index] = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
					checkPress3s[index] = 1;
					if (is_button_pressed_1s(index))
						checkPress1s[index]=1;
				}
			} break ;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:

			if (! is_button_pressed(index) ) {
				butList[index] = BUTTON_RELEASED ;
				checkPress3s[index] = 0;
			}else {
				if (is_button_pressed_1s(index))
					checkPress1s[index]=1;
			}
			break ;
	}
}
// Display 7 seg led
void display7SEG(int num){
	if (num==1){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 1);
	}
	else if (num==2){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==3){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);

	}
	else if (num==4){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==5){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==6){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==7){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 1);
	}
	else if (num==8){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==9){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 1);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 0);
	}
	else if (num==0){
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, b1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, c1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, d1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, e1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, f1_Pin, 0);
		HAL_GPIO_WritePin(a1_GPIO_Port, g1_Pin, 1 );
	}
}

int counter_display =0;
void fsm_simple_button_run(){
	for (uint8_t index = 0; index<N0_OF_BUTTONS;index++){
		updateButtonInfor(index);
	}

	if (isTimeout(&flag3)) {
		HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
		timer3Set(100);
	}
	display7SEG(counter_display);

	if (counter_display>9) counter_display = 0;
	if (counter_display<0) counter_display = 9;

	switch (status_mode) {
		case INIT:{
			status_mode = NORMAL_PRESS;
			timerSet(1000);
			flag = 0;
		}

		// NORMAL_PRESS
		case NORMAL_PRESS:{
			if (isPressed(butRST) )			counter_display = 0;

			if (isPressed3s(butINC)) 		status_mode = LONG_PRESS_INC;
			else if (isPressed(butINC)) 	counter_display ++;

			if (isPressed3s(butDEC))		status_mode = LONG_PRESS_DEC;
			else if (isPressed(butDEC))		counter_display --;


			if (isTimeout(&flag)) {
				status_mode = RELEASE;
				timer2Set(100);
				flag2 = 0;
			}
		} break;

		// LONGPRESS
		case LONG_PRESS_INC:{
			if (isPressed1s(butINC)) 		counter_display ++;
			if (!isPressed(butINC))		status_mode = INIT;
		} break;
		case LONG_PRESS_DEC:{
			if (isPressed1s(butDEC)) 		counter_display --;
			if (!isPressed(butDEC))		status_mode = INIT;
		} break;

		//RELEASE 10s
		case RELEASE:{
			if (isTimeout(&flag2)) {
				timer2Set(100);
				flag2 = 0;
				counter_display --;
			}
			if (counter_display==0) 		status_mode = INIT;

			if (isPressed3s(butINC))		status_mode = LONG_PRESS_INC;
			else if (isPressed(butINC)){
				counter_display ++;
				status_mode = INIT;
			}

			if (isPressed3s(butDEC))		status_mode = LONG_PRESS_DEC;
			else if (isPressed(butDEC)){
				counter_display --;
				status_mode = INIT;
			}
		}
		default: break;
	}
}


