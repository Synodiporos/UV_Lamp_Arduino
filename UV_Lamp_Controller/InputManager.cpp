/*
 * InputManager.cpp
 *
 *  Created on: 19 Απρ 2018
 *      Author: Synodiporos
 */

#include <Arduino.h>
#include "InputManager.h"
#include "AnalogInput/ToggleAnalogInput.h"

InputManager::InputManager() {
	// TODO Auto-generated constructor stub

}

InputManager::~InputManager() {
	// TODO Auto-generated destructor stub
}


void InputManager::onBack(){
	Serial.println("onBack");
}

void InputManager::onReturn(){
	Serial.println("onReturn");
}

void InputManager::onEnter(){
	Serial.println("onEnter");
}

void InputManager::onOK(){
	Serial.println("onOK");
}

void InputManager::onForward(){
	Serial.println("onForward");
}

void InputManager::onFastForward(){
	Serial.println("onFastForward");
}

void InputManager::onBackward(){
	Serial.println("onBackward");
}

void InputManager::onFastBackward(){
	Serial.println("onFastBackward");
}

void InputManager::onCaseOpen(){
	Serial.println("onCaseOpen");
}

void InputManager::onCaseClose(){
	Serial.println("onCaseClose");
}

void InputManager::stateChanged(State* state){

	if(state!=0){
		Button* button = (Button*)state->getSource();
		int pinNumber = button->getPinNumber();
		int id = state->getName();
		if(id==5){
			ToggleAnalogInput* irs = (ToggleAnalogInput*)state->getSource();
			bool toogleState = irs->getToggleState();
			if(toogleState)
				onCaseOpen();
			else
				onCaseClose();
		}
		else{
			ButtonState state = button->getButtonState();
			switch (pinNumber){
				case A0:
					if(state==ButtonState::CLICKED)
						onBack();
					else if(state==ButtonState::HOLDED)
						onReturn();
				break;
				case A1:
					if(state==ButtonState::CLICKED)
						onEnter();
					else if(state==ButtonState::HOLDED)
						onOK();
				break;
				case A2:
					if(state==ButtonState::CLICKED)
						onForward();
					else if(state==ButtonState::HOLDED)
						onFastForward();
				break;
				case A3:
					if(state==ButtonState::CLICKED)
						onBackward();
					else if(state==ButtonState::HOLDED)
						onFastBackward();
				break;
			}
		}
	}
}

