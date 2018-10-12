/*
 * teller.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */
#include "teller.h"
#include <cstdlib>

/**constructor for a teller object, sets isOnBreak and isOccupied to false
 *
 */
Teller::Teller(){
	isOnBreak = false; //.
	isOccupied = false;
}

/** gets the value of isOnBreak for a teller
 * @return isOnBreak the status of if a teller is on break
 */
bool Teller::getBreakStatus(){
	return isOnBreak;
}

/**resets the status of isOnBreak for a teller
 * @param x a new boolean variable
 */
void Teller::setBreakStatus(bool x){
	isOnBreak = x;
}

/** gets the status of how busy a teller is
 * @return isOccupied the status of how busy a teller is
 */
bool Teller::getOccupiedStatus() {
	return isOccupied;
}
/** resets the value of isOccupied to a different boolean value
 * @param y the boolean value to set isOccupied to
 */
void Teller::setOccupiedStatus(bool y) {
	isOccupied = y;
}
