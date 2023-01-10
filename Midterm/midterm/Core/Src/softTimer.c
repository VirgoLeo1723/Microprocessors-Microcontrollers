/*
 * softTimer.c
 *
 *  Created on: Nov 2, 2022
 *      Author: htn23
 */
#include "global.h"
#include "main.h"


void timerSet(int time){
	counter = time;
}
void timerRun(void){
	counter--;
	if (counter <= 0) flag = 1;

}
void timer2Set(int time){
	counter2 = time;
}
void timer2Run(void){
	counter2--;
	if (counter2 <= 0) flag2 = 1;
}
void timer3Set(int time){
	counter3 = time;
}
void timer3Run(void){
	counter3--;
	if (counter3 <= 0) flag3 = 1;
}


