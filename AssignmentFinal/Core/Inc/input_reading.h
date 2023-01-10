/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2022
 *      Author: This PC
 */


#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#define N0_OF_BUTTONS 4
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
void button_reading(void);
unsigned char is_button_pressed (uint8_t index );
unsigned char is_button_pressed_3s (uint8_t index);
int which_button_press_press3s(void);
int press_release(void);
#endif /* INC_INPUT_READING_H_ */

