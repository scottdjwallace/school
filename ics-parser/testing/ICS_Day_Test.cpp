#include <vector>
#include <iostream>
#include <fstream>
#include "ICS_Day_Test.h"
#include "../ics_files/ICS_Day.h"

using namespace std;

void test_ICS_Day(){
	vector<bool> testResults;
	//date constructor tests
	ICS_Day test1(2015, 02, 11); //past
	ICS_Day test2(2016, 04, 05); //future day
	ICS_Day test3(2015, 03, 26); //current day
	ICS_Day test4(2302349, 03, 05); //extremely future year
	ICS_Day test5(2015, 14, 25); //bad month
	ICS_Day test6(2015, 03, 35); //bad year
	ICS_Day test7(2015, 14, 35); //bad month and year

	ifstream fileVEvents("test_vevents00_validEvents.ics", ios::binary);

	ICS_VEvent feb11_1, feb12_1, feb13_1, feb12_2, feb11_2;

	fileVEvents >> feb11_1;
	fileVEvents >> feb12_1;
	fileVEvents >> feb13_1;
	fileVEvents >> feb12_2;
	fileVEvents >> feb11_2;

	fileVEvents.close();
	try{
		test1.add(feb11_1); //adding same day event
		testResults.push_back(true);
	}
	catch(DifferentDayException &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}
	try{
		test1.add(feb11_2); //adding same day event
		testResults.push_back(true);
	}
	catch(DifferentDayException &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}
	try{
		test1.add(feb12_1); //adding different day event
		testResults.push_back(true);
	}
	catch(DifferentDayException &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}

	cout << test1; //console output of several events

	//access events
	try {
		ICS_VEvent buffer = test1[0];
		testResults.push_back(true);
	}
	catch(out_of_range &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}

	//access an event that is out of bounds
	try {
		ICS_VEvent buffer1 = test1[5];
		testResults.push_back(true);
	}
	catch(out_of_range &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}


	//vector of events on different days
	vector<ICS_VEvent> testEventsBad;
	testEventsBad.push_back(feb11_1);
	testEventsBad.push_back(feb12_1);
	try{
		ICS_Day test8(testEventsBad);
		testResults.push_back(true);
	}
	catch (DifferentDayException &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}

	//vector of events on same day
	vector<ICS_VEvent> testEvents;
	testEvents.push_back(feb12_1);
	testEvents.push_back(feb12_2);
	try{
		ICS_Day test9(testEvents);
		cout << test9; //try output of several events, testEvents
		testResults.push_back(true);
	}
	catch (DifferentDayException &e){
		testResults.push_back(false);
		cout << e.what() << endl;
	}

	//empty vector
	vector<ICS_VEvent> emptyEvents;
	ICS_Day test10(emptyEvents);
	//empty vector output
	cout << test10;
	//add event to empty vector
	try{
		test10.add(feb13_1);
		testResults.push_back(true);
	}
	catch (DifferentDayException &e) {
		testResults.push_back(false);
		cout << e.what() << endl;
	}

	//testing size
	if(test1.size() == 2) testResults.push_back(true); //should have 2 events
	else testResults.push_back(false);

	if(test10.size() == 1) testResults.push_back(true); //should have 1 event
	else testResults.push_back(false);

	if(test3.size() == 0) testResults.push_back(true); //should be empty
	else testResults.push_back(false);

	//testing output to file
	ofstream testFile;
	testFile.open("testFile.ics");
	//testFile << test1;
	testFile.close();
	cout << "done." << endl;
}
