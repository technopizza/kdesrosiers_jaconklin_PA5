/*
 * tellerevent.h
 *
 *  Created on: Oct 4, 2018
 *      Author: kdesrosiers
 */

#ifndef TELLER_H_
#define TELLER_H_
#include <cstdlib>
class Teller{
private:
	bool isOnBreak; //.
	bool isOccupied;
public:
	Teller();
	bool getBreakStatus();
	void setBreakStatus(bool x);
	bool getOccupiedStatus();
	void setOccupiedStatus(bool y);
};


#endif /* TELLER_H_ */
