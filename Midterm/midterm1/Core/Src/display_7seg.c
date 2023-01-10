/*
 * display_7seg.c
 *
 *  Created on: Nov 4, 2022
 *      Author: htn23
 */

#include "main.h"
void display7SEG_1(int num){
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
void display7SEG_2(int num){
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
