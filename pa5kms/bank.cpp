/*
 * bank.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "teller.h"
#include "customer.h"
#include "tellerevent.h"
#include "customerevent.h"
#include <time.h>
#include "tellerqueue.h"
#include "eventqueue.h"
using namespace std;
const int MAXIDLE = 150;
int numOfCustomers; //number of customers in simulation.
int numOfTellers; //# of tellers in simulation
float simTime; //total simulation time in minutes
float avgServiceTime; //average time spent with each customer
unsigned int seed;
float simClock = 0; //the clock for keeping track of the time
float waitTime = 0;
float totalServiceTime = 0; //total amount of service time
int totalTellerIdleTime = 0; //total amount of teller idle time
int main(int argc, char** argv) {

	//if # of arguments greater than or equal to 5 and less than 7
	if (argc >= 5 && argc <= 7) {
		numOfCustomers = atoi(argv[1]); //numOfCustomers is the 2nd argument
		numOfTellers = atoi(argv[2]); //numOfTellers is the 3rd argument
		simTime = atof(argv[3]); //simTime is the 4th argument
		avgServiceTime = atof(argv[4]); //avgServiceTime is the 5th argument
		seed = time(0);
	}
	//if not any of above, error
	else {
		cout << "unexpected number of arguments!!" << endl;
		return EXIT_FAILURE;
	}
	//if the # of arguments is 7, use a seed
	if (argc == 7) {
		seed = atoi(argv[5]);
	}

	//After getting seed input or generating a seed, use seed for RNG
	srand(seed);




	//initialize teller queue to store customers
	TellerQueue *onlyLine = new TellerQueue();
	//initialize EventQueue to stor customer events
	EventQueue* eventqueue = new EventQueue(numOfCustomers);

	Customer* tmpCustomer; //placeholder pointer for initializing each new customer
	//Initiialize all customers (and thus their events)
	for (int i = 0; i < numOfCustomers; i++) {
		tmpCustomer = new Customer(simTime * (rand() / float(RAND_MAX)));
		eventqueue->enqueue(tmpCustomer->getArrival());
	}

	//add all customers to tellerqueue by pulling and running event actions from event priority queue
	while (eventqueue->size() > 0) {
		eventqueue->dequeue()->action(onlyLine);
	}
	//initialize array for storing customer wait times
	float waitTimes[numOfCustomers] = { 0 };
	//initialize array for tracking individual teller status
	float tellerLastPriority[numOfTellers] = { 0 };
	int idx = 0; //index to track current customer in wait times array
	//continue pulling from tellerqueue until no more customers
	while (onlyLine->sizeOfQueue() > 0) {
		//pop customer off of queue, save arrival time
		float arrivalTime = onlyLine->removeFromLine()->getArrival()->getPriority();
		cout << "Customer" << idx << " arrives at " << arrivalTime << " minutes" << endl;
		if (arrivalTime < simTime) { //discard customers who arrive after closing

			int i = 0; //index for finding open teller
			int minIdx = i; //variable to store index of open teller
			float start = tellerLastPriority[i];
			//cout << "Priority of Teller" << i << ": " << tellerLastPriority[i] << endl;

			//search for teller with min value to ensure shortest wait time
			if (numOfTellers > 1) {
				i = 1;
				while (i < numOfTellers) {
					if (tellerLastPriority[i] < start) {
						minIdx = i;
					}
					//cout << "Priority of Teller" << minIdx << ": " << tellerLastPriority[i] << endl;
					i++;
				}
			}
			start = tellerLastPriority[minIdx];
			//cout << "END Finding lowest prioirty line" << endl;

			//customer arrived before teller was open
			if (arrivalTime <= start) {
				waitTimes[idx] += start - arrivalTime;
				cout << "  He/She goes to teller" << minIdx << " at " << start << " minutes." << endl;
				cout << "  He/She waited in line for " << (start - arrivalTime) << " minutes." << endl;
			} else { //customer arrived and teller was open
				float tellerIdleTime = arrivalTime - start;
				totalTellerIdleTime += tellerIdleTime;
				start = arrivalTime;
				cout << "  He/She goes to teller" << minIdx << " at " << start << " minutes." << endl;
				cout << "  Teller" << minIdx << " has been unoccupied for " << tellerIdleTime << " minutes." << endl;

			}
			//compute random service time based on input, and update arrays
			float serviceTime = 2 * avgServiceTime * rand() / float(RAND_MAX);
			cout << "  It took Teller" << minIdx << " " << serviceTime << " minutes to serve Customer" << idx << endl;
			waitTimes[idx] += serviceTime;
			totalServiceTime += serviceTime;
			tellerLastPriority[minIdx] += (start + serviceTime);

		} else {
			numOfCustomers--; //if customers with invalidly high priority come, exclude them from array
		}
		idx++;
	}
	//calculate average and standard deviation of wait times
	waitTime = 0;
	for (int i = 0; i < numOfCustomers; i++) {
		waitTime += waitTimes[i];
	}
	float avgWaitTime = waitTime / numOfCustomers;
	float stdSumSquaredDiffs = 0;
	for (int i = 0; i < numOfCustomers; i++) {
		stdSumSquaredDiffs += pow((waitTimes[i] - avgWaitTime), 2);
	}
	float std = sqrt(stdSumSquaredDiffs / numOfCustomers);

	cout << "Number of customers served: " << numOfCustomers << endl;
	cout << "Number of tellers: " << numOfTellers << endl;
	cout << "Total teller service time: " << totalServiceTime << endl;
	cout << "Total teller idle time: " << totalTellerIdleTime << endl;
	cout << "The mean customer wait time was " << avgWaitTime << " with a standard deviation of " << std << endl;

	return 0;
}
