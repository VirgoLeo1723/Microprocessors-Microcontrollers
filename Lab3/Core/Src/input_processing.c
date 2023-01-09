/*
 * input_processing.c
 *
 *  Created on: Sep 26, 2022
 *      Author: htn23
 */

#include "main.h"
#include "input_reading.h"

#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND };
enum ButtonState butList[N0_OF_BUTTONS]={BUTTON_RELEASED,BUTTON_RELEASED,BUTTON_RELEASED};
int checkPress[N0_OF_BUTTONS] = {0,0,0};

#define butMode 0
#define butTime 1
#define butFirm 2

#define ledR 0
#define ledG 1
#define ledY 2

int secondDuration		=100;
int trafficDuration		=1000;
int ledRDuration		=500;
int ledGDuration		=300;
int ledYDuration		=200;
int blinkDuration		=25;
int	modeDuration		=50;

int confirmSignal		=8;
int resetSignal			=0;

int counter1 = 25;
int trafficCounter = 1000;
int trafficMode = -1;

int tempTime = 0;
int modeCounter = 25;

int flagLED = 0;
int flag7SEG = 0;
int flagBlink = 0;

int flagReset = 0;
int flagPress1s = 0;

void fsm_for_input_processing ( void ) {
	for (uint8_t index = 0; index<N0_OF_BUTTONS;index++){
		updateButtonInfor(index);
	}

	if (butList[butMode] == BUTTON_PRESSED && checkPress[butMode] == 1){
		trafficMode = (trafficMode + 1)%4;
		display7SEG_1(trafficMode+1);
		checkPress[butMode] = 0;
		executeReset();
	}
	if (butList[butTime] == BUTTON_PRESSED && checkPress[butTime] == 1 && trafficMode>0){
		tempTime = (tempTime + 100);
		display7SEG_2(tempTime/secondDuration);
		checkPress[butTime] = 0;
	}
	if (butList[butFirm] == BUTTON_PRESSED && checkPress[butFirm] == 1 && trafficMode>0){
		display7SEG_2(confirmSignal);
		checkPress[butFirm] = 0;
		executeConfirm();
	}
	if (trafficMode == 0){
		executeMode0();
	}
	if (trafficMode == 1){
		executeMode1();
	}
	if (trafficMode == 2){
		executeMode2();
	}
	if (trafficMode == 3){
		executeMode3();
	}
/*	if (butModeState==BUTTON_PRESSED_MORE_THAN_1_SECOND && flagPress1s == 1){
		number = (number+2)%10;
		display7SEG(number);
		flagPress1s = 0;
	}*/
}
void executeReset(void){
	display7SEG_1(trafficMode+1);
	display7SEG_2(resetSignal);
	tempTime = 0;
	trafficCounter = trafficDuration;
}
void executeConfirm(void){
	if (trafficMode == 1) ledRDuration = tempTime;
	if (trafficMode == 2) ledGDuration = tempTime;
	if (trafficMode == 3) ledYDuration = tempTime;
	trafficDuration = ledRDuration + ledGDuration + ledYDuration;
}
void executeMode0(void){
	int tempVal = 0;
	if (flagLED == ledR){
		HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,0);
		HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin,1);
		HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,1);
		tempVal = trafficCounter - ledGDuration - ledYDuration;
	}
	if (flagLED == ledG){
		HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,1);
		HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin,0);
		HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,1);
		tempVal = trafficCounter - ledYDuration ;
	}
	if (flagLED == ledY){
		HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,1);
		HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin,1);
		HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,0);
		tempVal = trafficCounter;
	}
	if (flag7SEG == 1 ){
		display7SEG_2(tempVal/secondDuration);
		flag7SEG = 0;
	}
}
void executeMode1(void){
	HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin,1);
	HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,1);
	if (flagBlink == 1){
		HAL_GPIO_TogglePin(LEDR_GPIO_Port,LEDR_Pin);
		flagBlink = 0;
	}
}
void executeMode2(void){
	display7SEG_2(tempTime);
	HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,1);
	HAL_GPIO_WritePin(LEDY_GPIO_Port, LEDY_Pin,1);
	if (flagBlink == 1){
		HAL_GPIO_TogglePin(LEDG_GPIO_Port,LEDG_Pin);
		flagBlink = 0;
	}
}
void executeMode3(void){
	display7SEG_2(tempTime);
	HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin,1);
	HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin,1);
	if (flagBlink == 1){
		HAL_GPIO_TogglePin(LEDY_GPIO_Port,LEDY_Pin);
		flagBlink = 0;
	}
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
void softTimer(void){
	button_reading();
	if (trafficCounter % secondDuration == 0)
		flag7SEG = 1;
	if (trafficCounter == trafficDuration)
		flagLED = ledR;
	if (trafficCounter == trafficDuration - ledRDuration)
		flagLED = ledG;
	if (trafficCounter == trafficDuration - ledRDuration - ledGDuration)
		flagLED = ledY;
	if (trafficCounter == trafficDuration - ledRDuration - ledGDuration - ledYDuration)
		trafficCounter = trafficDuration+1;
	trafficCounter --;

	if (modeCounter == 0) modeCounter = modeDuration;
	if (modeCounter % blinkDuration == 0) flagBlink = 1;
	modeCounter --;

}
