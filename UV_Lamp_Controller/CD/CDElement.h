/*
 * CDElement.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDELEMENT_H_
#define CD_CDELEMENT_H_
//#include <string>
#include "../Geometry/Dimension.h"
#include <LiquidCrystal.h>

class CDElement {
public:
	CDElement();
	CDElement(char* label);
	virtual ~CDElement();

	void setLabel(char* label);
	char* getLabel();
	void setSize(Dimension* size);
	void setSize(uint8_t width, uint8_t height);
	Dimension* getSize();

	void print(LiquidCrystal* lcd);
	void validate();

private:
	char* label;
	Dimension* size = new Dimension();
};

#endif /* CD_CDELEMENT_H_ */
