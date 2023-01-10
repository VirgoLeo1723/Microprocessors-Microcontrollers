/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: htn23
 */
#include "main.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define N0_OF_LEDS 3

#define butRST 0
#define butINC 1
#define butDEC 2



#define INIT 			-1
#define NORMAL_PRESS	0
#define LONG_PRESS_INC	1
#define LONG_PRESS_DEC	2
#define	RELEASE			3

extern int status_mode;


extern int counter;
extern int flag;

extern int counter2;
extern int flag2;

extern int counter3;
extern int flag3;


#endif /* INC_GLOBAL_H_ */
