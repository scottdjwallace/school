/*
 * ICS_Standard.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: christinaavchan
 *
 * ICS_Standard is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):
 * 	BEGIN:STANDARD
 * 	TZOFFSETFROM:-0400
 * 	RRULE:FREQ=YEARLY;BYMONTH=11;BYDAY=1SU
 * 	DTSTART:20071104T020000
 * 	TZNAME:EST
 * 	TZOFFSETTO:-0500
 * 	END:STANDARD
 *
 */

#include <ios>
#include <cstdlib>
#include <string>

#include "../dataStructures/stack.h"
#include "icsHelpers.h"
#include "ICS_Standard.h"

using namespace std;

/* Constants */

const string ICS_Standard::VALUE = "STANDARD";
const string ICS_Standard::KEY_TZOFFSETFROM = "TZOFFSETFROM";
const string ICS_Standard::KEY_RRULE = "RRULE";
const string ICS_Standard::KEY_DTSTART = "DTSTART";
const string ICS_Standard::KEY_TZNAME = "TZNAME";
const string ICS_Standard::KEY_TZOFFSETTO = "TZOFFSETTO";

/* Constructors */

ICS_Standard::ICS_Standard(){
	this-> tzoffsetfrom = "-0400";
	this-> rrule = "FREQ=YEARLY;BYMONTH=11;BYDAY=1SU";
	this-> dtstart = "20071104T020000";
	this-> tzname = "EST";
	this-> tzoffsetto = "-0500";
};

ICS_Standard::ICS_Standard(const ICS_Standard& other){
	this-> tzoffsetfrom = other.tzoffsetfrom;
	this-> rrule = other.rrule;
	this-> dtstart = other.dtstart;
	this-> tzname = other.tzname;
	this-> tzoffsetto = other.tzoffsetto;
} // end constructor (ICS_Standard object as argument)

ICS_Standard::ICS_Standard(const string& tzoffsetfrom, const string& rrule,
		const string& dtstart, const string& tzname, const string& tzoffsetto) {
	this-> tzoffsetfrom = tzoffsetfrom;
	this-> rrule = rrule;
	this-> dtstart = dtstart;
	this-> tzname = tzname;
	this-> tzoffsetto = tzoffsetto;
} // end constructor (string arguments)

/* I/O Operators */

ofstream& operator<<(ofstream& file, const ICS_Standard& standard){
	file << "BEGIN:" << ICS_Standard::VALUE << endl;
	file << ICS_Standard::KEY_TZOFFSETFROM << ':' << standard.tzoffsetfrom << endl;
	file << ICS_Standard::KEY_RRULE << ':' << standard.rrule << endl;
	file << ICS_Standard::KEY_DTSTART << ':' << standard.dtstart << endl;
	file << ICS_Standard::KEY_TZNAME << ':' << standard.tzname << endl;
	file << ICS_Standard::KEY_TZOFFSETTO << ':' << standard.tzoffsetto << endl;
	file << "END:" << ICS_Standard::VALUE << endl;
	return file;
} // end << file output

ostream& operator<<(ostream& output, const ICS_Standard& standard) {
	output << "Status: "<< ICS_Standard::VALUE << endl;
	output << "Rule: " << standard.rrule << endl;
	return output;
} // end << console output

ifstream& operator>>(ifstream& file, ICS_Standard& standard){
	//cout << "ICS_Standard.>>" << endl;
	Stack<string> validStack;
	bool endOfICS_Standard = false;

	while (!file.eof() && !endOfICS_Standard){
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
			//cout << value << " == stack.pop() = " << (top.compare(TT_Daylight::VALUE) == 0 ? "true" : "false") << endl;

			endOfICS_Standard = (top.compare(ICS_Standard::VALUE) == 0);
			if (endOfICS_Standard){
				file.seekg(pos, ios_base::beg);
			}
		} else if (validStack.peak().compare(ICS_Standard::VALUE) == 0){
			if (key.compare(ICS_Standard::KEY_TZOFFSETFROM) == 0){
				standard.tzoffsetfrom = value;
			} else if (key.compare(ICS_Standard::KEY_RRULE) == 0){
				standard.rrule = value;
			} else if (key.compare(ICS_Standard::KEY_DTSTART) == 0){
				standard.dtstart = value;
			} else if (key.compare(ICS_Standard::KEY_TZNAME) == 0){
				standard.tzname = value;
			} else if (key.compare(ICS_Standard::KEY_TZOFFSETTO) == 0){
				standard.tzoffsetto = value;
			}
		}
	}

	return file;
}

/* Accessors */

string ICS_Standard::getTzoffsetfrom(){
	return this-> tzoffsetfrom;
}

string ICS_Standard::getRrule(){
	return this-> rrule;
}

string ICS_Standard::getDtstart(){
	return this-> dtstart;
}

string ICS_Standard::getTzname(){
	return this-> tzname;
}

string ICS_Standard::getTzoffsetto(){
	return this-> tzoffsetto;
}

/* Mutators */

ICS_Standard& ICS_Standard::setTzoffsetfrom(const string& tzoffsetfrom){
	this-> tzoffsetfrom = tzoffsetfrom;
	return *this;
}

ICS_Standard& ICS_Standard::setRrule(const string& rrule){
	this-> rrule = rrule;
	return *this;
}

ICS_Standard& ICS_Standard::setDtstart(const string& dtstart){
	this-> dtstart = dtstart;
	return *this;
}

ICS_Standard& ICS_Standard::setTzname(const string& tzname){
	this-> tzname = tzname;
	return *this;
}

ICS_Standard& ICS_Standard::setTzoffsetto(const string& tzoffsetto){
	this-> tzoffsetto = tzoffsetto;
	return *this;
}
