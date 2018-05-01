/*
 * CDFrame.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDFrame.h"

CDFrame::CDFrame() {
	// TODO Auto-generated constructor stub
	elements = new CDElement*[1];
	size = 0;
}

CDFrame::CDFrame(uint8_t capacity) {
	if(capacity>0)
		elements = new CDElement*[capacity];
	size = 0;
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

void CDFrame::addElement(CDElement* element){
	elements[size] = element;
	size++;
}

void CDFrame::addElementAt(CDElement* element, uint8_t index){
	if(index>0 && index<capacity){
		elements[index] = element;
		size++;
	}
}

void CDFrame::addElementAt(CDElement* element, uint8_t x, uint8_t y){
	unsigned short int index =
			coordinatesToIndex(new Coordinates(x, y));
	this->addElementAt(element, index);
}

void CDFrame::removeElement(CDElement* element){
	for(short int i=0; i<=capacity; i++){
		CDElement* elem = elements[i];
		if(elem && elem==element){
			elements[i] = nullptr;
		}
	}
}

void CDFrame::removeElementAt(uint8_t index){
	if(index < capacity)
		elements[index] = nullptr;
}

void CDFrame::removeElementAt(uint8_t x, uint8_t y){
	unsigned short int index =
		coordinatesToIndex(new Coordinates(x, y));
	removeElementAt(index);
}

CDElement* CDFrame::getElementAt(uint8_t index){
	if(index<capacity)
		return this->elements[index];
	return nullptr;
}

CDElement* CDFrame::getElementAt(uint8_t x, uint8_t y){
	unsigned short int index =
			coordinatesToIndex(new Coordinates(x, y));
	return getElementAt(index);
}

uint8_t CDFrame::getColumns(){
	return this->columns;
}

uint8_t CDFrame::getRows(){
	return this->rows;
}

uint8_t CDFrame::getViewPosition(){
	return this->position;
}

void CDFrame::setViewPosition(uint8_t viewPosition){
	this->position = viewPosition;
	//
}

Coordinates* CDFrame::indexToCoordinates(unsigned short int i){
	return GeometryUtil::indexToCoordinates(i, columns);
}

unsigned short int CDFrame::coordinatesToIndex(Coordinates* coords){
	return GeometryUtil::coordinatesToIndex(coords, columns);
}

void CDFrame::print(LiquidCrystal lcd){
	for(short int i=0; i<=capacity; i++){
		CDElement* elem = elements[i];
		if(elem){
			elem->print(lcd);
		}
	}
}

void CDFrame::validate(){

}
