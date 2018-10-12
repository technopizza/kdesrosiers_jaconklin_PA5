/*
 * event.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */

#include "event.h"
#include <cstdlib>


Event::Event() {
	priority = rand();
}


/** returns the priority of the event
 * @author kdesrosiers
 * @return the priority of the event
 */
float Event::getPriority() {
	return priority;
}
