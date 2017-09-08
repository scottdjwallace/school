/*
 * Test_ICS_Date.h
 *
 *  Created on: Mar 29, 2015
 *      Author: 7cm5_000
 */

#ifndef TEST_ICS_DATE_H_
#define TEST_ICS_DATE_H_

#include "ICS_TestHelper.h"
#include "../ics_files/ICS_Time/ICS_Date.h"

class Test_ICS_Date {
private:
	static bool testComparisons(int answers, ICS_Date& left, ICS_Date& right, bool proveIt){
		vector<bool> results;

		results.push_back(left > right); // 1
		results.push_back(left < right); // 0
		results.push_back(left >= right); // 1
		results.push_back(left <= right); // 0
		results.push_back(left == right); // 0
		results.push_back(left != right); // 1

		return hasTestPassed(results, answers, proveIt);
	}
public:
	static bool test(){
		cout << "testing ICS_Date... " << endl;

		bool proveIt = true;
		int answers;
		vector<bool> testResults;

		cout << "Testing Date Constructors" << endl;
		ICS_Date date0;
		ICS_Date date1("20140201T173000");
		ICS_Date date11("20140201T173000");
		ICS_Date date2("20150201T173000");
		ICS_Date date3("20150601T173000");
		ICS_Date date4("20150617T173000");
		ICS_Date date5("20150617T221000");

		cout << "    \"default\" = " << date0 << '"' << endl;
		cout << "    \"20140201T173000\" = " << date1 << '"' << endl;
		cout << "    \"20140201T173000\" = " << date11 << '"' << endl;
		cout << "    \"20150201T173000\" = " << date2 << '"' << endl;
		cout << "    \"20150601T173000\" = " << date3 << '"' << endl;
		cout << "    \"20150617T173000\" = " << date4 << '"' << endl;
		cout << "    \"20150617T221000\" = " << date5 << '"' << endl;
		cout << endl;

		// Test incrementByDays
		cout << "Testing += operator" << endl;
		ICS_Date date6;
		for (int i = 1; i <= 15; i += 1 ){
			date0 += 30;
			cout << "    \"default + " << (i * 30) << " days\" = " << date0 << '"' << endl;
		}
		cout << endl;
		// testComparisons order: !=, ==, <=, >=, <, >

		// Test dayDifference method
		cout << "difference in date1 and date11 (should be 0) = " << date1.dayDifference(date11) << endl;
		cout << "difference in date1 and date2 (should be 365) = " << date1.dayDifference(date2) << endl;
		cout << "difference in date1 and date2 (should be -120) = " << date3.dayDifference(date2) << endl;

		// test0: default and non-default
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, date0, date1, proveIt));

		// test1: all same
		answers = 0b011100;
		testResults.push_back(testComparisons(answers, date1, date11, proveIt));

		// test2: year equal; month different
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, date2, date3, proveIt));

		// test3: year different, month equal
		answers = 0b100101;
		testResults.push_back(testComparisons(answers, date2, date1, proveIt));

		// test4: year equal, month equal, day different
		answers = 0b101010;
		testResults.push_back(testComparisons(answers, date3, date4, proveIt));

		// test5: year, month and day equal, time different
		answers = 0b100101;
		testResults.push_back(testComparisons(answers, date5, date4, proveIt));


		ICS_Date redDate1, redDate2, redDate3, redDate4;

		// standard read and write
		ofstream outDate1("date1.txt", ios::out);
		outDate1 << date1;
		outDate1.close();

		ifstream inDate1("date1.txt", ios::in);
		inDate1 >> redDate1;
		inDate1.close();
		testResults.push_back(date1 == redDate1);

		// added new line character
		ofstream outDate2("date2.txt", ios::out);
		outDate2 << date2 << '\n';
		outDate2.close();

		ifstream inDate2("date2.txt", ios::in);
		inDate2 >> redDate2;
		inDate2.close();
		testResults.push_back(date2 == redDate2);

		// added key:
		ofstream outDate3("date3.txt", ios::out);
		outDate3 << "CREATED:";
		outDate3 << date3;
		outDate3.close();

		ifstream inDate3("date3.txt", ios::in);
		char key[64];
		inDate3.getline(key, 64, ':');
		inDate3 >> redDate3;
		inDate3.close();
		testResults.push_back(date3 == redDate3);

		// added key: and newline
		ofstream outDate4("date4.txt", ios::out);
		outDate4 << "CREATED:";
		outDate4 << date4 << '\n';
		outDate4.close();

		ifstream inDate4("date4.txt", ios::in);
		inDate4.getline(key, 64, ':');
		inDate4 >> redDate4;
		inDate4.close();
		testResults.push_back(date4 == redDate4);

		bool testPassed = true;
		for (unsigned int i = 0; i < testResults.size(); i += 1){
			if (testResults.at(i) != 1){
				testPassed = false;
			}
		}

		cout << "ICS_Date has " << (testPassed ? "passed." : "NOT passed.") << endl;

		return testPassed;
	}

};



#endif /* TEST_ICS_DATE_H_ */
