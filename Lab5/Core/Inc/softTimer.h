/*
 * softTimer.h
 *
 *  Created on: Dec 2, 2022
 *      Author: htn23
 */

#ifndef INC_SOFTTIMER_H_
#define INC_SOFTTIMER_H_

extern count;
extern timerFlag;

void timerSet(int time);
void timerRun();
int isTimeOut();

#endif /* INC_SOFTTIMER_H_ */
