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

Coordinates::Coordinates(short int x, short int y) {
	this->x = x;
	this->y = y;
}

Coordinates::~Coordinates() {
	// TODO Auto-generated destructor stub
}

void Coordinates::setX(short int x){
	this->x = x;
}

short int Coordinates::getX(short int x){
	return this->x;
}

void Coordinates::setY(short int y){
	this->y = y;
}

short int Coordinates::getY(short int y){
	return this->y;
}

Coordinates Coordinates::copy(){
	return new Coordinates(this->x, this->y);
}
