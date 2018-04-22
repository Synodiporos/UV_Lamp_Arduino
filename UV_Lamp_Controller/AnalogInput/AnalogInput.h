/*
 * AnalogInput.h
 *
 *  Created on: Apr 20, 2018
 *      Author: sgeorgiadis
 */

#ifndef ANALOGINPUT_ANALOGINPUT_H_
#define ANALOGINPUT_ANALOGINPUT_H_
#include <stdint.h>
<<<<<<< Upstream, based on origin/master
=======
#include "../Commons/IPropertyListener.h"
#include "../Commons/Object.h"
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!

class AnalogInput : public Object{
public:
	AnalogInput(uint8_t pinNumber);
<<<<<<< Upstream, based on origin/master
=======
	AnalogInput(uint8_t pinNumber, uint8_t spv);
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
	virtual ~AnalogInput();

	void clearRecordsTable();
	uint8_t getPinNumber();
	unsigned short int getAnalogeValue();

	void validate();

<<<<<<< Upstream, based on origin/master
=======
protected:
	virtual void notifyPropertyChanged();
	unsigned short int _analogValue = 0;

>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
private:
<<<<<<< Upstream, based on origin/master
	unsigned short int _analogValue = 0;
=======
	uint8_t numReadings = 1;
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
	const uint8_t _pinNumber;
<<<<<<< Upstream, based on origin/master
=======
	unsigned long total = 0;
	unsigned short int * readings;
	uint8_t readIndex = 0;
	IPropertyListener * _listener = 0;


>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
};

#endif /* ANALOGINPUT_ANALOGINPUT_H_ */
