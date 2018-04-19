/*
 * Coordinates.h
 *
 *  Created on: Apr 19, 2018
 *      Author: sgeorgiadis
 */

#ifndef GEOMETRY_COORDINATES_H_
#define GEOMETRY_COORDINATES_H_

class Coordinates {
public:
	Coordinates();
	Coordinates(short int x, short int y);
	virtual ~Coordinates();

	void setX(short int x);
	short int getX();
	void setY(short int y);
	short int getY();
	Coordinates copy();

private:
	short int x = 0;
	short int y = 0;
};

#endif /* GEOMETRY_COORDINATES_H_ */
