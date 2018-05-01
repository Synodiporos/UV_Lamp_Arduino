/*
 * CDElement.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDELEMENT_H_
#define CD_CDELEMENT_H_
#include <string>
#include "../Geometry/Dimension.h"
#include <LiquidCrystal.h>

class CDElement {
public:
	CDElement();
	CDElement(std::string label);
	virtual ~CDElement();

	void setLabel(std::string label);
	std::string getLabel();
	void setSize(Dimension size);
	void setSize(uint8_t width, uint8_t height);
	Dimension* getSize();

	void print(LiquidCrystal lcd);
	void validate();

private:
	std::string label;
	Dimension* size = new Dimension();
};

#endif /* CD_CDELEMENT_H_ */
