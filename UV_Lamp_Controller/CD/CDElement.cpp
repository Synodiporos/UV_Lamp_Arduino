/*
 * CDElement.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDElement.h"
#include "Arduino.h"

CDElement::CDElement() {
	this->label = new char[0];
}

CDElement::CDElement(char* label) {
	this->label = label;
}

CDElement::~CDElement() {
	delete size;
}

void CDElement::setLabel(char* label){
	this->label = label;
}

char* CDElement::getLabel(){
	return this->label;
}

void CDElement::setSize(Dimension* size){
	this->size = size;
}

void CDElement::setSize(uint8_t width, uint8_t height){
	this->size = new Dimension(width, height);
}

Dimension* CDElement::getSize(){
	return this->size;
}

void CDElement::print(LiquidCrystal* lcd){
	Serial.print("Printing Element: ");
	Serial.println((int)this);

	lcd->print(getLabel());
}

void CDElement::validate(){

}
