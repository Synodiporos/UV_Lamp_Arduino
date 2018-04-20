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

class InputManager : public ButtonHandler{
public:
	InputManager();
	virtual ~InputManager();
	void stateChanged(void* source, void* state);

	void onBack();
	void onReturn();
	void onEnter();
	void onOK();
	void onForward();
	void onFastForward();
	void onBackward();
	void onFastBackward();
};

#endif /* INPUTMANAGER_H_ */
