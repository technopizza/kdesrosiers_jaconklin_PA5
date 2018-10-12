/*
 * customer.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */
#include "customer.h"
#include "customerevent.h"
Customer::Customer(float priority){
	arrival = new CustomerEvent(priority, this);
}

CustomerEvent* Customer::getArrival() {
	return arrival;
}
