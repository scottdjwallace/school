/*
 * ICS_Time_Test.h
 *
 *  Created on: Feb 18, 2015
 *      Author: 7cm5_000
 */

#ifndef ICS_TIME_TEST_H_
#define ICS_TIME_TEST_H_

#include "../ics_files/ICS_Time/ICS_Clock.h"
#include "ICS_TestHelper.h"

bool testComparisons(int answers, ICS_Clock& left, ICS_Clock& right, bool proveIt){
	vector<bool> results;

	results.push_back(left > right);
	results.push_back(left < right);
	results.push_back(left >= right);
	results.push_back(left <= right);
	results.push_back(left == right);
	results.push_back(left != right);

	return hasTestPassed(results, answers, proveIt);
}

bool test_ICS_Clock(){
	cout << "testing ICS_Clock with valid input... " << endl;

	try {
		bool proveIt = true;
		int answers;
		vector<bool> testResults;

		ICS_Clock t0;
		ICS_Clock t111(1, 11);
		ICS_Clock t211(2, 11);
		ICS_Clock t113(1, 13);
		ICS_Clock t300(3, 0);
		ICS_Clock t241(2, 41);
		ICS_Clock t1111(1, 11);

		cout << "    t0 = " << t0 << endl;
		cout << "    t111 = " << t111 << endl;
		cout << "    t211 = " << t211 << endl;
		cout << "    t113 = " << t113 << endl;
		cout << "    t300 = " << t300 << endl;
		cout << "    t241 = " << t241 << endl;
		cout << "    t1111 = " << t1111 << endl;

		// testComparisons order: !=, ==, <=, >=, <, >

		// test0: default time and non-default time;
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, t0, t111, proveIt));

		// test1: two equal times
		answers = 0b011100;
		testResults.push_back(testComparisons(answers, t111, t1111, proveIt));

		// test 2: hour different, minute same
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, t111, t211, proveIt));

		// test3: hour same, minute different
		answers = 0b100101;
		testResults.push_back(testComparisons(answers, t113, t111, proveIt));

		// test 4: hour different, minute different
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, t113, t211, proveIt));

		bool testPassed = true;
		for (unsigned int i = 0; i < testResults.size(); i += 1){
			if (testResults.at(i) != 1){
				testPassed = false;
			}
		}

		cout << "ICS_Clock has " << (testPassed ? "passed." : "NOT passed.") << endl;
		return testPassed;
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	cout << "testing ICS_Clock with invalid input... " << endl;

	// test 5: invalid hour, valid minute
	try {
		cout << "Error should be: 13" << endl;
		ICS_Clock test5(13, 11);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 6: invalid hour, invalid minute
	try {
		cout << "Error should be: 16 or 100" << endl;
		ICS_Clock test6(16, 100);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 7: valid hour, invalid minute
	try {
		cout << "Error should be: 60" << endl;
		ICS_Clock test7(1, 60);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 8: negative hour, valid minute
	try {
		cout << "Error should be: -1" << endl;
		ICS_Clock test8(-1, 59);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 9: negative hour, invalid minute
	try {
		cout << "Error should be: -1 or 70" << endl;
		ICS_Clock test9(-1, 70);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 10: valid hour, negative minute
	try {
		cout << "Error should be: -70" << endl;
		ICS_Clock test10(2, -70);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 11: invalid hour, negative minute
	try {
		cout << "Error should be: 14 or -70" << endl;
		ICS_Clock test11(14, -75);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}

	// test 12: valid hour, negative minute
	try {
		cout << "Error should be: -1 or 70" << endl;
		ICS_Clock test12(2, -70);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}
	// test 13: negative hour and minute
	try {
		cout << "Error should be: -2 or -70" << endl;
		ICS_Clock test12(-2, -70);
	} catch (HourOutOfBounds& e){
		cerr << e.what() << endl;
	} catch (MinuteOutOfBounds& e){
		cerr << e.what() << endl;
	}
	return false;
}



#endif /* ICS_TIME_TEST_H_ */
