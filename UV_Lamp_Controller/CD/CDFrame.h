/*
 * CDFrame.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDFRAME_H_
#define CD_CDFRAME_H_

class CDScreen;
#include "CDScreen.h"
#include "../Geometry/Coordinates.h"
#include "../Geometry/GeometryUtil.h"
#include "CDElement.h"
#include <LiquidCrystal.h>
#include <stdint.h>

class CDFrame {
public:
	CDFrame();
	CDFrame(uint8_t capacity);
	CDFrame(uint8_t cols, uint8_t rows);
	CDFrame(uint8_t capacity, uint8_t cols, uint8_t rows);
	virtual ~CDFrame();

	void addElement(CDElement* element);
	void addElementAt(CDElement* element, uint8_t index);
	void addElementAt(CDElement* element, uint8_t x, uint8_t y);
	void removeElement(CDElement* element);
	void removeElementAt(uint8_t index);
	void removeElementAt(uint8_t x, uint8_t y);
	CDElement* getElementAt(uint8_t index);
	CDElement* getElementAt(uint8_t x, uint8_t y);

	void setColumns(uint8_t columns);
	uint8_t getColumns();
	void setRows(uint8_t rows);
	uint8_t getRows();
	void setLayout(uint8_t cols, uint8_t rows);
	uint8_t getViewPosition();
	void setViewPosition(uint8_t viewPosition);
	uint8_t columnsToVerticalCell(uint8_t cols);

	void setParent(CDScreen* parent);
	CDScreen* getParent();

	void print(LiquidCrystal* lcd);
	void validate();

private:
	uint8_t columns = 1;
	uint8_t rows = 1;
	uint8_t position = 0;
	uint8_t size = 0;
	uint8_t capacity = 0;
	CDElement** elements;
	CDScreen* parent = nullptr;

	Coordinates* indexToCoordinates(unsigned short int i);
	unsigned short int coordinatesToIndex(Coordinates* coords);

};

#endif /* CD_CDFRAME_H_ */
