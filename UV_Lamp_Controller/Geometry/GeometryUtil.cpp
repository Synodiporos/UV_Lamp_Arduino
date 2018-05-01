/*
 * GeometryUtil.cpp
 *
 *  Created on: 27 Απρ 2018
 *      Author: Synodiporos
 */

#include "GeometryUtil.h"

GeometryUtil::GeometryUtil() {
	// TODO Auto-generated constructor stub

}

GeometryUtil::~GeometryUtil() {
	// TODO Auto-generated destructor stub
}

Coordinates* GeometryUtil::indexToCoordinates(
		unsigned short int i, uint8_t columns){
	return new Coordinates(i%columns, i/columns);
}

unsigned short int GeometryUtil::coordinatesToIndex(
		Coordinates* coords,	uint8_t columns){
	return coords->getX() + (columns*coords->getY());
}
