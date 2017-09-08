/*
 * ICS_Daylight.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: christinaavchan
 *
 * ICS_Daylight is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):
 * 	BEGIN:DAYLIGHT
 * 	TZOFFSETFROM:-0500
 * 	RRULE:FREQ=YEARLY;BYMONTH=3;BYDAY=2SU
 * 	DTSTART:20070311T020000
 * 	TZNAME:EDT
 * 	TZOFFSETTO:-0400
 * 	END:DAYLIGHT
 *
 */

#include <cstdlib>
#include <ios>

#include "../dataStructures/stack.h"
#include "icsHelpers.h"
#include "ICS_Daylight.h"

using namespace std;

/* Constants */

const string ICS_Daylight::VALUE = "DAYLIGHT";
const string ICS_Daylight::KEY_TZOFFSETFROM = "TZOFFSETFROM";
const string ICS_Daylight::KEY_RRULE = "RRULE";
const string ICS_Daylight::KEY_DTSTART = "DTSTART";
const string ICS_Daylight::KEY_TZNAME = "TZNAME";
const string ICS_Daylight::KEY_TZOFFSETTO = "TZOFFSETTO";

/* Constructors */

ICS_Daylight::ICS_Daylight(){
	this-> tzoffsetfrom = "-0500";
	this-> rrule = "FREQ=YEARLY;BYMONTH=3;BYDAY=2SU";
	this-> dtstart = "20070311T020000";
	this-> tzname = "EDT";
	this-> tzoffsetto = "-0400";
};

ICS_Daylight::ICS_Daylight(const ICS_Daylight& other){
	this-> tzoffsetfrom = other.tzoffsetfrom;
	this-> rrule = other.rrule;
	this-> dtstart = other.dtstart;
	this-> tzname = other.tzname;
	this-> tzoffsetto = other.tzoffsetto;
} // end constructor (ICS_Daylight object as argument)

ICS_Daylight::ICS_Daylight(const string& tzoffsetfrom, const string& rrule,
		const string& dtstart, const string& tzname, const string& tzoffsetto) {
	this-> tzoffsetfrom = tzoffsetfrom;
	this-> rrule = rrule;
	this-> dtstart = dtstart;
	this-> tzname = tzname;
	this-> tzoffsetto = tzoffsetto;
} // end constructor (string arguments)

/* I/O Operators */
ofstream& operator<<(ofstream& file, const ICS_Daylight& standard){
	file << "BEGIN:" << ICS_Daylight::VALUE << endl; // DAYLIGHT
	file << ICS_Daylight::KEY_TZOFFSETFROM << ':' << standard.tzoffsetfrom << endl;
	file << ICS_Daylight::KEY_RRULE << ':' << standard.rrule << endl;
	file << ICS_Daylight::KEY_DTSTART << ':' << standard.dtstart << endl;
	file << ICS_Daylight::KEY_TZNAME << ':' << standard.tzname << endl;
	file << ICS_Daylight::KEY_TZOFFSETTO << ':' << standard.tzoffsetto << endl;
	file << "END:" << ICS_Daylight::VALUE << endl;
	return file;
} // end << file output

ostream& operator<<(ostream& output, const ICS_Daylight& standard) {
	output << "Status: "<< ICS_Daylight::VALUE << endl;
	output << "Rule: " << standard.rrule << endl;
	return output;
} // end << console output

ifstream& operator>>(ifstream& file, ICS_Daylight& standard){
	//cout << "ICS_Daylight.>>" << endl;
	Stack<string> validStack;
	bool endOfICS_Daylight = false;

	while (!file.eof() && !endOfICS_Daylight){
		streampos pos = file.tellg();
		string key;
		string value;
		getline(file, key, ':');
		getline(file, value, '\n');
		trimRight(value);

		if (key.compare("BEGIN") == 0){
			validStack.push(value);
		} else if (key.compare("END") == 0){
			string top = validStack.pop();

			// throw an exception here if not equal
			//cout << value << " == stack.pop() = " << (top.compare(value) == 0 ? "true" : "false") << endl;

			endOfICS_Daylight = (top.compare(ICS_Daylight::VALUE) == 0);
			if (endOfICS_Daylight){
				file.seekg(pos, ios_base::beg);
			}
		} else if (validStack.peak().compare(ICS_Daylight::VALUE) == 0){
			if (key.compare(ICS_Daylight::KEY_TZOFFSETFROM) == 0){
				standard.tzoffsetfrom = value;
			} else if (key.compare(ICS_Daylight::KEY_RRULE) == 0){
				standard.rrule = value;
			} else if (key.compare(ICS_Daylight::KEY_DTSTART) == 0){
				standard.dtstart = value;
			} else if (key.compare(ICS_Daylight::KEY_TZNAME) == 0){
				standard.tzname = value;
			} else if (key.compare(ICS_Daylight::KEY_TZOFFSETTO) == 0){
				standard.tzoffsetto = value;
			}
		}
	}

	return file;
} // end >> file input

string ICS_Daylight::getTzoffsetfrom(){
	return this-> tzoffsetfrom;
}

string ICS_Daylight::getRrule(){
	return this-> rrule;
}

string ICS_Daylight::getDtstart(){
	return this-> dtstart;
}

string ICS_Daylight::getTzname(){
	return this-> tzname;
}

string ICS_Daylight::getTzoffsetto(){
	return this-> tzoffsetto;
}

/* Mutators */

ICS_Daylight& ICS_Daylight::setTzoffsetfrom(const string& tzoffsetfrom){
	this-> tzoffsetfrom = tzoffsetfrom;
	return *this;
}

ICS_Daylight& ICS_Daylight::setRrule(const string& rrule){
	this-> rrule = rrule;
	return *this;
}

ICS_Daylight& ICS_Daylight::setDtstart(const string& dtstart){
	this-> dtstart = dtstart;
	return *this;
}

ICS_Daylight& ICS_Daylight::setTzname(const string& tzname){
	this-> tzname = tzname;
	return *this;
}

ICS_Daylight& ICS_Daylight::setTzoffsetto(const string& tzoffsetto){
	this-> tzoffsetto = tzoffsetto;
	return *this;
}
