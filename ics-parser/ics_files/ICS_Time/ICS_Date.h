/*
 * Date.h
 *
 *  Created on: Feb 11, 2015
 *      Author: 7cm5_000
 */

#ifndef DATE_H_
#define DATE_H_


#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ICS_Clock.h"

using namespace std;

class ICSDateStringException : public runtime_error {
public:
	ICSDateStringException(string s) :
		runtime_error("Format error in ICS Date String: " + s) {};
};

class NegativeYearException : public runtime_error {
public:
	NegativeYearException(int year) :
		runtime_error("Negative year: " + year) {};
};

class MonthOutOfBounds : public runtime_error {
public:
	MonthOutOfBounds(int month) :
		runtime_error("Month outside of bounds [1, 12]: " + month) {};
};

class DayOutOfBounds : public runtime_error {
public:
	DayOutOfBounds(int day) :
		runtime_error("Day outside of bounds [1, 31]: " + day) {};
};


class ICS_Date{
	friend ofstream& operator<<(ofstream& file, const ICS_Date& date);
	friend ostream& operator<<(ostream& output, const ICS_Date& date);

	friend ifstream& operator>>(ifstream& file, ICS_Date& date);
public:
	// Default ICS_Date: January 1, 2000 @ 0:00
	ICS_Date();

	// Self Explanatory
	ICS_Date(int year, int month, int day) throw (NegativeYearException, MonthOutOfBounds, DayOutOfBounds);
	ICS_Date(const ICS_Date& date);
	ICS_Date(const string& icsDateAndTimeString);

	// returns ICS_Date with the current date information
	static ICS_Date now();

	int getYear() const;
	int getMonth() const;
	int getDayOfMonth() const;
	ICS_Clock getTime();
	int getHour() const;
	int getMinute() const;

	// return *this so that these methods can be chained
	ICS_Date& setDateFromICSString(string icsDateAndTimeString) throw (ICSDateStringException
			, NegativeYearException, MonthOutOfBounds, DayOutOfBounds
			, HourOutOfBounds, MinuteOutOfBounds);
	ICS_Date& setYear(int year) throw (NegativeYearException);
	ICS_Date& setMonth(int month) throw (MonthOutOfBounds);
	ICS_Date& setDayOfMonth(int dayOfMonth) throw (DayOutOfBounds);
	ICS_Date& setHour(int hour) throw (HourOutOfBounds);
	ICS_Date& setMinute(int minute) throw (MinuteOutOfBounds);

	// returns a the difference in days between this date and another
	int dayDifference(const ICS_Date& otherDate) const;

	/* returns -1 if otherDate > this
	 * returns 0 of otherDate == this
	 * returns 1 if otherDate < this  */
	int compareTo(const ICS_Date& otherDate);

	bool operator>(const ICS_Date& right) const;
	bool operator<(const ICS_Date& right) const;
	bool operator==(const ICS_Date& right);
	bool operator!=(const ICS_Date& right);
	bool operator>=(const ICS_Date& right);
	bool operator<=(const ICS_Date& right);

	ICS_Date& operator+=(int days){
		while (days > 0){
			int daysInCurrentMonth = daysInMonth[month - 1];
			if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
				daysInCurrentMonth += 1;
			}
			if (days >= (daysInCurrentMonth - this->dayOfMonth + 1)){
				if (month == 12){
					year += 1;
					month = 1;
				} else {
					month += 1;
				}
				days -= daysInCurrentMonth - this->dayOfMonth + 1;
				dayOfMonth = 1;
			} else {
				dayOfMonth += days;
				days -= days;
			}
		}

		return *this;
	}

	ICS_Date operator+(int days){
		ICS_Date newDate(*this);
		while (days > 0){
			int daysInCurrentMonth = daysInMonth[newDate.month - 1];
			if (newDate.month == 2 && newDate.year % 4 == 0 && (newDate.year % 100 != 0 || newDate.year % 400 == 0)){
				daysInCurrentMonth += 1;
			}
			if (days >= (daysInCurrentMonth - newDate.dayOfMonth + 1)){
				if (newDate.month == 12){
					newDate.year += 1;
					newDate.month = 1;
				} else {
					newDate.month += 1;
				}
				days -= daysInCurrentMonth - newDate.dayOfMonth + 1;
				newDate.dayOfMonth = 1;
			} else {
				newDate.dayOfMonth += days;
				days -= days;
			}
		}
		return newDate;
	}

	// Programmer readable string
	string toString();

	/* ICS string format: "yyyymmdd" + time.toICSString();
	 * i.e. January 2, 2001 @ 13:30 == 20010102T133000 */
	string toICSString();
public:
	static bool isLeapYear(int year);
public:
	static const string monthString[];
	static const int daysInMonth[];
private:
	ICS_Clock clock;
	int year, month, dayOfMonth;
};


#endif /* DATE_H_ */
