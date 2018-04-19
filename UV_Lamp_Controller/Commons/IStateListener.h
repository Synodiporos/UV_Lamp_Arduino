/*
 * IStateListener.h
 *
 *  Created on: 27 Ξ�Ξ±Ο� 2018
 *      Author: Synodiporos
 */

#ifndef ISTATELISTENER_H_
#define ISTATELISTENER_H_

class IStateListener {
public:
	IStateListener();
	virtual ~IStateListener();
	virtual void stateChanged(void* source, void* stateChanged) = 0;
};

#endif /* ISTATELISTENER_H_ */
