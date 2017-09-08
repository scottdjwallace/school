/*
 * ICS_Daylight.h
 *
 *  Created on: Feb 19, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_Daylight_H_
#define ICS_Daylight_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class DaylightException : public runtime_error {
public:
	DaylightException(string message) :
		runtime_error(message + " Error Code: ") {};
};

/* ICS_Daylight is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):

BEGIN:DAYLIGHT
TZOFFSETFROM:-0500
RRULE:FREQ=YEARLY;BYMONTH=3;BYDAY=2SU
DTSTART:20070311T020000
TZNAME:EDT
TZOFFSETTO:-0400
END:DAYLIGHT

 */

class ICS_Daylight {
	friend ostream& operator<<(ostream& output, const ICS_Daylight& daylight);

		/* File IO operators: ICS formatted Standard block to TT_Standard object */
		friend ifstream& operator>>(ifstream& file, ICS_Daylight& daylight);
		friend ofstream& operator<<(ofstream& file, const ICS_Daylight& daylight);
public:
	ICS_Daylight();
	ICS_Daylight(const ICS_Daylight& other);
	ICS_Daylight(const string& tzoffsetfrom, const string& rrule,
			const string& dtstart, const string& tzname, const string& tzoffsetto);

	string getTzoffsetfrom();
	string getRrule();
	string getDtstart();
	string getTzname();
	string getTzoffsetto();

	ICS_Daylight& setTzoffsetfrom(const string& tzoffsetfrom);
	ICS_Daylight& setRrule(const string& rrule);
	ICS_Daylight& setDtstart(const string& dtstart);
	ICS_Daylight& setTzname(const string& tzname);
	ICS_Daylight& setTzoffsetto(const string& tzoffsetto);

	/* ICS format keys */
	static const string VALUE// = "DAYLIGHT"
		, KEY_TZOFFSETFROM// = "TZOFFSETFROM"
		, KEY_RRULE// = "RRULE"
		, KEY_DTSTART// = "DTSTART"
		, KEY_TZNAME// = "TZNAME"
		, KEY_TZOFFSETTO;// = "TZOFFSETTO";

private:
	string tzoffsetfrom
		, rrule
		, dtstart
		, tzname
		, tzoffsetto;
};

#endif /* ICS_Daylight_H_ */
