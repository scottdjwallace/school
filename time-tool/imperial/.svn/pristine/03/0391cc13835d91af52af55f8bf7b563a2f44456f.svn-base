/*
 * ICS_RRule.h
 *
 *  Created on: Mar 26, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_RRULE_H_
#define ICS_RRULE_H_

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ICS_Time/ICS_Date.h"
#include "icsHelpers.h"

using namespace std;

class RRuleNotSupportedException : public runtime_error {
public:
	RRuleNotSupportedException(string strRrule) :
		runtime_error("Unsupported RRule: " + strRrule) {};
};

class RecurranceException : public runtime_error {
public:
	RecurranceException(ICS_Date date) :
		runtime_error("Recurrence does not occur on the date: " + date.toString()) {};
};

class InvalidRRuleException : public runtime_error {
public:
	InvalidRRuleException(string key) :
		runtime_error("ICS Key: '" + key + "' is not an RRule key.") {};
};

enum Freq {
	yearly, monthly, weekly, daily
};

class ICS_RRule {
	friend ofstream& operator<<(ofstream& outFile, const ICS_RRule& right);
	friend ifstream& operator>>(ifstream& inFile, ICS_RRule& right) throw (InvalidRRuleException);
	friend ostream& operator<<(ostream& out, const ICS_RRule& right);
public:
	static const string BEGIN	// BEGIN
		, END 					// END
		, VALUE					// RRULE
		, KEY_FREQ				// FREQ
		, FREQ_YEARLY			// YEARLY
		, FREQ_MONTHLY			// MONTHLY
		, FREQ_WEEKLY			// WEEKLY
		, FREQ_DAILY			// DAILY
		, KEY_UNTIL	 ;			// UNTIL

		// for now, we will not support these RRULE recurrences
		//, KEY_COUNT 			// COUNT
		//, KEY_INTERVAL		// INTERVAL
		//, KEY_BYMONTH			// BYMONTH
		//, KEY_BYDAY			// BYDAY
		//, BYDAY_0				// SU
		//, BYDAY_1				// MO
		//, BYDAY_2				// TU
		//, BYDAY_3				// WE
		//, BYDAY_4				// TH
		//, BYDAY_5				// FR
		//, BYDAY_6	;			// SA

	ICS_RRule();
	ICS_RRule(const string& rruleString);
	ICS_RRule(const ICS_RRule& rrule);

	string getFreqString() const;

	ICS_RRule& setFreq(Freq freq);

	void set(const string& rruleString) throw (RRuleNotSupportedException);
	bool hasRecurrence(const ICS_Date& start, const ICS_Date& date) const;
	ICS_Date generateRecurrence(const ICS_Date& baseDate, const ICS_Date& recurranceDate) const throw (RecurranceException);

private:
	Freq freq;
	ICS_Date until;
};

#endif /* ICS_RRULE_H_ */
