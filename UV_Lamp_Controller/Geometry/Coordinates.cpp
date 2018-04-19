/*
 * Coordinates.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#include "Coordinates.h"

Coordinates::Coordinates() {
	// TODO Auto-generated constructor stub

}

Coordinates::Coordinates(unsigned short int x, unsigned short int y) {
	this->x = x;
	this->y = y;
}

Coordinates::~Coordinates() {
	// TODO Auto-generated destructor stub
}

void Coordinates::setX(unsigned short int x){

}

unsigned short int Coordinates::getX(unsigned short int x){
	return this->x;
}

void Coordinates::setY(unsigned short int y){

}

unsigned short int Coordinates::getY(unsigned short int y){
	return this->y;
}

Coordinates Coordinates::copy(){
	return new Coordinates(this->x, this->y);
}
