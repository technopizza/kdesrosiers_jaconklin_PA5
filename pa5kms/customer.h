/*
 * customerevent.h
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include "customerevent.h"
class CustomerEvent;
class Customer{
private:
	CustomerEvent* arrival;
public:
	Customer(float priority);
	CustomerEvent* getArrival();
};


#endif /* CUSTOMER_H_ */
