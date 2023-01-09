/*
 * softTimer.c
 *
 *  Created on: Dec 2, 2022
 *      Author: htn23
 */

#include "softTimer.h"

int count =0;
int timerFlag = 0;

void timerSet(int time){
	count = time;
}
void timerRun(){
	if (count > 0) count -- ;
	else timerFlag = 1;
}
int isTimeOut(){
	if (timerFlag == 1) {
		timerFlag = 0;
		return 1;
	}
	else return 0;
}
