/*
 * CDScreen.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDScreen.h"
#include "Arduino.h"

CDScreen::CDScreen(LiquidCrystal* _lcd) :
	lcd(_lcd){
	this->capacity = 1;
	this->frames = new CDFrame*[1];
}

CDScreen::CDScreen(LiquidCrystal* _lcd, uint8_t capacity) :
	lcd(_lcd){
	this->capacity = capacity;
	this->frames = new CDFrame*[capacity];
}

CDScreen::~CDScreen() {
	// TODO Auto-generated destructor stub
}

void CDScreen::init(uint8_t cols, uint8_t rows){
	this->columns = cols;
	this->rows = rows;
	if(this->lcd)
		this->lcd->begin(cols, rows);
}

uint8_t CDScreen::getColumns(){
	return this->columns;
}

uint8_t CDScreen::getRows(){
	return this->rows;
}

void CDScreen::addFrame(CDFrame* frame){
	if(size<capacity){
		this->frames[size] = frame;
		size++;
		addingFrame(frame);

		Serial.print("Adding Frame: ");
		Serial.print((int) frame);
		Serial.print(" into CDScreen: ");
		Serial.print((int)this);
		Serial.print(" at: ");
		Serial.println((int)size-1);
	}
}

void CDScreen::addFrameAt(CDFrame* frame, uint8_t index){
	if(index<capacity){
		this->frames[index] = frame;
		addingFrame(frame);

		Serial.print("Adding Frame: ");
		Serial.print((int) frame);
		Serial.print(" into CDScreen: ");
		Serial.print((int)this);
		Serial.print(" at: ");
		Serial.println((int)index);
	}
}

void CDScreen::addingFrame(CDFrame* frame){
	if(frame){
		frame->setParent(this);
		setCurrentFrameIndex(size-1);
	}
}

void CDScreen::removeFrameAt(uint8_t index){
	if(index<capacity){
		this->frames[index] = nullptr;
	}
}

void CDScreen::removeFrame(CDFrame* frame){
	for(int i=0; i<capacity; i++){
		CDFrame* f = this->frames[i];
		if(frame!=nullptr && frame==f){
			frames[i] = nullptr;
			return;
		}
	}
}

CDFrame* CDScreen::getFrameAt(uint8_t index){
	if(index<capacity)
		return this->frames[index];
	return nullptr;
}

void CDScreen::setCurrentFrameIndex(uint8_t index){
	if(index<capacity)
		this->currentFrameIndex = index;
}

void CDScreen::setCurrentFrame(CDFrame* frame){
	for(int i=0; i<capacity; i++){
		CDFrame* f = this->frames[i];
		if(frame!=nullptr && frame==f){
			this->currentFrameIndex = i;
			return;
		}
	}
}

CDFrame* CDScreen::getCurrentFrame(){
	return this->frames[currentFrameIndex];
}

void CDScreen::printCurrentFrame(){
	printFrame(getCurrentFrame());
}

void CDScreen::printFrame(CDFrame* frame){
	if(frame){
		frame->print(this->lcd);
	}
}

void CDScreen:: print(){
	printCurrentFrame();
}
