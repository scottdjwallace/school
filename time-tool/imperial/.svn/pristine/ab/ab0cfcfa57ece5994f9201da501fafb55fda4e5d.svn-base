/*
 * TT_ICSFile.h
 *
 *  Created on: Feb 19, 2015
 *      Author: 7cm5_000
 */

#ifndef TT_ICSFILE_H_
#define TT_ICSFILE_H_

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "../dataStructures/stack.h"
#include "ICS_Timezone.h"
#include "ICS_VEvent.h"
#include "ICS_Day.h"

using namespace std;

class VCalendarException : public runtime_error {
public:
	VCalendarException(string message) :
		runtime_error(message + " Error Code: ") {};
};

class FileFormatException : public runtime_error {
public:
	FileFormatException() :
		runtime_error("Improperly formatted input file") {};
};

class ICS_VCalendar {
	friend ofstream& operator<<(ofstream& outFile, const ICS_VCalendar& calendar);
	friend ifstream& operator>>(ifstream& inFile, ICS_VCalendar& ics);

	friend ostream& operator<<(ostream& out, const ICS_VCalendar& calendar);

	friend void setWeekAttribute(string& key, string& value, ICS_VCalendar& calendar);
	friend void setTimezoneAttributes(string& key, string& value, ICS_VCalendar& calendar);
public:
	ICS_VCalendar();

	// A ICS_VCalendar contains a vector of ICS_VEvents that happen on any calendar date.
	// This method takes a date, and returns a ICS_Day object (wrapper for a list of VEvents
	// occuring on a certain day)
	ICS_Day getEventsOn(const ICS_Date& date) const;

	size_t getNumberOfVEvents() const;
	string getCalscale() const;
	string getVersion() const ;
	string getMethod() const;
	string getName() const;
	ICS_Timezone getTimezone() const;

	ICS_VCalendar& setCalscale(const string& calscale);
	ICS_VCalendar& setVersion(const string& version);
	ICS_VCalendar& setMethod(const string& method);
	ICS_VCalendar& setName(const string& name);
	ICS_VCalendar& setTimezone(const ICS_Timezone& timezone);

	vector<ICS_VEvent>& getVEvents(){
		return events;
	}

	void addVEvent(ICS_VEvent event);

	static const string BEGIN
				, END
				, VALUE // ""
				, KEY_CALSCALE // = "CALSCALE";
				, KEY_VERSION // = "VERSION";
				, KEY_METHOD;
private:
	ICS_Timezone timezone;
	string calscale;
	string version;
	string method;
	string name;

	vector<ICS_VEvent> events;
};

#endif /* TT_ICSFILE_H_ */
