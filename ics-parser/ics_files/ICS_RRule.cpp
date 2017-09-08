/*
 * ICS_RRule.cpp
 *
 *  Created on: Mar 20, 2015
 *      Author: 7cm5_000
 */

#include "ICS_RRule.h"

const string ICS_RRule::BEGIN = "BEGIN";
const string ICS_RRule::END = "END";
const string ICS_RRule::VALUE = "RRULE";
const string ICS_RRule::KEY_UNTIL = "UNTIL";
const string ICS_RRule::KEY_FREQ = "FREQ";
const string ICS_RRule::FREQ_DAILY = "DAILY";
const string ICS_RRule::FREQ_MONTHLY = "MONTHLY";
const string ICS_RRule::FREQ_WEEKLY = "WEEKLY";
const string ICS_RRule::FREQ_YEARLY = "YEARLY";

ICS_RRule::ICS_RRule(){
	this->freq = yearly;
}

ICS_RRule::ICS_RRule(const string& rruleString){
	this->freq = yearly;
	set(rruleString);
}

ICS_RRule::ICS_RRule(const ICS_RRule& other){
	this->freq = other.freq;
	this->until = other.until;

}

ofstream& operator<<(ofstream& outFile, const ICS_RRule& right){
	outFile << ICS_RRule::KEY_FREQ << '=';
	switch (right.freq){
	case yearly:
		outFile << ICS_RRule::FREQ_YEARLY;
		break;
	case monthly:
		outFile << ICS_RRule::FREQ_MONTHLY;
		break;
	case weekly:
		outFile << ICS_RRule::FREQ_WEEKLY;
		break;
	case daily:
		outFile << ICS_RRule::FREQ_DAILY;
		break;
	}
	outFile << ";";
	outFile << ICS_RRule::KEY_UNTIL << ':';
	outFile << right.until;

	return outFile;
}

ifstream& operator>>(ifstream& inFile, ICS_RRule& right) throw (InvalidRRuleException){
	string key;
	string value;
	getline(inFile, key, ':');
	getline(inFile, value, '\n');
	trimRight(value);

	if (key.compare(ICS_RRule::VALUE) != 0){
		throw InvalidRRuleException(key);
	}

	right.set(value);
	return inFile;
}

ostream& operator<<(ostream& out, const ICS_RRule& right){
	out << "rrule object: " << endl;
	out << "    freq = " << right.getFreqString() << endl;
	out << "    end = " << right.until << endl;
	return out;
 }

void ICS_RRule::set(const string& rruleString) throw (RRuleNotSupportedException){
	int indexFreq = rruleString.find(ICS_RRule::KEY_FREQ);
	if (indexFreq < 0){
		throw RRuleNotSupportedException("Not a FREQ rule: " + rruleString);
	}

	unsigned int threshold = indexFreq + ICS_RRule::KEY_FREQ.length();
	if (rruleString.find(ICS_RRule::FREQ_YEARLY) != string::npos){
		this->freq = yearly;
	} else if (rruleString.find(ICS_RRule::FREQ_MONTHLY) != string::npos){
		this->freq = monthly;
	} else if (rruleString.find(ICS_RRule::FREQ_WEEKLY) != string::npos){
		this->freq = weekly;
	} else if (rruleString.find(ICS_RRule::FREQ_DAILY) != string::npos){
		this->freq = daily;
	} else {
		throw RRuleNotSupportedException("FREQ value: " + rruleString);
	}

	int indexUntil = rruleString.find(ICS_RRule::KEY_UNTIL);

	if (indexUntil < 0){
		throw RRuleNotSupportedException("Not an UNTIL rule: " + rruleString);
	}

	string stringUntil = rruleString.substr(indexUntil + ICS_RRule::KEY_UNTIL.length() + 1);
	ICS_Date dateUntil(stringUntil);
	this->until = dateUntil;
}

string ICS_RRule::getFreqString() const{
	switch (freq){
	case yearly:
		return "yearly";
	case monthly:
		return "monthly";
	case weekly:
		return "weekly";
	default:
		return "daily";
	}
}

ICS_RRule& ICS_RRule::setFreq(Freq freq){
	this->freq = freq;
	return *this;
}

bool ICS_RRule::hasRecurrence(const ICS_Date& start, const ICS_Date& date) const{
	int daysBetween = start.dayDifference(date);
	if (daysBetween < 0) return false;
	if (date > until){
		return false;
	}

	switch (freq){
	case yearly:
		return false;
	case monthly:
		return false;
	case weekly:
		return daysBetween % 7 == 0;
	case daily:
		return true;
	default:
		return false;
	}
}

ICS_Date ICS_RRule::generateRecurrence(const ICS_Date& baseDate, const ICS_Date& recurrenceDate) const throw (RecurranceException){
	if (this->hasRecurrence(baseDate, recurrenceDate)){
		ICS_Date recurrence(recurrenceDate);
		recurrence.setHour(baseDate.getHour());
		recurrence.setMinute(baseDate.getMinute());
		return recurrence;
	} else {
		throw RecurranceException(recurrenceDate);
	}
}


