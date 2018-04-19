/*
 * Button.cpp
 *
 *  Created on: 24 Μαρ 2018
 *      Author: Synodiporos
 */
#include "Button.h"

unsigned short int Button::filterInterval = 50;
unsigned short int Button::holdStateInterval = 500;

Button::Button(unsigned short int pinNumber) {
	// TODO Auto-generated constructor stub
	this->pinNumber = pinNumber;
	pinMode(pinNumber, INPUT);
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

int Button::getPinNumber(){
	return Button::pinNumber;
}

void Button::setName(String name){
	Button::name = name;
}

String Button::getName(){
	return Button::name;
}

void Button::setButtonState(const ButtonState state){
	Button::buttonState = state;
}

ButtonState Button::getButtonState(){
	return Button::buttonState;
}

void Button::validate(){
	if(digitalRead(getPinNumber())==LOW){
		if(getButtonState()==ButtonState::PRESSED){
			if(getIntervalFromLastEvent()>=Button::holdStateInterval)
				hold();
		}
		else if(getButtonState()==ButtonState::RELEASED)
			press();
	}
	else{
		//if(getButtonState()==ButtonState::PRESSED)
		//	click();
		release();
	}
}

void Button::press(){
	if(getButtonState()!=ButtonState::PRESSED &&
			getIntervalFromLastEvent()>Button::filterInterval){
		Button::setButtonState(ButtonState::PRESSED);
		Button::notifyButtonStateChanged();
		Button::updateLastTimeEvent();
	}
}

void Button::release(){
	if(getButtonState()!=ButtonState::RELEASED &&
			getIntervalFromLastEvent()>Button::filterInterval){
		if(getButtonState()==ButtonState::PRESSED)
					click();
		Button::setButtonState(ButtonState::RELEASED);
		Button::notifyButtonStateChanged();
		Button::updateLastTimeEvent();
	}
}

void Button::click(){
	if(getButtonState()!=ButtonState::CLICKED){
		Button::setButtonState(ButtonState::CLICKED);
		Button::notifyButtonStateChanged();
		//Button::updateLastTimeEvent();
	}
}

void Button::hold(){
	if(getButtonState()!=ButtonState::HOLDED){
		Button::setButtonState(ButtonState::HOLDED);
		Button::notifyButtonStateChanged();
		//Button::updateLastTimeEvent();
	}
}

unsigned long Button::getLastEventTime(){
	return Button::lastEventTime;
}

void Button::updateLastTimeEvent(){
	Button::lastEventTime = millis();
}

unsigned long Button::getIntervalFromLastEvent(){
	return millis() - Button::getLastEventTime();
}

void Button::setButtonListener(IStateListener* l){
	Button::listener = l;
}

IStateListener* Button::getButtonListener(){
	return Button::listener;
}

void Button::notifyButtonStateChanged(){
	/*Serial.print("Button");
	Serial.print(getPinNumber());
	Serial.print(" & ");
	Serial.print((unsigned int)this);
	Serial.print(": State Changed");

	switch (getButtonState()){
	case ButtonState::PRESSED:
		Serial.print(" PRESSED");
		break;
	case ButtonState::RELEASED:
		Serial.print(" RELEASED");
		break;
	case ButtonState::CLICKED:
		Serial.print(" CLICKED");
		break;
	case ButtonState::HOLDED:
		Serial.print(" HOLDED");
		break;
	}*/

//	Serial.print(" , interval: ");
//	Serial.print(getIntervalFromLastEvent());
//	Serial.print(" , listener: ");
//
//	IStateListener* l = getButtonListener();
//	Serial.print((unsigned int)l);
//	Serial.print(" - ");
//	Serial.println((unsigned int)&l, HEX);
//	Serial.println();

	if(getButtonListener())
		getButtonListener()->stateChanged(this, 0);
}
