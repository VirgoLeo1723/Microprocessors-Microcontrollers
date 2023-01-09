/*
 * input_reading.h
 *
 *  Created on: Nov 3, 2022
 *      Author: htn23
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define butMode 0
#define butTime 1
#define butFirm 2

#define button0 0
#define button1 1

extern GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
extern GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
extern GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
extern uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
extern uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ];

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);


#endif /* INC_INPUT_READING_H_ */
