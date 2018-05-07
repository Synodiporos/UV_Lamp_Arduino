/*
 * CDFrame.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDFrame.h"
#include "Arduino.h"

CDFrame::CDFrame() {
	// TODO Auto-generated constructor stub
	this->capacity = 1;
	elements = new CDElement*[1];
	size = 0;
}

CDFrame::CDFrame(uint8_t capacity) {
	this->capacity = capacity;
	if(capacity>0)
		elements = new CDElement*[capacity];
	size = 0;
}

CDFrame::CDFrame(uint8_t cols, uint8_t rows){
	this->columns = cols;
	this->rows = rows;
	elements = new CDElement*[1];
	this->capacity = 1;
	size = 0;
}

CDFrame::CDFrame(uint8_t capacity, uint8_t cols, uint8_t rows){
	this->capacity = capacity;
	if(capacity>0)
		elements = new CDElement*[capacity];
	size = 0;
	this->columns = cols;
	this->rows = rows;
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

void CDFrame::addElement(CDElement* element){
	elements[size] = element;
	size++;
}

void CDFrame::addElementAt(CDElement* element, uint8_t index){
	if(index<capacity){
		elements[index] = element;
		size++;

		Serial.print("Adding Element: ");
		Serial.print((int) element);
		Serial.print(" into CDFrame: ");
		Serial.print((int)this);
		Serial.print(" at: ");
		Serial.println((int)index);
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

void CDFrame::setColumns(uint8_t columns){
	this->columns = columns;
}

uint8_t CDFrame::getColumns(){
	return this->columns;
}


void CDFrame::setRows(uint8_t rows){
	this->rows = rows;
}

uint8_t CDFrame::getRows(){
	return this->rows;
}

void CDFrame::setLayout(uint8_t cols, uint8_t rows){
	this->columns = cols;
	this->rows = rows;
}

uint8_t CDFrame::getViewPosition(){
	return this->position;
}

void CDFrame::setViewPosition(uint8_t viewPosition){
	this->position = viewPosition;
	//
}

void CDFrame::setParent(CDScreen* parent){
	this->parent = parent;
}

CDScreen* CDFrame::getParent(){
	return this->parent;
}

Coordinates* CDFrame::indexToCoordinates(unsigned short int i){
	return GeometryUtil::indexToCoordinates(i, columns);
}

unsigned short int CDFrame::coordinatesToIndex(Coordinates* coords){
	return GeometryUtil::coordinatesToIndex(coords, columns);
}

uint8_t CDFrame::columnsToVerticalCell(uint8_t cols){
	CDScreen* parent = getParent();
	if(parent){
		uint8_t c = parent->getColumns();
		return (c/columns)*cols;
	}
	return cols;
}

void CDFrame::print(LiquidCrystal* lcd){
	for(short int i=0; i<size; i++){
		CDElement* elem = elements[i];
		if(elem){
			Coordinates* c = indexToCoordinates(i);
			uint8_t x = columnsToVerticalCell(c->getX());
			lcd->setCursor(x, c->getY());

			Serial.print("Set cursor: [");
			Serial.print(x);
			Serial.print(",");
			Serial.print(c->getY());
			Serial.println("]");

			elem->print(lcd);
		}
	}
}

void CDFrame::printVisibleElements(LiquidCrystal* lcd){
	uint8_t start = this->position*this->columns;
	uint8_t end = start + this->rows*this->columns;
	for(short int i=start; i<end; i++){
		CDElement* elem = elements[i];
		if(elem){
			Coordinates* c = indexToCoordinates(i);
			uint8_t x = columnsToVerticalCell(c->getX());
			lcd->setCursor(x, c->getY()-position);

			Serial.print("Set cursor: [");
			Serial.print(x);
			Serial.print(",");
			Serial.print(c->getY()-position);
			Serial.println("]");

			elem->print(lcd);
		}
	}
}

void CDFrame::validate(){

}
