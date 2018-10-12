/*
 * tellerqueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: kdesrosiers
 */
#include "tellerqueue.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/**constructor for the teller queue
 */
TellerQueue::TellerQueue() {
	head = NULL;
	tail = NULL;
	size = 0;
}


/**adds a new customer to the queue
 * @param ex a pointer to a customer
 */

void TellerQueue::addToLine(Customer* acustomer) {
	Node *n = new Node();
	n->acustomer = acustomer;
	n->nextCustomer = NULL;
	if (head == NULL) {
		head = n;
		tail = n;
	} else {
		tail->nextCustomer = n;
		tail = n;
	}
	size++;
}

/**removes a customer from the queue
 * @author kdesrosiers
 */
Customer* TellerQueue::removeFromLine() {
	//cout << "TELLERQUEUE REMOVE HEAD -- BEGIN" << endl;
	//cout << "Current Head: " << head->acustomer->getArrival() << endl;
	Node* temp = head;
	head = head->nextCustomer;
	//cout << "New Head: " << head->acustomer->getArrival() << endl;
	//cout << "TELLERQUEUE REMOVE HEAD -- END" << endl;
	size--;
	return temp->acustomer;
}

/*this function finds the size of the linked list
 * @return size the number of customers in the line
 * @author kdesrosiers
 */
int TellerQueue::sizeOfQueue() {
	return size;
}
