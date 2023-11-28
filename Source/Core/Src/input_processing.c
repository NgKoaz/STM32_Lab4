/*
 * input_processing.c
 *
 *  Created on: Oct 8, 2023
 *      Author: HP
 */

#include "input_processing.h"

ButtonState buttonState[NO_BUTTON];


void Input_Processing_Init(void)
{
	buttonState[BTN] = RELEASED;
}


//This is abstract function. Use for those function below.
void FSM_ForInputProcessing(void (*processing) (void), const short index){
	switch(buttonState[index]){
	case RELEASED:
		if (IsButtonPressed(index)){
			buttonState[index] = PRESSED;
			(*processing)();
		}
		break;
	case PRESSED:
		if (!IsButtonPressed(index)){
			buttonState[index] = RELEASED;
		} else if (IsButtonPressedOneSec(index)){
			buttonState[index] = PRESSED_MORE_THAN_ONE_SECOND;
		}
		break;
	case PRESSED_MORE_THAN_ONE_SECOND:
		if (!IsButtonPressedOneSec(index)){
			buttonState[index] = RELEASED;
		}
		break;
	}
}

