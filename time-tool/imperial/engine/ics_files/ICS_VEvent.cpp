/*
 * ICS_VEvent.cpp
 * Coded by: Paul Allison, Christopher McGrath
 * Submitted to team on February 19th, 2015.
 *
 */


#include <stdlib.h>
#include <string>
#include <iostream>

#include "../dataStructures/stack.h"
#include "icsHelpers.h"
#include "ICS_VEvent.h"
#include "ICS_Time/ICS_Date.h"
#include "ICS_Time/ICS_Clock.h"

using namespace std;

const string ICS_VEvent::VALUE = "VEVENT";
const string ICS_VEvent::KEY_CREATED = "CREATED";
const string ICS_VEvent::KEY_TZID = "TZID";
const string ICS_VEvent::KEY_UID = "UID";
const string ICS_VEvent::KEY_DTEND = "DTEND";
const string ICS_VEvent::KEY_SUMMARY = "SUMMARY";
const string ICS_VEvent::KEY_RRULE = "RRULE";
const string ICS_VEvent::KEY_DTSTART = "DTSTART";
const string ICS_VEvent::KEY_DTSTAMP = "DTSTAMP";
const string ICS_VEvent::KEY_LOCATION = "LOCATION";
const string ICS_VEvent::KEY_SEQUENCE = "SEQUENCE";
const string ICS_VEvent::KEY_DESCRIPTION = "DESCRIPTION";

string ICS_VEvent::tzid = "America/Toronto";

ofstream& operator<<(ofstream& file, const ICS_VEvent& right){
	file << "BEGIN:" << ICS_VEvent::VALUE << endl;
	file << ICS_VEvent::KEY_UID << ':' << right.uid << endl;

	file << ICS_VEvent::KEY_CREATED << ':';
	file << right.created << endl;

	file << ICS_VEvent::KEY_DTSTART << ';'
		<< ICS_VEvent::KEY_TZID << '=' << ICS_VEvent::tzid << ':';
	file << right.startTime << endl;

	file << ICS_VEvent::KEY_DTEND << ';'
		<< ICS_VEvent::KEY_TZID << '=' << ICS_VEvent::tzid << ':';
	file << right.endTime << endl;

	if (right.hasRRule()){
		file << ICS_VEvent::KEY_RRULE << ';';
		file << right.rrule << endl;
	}

	if (right.summary.size() > 0){
		file << ICS_VEvent::KEY_SUMMARY << ':' << right.summary << endl;
	}

	file << ICS_VEvent::KEY_DTSTAMP << ':';
	file << ICS_Date::now() << endl;

	if (right.description.size() > 0){
		file << ICS_VEvent::KEY_DESCRIPTION << ':' << right.description << endl;
	}

	if (right.location.size() > 0){
		file << ICS_VEvent::KEY_LOCATION << ':' << right.location << endl;
	}

	if (right.sequence.size() > 0){
		file << ICS_VEvent::KEY_SEQUENCE << ':' << right.sequence << endl;
	}
	file << "END:" << ICS_VEvent::VALUE << endl;
	return file;
}

ostream& operator<<(ostream& output, const ICS_VEvent& right){
	output << "\t" << right.summary << "\tfrom: " << right.startTime << "\tto: " << right.endTime;
	return output;
}

ifstream& operator>>(ifstream& file, ICS_VEvent& right){
	//cout << "ICS_VEvent.>>" << endl;
	Stack<string> validStack;
	bool endOfICS_VEvent = false;

	while (!file.eof() && !endOfICS_VEvent){
		streampos pos = file.tellg();
		string key;
		getline(file, key, ':');
		string value;
		getline(file, value, '\n');
		trimRight(value);

		if (key.compare("BEGIN") == 0){
			validStack.push(value);
		} else if (key.compare("END") == 0){
			string top = validStack.pop();

			// throw an exception here if not equal
			//cout << value << " == stack.pop() = " << (top.compare(value) == 0 ? "true" : "false") << endl;

			endOfICS_VEvent = (top.compare(ICS_VEvent::VALUE) == 0);
			if (endOfICS_VEvent){
				file.seekg(pos, ios_base::beg);
			}
		} else if (validStack.peak().compare(ICS_VEvent::VALUE) == 0){
			if (key.compare(ICS_VEvent::KEY_CREATED) == 0){
				ICS_Date created(value);
				right.created = created;
			} else if (key.compare(ICS_VEvent::KEY_UID) == 0){
				right.uid = value;
			} else if (key.compare(0, 5, ICS_VEvent::KEY_DTEND) == 0){
				ICS_Date endTime(value);
				right.endTime = endTime;
			} else if (key.compare(ICS_VEvent::KEY_SUMMARY) == 0){
				right.summary = value;
			} else if (key.compare(0, 7, ICS_VEvent::KEY_DTSTART) == 0){
				ICS_Date startTime(value);
				right.startTime = startTime;
			} else if (key.compare(ICS_VEvent::KEY_LOCATION) == 0){
				right.location = value;
			} else if (key.compare(ICS_VEvent::KEY_SEQUENCE) == 0){
				right.sequence = value;
			} else if (key.compare(ICS_VEvent::KEY_RRULE) == 0){
				ICS_RRule rrule(value);
				right.rrule = rrule;
				right.repeats = true;
			} else if (key.compare(ICS_VEvent::KEY_DESCRIPTION) == 0){
				right.description = value;
			}
		}
	}

	return file;
}

ICS_VEvent::ICS_VEvent(){
	this->repeats = false;
}

ICS_VEvent::ICS_VEvent(const ICS_VEvent& otherEvent){
	this -> startTime = otherEvent.startTime;
	this -> endTime = otherEvent.endTime;
	this -> created = otherEvent.created;
	this -> uid = otherEvent.uid;
	this -> tzid =  otherEvent.tzid;
	this -> summary =  otherEvent.summary;
	this -> location = otherEvent.location;
	this -> sequence = otherEvent.sequence;
	this->description = otherEvent.description;

	if (otherEvent.hasRRule()){
		this->rrule = otherEvent.rrule;
		this->repeats = true;
	} else {
		this->repeats = false;
	}
};

ICS_VEvent::ICS_VEvent(const ICS_Date& startTime, const ICS_Date& endTime){
	this->startTime = startTime;
	this->endTime = endTime;
	this->uid = "placeholderForRandomOne";
	this->description = "This block is free for all other members of your group";
	this->summary = "Free Block";
	this->tzid = ICS_VEvent::tzid;
	this->repeats = false;
}

string ICS_VEvent::getUid() const{
	return this->uid;
}

string ICS_VEvent::getTzid() const{
	return ICS_VEvent::tzid;
}

string ICS_VEvent::getSummary() const{
	return this->summary;
}

string ICS_VEvent::getLocation() const{
	return this->location;
}

string ICS_VEvent::getDescription() const{
	return this->description;
}

string ICS_VEvent::getSequence() const {
	return this->sequence;
}

bool ICS_VEvent::hasRRule() const {
	return repeats;
}

ICS_RRule ICS_VEvent::getRRule() const{
	return this->rrule;
}

ICS_Date ICS_VEvent::getStartTime() const{
	return this->startTime;
}

ICS_Date ICS_VEvent::getEndTime() const{
	return this->endTime;
}

bool ICS_VEvent::onDate(const ICS_Date& date) const{
	return startTime.getYear() == date.getYear() &&
		   startTime.getMonth() == date.getMonth() &&
		   startTime.getDayOfMonth() == date.getDayOfMonth();
}

ICS_VEvent ICS_VEvent::createOnDate(const ICS_Date& date) const{
	ICS_VEvent event(*this);
	event.startTime.setDayOfMonth(date.getDayOfMonth());
	event.startTime.setMonth(date.getMonth());
	event.startTime.setYear(date.getYear());
	event.endTime.setDayOfMonth(date.getDayOfMonth());
	event.endTime.setMonth(date.getMonth());
	event.endTime.setYear(date.getYear());
	return event;
}

ICS_VEvent& ICS_VEvent::setUid(const string& uid){
	this->uid = uid;
	return *this;
}

void ICS_VEvent::setTzid(const string& tzid){
	ICS_VEvent::tzid = tzid;
}

ICS_VEvent& ICS_VEvent::setSummary(const string& summary){
	this->summary = summary;
	return *this;
}

ICS_VEvent& ICS_VEvent::setLocation(const string& location){
	this->location = location;
	return *this;
}

ICS_VEvent& ICS_VEvent::setStartTime(const ICS_Date& startTime){
	this->startTime = startTime;
	return *this;
}

ICS_VEvent& ICS_VEvent::setDescription(const string& description){
	this->description = description;
	return *this;
}

ICS_VEvent& ICS_VEvent::setStartTime(const string& icsDateString){
	this->startTime = icsDateString;
	return *this;
}

ICS_VEvent& ICS_VEvent::setEndTime(const ICS_Date& endTime){
	this->endTime = endTime;
	return *this;
}

ICS_VEvent& ICS_VEvent::setEndTime(const string& icsDateString){
	this->endTime = icsDateString;
	return *this;
}

ICS_VEvent& ICS_VEvent::setSequence(const string& sequence){
	this->sequence = sequence;
	return *this;
}

bool ICS_VEvent::overlaps(const ICS_VEvent& otherEvent){
	ICS_Date startTimeA = getStartTime();
	ICS_Date startTimeB = otherEvent.startTime;
	ICS_Date endTimeA = this -> getEndTime();
	ICS_Date endTimeB = otherEvent.endTime;

	if(startTimeA <= startTimeB && endTimeA > startTimeB){
		return true;
	}

	if(startTimeA < endTimeB && endTimeA >= endTimeB){
		return true;
	}

	return false; //no overlap
}

bool ICS_VEvent::startsBefore(const ICS_VEvent& otherEvent){
	ICS_Date startTimeA = this -> getStartTime();
	ICS_Date startTimeB = otherEvent.startTime;
	if (startTimeA < startTimeB){
		return true;
	}
	return false;
}

ICS_VEvent ICS_VEvent::operator&&(const ICS_VEvent& right) throw (NoOverlapException){
	if (overlaps(right) == true){
		return *this && right;
	}
	else{
		throw new(NoOverlapException);
	}
	return *this && right;
}


