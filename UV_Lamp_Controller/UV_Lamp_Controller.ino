#include "Arduino.h"

#include <LiquidCrystal.h>
#include "Button/ButtonHandler.h"
#include "Button/Button.h"
#include "InputManager.h"
//#include "IRSensor.h"
//#include "Buzzer/BuzzerPlayer.h"
//#include "Buzzer/BuzzerTone.h"
//#include "Buzzer/Pitches.h"
//#include "CD/CDFrame.h"
//#include "CD/CDElement.h"
//#include "CD/CDOption.h"
//#include <string>


// the setup routine runs once when you press reset:
InputManager* inputManager;
//InputManager* inputManager;
Button* buttonD = new Button(A0);
Button* buttonC = new Button(A1);
Button* buttonB = new Button(A2);
Button* buttonA = new Button(A3);
//IRSensor* sensor = new IRSensor(5, 70, 20);

//BuzzerPlayer* buzzerPlayer = new BuzzerPlayer(6, 2);

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//CDFrame* frame = new CDFrame(lcd, 4);

unsigned long time = 0;

void setup() {
	Serial.begin(9600);
	Serial.println("Starting...");

	//inputManager = new InputManager();
	inputManager = new InputManager();
	//sensor->setStateListener(inputManager);

	/*Serial.println((unsigned int)buttonHandler);
	Serial.println((unsigned int)inputManager);
	Serial.println((unsigned int)buttonD);
	Serial.println((unsigned int)buttonC);
	Serial.println((unsigned int)buttonB);
	Serial.println((unsigned int)buttonA);*/


	inputManager->addButton(buttonD);
	inputManager->addButton(buttonC);
	inputManager->addButton(buttonB);
	inputManager->addButton(buttonA);
	inputManager->activate();

	createGUI();

	//============== BuzzerPlayer init
	//BuzzerTone* t1 = new BuzzerTone(NOTE_C6, 500);
	//buzzerPlayer->setHeadTone(t1);
	//buzzerPlayer->play();



	time = millis();
	Serial.println("Started!");
}

void loop() {

	//delay(10);
	inputManager->validate();
	//sensor->validate();
	//buzzerPlayer->validate();
	//frame->validate();
}

void createGUI(){
	/*lcd.setCursor(0, 0);
	CDElement elem1("elem1");
	CDOption opt1("opt1");
	CDOption opt2("opt2");
	CDOption opt3("opt3");

	std::string txt = "Test Text!";

	frame->addElemenentAtIndex(&elem1, 0);
	frame->addElemenentAtIndex(&opt1, 1);
	frame->addElemenentAtIndex(&opt2, 2);
	frame->addElemenentAtIndex(&opt3, 3);

	frame->begin(16,2);
	lcd.print("Start!");

	frame->print();*/
}
