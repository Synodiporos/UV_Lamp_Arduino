/*
 * InputManager.h
 *
 *  Created on: 19 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

//#include "Commons/IStateListener.h"
#include "Button/ButtonHandler.h"
#include "Commons/State.h"

class InputManager : public ButtonHandler{
public:
	InputManager();
	virtual ~InputManager();
	void stateChanged(State* state);

	void onBack();
	void onReturn();
	void onEnter();
	void onOK();
	void onForward();
	void onFastForward();
	void onBackward();
	void onFastBackward();
	void onCaseOpen();
	void onCaseClose();
};

#endif /* INPUTMANAGER_H_ */
