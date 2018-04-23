/*
 * BuzzerMelody.h
 *
 *  Created on: 22 Ξ‘Ο€Ο� 2018
 *      Author: Synodiporos
 */

#ifndef BUZZER_BUZZERMELODY_H_
#define BUZZER_BUZZERMELODY_H_
#include <stdint.h>
#include "BuzzerTone.h"

class BuzzerMelody {
public:
	BuzzerMelody(BuzzerTone* headTone);
	BuzzerMelody(BuzzerTone* headTone, short int iterations);
	virtual ~BuzzerMelody();

	void setIterations(short int iterations);
	short int getIterations();
	void setHeadTone(BuzzerTone* headTone);
	BuzzerTone* getHeadTone();
	BuzzerTone* getCurrentTone();

	void play();
	void resume();
	void pause();
	void stop();

	void validate();

private:
	uint8_t _pinNumber = 0;
	//0=stop, 1=pause, 2=resume, 3=play
	uint8_t _state = 0;
	short int _iterations = 1;
	short int _remainingIter = 1;
	unsigned long int _millis = 0;
	BuzzerTone* _headTone;
	BuzzerTone* _currentTone = 0;

	void playNextTone();
	void resumeFromCurrent();
	void playCurrentTone();
};

#endif /* BUZZER_BUZZERMELODY_H_ */
