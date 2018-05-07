/*
 * GUI.cpp
 *
 *  Created on: 29 Απρ 2018
 *      Author: Synodiporos
 */

#include "GUI.h"
#include "Arduino.h"

GUI::GUI(LiquidCrystal* lcd) : CDScreen(lcd) {

}

GUI::~GUI() {
	// TODO Auto-generated destructor stub
}

void GUI::init(){
	CDScreen::init(16, 2);

	//lcd->print("GUI Init");

	Serial.print("Frame is: ");
	Serial.println((int)frameMain);

	this->frameMain->addElementAt(label1, 0);
	this->frameMain->addElementAt(label2, 1);
	this->frameMain->addElementAt(label3, 2);
	this->frameMain->addElementAt(label4, 3);
	this->frameMain->addElementAt(label5, 4);
	this->frameMain->addElementAt(label6, 5);
	this->frameMain->addElementAt(label7, 6);
	this->frameMain->addElementAt(label8, 7);

	this->addFrame(frameMain);
	this->setCurrentFrameIndex(0);

	frameMain->setViewPosition(1);
}
