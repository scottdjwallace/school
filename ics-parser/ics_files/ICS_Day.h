/*
 * ICS_Day.h
 *
 *  Created on: Feb 15, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_Day_H_
#define ICS_Day_H_

#include <string>
#include <vector>
#include "ICS_VEvent.h"

using namespace std;

/* The ICS_Day class is essentially a wrapper class around a vector
 * of ICS_VEvents that occur on a specific date.
 */

class DifferentDayException : public runtime_error {
public:
	DifferentDayException(string message) :
		runtime_error(message + " Error Code: ") {};
};

class DayException : public runtime_error {
public:
	DayException(string message) :
		runtime_error(message + " Error Code: ") {};
};

class ICS_Day {
	friend ostream& operator<<(ostream& output, ICS_Day& right);

	// writes the vector of VEvent as a sequential series of VEVENTs to .ics file
	friend ofstream& operator<<(ofstream& file, const ICS_Day& right);
public:
	ICS_Day();
	ICS_Day(const ICS_Day& other);
	ICS_Day(const ICS_Date& date);
	ICS_Day(int year, int month, int dayOfMonth);
	ICS_Day(vector<ICS_VEvent> daysEvents) throw (DifferentDayException);

	ICS_VEvent& operator[](int index);

	size_t size() const;
	ICS_Date getDate() const;

	/* Chris can do this one if you have trouble. Basically,
	 * run through the > two arrays (which will be sorted,
	 * this->sort() first) with two integers (i and j), testing for
	 * overlap in a similar fashion to merge sort. */
	static ICS_Day generateCommonDay(vector<ICS_Day> otherDays);

	void pop(int);
	/* use ICS_VEvent.startDate >, <, ==... other.StartDate
	 * Must run in a good run time {i.e. n(log(n))}  */
	void sortVEvents();

	void add(const ICS_VEvent& event) throw (DifferentDayException);
private:
	bool dateSet = false;
	vector<ICS_VEvent> daysEvents;
	ICS_Date date;
	//bool checkSameDay(vector<ICS_VEvent> testDaysEvents);
};



#endif /* ICS_Day_H_ */
