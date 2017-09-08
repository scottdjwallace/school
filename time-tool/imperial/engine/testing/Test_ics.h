/*
 * Test_ics.h
 *
 *  Created on: Mar 29, 2015
 *      Author: 7cm5_000
 */

#ifndef TEST_ICS_H_
#define TEST_ICS_H_

#include <iostream>
#include <ios>
#include <fstream>
#include "../ics_files/ics.h"
using namespace std;

class Test_ics {
public:
	void test_ICS() {
		bool valid = isValid("testing/sample_ics/coursecalendar.ics");
		cout << "Testing isValid ICS file tester bool(1/0): " << valid << endl;
	}
};


#endif /* TEST_ICS_H_ */
