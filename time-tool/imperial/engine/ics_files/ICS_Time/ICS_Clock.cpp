/* ICS_Clock.cpp
 * Coded by: Paul Allison.
 * Version 1: Submitted to team on February 18th, 2015.
 */

#include "ICS_Clock.h"
//#include "../icsExceptions.h"
#include <string>
#include <iostream>
using namespace std;

ofstream& operator<<(ofstream& file, const ICS_Clock& time){
	file << (time.hour < 10 ? "0" : "") << time.hour;
	file << (time.minute < 10 ? "0" : "") << time.minute;
	file << "00";
	return file;
}

ostream& operator<<(ostream& output, const ICS_Clock& time){
	output << time.hour << ":" << (time.minute >= 10 ? "" : "0") << time.minute;
	return output;
}

ICS_Clock::ICS_Clock(){
	this -> hour = 0;
	this -> minute = 00;
};

ICS_Clock::ICS_Clock(int hour, int minute) throw (HourOutOfBounds, MinuteOutOfBounds){
	if (hour < 0 || hour > 23) throw HourOutOfBounds(hour);
	if (minute < 0 || minute > 59) throw MinuteOutOfBounds(minute);

	this -> hour = hour;
	this -> minute = minute;
};

//Passed preliminary tests.
int ICS_Clock::getHour() const{
	return this -> hour;
}

//Passed preliminary tests.
int ICS_Clock::getMinute() const{
	return this -> minute;
}

ICS_Clock& ICS_Clock::setClock(int hour, int minute) throw (HourOutOfBounds, MinuteOutOfBounds){
	if (hour < 0 || hour > 23) {
		throw HourOutOfBounds(hour);
	}
	if (minute < 0 || minute > 59) {
		throw MinuteOutOfBounds(minute);
	}

	this -> hour = hour;
	this -> minute = minute;
	return *this;
}

ICS_Clock& ICS_Clock::setHour(int hour) throw (HourOutOfBounds){
	if (hour < 0 || hour > 23){
			throw HourOutOfBounds(hour);
	}
	this->hour = hour;
	return *this;
}

ICS_Clock& ICS_Clock::setMinute(int minute) throw (MinuteOutOfBounds){
	if (minute < 0 || minute > 59){
		throw MinuteOutOfBounds(minute);
	}
	this->minute = minute;
	return *this;
}

int ICS_Clock::compareTo(const ICS_Clock& otherTime){
	if (hour != otherTime.getHour()) {
		if (hour > otherTime.getHour()){
			return 1;
		} else {
			return -1;
		}
	}

	if (minute > otherTime.getMinute()){
		return 1;
	}
	if (minute == otherTime.getMinute()){
		return 0;
	}
	else {
		return -1;
	}
}

bool ICS_Clock::operator>(const ICS_Clock& right) const{
	if (hour == right.hour){
		return minute > right.minute;
	}

	return hour > right.hour;
}

bool ICS_Clock::operator<(const ICS_Clock& right) const{
	return right > *this;
}

bool ICS_Clock::operator==(const ICS_Clock& right) const{
	return hour == right.hour && minute == right.minute;
}

bool ICS_Clock::operator!=(const ICS_Clock& right) const{
	return !(*this == right);
}

bool ICS_Clock::operator>=(const ICS_Clock& right) const{
	return !(*this < right);
}

bool ICS_Clock::operator<=(const ICS_Clock& right) const{
	return !(*this > right);
}

string ICS_Clock::toString(){
	char cA[9];
	cA[0] = '0' + (hour / 10);
	cA[1] = '0' + (hour % 10);
	cA[2] = ':';
	cA[3] = '0' + (minute / 10);
	cA[4] = '0' + (minute % 10);
	cA[5] = ':';
	cA[6] = '0';
	cA[7] = '0';
	cA[8] = 0;
	return cA;
}

string ICS_Clock::toICSString(){
	char cA[7];
	cA[0] = '0' + (hour / 10);
	cA[1] = '0' + (hour % 10);
	cA[2] = '0' + (minute / 10);
	cA[3] = '0' + (minute % 10);
	cA[4] = '0';
	cA[5] = '0';
	cA[6] = 0;
	return cA;
}
