/*
 * eventqueue.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: jconklin
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "eventqueue.h"
using namespace std;

/** Constructor for EventQueue
 * @param size the size of the queue
 * @author Jason Conklin
 */
EventQueue::EventQueue(int size) {
	maxSize = size;
	mSize = 0;
	eventArr = new CustomerEvent*[size];
}

/** Get number of items in the queue
 * @return number of items in queue
 * @author Jason Conklin
 */
int EventQueue::size(){
	return mSize;
}

/** Recursively re-organize heap structure starting at given index
 * @param index the starting index for recursive reorganization
 * @author Jason Conklin
 */
void EventQueue::heapify(int index) {
	//cout << "\tStarting Heapify at index " << index << endl;
	int min = index;
	int leftChild = 2 * index + 1;
	int rightChild = leftChild + 1;
	//get the smallest value from among current node and its two children
	if ((leftChild < mSize) && (eventArr[leftChild]->getPriority()< eventArr[index]->getPriority())) {
		min = leftChild;
	}
	if ((rightChild < mSize)
			&& (eventArr[rightChild]->getPriority()
					< eventArr[min]->getPriority())) {
		min = rightChild;
	}
	//if one of children is smaller, recursively heapify
	if (min != index) {
		//cout << "\t\tSwapping event at " << index << " (Priority " << eventArr[index]->getPriority() << ") with event at " << min << " (Priority " << eventArr[min]->getPriority() << ")" << endl;

		//swap child and parent positions
		CustomerEvent* tmp = eventArr[index];
		eventArr[index] = eventArr[min];
		eventArr[min] = tmp;

		heapify(min);
	}
}
/** Add a new item to the queue into its proper place in the heap
 * @param Event the event to add to the queue
 * @author Jason Conklin
 */
void EventQueue::enqueue(CustomerEvent* event) {
	//cout << "BEGIN ENQUEUE" << endl;
	if (mSize < maxSize) {
		int i = mSize;
		//cout << "Enqueuing event with priority " << event->getPriority() << endl;
		eventArr[i] = event;
		//move new event back up the tree to correct spot by swapping
		int parent= ((int) ((i - 1) / 2));
		while ((i > 0) && (eventArr[i]->getPriority() < eventArr[parent]->getPriority())) {
			//cout << "swapping event at index " << i << " (priority " << eventArr[i]->getPriority() << ") with index " << parent << " (priority " << eventArr[parent]->getPriority() << endl;
			//swap parent and smaller child
			CustomerEvent* tmp = eventArr[i];
			eventArr[i] = eventArr[parent];
			eventArr[parent] = tmp;

			//update indexes
			i = parent;
			parent = ((int) ((i - 1) / 2));
		}
	}
		mSize++;
		//cout << "END ENQUEUE" << endl;
	}


/** Get the next item in the queue and rebuild the heap
 * @return the front item in the queue
 * @author Jason Conklin
 */
CustomerEvent* EventQueue::dequeue() {
	CustomerEvent* event;
	if (mSize > 0) {
		//cout << "Starting Dequeue" << endl;
		//get top of heap
		//if (eventArr[0] == NULL) {
			//cout << "NULL HEAD" << endl;
		//}
		event = eventArr[0];
		//cout << "\tItem at the top of the heap: " << event->getPriority() << endl;
		//find last item in heap

		//cout << "\tLast item in queue, index " << mSize-1 << ", " << eventArr[mSize-1]->getPriority() << endl;
		//put last item on top and rebuild heap
		//cout << "\tputting " << eventArr[mSize-1]->getPriority() << " at top of heap..." << endl;
		eventArr[0] = eventArr[mSize-1]; //replace top item spot with last item
		//cout << "\tsetting index " << mSize-1 << " to NULL..." << endl;
		eventArr[mSize-1] = NULL; //remove last item
		//cout << "\theapify to fix heap" << endl;
		mSize--;if(mSize > 0){
		heapify(0);} //rebuild heap
	}
	return event;
}
