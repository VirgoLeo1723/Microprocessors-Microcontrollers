#include "input_reading.h"

int FLAG_CHECK_PRESSED[N0_OF_BUTTONS]={1,1,1,1};
static uint16_t counterForButtonPress3s [N0_OF_BUTTONS];

static GPIO_PinState Key_0 [N0_OF_BUTTONS]={1,1,1,1};
static GPIO_PinState Key_1 [N0_OF_BUTTONS]={1,1,1,1};
static GPIO_PinState Key_2 [N0_OF_BUTTONS]={1,1,1,1};
static GPIO_PinState Key_3 [N0_OF_BUTTONS]={1,1,1,1};

static uint8_t buttonBuffer [N0_OF_BUTTONS]={1,1,1,1};
static uint8_t flagForButtonPress3s [N0_OF_BUTTONS];
static uint16_t counterForButtonPress3s [N0_OF_BUTTONS ];
// mode  time  select button
// RESET INC DEC
void button_reading ( void ) {
	for ( char i = 0; i < N0_OF_BUTTONS ; i ++) {
			Key_2[i]=Key_1[i];
			Key_1[i]=Key_0[i];
			if (i==0)  Key_0[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
			if (i==1)  Key_0[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
			if (i==2)  Key_0[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
			if (i==3)  Key_0[i] = HAL_GPIO_ReadPin(Ped_Button_GPIO_Port, Ped_Button_Pin);

			if(Key_2[i]==Key_1[i] && Key_1[i]==Key_0[i]){
				if(Key_3[i]!=Key_2[i]){
					Key_3[i]=Key_2[i];
					if(Key_3[i]==BUTTON_IS_PRESSED){
						buttonBuffer[i]=BUTTON_IS_PRESSED;
						counterForButtonPress3s[i]=DURATION_FOR_AUTO_INCREASING;
					}else{
						buttonBuffer[i]=BUTTON_IS_RELEASED;
						flagForButtonPress3s[i]=0;
						FLAG_CHECK_PRESSED[i]=1;
					}
				}else{
					if(Key_3[i]==BUTTON_IS_PRESSED){
						counterForButtonPress3s[i]--;
						if(counterForButtonPress3s[i]==0){
							//flagForButtonPress3s[i]=1;
							Key_3[i]=BUTTON_IS_RELEASED;
							buttonBuffer[i]=BUTTON_IS_RELEASED;
							FLAG_CHECK_PRESSED[i]=1;
							flagForButtonPress3s[i]=0;

						}
					}
			}
		}
	}
}
unsigned char is_button_pressed ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if(buttonBuffer[index]==BUTTON_IS_PRESSED && FLAG_CHECK_PRESSED[index]==1 ){
		FLAG_CHECK_PRESSED[index]=0;
		return 1;
	}
	return 0;
}
unsigned char is_button_pressed_3s ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	return (flagForButtonPress3s[index]==1);
}

int which_button_press(void){
	for(int i=0;i<N0_OF_BUTTONS;i++){
		if(is_button_pressed(i)){
			return (i);
		}
	}
	return N0_OF_BUTTONS;
}
int which_button_press3s(void){
	for(int i=1;i<N0_OF_BUTTONS;i++){
		if(is_button_pressed_3s(i)){
			return (i);
		}
	}
	return N0_OF_BUTTONS;
}
int press_or_press3s(void){
	for(int i=0;i<N0_OF_BUTTONS;i++){
		if((buttonBuffer[i]==BUTTON_IS_PRESSED && FLAG_CHECK_PRESSED[i]==1)){
			return 0; // pressed
		}
	}
	for(int i=0;i<N0_OF_BUTTONS;i++){
		if(flagForButtonPress3s[i]==1){
			return 1; // pressed1s
		}
	}
	return -1;
}
int press_release(void){
	for(int i=0;i<N0_OF_BUTTONS;i++){
		if(buttonBuffer[i]!=BUTTON_IS_RELEASED ){
			return 1;
		}
	}
	return -1;
}

