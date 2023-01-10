/*
 * input_reading.c
 *
 *  Created on: Nov 2, 2022
 *      Author: htn23
 */

#include "main.h"

#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];

static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ]= {100,100,100};

static uint8_t flagForButtonPress3s [ N0_OF_BUTTONS ];
static uint16_t counterForButtonPress3s [ N0_OF_BUTTONS ];


void button_reading ( void ) {
	for ( char i = 0; i < N0_OF_BUTTONS ; i ++) {
			debounceButtonBuffer2 [i] = debounceButtonBuffer1 [ i ];

			if (i==0) debounceButtonBuffer1 [i] = HAL_GPIO_ReadPin(butRST_GPIO_Port, butRST_Pin);
			if (i==1) debounceButtonBuffer1 [i] = HAL_GPIO_ReadPin(butINC_GPIO_Port, butINC_Pin);
			if (i==2) debounceButtonBuffer1 [i] = HAL_GPIO_ReadPin(butDEC_GPIO_Port, butDEC_Pin);

			if( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])
					buttonBuffer [ i] = debounceButtonBuffer1 [ i ];
			if( buttonBuffer [i] == BUTTON_IS_PRESSED ) {
				if ( counterForButtonPress3s [i] < 300 ) {
					counterForButtonPress3s [i]++;
				}else {
					flagForButtonPress3s[i] = 1;
					if ( counterForButtonPress1s [i] < 100 ){
						counterForButtonPress1s [i]++;
					} else flagForButtonPress1s[i] = 1;
				}

			} else {
				counterForButtonPress3s [i] = 0;
				flagForButtonPress3s[i] = 0;
			}
	}
}
unsigned char is_button_pressed ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	return ( buttonBuffer [index] == BUTTON_IS_PRESSED ) ;
}
unsigned char is_button_pressed_1s ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0xff ;
	if(flagForButtonPress1s[index] == 1){
		counterForButtonPress1s [index] = 0;
		flagForButtonPress1s[index] = 0;
		return 1;
	}else return 0;
}
unsigned char is_button_pressed_3s (uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0xff ;
	return ( flagForButtonPress3s [index] == 1) ;
}

