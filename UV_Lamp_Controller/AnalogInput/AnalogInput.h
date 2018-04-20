/*
 * AnalogInput.h
 *
 *  Created on: Apr 20, 2018
 *      Author: sgeorgiadis
 */

#ifndef ANALOGINPUT_ANALOGINPUT_H_
#define ANALOGINPUT_ANALOGINPUT_H_
#include <stdint.h>

class AnalogInput {
public:
	AnalogInput(uint8_t pinNumber);
	virtual ~AnalogInput();

	uint8_t getPinNumber();
	unsigned short int getAnalogeValue();

	void validate();

private:
	unsigned short int _analogValue = 0;
	const uint8_t _pinNumber;
};

#endif /* ANALOGINPUT_ANALOGINPUT_H_ */
