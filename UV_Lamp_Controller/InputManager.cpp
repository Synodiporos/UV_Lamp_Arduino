/*
 * InputManager.cpp
 *
 *  Created on: 19 Απρ 2018
 *      Author: Synodiporos
 */

#include <Arduino.h>
#include "InputManager.h"

InputManager::InputManager() {
	// TODO Auto-generated constructor stub

}

InputManager::~InputManager() {
	// TODO Auto-generated destructor stub
}


void InputManager::stateChanged(void* s, void* state){
	//Serial.print("- stateChanged: ");
	if(s!=NULL){
		/*
		Button* button = (Button*)s;

		int buttonPin = button->getPinNumber();
		ButtonState state = button->getButtonState();
		switch (buttonPin){
			case A0:
				if(state==ButtonState::CLICKED)
					this->inputManager->onBack();
				else if(state==ButtonState::HOLDED)
					getInputManager()->onReturn();
			break;
			case A1:
				if(state==ButtonState::CLICKED)
					getInputManager()->onEnter();
				else if(state==ButtonState::HOLDED)
					getInputManager()->onOK();
			break;
			case A2:
				if(state==ButtonState::CLICKED)
					getInputManager()->onForward();
				else if(state==ButtonState::HOLDED)
					getInputManager()->onFastForward();
			break;
			case A3:
				if(state==ButtonState::CLICKED)
					getInputManager()->onBackward();
				else if(state==ButtonState::HOLDED)
					getInputManager()->onFastBackward();
			break;
			*/
	}
}

