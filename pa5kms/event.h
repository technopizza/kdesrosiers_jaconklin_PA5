/*
 * event.h
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "tellerqueue.h"
class TellerQueue;
//abstract class
class Event{
protected:
	float priority;
	virtual void action(TellerQueue* queue) = 0; //pure, must be overridden
public:
	Event();
	//static float getTime(); //a function to get the time
	//static void setTime(float x); //a function set the time
	virtual ~Event(){} //virtual destructor
	float getPriority();
};


#endif /* EVENT_H_ */
