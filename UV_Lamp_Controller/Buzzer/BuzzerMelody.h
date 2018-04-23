/*
 * BuzzerMelody.h
 *
 *  Created on: 22 Απρ 2018
 *      Author: Synodiporos
 */

#ifndef BUZZER_BUZZERMELODY_H_
#define BUZZER_BUZZERMELODY_H_
#include <stdint.h>

class BuzzerMelody {
public:
	BuzzerMelody();
	virtual ~BuzzerMelody();

	void play();
	void resume();
	void pause();
	void stop();

	void validate();

private:
	uint8_t pinNumber = 0;
	//0=stop, 1=pause, 2=resume, 3=play
	uint8_t state = 0;
	unsigned long int milis = 0;
};

#endif /* BUZZER_BUZZERMELODY_H_ */
