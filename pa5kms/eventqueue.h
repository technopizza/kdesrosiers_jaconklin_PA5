/*
 * eventqueue.h
 *
 *  Created on: Oct 8, 2018
 *      Author: jconklin
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

#include "customerevent.h"

class EventQueue{
private:
	int maxSize; //max size of array
	int mSize; //current size of the array
	CustomerEvent** eventArr; //array of pointers
	void heapify(int index); //used to rebuild heap

public:
	EventQueue(int size); //constructor
	void enqueue(CustomerEvent* event); //add item to queue
	CustomerEvent* dequeue(); //get front item off of queue
	int size(); //get number of items in queue
};

#endif /* EVENTQUEUE_H_ */
