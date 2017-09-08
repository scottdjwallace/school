/*
 * ICS_Timezone_Test.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ecosse_18
 */

#ifndef TESTING_ICS_TIMEZONE_TEST_H_
#define TESTING_ICS_TIMEZONE_TEST_H_

#include <iostream>
#include <fstream>
#include "../ics_files/ICS_Timezone.h"

using namespace std;

void test_ICS_Timezone() {
	ICS_Timezone tz;
	ifstream inputTimezone("sample_ics/coursecalendar.ics",ios::binary);
	cout << "Test Input for Time zone.h " << endl;
	inputTimezone >> tz;
	cout << "Test output for Time zone.h" << endl;
	ofstream outputTimezone("outTimezone.ics", ios::binary);

	outputTimezone << tz;
	cout << "Test accessors Timezone getTzid " <<  tz.getTzid() <<  endl;
	cout << "Test accessors Timezone getDaylight " << tz.getDaylight() << endl;
	cout << "Test accessors Timezone getStandard" << tz.getStandard() << endl;
}




#endif /* TESTING_ICS_TIMEZONE_TEST_H_ */
