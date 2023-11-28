/*
 * input_reading.c
 *
 *  Created on: Oct 8, 2023
 *      Author: HP
 */


#include "input_reading.h"

//Set Port and Pin for button
//#define BTN_GPIO GPIOB
//const short BTN_Pin[NO_BUTTON] = {
//		BTN_Pin
//};

//Current state of button
GPIO_PinState filtered[NO_BUTTON];

//Two debounce buffer.
GPIO_PinState buffer0[NO_BUTTON];
GPIO_PinState buffer1[NO_BUTTON];

//These variable use for handling pressed more than one second.
uint8_t flagOneSec[NO_BUTTON];
short counterOneSec[NO_BUTTON];

void Input_Reading_Init(void){
	for(short i = 0; i < NO_BUTTON; i++){
		filtered[i] = buffer0[i] = buffer1[i] = BUTTON_RELEASED;
		flagOneSec[i] = 0;
		counterOneSec[i] = 100;
	}
}

void ButtonReading(const short index){
	//Save 2 recently states
	buffer1[index] = buffer0[index];
	buffer0[index] = HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin);

	//If all saved states equal -> that's a good reading (filtered)
	if(buffer1[index] == buffer0[index]){
		filtered[index] = buffer0[index];
		//If button_pressed -> counter will work, if not -> just reset counter.
		if (filtered[index] == BUTTON_PRESSED){
			counterOneSec[index]--;
			if (counterOneSec[index] <= 0){
				flagOneSec[index] = 1;
			}
		} else {
			counterOneSec[index] = 100;
			flagOneSec[index] = 0;
		}
	}
}

uint8_t IsButtonPressed(const short index){
	return (filtered[index] == BUTTON_PRESSED);
}

uint8_t IsButtonPressedOneSec(const short index){
	return flagOneSec[index];
}





