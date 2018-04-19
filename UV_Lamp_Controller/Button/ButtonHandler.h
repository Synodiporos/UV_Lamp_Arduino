/*
 * ButtonHandler.h
 *
 *  Created on: 19 Μαρ 2018
 *      Author: Synodiporos
 */

#ifndef BUTTONHANDLER_H_
#define BUTTONHANDLER_H_
#include "Button.h"
#include "../Commons/IStateListener.h"
#include <vector>

class ButtonHandler : public IStateListener {
public:
	ButtonHandler();
	virtual ~ButtonHandler();
	void addButton(Button* button);
	void removeButton(Button* button);
	Button* getButton(int index);
	std::vector<Button*>* getButtons();
	void activate();
	void deactivate();
	bool isHandlerActivate();
	void validate();
	void stateChanged(void* source, void* stateChanged);

private:
	std::vector<Button*>* buttons = new std::vector<Button*>;
	bool isActivate = false;
};

#endif /* BUTTONHANDLER_H_ */
