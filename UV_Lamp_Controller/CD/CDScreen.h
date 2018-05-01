/*
 * CDScreen.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDSCREEN_H_
#define CD_CDSCREEN_H_
#include <LiquidCrystal.h>
#include "CDFrame.h"

class CDScreen {
public:
	CDScreen();
	CDScreen(LiquidCrystal* lcd);
	virtual ~CDScreen();
	void addFrame(CDFrame* frame);
	void removeFrame(CDFrame* frame);
	CDFrame* getFrameAt(uint8_t index);
	void setCurrentFrame(uint8_t index);
	void setCurrentFrame(CDFrame frame);
	CDFrame* getCurrentFrame();

	void printCurrentFrame();
	void printFrame(CDFrame* frame);

	void print();

private:
	LiquidCrystal* lcd;
	CDFrame* frames;
	uint8_t currentFrameIndex = -1;

};

#endif /* CD_CDSCREEN_H_ */
