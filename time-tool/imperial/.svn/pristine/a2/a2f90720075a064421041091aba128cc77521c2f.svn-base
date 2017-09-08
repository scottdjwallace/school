/*
 * ICS_Standard.h
 *
 *  Created on: Feb 19, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_Standard_H_
#define ICS_Standard_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class StandardException : public runtime_error {
public:
	StandardException(string message) :
		runtime_error(message + " Error Code: ") {};
};

/* ICS_Standard is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):

BEGIN:STANDARD
TZOFFSETFROM:-0400
RRULE:FREQ=YEARLY;BYMONTH=11;BYDAY=1SU
DTSTART:20071104T020000
TZNAME:EST
TZOFFSETTO:-0500
END:STANDARD

 */

class ICS_Standard {
	friend ostream& operator<<(ostream& output, const ICS_Standard& standard);

	/* File IO operators: ICS formatted Standard block to ICS_Standard object */
	friend ifstream& operator>>(ifstream& file, ICS_Standard& standard);
	friend ofstream& operator<<(ofstream& file, const ICS_Standard& standard);
public:
	ICS_Standard();
	ICS_Standard(const ICS_Standard& other);
	ICS_Standard(const string& tzoffsetfrom, const string& rrule,
			const string& dtstart, const string& tzname, const string& tzoffsetto);

	string getTzoffsetfrom();
	string getRrule();
	string getDtstart();
	string getTzname();
	string getTzoffsetto();

	ICS_Standard& setTzoffsetfrom(const string& tzoffsetfrom);
	ICS_Standard& setRrule(const string& rrule);
	ICS_Standard& setDtstart(const string& dtstart);
	ICS_Standard& setTzname(const string& tzname);
	ICS_Standard& setTzoffsetto(const string& tzoffsetto);

	static const string VALUE // = "STANDARD"
		, KEY_TZOFFSETFROM // = "TZOFFSETFROM"
		, KEY_RRULE // = "RRULE"
		, KEY_DTSTART // = "DTSTART"
		, KEY_TZNAME // = "TZNAME"
		, KEY_TZOFFSETTO; // = "TZOFFSETTO";

private:
	string tzoffsetfrom
		, rrule
		, dtstart
		, tzname
		, tzoffsetto;
};

#endif /* ICS_Standard_H_ */
