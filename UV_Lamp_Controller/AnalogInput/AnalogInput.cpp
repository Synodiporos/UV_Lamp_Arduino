/*
 * AnalogInput.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: sgeorgiadis
 */

#include "AnalogInput.h"

AnalogInput::AnalogInput(uint8_t pinNumber) : _pinNumber(pinNumber){
	// TODO Auto-generated constructor stub

}

AnalogInput::~AnalogInput() {
	// TODO Auto-generated destructor stub
}

uint8_t AnalogInput::getPinNumber(){
	return this->_pinNumber;
}
unsigned short int AnalogInput::getAnalogeValue(){
	return this->_analogValue;
}

void AnalogInput::validate(){

	// subtract the last reading:
	total = total - readings[readIndex];
	// read from the sensor:
	readings[readIndex] = analogRead(inputPin);
	// add the reading to the total:
	total = total + readings[readIndex];
	// advance to the next position in the array:
	readIndex = readIndex + 1;

	// if we're at the end of the array...
	if (readIndex >= numReadings) {
		// ...wrap around to the beginning:
		readIndex = 0;
	}

	// calculate the average:
	_analogValue = total / numReadings;
}
