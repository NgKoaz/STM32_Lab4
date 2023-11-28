/*
 * input_processing.h
 *
 *  Created on: Oct 8, 2023
 *      Author: HP
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "input_reading.h"

//After we hold modify button more than 1s,
//it will increase after this milisecond.
#define INCREASING_PERIOD 	100

typedef enum{
	RELEASED,
	PRESSED,
	PRESSED_MORE_THAN_ONE_SECOND
} ButtonState;

void Input_Processing_Init(void);
void FSM_ForInputProcessing(void (*processing) (void), const short index);

#endif /* INC_INPUT_PROCESSING_H_ */
