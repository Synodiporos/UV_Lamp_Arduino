/*
 * CDScreen.h
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#ifndef CD_CDSCREEN_H_
#define CD_CDSCREEN_H_
class CDFrame;
#include "CDFrame.h"
#include <LiquidCrystal.h>

class CDScreen {
public:
	CDScreen(LiquidCrystal* lcd);
	CDScreen(LiquidCrystal* lcd, uint8_t capacity);
	virtual ~CDScreen();
	void init(uint8_t cols, uint8_t rows);
	uint8_t getColumns();
	uint8_t getRows();
	void addFrame(CDFrame* frame);
	void addFrameAt(CDFrame* frame, uint8_t index);
	void removeFrameAt(uint8_t index);
	void removeFrame(CDFrame* frame);
	CDFrame* getFrameAt(uint8_t index);
	void setCurrentFrameIndex(uint8_t index);
	void setCurrentFrame(CDFrame* frame);
	CDFrame* getCurrentFrame();

	void printCurrentFrame();
	void printFrame(CDFrame* frame);

	void print();

protected:
	LiquidCrystal* lcd;

private:
	uint8_t capacity = 0;
	uint8_t size = 0;
	CDFrame** frames;
	uint8_t currentFrameIndex = -1;
	uint8_t columns = 0;
	uint8_t rows = 0;

	void addingFrame(CDFrame* frame);
};

#endif /* CD_CDSCREEN_H_ */
