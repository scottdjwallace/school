/*
 * Date.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: 7cm5_000
 */

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "ICS_Date.h"

bool ICS_Date::isLeapYear(int year){
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

const string ICS_Date::monthString[] = {
		"January ", "February ", "March ", "April ",
		"May ", "June ", "July ", "August ", "September ",
		"October ", "November ", "December"
};

const int ICS_Date::daysInMonth[] = {
		31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31
};

ofstream& operator<<(ofstream& file, const ICS_Date& date){
	file << date.year;
	file << (date.month < 10 ? "0" : "") << date.month;
	file << (date.dayOfMonth < 10 ? "0" : "") << date.dayOfMonth;
	file << 'T';
	file << date.clock;
	return file;
}

ostream& operator<<(ostream& output, const ICS_Date& date){
	output << ICS_Date::monthString[date.month - 1];
	output << date.dayOfMonth;
	output << ", ";
	output << date.year;
	output << " @ ";
	output << date.clock;
	return output;
}

ifstream& operator>>(ifstream& file, ICS_Date& date){
	char line[64];
	file.getline(line, 64, '\n');
	cout << "read line = " << line << endl;
	try {
		date.setDateFromICSString(line);
	} catch (ICSDateStringException& e) {
		cerr << e.what() << endl;
		exit(1);
	} catch (NegativeYearException& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (MonthOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (DayOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	}
	return file;
}

ICS_Date ICS_Date::now(){
        //*******GET THE CURRENT TIME*****************
	time_t todaysTime = time(0); // time_t is a type to represent times.
	//time(&todaysTime);	// "time()" is a function used to obtain the current time.

	//******CREATE A TIME STRUCTURE***************
	struct tm *timeHere; // A tm struct is a time structure.

	getenv("TZ");
	tzset();

	todaysTime -= (daylight ? timezone : timezone - 3600);
	ICS_Date currentDate; // Create a ICS_Date object to return.

	timeHere = gmtime( &todaysTime ); // Populate my time struct.

	// More information on the time struct, including the members can be found
	// at http://www.cplusplus.com/reference/ctime/tm/.

	//********OBTAIN RELEVANT DATE INFORMATION*****************
	int day = timeHere->tm_mday;		// Day of month.
	int month = timeHere->tm_mon + 1; // Months since January.
	int year = timeHere->tm_year + 1900; // Years since 1900.
	int hour = timeHere->tm_hour; // Hour since midnight.
	int min = timeHere->tm_min; // Minutes after the hour.

	//********SET THE DATE OF OUR CURRENT DATE OBJECT***********
	currentDate.setDayOfMonth(day);
	currentDate.setMonth(month);
	currentDate.setYear(year);
	currentDate.setHour(hour);
	currentDate.setMinute(min);
	return currentDate;
}

ICS_Date::ICS_Date(){
	this->year = 0;
	this->month = 1;
	this->dayOfMonth = 1;
};

ICS_Date::ICS_Date(int year, int month, int day) throw (NegativeYearException, MonthOutOfBounds, DayOutOfBounds){
	setYear(year);
	setMonth(month);
	setDayOfMonth(day);
}

ICS_Date::ICS_Date(const ICS_Date& otherDate){
	this->year = otherDate.year;
	this->month = otherDate.month;
	this->dayOfMonth = otherDate.dayOfMonth;
	this->clock = otherDate.clock;
}

// icsDateAndTimeString format == "YYYYMMDD'T'hhmmss"
ICS_Date::ICS_Date(const string& icsDateAndClockString){
	try {
		setDateFromICSString(icsDateAndClockString);
	} catch (ICSDateStringException& e) {
		cerr << e.what() << endl;
		exit(1);
	} catch (NegativeYearException& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (MonthOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (DayOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
		exit(1);
	}
}

int ICS_Date::getYear() const{
	return year;
}

int ICS_Date::getMonth() const{
	return month;
}

int ICS_Date::getDayOfMonth() const{
	return dayOfMonth;
}

int ICS_Date::getHour() const{
	return clock.getHour();
}

int ICS_Date::getMinute() const{
	return clock.getMinute();
}

ICS_Date& ICS_Date::setDateFromICSString(string icsDateAndClockString) throw (ICSDateStringException
		, NegativeYearException, MonthOutOfBounds, DayOutOfBounds
		, HourOutOfBounds, MinuteOutOfBounds)
{
	if (icsDateAndClockString.at(8) != 'T') throw ICSDateStringException(icsDateAndClockString);

	year = 0;
	int i = 0;
	while (i < 4){
		year *= 10;
		year += icsDateAndClockString.at(i) - '0';
		i += 1;
	}

	if (year < 0) throw NegativeYearException(year);

	month = 0;
	dayOfMonth = 0;
	int hour = 0;
	int minute = 0;
	while (i < 6){
		month *= 10;
		dayOfMonth *= 10;
		hour *= 10;
		minute *= 10;
		month += (int)icsDateAndClockString.at(i) - '0';
		dayOfMonth += (int)icsDateAndClockString.at(i + 2) - '0';
		hour += (int)icsDateAndClockString.at(i + 5) - '0';
		minute += (int)icsDateAndClockString.at(i + 7) - '0';
		i += 1;
	}

	if (month < 1 || month > 12) throw MonthOutOfBounds(month);
	if (dayOfMonth < 1 || dayOfMonth > 31) throw DayOutOfBounds(dayOfMonth);

	clock.setClock(hour, minute);
	return *this;
}

ICS_Date& ICS_Date::setYear(int year) throw (NegativeYearException){
	if (year < 0){
		throw NegativeYearException(year);
	}
	this->year = year;
	return *this;
}

ICS_Date& ICS_Date::setMonth(int month) throw (MonthOutOfBounds){
	if (month < 1 || month > 12){
		throw MonthOutOfBounds(month);
	}
	this->month = month;
	return *this;
}

ICS_Date& ICS_Date::setDayOfMonth(int dayOfMonth) throw (DayOutOfBounds){
	if (dayOfMonth < 1 || dayOfMonth > 31){
		throw DayOutOfBounds(dayOfMonth);
	}
	this->dayOfMonth = dayOfMonth;
	return *this;
}

ICS_Date& ICS_Date::setHour(int hour) throw (HourOutOfBounds){
	clock.setHour(hour);
	return *this;
}

ICS_Date& ICS_Date::setMinute(int minute) throw (MinuteOutOfBounds){
	clock.setMinute(minute);
	return *this;
}

int ICS_Date::compareTo(const ICS_Date& otherDate){
	if (*this < otherDate){
		return -1;
	} else if (*this > otherDate){
		return 1;
	} else {
		return 0;
	}
}

bool ICS_Date::operator>(const ICS_Date& right) const{
	if (year > right.year){
		return true;
	} else if (year < right.year){
		return false;
	}

	if (month > right.month){
		return true;
	} else if (month < right.month){
		return false;
	}

	if (dayOfMonth > right.dayOfMonth){
		return true;
	} else if (dayOfMonth < right.dayOfMonth){
		return false;
	}

	return clock > right.clock;
}

bool ICS_Date::operator<(const ICS_Date& right) const{
	return right > *this;
}

bool ICS_Date::operator==(const ICS_Date& right){
	return (year == right.year &&
			month == right.month &&
			dayOfMonth == right.dayOfMonth &&
			clock == right.clock);
}

bool ICS_Date::operator!=(const ICS_Date& right){
	return !(*this == right);
}

bool ICS_Date::operator>=(const ICS_Date& right){
	return !(*this < right);
}

bool ICS_Date::operator<=(const ICS_Date& right){
	return !(*this > right);
}

string ICS_Date::toString(){
	char cA[13];
	cA[0] = '0' + (dayOfMonth / 10);
	cA[1] = '0' + (dayOfMonth % 10);
	cA[2] = '/';
	cA[3] = '0' + (month / 10);
	cA[4] = '0' + (month % 10);
	cA[5] = '/';
	int y = year;
	int i = 0;
	while (y > 0){
		cA[9 - i] = '0' + (y % 10);
		y /= 10;
		i += 1;
	}
	cA[10] = ' ';
	cA[11] = '@';
	cA[12] = ' ';

	return cA + clock.toString();
}

/* ICS string format: "yyyymmdd" + time.toICSString();
	 * i.e. January 2, 2001 @ 13:30 == 20010102T133000 */
string ICS_Date::toICSString(){
	//string s;
	char s[9];

	s[0] = '0' + (year / 1000);
	s[1] = '0' + (year / 100 % 10);
	s[2] = '0' + (year / 10 % 10);
	s[3] = '0' + (year % 10);
	
	s[4] = '0' + (month / 10);
	s[5] = '0' + (month % 10);

	s[6] = '0' + (dayOfMonth / 10);
	s[7] = '0' + (dayOfMonth % 10);
	s[8] = 'T';
	
	return s + clock.toICSString();
}

int ICS_Date::dayDifference(const ICS_Date& otherDate) const {
	int days = 0;
	if (*this < otherDate){
		ICS_Date smaller(*this);
		while (!(smaller.getDayOfMonth() == otherDate.getDayOfMonth()
			&& smaller.getYear() == otherDate.getYear()
			&& smaller.getMonth() == otherDate.getMonth())){
			days += 1;
			smaller += 1;
		}
	} else {
		ICS_Date smaller(otherDate);
		while (!(smaller.getDayOfMonth() == getDayOfMonth()
			&& smaller.getYear() == getYear()
			&& smaller.getMonth() == getMonth())){
			days -= 1;
			smaller += 1;
		}
	}

	return days;
}
