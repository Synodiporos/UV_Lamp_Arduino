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
	Coordinates(unsigned short int x, unsigned short int y);
	virtual ~Coordinates();

	void setX(unsigned short int x);
	unsigned short int getX(unsigned short int x);
	void setY(unsigned short int y);
	unsigned short int getY(unsigned short int y);
	Coordinates copy();

private:
	unsigned short int x = 0;
	unsigned short int y = 0;
};

#endif /* GEOMETRY_COORDINATES_H_ */
