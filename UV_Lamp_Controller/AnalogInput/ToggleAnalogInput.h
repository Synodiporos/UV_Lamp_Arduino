/*
 * ToggleAnalogInput.h
 *
 *  Created on: Apr 20, 2018
 *      Author: sgeorgiadis
 */

#ifndef ANALOGINPUT_TOGGLEANALOGINPUT_H_
#define ANALOGINPUT_TOGGLEANALOGINPUT_H_
<<<<<<< Upstream, based on origin/master
=======
#include "AnalogInput.h"
#include "../Commons/IStateListener.h"
#include "../Commons/State.h"
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!

<<<<<<< Upstream, based on origin/master
class ToggleAnalogInput {
=======
class ToggleAnalogInput : public AnalogInput{
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
public:
<<<<<<< Upstream, based on origin/master
	ToggleAnalogInput();
=======
	ToggleAnalogInput(uint8_t pinNumber);
	ToggleAnalogInput(uint8_t pinNumber, uint8_t spv);
	ToggleAnalogInput(uint8_t pinNumber, uint8_t spv,
				unsigned short int switchValue);
	ToggleAnalogInput(uint8_t pinNumber, uint8_t spv,
			unsigned short int switchValue,
			unsigned short int hysterisis);
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
	virtual ~ToggleAnalogInput();
<<<<<<< Upstream, based on origin/master
=======
	bool getToggleState();
	void setSwitchValue(unsigned short int switchValue);
	unsigned short int getSwitchValue();
	void setHysterisis(unsigned short int hysterisis);
	unsigned short int getHysterisis();
	void setStateListener(IStateListener * listener);
	IStateListener* getStateListener();

private:
	bool state = false;
	unsigned short int switchValue = 0;
	unsigned short int hysterisis = 0;

	IStateListener * _stateListener = 0;

	void notifyPropertyChanged();
	void notifyToggleStateChanged();
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
};

#endif /* ANALOGINPUT_TOGGLEANALOGINPUT_H_ */
