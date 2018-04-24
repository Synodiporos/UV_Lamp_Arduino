/*
 * BuzzerMelody.cpp
 *
 *  Created on: 22 Ξ‘Ο€Ο� 2018
 *      Author: Synodiporos
 */

#include <Arduino.h>
#include "BuzzerMelody.h"

BuzzerMelody::BuzzerMelody(BuzzerTone* headTone) :
	_headTone(headTone){
	// TODO Auto-generated constructor stub
}

BuzzerMelody::BuzzerMelody(BuzzerTone* headTone, short int iterations) :
	_headTone(headTone){
	this->setIterations(iterations);
}

BuzzerMelody::~BuzzerMelody() {
	// TODO Auto-generated destructor stub
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
	noTone(_pinNumber);
}

void BuzzerMelody::playNextTone(){
	//Current Tone has next tone
	if(_currentTone->hasNext()){
		_currentTone = _currentTone->getNextTone();
		_interval = 0;
		playCurrentTone();
	}
	//Current Tone has no next tone
	else{
		//There are remaining iterations to be performed
		if(_remainingIter >= _iterations)	{
			_currentTone = _headTone;
			_remainingIter--;
			_interval = 0;
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
