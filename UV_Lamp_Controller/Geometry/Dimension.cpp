/*
 * Dimension.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#include "Dimension.h"

Dimension::Dimension() {
	// TODO Auto-generated constructor stub

}

Dimension::Dimension(unsigned short int width, unsigned short int height){
	this->height = height;
	this->width = width;
}

Dimension::~Dimension() {
	// TODO Auto-generated destructor stub
}

void Dimension::setWidth(unsigned short int width){
	this->width = width;
}
unsigned short int Dimension::getWidth(){
	return this->width;
}

void Dimension::setHeight(unsigned short int height){
	this->height = height;
}

unsigned short int Dimension::getHeight(){
	return this->height;
}

Dimension Dimension::copy(){
	return new Dimension(getWidth(), getHeight());
}

