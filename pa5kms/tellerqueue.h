/*
 * tellerqueue.h
 *
 *  Created on: Oct 8, 2018
 *      Author: kdesrosiers
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_ //.
#include "customer.h"
class Customer;
class TellerQueue {
private:
	/* defines the struct for a node in the linked list */

	struct Node {
		Customer* acustomer;
		Node* nextCustomer;
	};

	Node *head; //the first node in the line
	Node *tail; //the last node in the line
	int size; //the number of nodes in the line
public:
	TellerQueue();
	void addToLine(Customer* acustomer);
	Customer* removeFromLine();
	int sizeOfQueue();
};

#endif /* TELLERQUEUE_H_ */
