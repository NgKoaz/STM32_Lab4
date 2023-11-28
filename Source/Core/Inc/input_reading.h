/*
 * input_reading.h
 *
 *  Created on: Oct 8, 2023
 *      Author: HP
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"


#define BUTTON_PRESSED 	GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET

//Number of buttons
#define NO_BUTTON 		1

//Index for each button
#define BTN 			0

void Input_Reading_Init(void);
void ButtonReading(const short index);
uint8_t IsButtonPressed(const short index);
uint8_t IsButtonPressedOneSec(const short index);

#endif /* INC_INPUT_READING_H_ */
