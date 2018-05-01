/*
 * GUI.h
 *
 *  Created on: 29 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef VIEW_GUI_H_
#define VIEW_GUI_H_
#include "../CD/CDScreen.h"
#include "../CD/CDFrame.h"
#include "../CD/CDElement.h"
//#include "../CD/CDScreen.h";
#include <LiquidCrystal.h>
#include <string>

class GUI : public CDScreen{
public:
	CDFrame frameMain();
	CDFrame frameMenu1();
	CDElement* label1 = new CDElement("label1");
	CDElement* label2 = new CDElement("label2");


	GUI();
	GUI(LiquidCrystal* lcd);
	virtual ~GUI();

	void init();
};

#endif /* VIEW_GUI_H_ */
