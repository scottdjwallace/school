/*
 * Test_ICS_VCalendar.h
 *
 *  Created on: Mar 29, 2015
 *      Author: 7cm5_000
 */

#ifndef TEST_ICS_VCALENDAR_H_
#define TEST_ICS_VCALENDAR_H_

#include <fstream>
#include "../ics_files/ICS_VCalendar.h"

using namespace std;

class Test_ICS_VCalendar {
public:
	static void test(){
		cout << "opening engine/testing/sample_ics/coursecalendar.ics..." << endl;
		ifstream file0("engine/testing/sample_ics/coursecalendar.ics", ios::binary);
		ICS_VCalendar courseCalendar;
		file0 >> courseCalendar;
		file0.close();
		cout << "successfully read courcecalendar.ics into ICS_VCalendar object." << endl << endl;

		cout << "opening engine/testing/sample_ics/basic_daily.ics..." << endl;
		ifstream file1("engine/testing/sample_ics/basic_daily.ics", ios::binary);
		ICS_VCalendar basicDaily;
		file1 >> basicDaily;
		file1.close();
		cout << "successfully read basic_daily.ics into ICS_VCalendar object." << endl << endl;
		printCalStats(courseCalendar, "coursecalendar", 27, 27);
		printCalStats(basicDaily, "basic_daily", 2, 1);

		cout << "Creating 7 new dates..." << endl;
		vector<ICS_Date> dates;
		ICS_Date dateSun(2015, 3, 29);
		for (unsigned int i = 0 ; i < 7; i += 1){
			ICS_Date date = dateSun + i;
			dates.push_back(date);
		}
		cout << "Dates created." << endl << endl;

		getAndDisplayVEvents(courseCalendar, "coursecalendar", dates);
		getAndDisplayVEvents(basicDaily, "basic_daily", dates);
	}
	static void printCalStats(ICS_VCalendar& cal, string label, int eventCount, int recurringEventCount){
		cout << label << " stats:" << endl;
		cout << "    number of events (should be " << eventCount << " ): " << cal.getNumberOfVEvents() << endl;
		int countRecurringEvents = 0;
		for (unsigned int i = 0; i < cal.getNumberOfVEvents(); i += 1){
			if (cal.getVEvents()[i].hasRRule()){
				countRecurringEvents += 1;
			}
		}
		cout << "    number of recurring events (should be " << recurringEventCount << "): " << countRecurringEvents << endl;
		cout << endl;
	}
	static void icsFileReadWriteTest(){
		cout << "opening sample.ics" << endl;
		ifstream sample("engine/testing/sample_ics/coursecalendar.ics", ios::binary);
		sample >> skipws;

		ICS_VCalendar cal;
		try {
			sample >> cal;
		} catch (runtime_error& e){
			cout << "Error: " << e.what() << endl;
		}
		sample.close();
		cout << "finished reading sample.ics" << endl << endl;

		cout << "outputting sampleCopy.ics" << endl;
		ofstream sampleCopy("sampleCopy.ics", ios::out);
		sampleCopy << cal;
		sampleCopy.close();
		cout << "finished writing sampleCopy.ics" << endl;
	}
private:
	static void getAndDisplayVEvents(ICS_VCalendar& cal, string label, vector<ICS_Date>& dates){
		cout << "Getting events from " << label << ":" << endl;
		vector<ICS_Day> generatedDays;
		for (unsigned int i = 0; i < dates.size(); i += 1){
			ICS_Date currentDate = dates.at(i);
			cout << "Getting events on " << currentDate << endl;
			ICS_Day currentDay = cal.getEventsOn(currentDate);
			generatedDays.push_back(currentDay);
		}
		cout << endl;

		cout << "Displaying events from " << label << ":" << endl;
		for (unsigned int i = 0; i < generatedDays.size(); i += 1){
			ICS_Date currentDate = generatedDays.at(i).getDate();
			displayDay(generatedDays.at(i), currentDate.toString());
		}
		cout << endl;
	}

	static void displayDay(ICS_Day& day, string name){
		cout << "Events on " << day.getDate() << " (" << "):" << endl;
		for (unsigned int i = 0; i < day.size(); i += 1){
			cout << day[i];
			cout << endl;
		}
	}
};



#endif /* TEST_ICS_VCALENDAR_H_ */
