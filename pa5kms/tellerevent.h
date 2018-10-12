/*
 * tellerevent.h
 *
 *  Created on: Oct 6, 2018
 *      Author: kdesrosiers
 */

#ifndef TELLEREVENT_H_ //.
#define TELLEREVENT_H_
#include "event.h"
class TellerEvent : public Event {
public:
	void action();
	~TellerEvent();
};

#endif /* TELLEREVENT_H_ */
