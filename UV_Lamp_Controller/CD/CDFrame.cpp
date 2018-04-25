/*
 * CDFrame.cpp
 *
 *  Created on: Apr 24, 2018
 *      Author: sgeorgiadis
 */

#include "CDFrame.h"

CDFrame::CDFrame() {
	// TODO Auto-generated constructor stub
	elements = new CDElement[1];
}

CDFrame::CDFrame(uint8_t size) {
	elements = new CDElement[size];
}

CDFrame::~CDFrame() {
	// TODO Auto-generated destructor stub
}

