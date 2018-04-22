/*
 * AnalogInput.cpp
 *
 *  Created on: Apr 20, 2018
 *      Author: sgeorgiadis
 */

#include "AnalogInput.h"

<<<<<<< Upstream, based on origin/master
AnalogInput::AnalogInput(uint8_t pinNumber) : _pinNumber(pinNumber){
	// TODO Auto-generated constructor stub

=======
AnalogInput::AnalogInput(uint8_t pinNumber)
	: _pinNumber(pinNumber){
	readings = new unsigned short int[1];
	clearRecordsTable();
}

AnalogInput::AnalogInput(uint8_t pinNumber, uint8_t spv)
	: _pinNumber(pinNumber){
	readings = new unsigned short int[spv];
	numReadings = spv;
	clearRecordsTable();
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
}

AnalogInput::~AnalogInput() {
	// TODO Auto-generated destructor stub
}

void AnalogInput::clearRecordsTable(){
	for (int thisReading = 0; thisReading < numReadings; thisReading++) {
		readings[thisReading] = 0;
	}
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
<<<<<<< Upstream, based on origin/master
	_analogValue = total / numReadings;
=======
	unsigned short int average = total / numReadings;

	//Check if average value has changed
	if(average != _analogValue)
		notifyPropertyChanged();
	//Update the analogeValue value
	_analogValue = average;
>>>>>>> 51b26b2 Input controll completed AnalogeInput, ToggleAnalogInput, InputManager & input events are done!
}
