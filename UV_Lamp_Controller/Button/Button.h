/*
 * Button.h
 *
 *  Created on: 24 Μαρ 2018
 *      Author: Synodiporos
 */
#include <Arduino.h>
#include "../Commons/IStateListener.h"

#ifndef BUTTON_H_
#define BUTTON_H_

enum class ButtonState { PRESSED, RELEASED, CLICKED, HOLDED };

class Button{
public:
	static unsigned short int filterInterval;
	static unsigned short int holdStateInterval;

	Button(unsigned short int pinNumber);
	virtual ~Button();
	int getPinNumber();
	String getName();
	void setName(String name);
	ButtonState getButtonState();
	unsigned long getLastEventTime();
	unsigned long getIntervalFromLastEvent();
	IStateListener* getButtonListener();
	void setButtonListener(IStateListener* l);
	void validate();

private:
	unsigned short int pinNumber = -1;
	unsigned long lastEventTime = 0;
	String name = "";
	ButtonState buttonState = ButtonState::RELEASED;
	IStateListener* listener = 0;

	void setButtonState(const ButtonState state);
	void press();
	void release();
	void click();
	void hold();
	void updateLastTimeEvent();
	void notifyButtonStateChanged();
};

#endif /* BUTTON_H_ */
