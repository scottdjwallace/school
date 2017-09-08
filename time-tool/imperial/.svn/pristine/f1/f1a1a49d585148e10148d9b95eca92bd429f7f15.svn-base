/*
 * ICS_VCalendar.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: 7cm5_000
 */

#include <vector>
#include <ios>

#include "../dataStructures/stack.h"
#include "icsHelpers.h"
#include "ICS_VCalendar.h"


using namespace std;

const string ICS_VCalendar::BEGIN = "BEGIN";
const string ICS_VCalendar::END = "END";
const string ICS_VCalendar::VALUE = "VCALENDAR";
const string ICS_VCalendar::KEY_CALSCALE = "CALSCALE";
const string ICS_VCalendar::KEY_VERSION = "VERSION";
const string ICS_VCalendar::KEY_METHOD = "METHOD";

ifstream& operator>>(ifstream& file, ICS_VCalendar& calendar){
	//cout << "ICS_Calendar.>>" << endl;
	Stack<string> validStack;
	bool endOfICS_VCalendar = false;

	string key;

	while (!file.eof() && !endOfICS_VCalendar){
		streampos pos = file.tellg();
		string key;
		string value;
		getline(file, key, ':');
		getline(file, value, '\n');
		trimRight(value);

		if (key.compare(ICS_VCalendar::BEGIN) == 0){
			validStack.push(value);

			if (value.compare(ICS_Timezone::VALUE) == 0){
				file.seekg(pos, ios_base::beg);
				file >> calendar.timezone;
			} else if (value.compare(ICS_VEvent::VALUE) == 0) {
				file.seekg(pos, ios_base::beg);
				ICS_VEvent e;
				file >> e;
				calendar.addVEvent(e);
			}
		} else if (key.compare(ICS_VCalendar::END) == 0){
			string top = validStack.pop();

			endOfICS_VCalendar = top.compare(ICS_VCalendar::VALUE) == 0;
		} else if (validStack.peak().compare(ICS_VCalendar::VALUE) == 0 ){
			if (key.compare(ICS_VCalendar::KEY_CALSCALE) == 0){
				calendar.calscale = value;
			} else if (key.compare(ICS_VCalendar::KEY_VERSION) == 0){
				calendar.version = value;
			} else if (key.compare(ICS_VCalendar::KEY_METHOD) == 0){
				calendar.method = value;
			}
		}
	}
	return file;
}

ofstream& operator<<(ofstream& file, const ICS_VCalendar& calendar){
	cout << "Writing ICS_VCalendar to file..." << endl;

	file << "BEGIN:" << ICS_VCalendar::VALUE << endl;

	if (calendar.calscale.size() > 0){
		file << ICS_VCalendar::KEY_CALSCALE << ':' << calendar.calscale << endl;
	}
	if (calendar.version.size() > 0){
		file << ICS_VCalendar::KEY_VERSION << ':' << calendar.version << endl;
	}
	if (calendar.method.size() > 0){
		file << ICS_VCalendar::KEY_METHOD << ':' << calendar.method << endl;
	}
	file << calendar.timezone;

	for (size_t i = 0; i < calendar.events.size(); i += 1){
		file << calendar.events[i];
	}

	file << "END:" << ICS_VCalendar::VALUE << endl;

	//cout << "ICS_VCalendar written to file successfully. " << endl;
	return file;
}

ostream& operator<<(ostream& out, const ICS_VCalendar& cal){
	ICS_Date earliestDate(10000, 1, 1);
	ICS_Date latestDate(1, 1, 1);
	for (unsigned int i = 0; i < cal.events.size(); i += 1){
		if (cal.events[i].getStartTime() < earliestDate){
			earliestDate = cal.events[i].getStartTime();
		}
		if (cal.events[i].getEndTime() > latestDate){
			latestDate = cal.events[i].getEndTime();
		}
	}

	int numDates = earliestDate.dayDifference(latestDate);
	for (int i = 0; i <= numDates; i += 1){
		ICS_Date date = earliestDate + i;
		out << "    date = " ;
		out << date << endl;
		ICS_Day currentDay = cal.getEventsOn(date);
		if (currentDay.size() == 0){
			out << "        no events" << endl;
		} else {
			for (unsigned int i = 0; i < currentDay.size(); i += 1){
				out << "        ";
				out << currentDay[i] << endl;
			}
		}
	}
	return out;

}

ICS_Day ICS_VCalendar::getEventsOn(const ICS_Date& date) const {
	ICS_Day currentDay(date);

	for (unsigned int i = 0; i < this->events.size(); i += 1){
		ICS_RRule rule = events[i].getRRule();
		if (rule.hasRecurrence(events[i].getStartTime(), date) || events[i].onDate(date)){
			currentDay.add(events[i].createOnDate(date));
		}
	}
	return currentDay;
}

void ICS_VCalendar::addVEvent(ICS_VEvent event){
	events.push_back(event);
}

ICS_VCalendar::ICS_VCalendar(){
	calscale = "GREGORIAN";
	version = "2.0";
}

string ICS_VCalendar::getCalscale() const{
	return calscale;
}

string ICS_VCalendar::getMethod() const{
	return method;
}

string ICS_VCalendar::getVersion() const{
	return version;
}


string ICS_VCalendar::getName() const{
	return name;
}

ICS_Timezone ICS_VCalendar::getTimezone() const{
	return timezone;
}

size_t ICS_VCalendar::getNumberOfVEvents() const{
	return events.size();
}

ICS_VCalendar& ICS_VCalendar::setTimezone(const ICS_Timezone& timezone){
	this->timezone = timezone;
	return *this;
}

ICS_VCalendar& ICS_VCalendar::setCalscale(const string& calscale){
	this->calscale = calscale;
	return *this;
}

ICS_VCalendar& ICS_VCalendar::setMethod(const string& method){
	this->method = method;
	return *this;
}

ICS_VCalendar& ICS_VCalendar::setVersion(const string& version){
	this->version = version;
	return *this;
}

ICS_VCalendar& ICS_VCalendar::setName(const string& name){
	this->name = name;
	return *this;
}

