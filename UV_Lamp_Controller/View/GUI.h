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
//#include <string>

class GUI : public CDScreen{
public:
	CDFrame* frameMain = new CDFrame(8, 2, 2);
	CDFrame frameMenu1;
	CDElement* label1 = new CDElement("label1");
	CDElement* label2 = new CDElement("label2");
	CDElement* label3 = new CDElement("label3");
	CDElement* label4 = new CDElement("label4");
	CDElement* label5 = new CDElement("label5");
	CDElement* label6 = new CDElement("label6");
	CDElement* label7 = new CDElement("label7");
	CDElement* label8 = new CDElement("label8");

	GUI(LiquidCrystal* lcd);
	virtual ~GUI();

	void init();
};

#endif /* VIEW_GUI_H_ */
