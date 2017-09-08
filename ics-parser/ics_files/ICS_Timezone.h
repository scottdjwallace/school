/*
 * ICS_Timezone.h
 *
 *  Created on: Feb 19, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_Timezone_H_
#define ICS_Timezone_H_

#include <string>
#include <iostream>
#include <fstream>

#include "ICS_Daylight.h"
#include "ICS_Standard.h"

using namespace std;

class TimezoneException : public runtime_error {
public:
	TimezoneException(string message) :
		runtime_error(message + " Error Code: ") {};
};

/* ICS_Timezone is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):

BEGIN:VTIMEZONE
TZID:America/Toronto
BEGIN:DAYLIGHT
... // ICS_Daylight class
END:DAYLIGHT
BEGIN:STANDARD
... // ICS_Standard class
END:STANDARD
END:VTIMEZONE
 */

class ICS_Timezone {
	friend ofstream& operator<<(ofstream& file, const ICS_Timezone& timezone);

	friend ifstream& operator>>(ifstream& file, ICS_Timezone& timezone);
public:
	ICS_Timezone();
	ICS_Timezone(const ICS_Timezone& tz);

	string getTzid();
	ICS_Daylight& getDaylight();
	ICS_Standard& getStandard();

	ICS_Timezone& setTzid(const string& tzid);

	static const string VALUE
		, KEY_TZID;
private:
	string tzid;
	ICS_Daylight daylight;
	ICS_Standard standard;
};

#endif /* ICS_Timezone_H_ */
