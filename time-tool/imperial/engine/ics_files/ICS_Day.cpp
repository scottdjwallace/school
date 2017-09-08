
#include <string>
#include <vector>

#include "ICS_Day.h"
#include "ICS_VEvent.h"
#include "ICS_Time/ICS_Date.h"

using namespace std;

ICS_Day ICS_Day::generateCommonDay(vector<ICS_Day> otherDays){
	ICS_Day day(1, 1, 1);
	return day;
}

ICS_Day::ICS_Day(const ICS_Day& other){
	if (other.daysEvents.size() == 0){
		this->date = other.date;
		this->dateSet = true;
	}
	for (unsigned int i = 0; i < other.daysEvents.size(); i += 1){
		add(other.daysEvents[i]);
	}
}

/* Programmer readable console output.
 * i.e. Monday: VEventCount, stuff
 *      Tuesday: VEventCount, stuff... */
ICS_Day::ICS_Day(vector<ICS_VEvent> daysEvents) throw (DifferentDayException){
	for (unsigned int i = 0; i < daysEvents.size(); i += 1){
		add(daysEvents[i]);
	}
};

ICS_Day::ICS_Day(int year, int month, int dayOfMonth){
	this->date.setYear(year);
	this->date.setMonth(month);
	this->date.setDayOfMonth(dayOfMonth);
	this->dateSet = true;
};

ICS_Day::ICS_Day(const ICS_Date& date){
	this->date.setYear(date.getYear());
	this->date.setMonth(date.getMonth());
	this->date.setDayOfMonth(date.getDayOfMonth());
	this->dateSet = true;
}

/*
bool ICS_Day::checkSameDay(vector<ICS_VEvent> testDaysEvents){
	if(testDaysEvents.size() <= 0){
	} else {
		for(unsigned int i = 0; i < testDaysEvents.size(); i++){
			if(!testDaysEvents[0].onDate()) {
				throw DifferentDayException("Not all events are on the same day!");
				return false;
			}
		}
	}
	return true;
}
*/

ostream& operator<<(ostream& output, ICS_Day& right){
	if(right.daysEvents.size() > 0){
		right.sortVEvents();
		output << "# of vEvents: " << right.size();
		//output << "Earliest start time: " << right.getDaysEvents[0].getStartTime();
		output << "Latest end time: " << right.daysEvents[right.size() - 1].getEndTime();
	} else output << "No events are present.";
	return output;
};

// writes the vector of VEvent as a list of VEVENTs to .ics file
ofstream& operator<<(ofstream& file, const ICS_Day& right){
	for(size_t i = 0; i < right.daysEvents.size(); i++){
		file << right.daysEvents[i];
	}
	return file;
};

ICS_VEvent& ICS_Day::operator[](int index){
	if (index < this->daysEvents.size()){
		return this->daysEvents[index];
	} else throw out_of_range("No event at this index");
};

/* use ICS_VEvent.startDate >, <, ==... other.StartDate
 * Must run in a good run time {i.e. n(log(n))}, insertion sort  */
void ICS_Day::sortVEvents(){
	if (daysEvents.size() <= 1) return;
	int d;
	ICS_VEvent temp;
	for (unsigned int c = 1 ; c <= daysEvents.size() - 1; c++) {
		d = c;
		while ( d > 0 && daysEvents[d].getStartTime() < daysEvents[d-1].getStartTime()) {
			temp = daysEvents[d];
			daysEvents[d] = daysEvents[d-1];
			daysEvents[d-1] = temp;
			d--;
		}
	}
}

size_t ICS_Day::size() const{
	return daysEvents.size();
}

void ICS_Day::add(const ICS_VEvent& event) throw (DifferentDayException){
	if(!dateSet){ // no date or events
		this->date.setYear(event.getStartTime().getYear());
		this->date.setMonth(event.getStartTime().getMonth());
		this->date.setDayOfMonth(event.getStartTime().getDayOfMonth());
		daysEvents.push_back(event);
		dateSet = true;
	} else {
		ICS_Date start = event.getStartTime();
		if (this->date.getYear() == start.getYear() && this->date.getMonth() == start.getMonth() && this->date.getDayOfMonth() == start.getDayOfMonth()){
			daysEvents.push_back(event);
		} else if (this->date.getYear() == event.getStartTime().getYear() && this->date.getMonth() == event.getStartTime().getMonth() && this->date.getDayOfMonth() == event.getStartTime().getDayOfMonth()){
				daysEvents.push_back(event);
		} else throw DifferentDayException("Event is not on the same day.");
	}
	this->sortVEvents();
};

void ICS_Day::pop(const int i){
	this->daysEvents.erase(daysEvents.begin() + i);
};

ICS_Date ICS_Day::getDate() const{
	return this->date;
};
