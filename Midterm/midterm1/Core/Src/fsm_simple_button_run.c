/*
 * fsm_simple_button_run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: htn23
 */
#include "fsm_simple_button.h"
#include "display_7seg.h"

#define butInc  1
#define N0_OF_BUTTONS 3

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND,  } ;
enum ButtonState butList[N0_OF_BUTTONS]={BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

int checkPress[N0_OF_BUTTONS] 		= {0,0,0};

int counter_display = 0;

int isPressed(int index){
	if (checkPress[index] == 1) {
		checkPress[index] = 0;
		return 1;
	} else return 0;
}
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
				if( is_button_pressed_1s(index) ) {
					butList[index] = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
				}
			} break ;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND :
			if (! is_button_pressed(index) ) {
				butList[index] = BUTTON_RELEASED ;
			}
			break ;
	}
}

void fsm_simple_button_run(){
	for (uint8_t index = 0; index<N0_OF_BUTTONS;index++){
		updateButtonInfor(index);
	}

	display7SEG_1(counter_display);
	if (butList[butInc] == BUTTON_PRESSED && isPressed(butInc)) counter_display++;
}


