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
	this->_remainingIter = iterations;
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
	this->_state = 3;
	tone(getPinNumber(), getHeadTone()->getFrequency());
}

void BuzzerMelody::resume(){
	this->_state = 2;
}

void BuzzerMelody::pause(){
	this->_state = 1;
	noTone(getPinNumber());
}

void BuzzerMelody::stop(){
	this->_state = 0;
	noTone(getPinNumber());
	_currentTone = _headTone;
	_millis = 0;
	_remainingIter = _iterations;
}

void BuzzerMelody::playNextTone(){
	_millis = 0;
	//Current Tone has next tone
	if(_currentTone->hasNext()){
		_currentTone = _currentTone->getNextTone();
		playCurrentTone();
	}
	//Current Tone has no next tone
	else{
		//There are remaining iterations to be performed
		if(_remainingIter>=_iterations)	{
			_currentTone = _headTone;
			_remainingIter--;
			playCurrentTone();
		}
		//There are NO remaining iterations
		else{
			_currentTone = _currentTone->getNextTone();
			_remainingIter = _iterations;
			stop();
		}
	}
}

void BuzzerMelody::playCurrentTone(){

}

void BuzzerMelody::resumeFromCurrent(){

}

void BuzzerMelody::validate(){
	if(_state==3){
		if(_currentTone->getDuration()>=_millis){
			playNextTone();
		}
	}
	else if(_state==2){

	}
	_millis = millis();
}
