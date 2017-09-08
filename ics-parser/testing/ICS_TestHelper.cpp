/*
 * TT_Tester.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: 7cm5_000
 */

#include <iostream>
#include "ICS_TestHelper.h"

bool hasTestPassed(vector<bool> results, int answers, bool proveIt){
	bool good = true;
	if (proveIt) cout << "    ";
	for (unsigned int i = 0; i < results.size(); i += 1){
		if (proveIt) cout << (answers >> i) % 2 << results.at(i) << " ";
		if (results.at(i) != (answers >> i) % 2) good = false;
	}
	if (proveIt) cout << endl;
	return good;
}

void printTestResults(vector<bool> testResults){
	cout << "testResults: ";
	for (unsigned int i = 0; i < testResults.size(); i += 1){
		cout << testResults.at(i) << " ";
	}
	cout << endl;
}


