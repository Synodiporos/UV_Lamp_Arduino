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
};

#endif /* INPUTMANAGER_H_ */
