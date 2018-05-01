/*
 * CDFrame.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_
#include "../Geometry/Coordinates.h"
#include "../Geometry/GeometryUtil.h"
#include "CDElement.h"
#include <LiquidCrystal.h>
#include <stdint.h>

class CDFrame {
public:
	CDFrame();
	CDFrame(uint8_t capacity);
	virtual ~CDFrame();

	void addElement(CDElement* element);
	void addElementAt(CDElement* element, uint8_t index);
	void addElementAt(CDElement* element, uint8_t x, uint8_t y);
	void removeElement(CDElement* element);
	void removeElementAt(uint8_t index);
	void removeElementAt(uint8_t x, uint8_t y);
	CDElement* getElementAt(uint8_t index);
	CDElement* getElementAt(uint8_t x, uint8_t y);

	uint8_t getColumns();
	uint8_t getRows();
	uint8_t getViewPosition();
	void setViewPosition(uint8_t viewPosition);


	void print(LiquidCrystal lcd);
	void validate();

private:
	uint8_t columns = 1;
	uint8_t rows = 2;
	uint8_t position = 0;
	uint8_t size = 0;
	uint8_t capacity = 0;
	CDElement** elements;

	Coordinates* indexToCoordinates(unsigned short int i);
	unsigned short int coordinatesToIndex(Coordinates* coords);

};

#endif /* CD_CDFRAME_H_ */
