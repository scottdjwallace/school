/*
 * TTBlock.h
 *
 *  Created on: Feb 11, 2015
 *      Author: 7cm5_000
 */

#ifndef TTBLOCK_H_
#define TTBLOCK_H_

/* Bare minimum information
 *
BEGIN:VEVENT
CREATED:20150211T203706Z
UID:A2B54025-3D39-4795-A93E-FAD711D8F992
DTEND;TZID=America/Toronto:20150211T113000
TRANSP:OPAQUE
SUMMARY:CISC 324
DTSTART;TZID=America/Toronto:20150211T103000
DTSTAMP:20150105T135120Z
LOCATION:Ellis 324
SEQUENCE:0
END:VEVENT
 */

#include <string>
#include <ctime>
#include "ICS_Time/ICS_Date.h"
#include "ICS_RRule.h"

using namespace std;

class VEventException : public runtime_error {
public:
	VEventException(string message) :
		runtime_error(message + " Error Code: ") {};
};

class NoOverlapException : public runtime_error {
public:
	NoOverlapException() :
		runtime_error("Two ICS_VEvents have no overlap.") {};
};

class ICS_VEvent {
	friend ofstream& operator<<(ofstream& file, const ICS_VEvent& right);
	/* Programmer readable console output.
	 * maybe only output like start and end times or something
	 * so the programmer can tell important stuff about VEvent
	 * (i.e. Uid and Tzid are not important use your judgement I guess */
	friend ostream& operator<<(ostream& output, const ICS_VEvent& right);

	friend ifstream& operator>>(ifstream& file, ICS_VEvent& right);
	friend istream& operator>>(istream& input, ICS_VEvent& right);
public :
	ICS_VEvent();
	ICS_VEvent(const ICS_VEvent& otherEvent);
	ICS_VEvent(const ICS_Date& startTime, const ICS_Date& endTime);

	// self explanatory
	string getTzid() const;
	string getUid() const;
	string getSummary() const;
	string getDescription() const;
	string getLocation() const;
	string getSequence() const;
	bool hasRRule() const;
	ICS_RRule getRRule() const;
	ICS_Date getStartTime() const;
	ICS_Date getEndTime() const;

	bool onDate(const ICS_Date& date) const;
	ICS_VEvent createOnDate(const ICS_Date& date) const;

	// return *this so that these methods can be chained
	static void setTzid(const string& tzid);
	ICS_VEvent& setUid(const string& uid);
	ICS_VEvent& setSummary(const string& summary);
	ICS_VEvent& setDescription(const string& description);
	ICS_VEvent& setLocation(const string& location);
	ICS_VEvent& setSequence(const string& sequence);
	ICS_VEvent& setStartTime(const ICS_Date& startTime);
	ICS_VEvent& setStartTime(const string& icsDateString);
	ICS_VEvent& setEndTime(const ICS_Date& endTime);
	ICS_VEvent& setEndTime(const string& icsDateString);

	/* Does this timetable block overlap another? use startTime and endTime of
	 * this class. */
	bool overlaps(const ICS_VEvent& otherEvent);
	bool startsBefore(const ICS_VEvent& otherEvent);

	// will be used for generating a conflict block
	ICS_VEvent operator&&(const ICS_VEvent& right) throw (NoOverlapException);

public:
	static const string VALUE
		, KEY_CREATED       // = CREATED
		, KEY_UID           // = UID
		, KEY_DTEND			// = DTEND
		, KEY_TZID			// = TZID (special one for dates)
		, KEY_SUMMARY       // = SUMMARY
		, KEY_DTSTART		// = DTSTART
		, KEY_DTSTAMP 		// = DTSTAMP
		, KEY_LOCATION		// = LOCATION
		, KEY_SEQUENCE		// = SEQUENCE
		, KEY_RRULE
		, KEY_DESCRIPTION; 		// = RRULE
private :
	static string tzid; // singleton
	ICS_Date startTime, endTime, created;
	ICS_RRule rrule;
	bool repeats;
	string uid
		, description
		, summary
		, location
		, sequence;

};



#endif /* TTBLOCK_H_ */
