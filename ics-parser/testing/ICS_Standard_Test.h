/*
 * ICS_Standard_Test.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ecosse_18
 */

#ifndef TESTING_ICS_STANDARD_TEST_H_
#define TESTING_ICS_STANDARD_TEST_H_

#include <iostream>
#include <fstream>
#include "../ics_files/ICS_Standard.h"

using namespace std;

void test_ICS_Standard() {
	ICS_Standard standard;
	cout  << "Test input Standard.h" << endl;

	ifstream inputStandard("sample_ics/coursecalendar.ics", ios::binary);
	cout << "Test Input for Standard.h " << endl;

	inputStandard >> standard;
	cout << "Test file output for Standard.h" << endl;

	ofstream outputStandard("sample_ics/outStandard.ics", ios::binary);
	outputStandard << standard; // file output

	cout << "Test console output for Standard.h is working" << endl;
	cout << "Test accessors Standard getDTstart " << standard.getDtstart() <<  endl;
	cout << "Test accessors Standard getRrule " << standard.getRrule() << endl;
	cout << "Test accessors Standard getTzname" << standard.getTzname() << endl;
	cout << "Test accessors Standard getTzoffsetfrom" << standard.getTzoffsetfrom() << endl;
	cout << "Test accessors Standard getTzffseto" << standard.getTzoffsetto() << endl;
}



#endif /* TESTING_ICS_STANDARD_TEST_H_ */
