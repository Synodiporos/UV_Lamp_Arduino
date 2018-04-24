/*
 * BuzzerMelody.cpp
 *
 *  Created on: 22 Απρ 2018
 *      Author: Synodiporos
 */

#include <Arduino.h>
#include "BuzzerMelody.h"

BuzzerMelody::BuzzerMelody(uint8_t pinNumber) :
	_pinNumber(pinNumber){
	// TODO Auto-generated constructor stub
}

BuzzerMelody::BuzzerMelody(uint8_t pinNumber, BuzzerTone* headTone) :
	_pinNumber(pinNumber), _headTone(headTone){
	// TODO Auto-generated constructor stub
}

BuzzerMelody::BuzzerMelody(uint8_t pinNumber, BuzzerTone* headTone, short int iterations) :
	_pinNumber(pinNumber), _headTone(headTone){
	this->setIterations(iterations);
}

BuzzerMelody::~BuzzerMelody() {
	// TODO Auto-generated destructor stub
}

uint8_t BuzzerMelody::getPinNumber(){
	return this->_pinNumber;
}

void BuzzerMelody::setIterations(short int iterations){
	this->_iterations = iterations;
	this->_iterTBP = 0;
}

short int BuzzerMelody::getIterations(){
	return this->_iterations;
}

void BuzzerMelody::setHeadTone(BuzzerTone* headTone){
	this->_headTone = headTone;
}

BuzzerTone* BuzzerMelody::getHeadTone(){
	return this->_headTone;
}

BuzzerTone* BuzzerMelody::getCurrentTone(){
	return this->_currentTone;
}

void BuzzerMelody::play(){
	this->_state = 2;
	_interval = 0;
	playCurrentTone();
}

void BuzzerMelody::pause(){
	this->_state = 1;
	noTone(_pinNumber);
}

void BuzzerMelody::stop(){
	this->_state = 0;
	_currentTone = _headTone;
	_interval = 0;
	_iterTBP = _iterations;
	noTone(_pinNumber);
}

void BuzzerMelody::playNextTone(){
	_interval = 0;
	//Current Tone has next tone
	if(_currentTone->hasNext()){
		_currentTone = _currentTone->getNextTone();
		playCurrentTone();
	}
	//Current Tone has no next tone
	else{
		//There are remaining iterations to be performed
		if(_iterTBP==-1 || _iterTBP<_iterations)	{
			_currentTone = _headTone;
			_iterTBP++;
			playCurrentTone();
		}
		//There are NO remaining iterations
		else{
			_currentTone = _currentTone->getNextTone();
			stop();
		}
	}
}

void BuzzerMelody::playCurrentTone(){
	playTone(_currentTone);
}

void BuzzerMelody::resumeFromCurrent(){

}

void BuzzerMelody::playTone(BuzzerTone* _tone){
	unsigned short int freq = _tone->getFrequency();
	if(freq>0)
		tone(_pinNumber, freq);
	else
		noTone(_pinNumber);

	Serial.print("Play Tone: ");
		Serial.println(freq);
}

void BuzzerMelody::validate(){
	if(_state==2){
		_interval = _interval + (millis() - _millis);
		if(_interval >= _currentTone->getDuration()){
			playNextTone();
		}
	}
	else if(_state==1){

	}
	_millis = millis();
}
