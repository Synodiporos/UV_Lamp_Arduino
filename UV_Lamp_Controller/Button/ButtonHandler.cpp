/*
 * ButtonHandler.cpp
 *
 *  Created on: 19 Μαρ 2018
 *      Author: Synodiporos
 */
#include "ButtonHandler.h"

ButtonHandler::ButtonHandler() {
	//this->buttons = buttons[2];
}

ButtonHandler::~ButtonHandler() {
	// TODO Auto-generated destructor stub
}

void ButtonHandler::validate(){
	//Serial.println(getButtons()->size());
	for (std::vector<Button*>::iterator it = getButtons()->begin();
			it != getButtons()->end(); ++it){
		//Serial.println( (*it)->getPinNumber() );
		(*it)->validate();
	}
}

void ButtonHandler::activate(){
	for (std::vector<Button*>::iterator it = getButtons()->begin();
			it != getButtons()->end(); ++it){
		((Button*)*it)->setButtonListener(this);

		//Serial.println((unsigned int)(*it));
	}
	ButtonHandler::isActivate = true;
}

void ButtonHandler::deactivate(){
	ButtonHandler::isActivate = false;
	for (std::vector<Button*>::iterator it = getButtons()->begin();
				it != getButtons()->end(); ++it)
			((Button*)it)->setButtonListener(NULL);
}

bool ButtonHandler::isHandlerActivate(){
	return ButtonHandler::isActivate;
}

std::vector<Button*>* ButtonHandler::getButtons(){
	return ButtonHandler::buttons;
}

void ButtonHandler::addButton(Button* button){
	//Serial.print(" add button: ");
	//Serial.println((unsigned int)button);

	if(isHandlerActivate())
		button->setButtonListener(this);
	getButtons()->push_back(button);
}

void ButtonHandler::removeButton(Button* button){
		button->setButtonListener(0);
		getButtons()->push_back(button);
}

/*void ButtonHandler::ButtonHandler::stateChanged(void* s, void* state){

}*/
