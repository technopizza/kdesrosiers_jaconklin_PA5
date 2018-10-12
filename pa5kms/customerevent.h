/*
 * customerevent.h
 *
 *  Created on: Oct 6, 2018
 *      Author: kdesrosiers _
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_
#include "event.h"
#include "customer.h"
#include "tellerqueue.h"
class Customer;
class TellerQueue;
class CustomerEvent{
private:
	float priority;
	Customer* customer;
public:
	CustomerEvent(float t, Customer* c);
	float getPriority();
	void action(TellerQueue* line);
	Customer* getCustomer();
	~CustomerEvent(){

	}
};

#endif /* CUSTOMEREVENT_H_ */
