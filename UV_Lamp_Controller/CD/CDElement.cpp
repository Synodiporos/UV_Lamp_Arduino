/*
 * CDElement.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDElement.h"

CDElement::CDElement() {
	this->label = "";
}

CDElement::CDElement(std::string label) {
	this->label = label;
}

CDElement::~CDElement() {
	delete size;
}

void CDElement::setLabel(std::string label){

}

std::string CDElement::getLabel(){
	return this->label;
}

void CDElement::setSize(Dimension size){

}

void CDElement::setSize(uint8_t width, uint8_t height){
	this->size = new Dimension(width, height);
}

Dimension* CDElement::getSize(){
	return this->size;
}

void CDElement::print(LiquidCrystal lcd){

}

void CDElement::validate(){

}
