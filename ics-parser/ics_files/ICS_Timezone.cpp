/*
 * ICS_Timezone.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: christinaavchan
 *
 *	ICS_Timezone is a wrapper for the following ICS block
 * (From bare-bones minimum ICS file):

BEGIN:VTIMEZONE
TZID:America/Toronto
BEGIN:DAYLIGHT
... // ICS_Daylight class
END:DAYLIGHT
BEGIN:STANDARD
... // ICS_Standard class
END:STANDARD
END:VTIMEZONE
 */

#include <ios>

#include "../dataStructures/stack.h"
#include "icsHelpers.h"
#include "ICS_VEvent.h"
#include "ICS_Daylight.h"
#include "ICS_Standard.h"
#include "ICS_Timezone.h"

/* Constants */

const string ICS_Timezone::VALUE = "VTIMEZONE";
const string ICS_Timezone::KEY_TZID = "TZID";

/* IO operators */

ofstream& operator<<(ofstream& file, const ICS_Timezone& tz){
	// add check to see if there is daylight savings for given time zone
	file << "BEGIN:" << ICS_Timezone::VALUE << endl;
	file << ICS_Timezone::KEY_TZID << ':' << tz.tzid << endl;
	file << tz.daylight;
	file << tz.standard;
	file << "END:" << ICS_Timezone::VALUE << endl;
	return file;
} // end << file output

ifstream& operator>>(ifstream& file, ICS_Timezone& timezone){
	//cout << "ICS_Timezone.>>" << endl;
	Stack<string> validStack;
	bool endOfICS_Timezone = false;

	while (!file.eof() && !endOfICS_Timezone){
		streampos pos = file.tellg();
		string key;
		string value;
		getline(file, key, ':');
		getline(file, value, '\n');
		trimRight(value);

		if (key.compare("BEGIN") == 0){
			validStack.push(value);

			if (value.compare(ICS_Standard::VALUE) == 0){
				file.seekg(pos, ios_base::beg);
				file >> timezone.standard;
			} else if (value.compare(ICS_Daylight::VALUE) == 0){
				file.seekg(pos, ios_base::beg);
				file >> timezone.daylight;
			}
		} else if (key.compare("END") == 0){
			string top = validStack.pop();

			// throw an exception here if not equal
			// cout << value << " == stack.pop() = " << (top.compare(value) == 0 ? "true" : "false") << endl;

			endOfICS_Timezone = top.compare(ICS_Timezone::VALUE) == 0;
			if (endOfICS_Timezone){
				file.seekg(pos, ios_base::beg);
			}
		} else if (validStack.peak().compare(ICS_Timezone::VALUE) == 0){
			if (key.compare(ICS_Timezone::KEY_TZID) == 0){
				ICS_VEvent::setTzid(value);
				timezone.tzid = value;
			}
		}
	}
	return file;
}





/* Constructors */

ICS_Timezone::ICS_Timezone(){
	this-> tzid = "America/Toronto";
	this-> daylight = ICS_Daylight();
	this-> standard = ICS_Standard();
} // end constructor

ICS_Timezone::ICS_Timezone(const ICS_Timezone& tz){
	this-> tzid = tz.tzid;
	this-> daylight = tz.daylight;
	this-> standard = tz.standard;
} // end constructor (ICS_Timezone as argument)

/* accessors */

string ICS_Timezone::getTzid(){
	return this-> tzid;
}

ICS_Daylight& ICS_Timezone::getDaylight(){
	return this-> daylight;
}
ICS_Standard& ICS_Timezone::getStandard(){
	return this-> standard;
}

/* mutator */

ICS_Timezone& ICS_Timezone::setTzid(const string& tzid){
	this-> tzid = tzid;
	return *this;
}
