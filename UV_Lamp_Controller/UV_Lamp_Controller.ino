#include "Arduino.h"

#include <LiquidCrystal.h>
#include "Button/ButtonHandler.h"
#include "Button/Button.h"
#include "InputManager.h"
#include "AnalogInput/ToggleAnalogInput.h"
#include "Buzzer/BuzzerMelody.h"
#include "Buzzer/BuzzerTone.h"
#include "Buzzer/Pitches.h"
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
ToggleAnalogInput* irSensor = new ToggleAnalogInput(5, 6, 30, 50);

BuzzerMelody* buzzerMelody ;

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//CDFrame* frame = new CDFrame(lcd, 4);

unsigned long int _millis = 0;

void setup() {
	Serial.begin(9600);
	Serial.println("Starting ...");

	//inputManager = new InputManager();
	inputManager = new InputManager();
	//sensor->setStateListener(inputManager);


	inputManager->addButton(buttonD);
	inputManager->addButton(buttonC);
	inputManager->addButton(buttonB);
	inputManager->addButton(buttonA);
	irSensor->setStateListener(inputManager);
	inputManager->activate();

	Serial.println("GUI init...");
	createGUI();

	//============== BuzzerPlayer init
	BuzzerTone* t1 = new BuzzerTone(NOTE_C6, 1000);
	BuzzerTone* t2 = new BuzzerTone(NOTE_E6, 1000);
	//BuzzerTone* t3 = new BuzzerTone(NOTE_BREAK, 250);
	//BuzzerTone* t4 = new BuzzerTone(NOTE_G6, 250);
	//BuzzerTone* t5 = new BuzzerTone(NOTE_C7, 1000);
	t1->setNextTone(t2);
	//t2->setNextTone(t3);
	//t3->setNextTone(t4);
	//t4->setNextTone(t5);
	buzzerMelody = new BuzzerMelody(6, t1, 3);
	//buzzerMelody->setHeadTone(t1);
	//buzzerMelody->setIterations(3);
	buzzerMelody->play();
	Serial.println("Buzzer init...");

	Serial.println("Started!");
	_millis = millis();
}


void loop() {
	if(buzzerMelody->getState()==2 && millis()-_millis>=1500){
		//buzzerMelody->stop();
		_millis = millis();
	}
	if(buzzerMelody->getState()==0 && millis()-_millis>=3000){
		buzzerMelody->play();
		_millis = millis();
	}

	//delay(10);
	inputManager->validate();
	irSensor->validate();
	buzzerMelody->validate();
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
