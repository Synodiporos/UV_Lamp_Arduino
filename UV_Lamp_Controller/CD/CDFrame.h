/*
 * CDFrame.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_
#include "../Geometry/Coordinates.h"
#include "CDElement.h"
#include <stdint.h>

class CDFrame {
public:
	CDFrame();
	CDFrame(uint8_t size);
	virtual ~CDFrame();

	void print();
	void validate();

private:
	uint8_t columns = 1;
	uint8_t rows = 2;
	uint8_t position = 0;
	CDElement* elements;

	Coordinates indexToCoordinated(unsigned short int);
	unsigned short int coordinatedToIndex(Coordinates coords);

};

#endif /* CD_CDFRAME_H_ */
