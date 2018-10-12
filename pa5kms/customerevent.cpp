/*
 * customerevent.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: kdesrosiers
 */
#include "customerevent.h"
#include "customer.h"

CustomerEvent::CustomerEvent(float t, Customer* c){
	priority = t;
	customer = c;
}
float CustomerEvent::getPriority(){
	return priority;
}
void CustomerEvent::action(TellerQueue* line){
	line->addToLine((Customer *) customer);
}
/**
 *Get this customer events associated customer
 *@return the Customer object
 *@author Jason Conklin
 */
Customer* CustomerEvent::getCustomer(){
	return customer;
}
