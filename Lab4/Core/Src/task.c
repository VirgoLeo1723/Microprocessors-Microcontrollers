/*
 * task.c
 *
 *  Created on: Nov 12, 2022
 *      Author: htn23
 */
#include "task.h"
int second = 0;
int key1[N0_OF_BUTTONS] = {0,0,0};
int key2[N0_OF_BUTTONS] = {0,0,0};
int key3[N0_OF_BUTTONS] = {0,0,0};
int key4[N0_OF_BUTTONS] = {0,0,0};

int state_led2 = 0;
void LedR_Display(void){
	HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
}
void LedG_Display(void){
	HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
}
void LedY_Display(void){
	HAL_GPIO_TogglePin(LEDY_GPIO_Port, LEDY_Pin);
}

void incTime(void){
	second = (second + 1)%10;
}
void display7SEG_2(void){
	int num = second;
	if (num==1){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 1);
	}
	else if (num==2){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	}
	else if (num==3){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);

	}
	else if (num==4){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	}
	else if (num==5){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	}
	else if (num==6){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	}
	else if (num==7){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 1);
	}
	else if (num==8){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	}
	else if (num==9){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 1);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 0);
	} else if (num==0){
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, b2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, c2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, d2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, e2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, f2_Pin, 0);
		HAL_GPIO_WritePin(a2_GPIO_Port, g2_Pin, 1 );
	}
}
void display7SEG_1(void){
	int num = second;
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

void Led1_end(void){
	if (is_button_pressed(button0))
		HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);

}
void Led2_end(void){
	if (is_button_pressed(button1))
		HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
}
