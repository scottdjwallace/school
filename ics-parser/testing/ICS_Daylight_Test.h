/*
 * ICS_Daylight_Test.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ecosse_18
 */

#ifndef TESTING_ICS_DAYLIGHT_TEST_H_
#define TESTING_ICS_DAYLIGHT_TEST_H_

#include <iostream>
#include "../ics_files/ICS_Daylight.h"

using namespace std;

void test_ICS_Daylight() {
	cout << "\nCURRENTLY TESTING ICS_DAYLIGHT...\n" << endl;

	ICS_Daylight day;
	cout  << "Test input ICS_Daylight.h" << endl;

	ifstream inputDaylight("sample_ics/coursecalendar.ics", ios::binary);
	cout << "Test Input for ICS_Daylight.h " << endl;

	inputDaylight >> day;
	cout << "Test file output for ICS_Daylight.h" << endl;

	ofstream outputDaylight("sample_ics/outDaylight.ics", ios::binary);
	outputDaylight << day; // file output

	cout << "Test console output for Standard.h is working" << endl;
	cout << "Test accessors Daylight getDTstart " << day.getDtstart() <<  endl;
	cout << "Test accessors Daylight getRrule " << day.getRrule() <<  endl;
	cout << "Test accessors Daylight getTzname " << day.getTzname() <<  endl;
	cout << "Test accessors Daylight getTzoffsetfrom " << day.getTzoffsetfrom() <<  endl;
	cout << "Test accessors Daylight getTzoffsetto " << day.getTzoffsetto() <<  endl;
}


#endif /* TESTING_ICS_DAYLIGHT_TEST_H_ */
