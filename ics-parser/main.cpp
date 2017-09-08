/*
 * main.cpp
 *
 *  Created on: Mar 1, 2015
 *      Author: 7cm5_000
 */

#include <fstream>
#include <iostream>

#include "Engine.h"
#include "testing/Test_ICS_VCalendar.h"
#include "ics_files/ics.h"

using namespace std;

// main is subject to change, so only include one
// line method/function calls
int main(){
	//Test_ICS_VCalendar::test();
	ifstream fClarkCal("engine/testing/sample_ics/clarkcalendar.ics", ios::binary);
	ICS_VCalendar calClark;
	fClarkCal >> calClark;
	fClarkCal.close();

	cout << "Clark's schedule:" << endl;
	cout << calClark ;
	cout << endl;

	ifstream fChrisCal("engine/testing/sample_ics/chriscalendar.ics", ios::binary);
	ICS_VCalendar calChris;
	fChrisCal >> calChris;
	fChrisCal.close();

	cout << "Chris' schedule:" << endl;
	cout << calChris ;
	cout << endl;

	ifstream fPaulCal("engine/testing/sample_ics/paulcalendar.ics", ios::binary);
	ICS_VCalendar calPaul;
	fPaulCal >> calPaul;
	fPaulCal.close();

	cout << "Pauls's schedule:" << endl;
	cout << calPaul ;
	cout << endl;

	ifstream fAnthonyCal("engine/testing/sample_ics/anthonycalendar.ics", ios::binary);
	ICS_VCalendar calAnthony;
	fAnthonyCal >> calAnthony;
	fAnthonyCal.close();

	cout << "Anthony's schedule:" << endl;
	cout << calAnthony ;
	cout << endl;

	vector<ICS_VCalendar> cals;
	cals.push_back(calAnthony);
	cals.push_back(calClark);
	cals.push_back(calChris);
	cals.push_back(calPaul);

	ICS_Date startDate(2015, 3, 29);
	ICS_Date endDate(2015, 4, 4);
	try {
		ICS_VCalendar commonCal = Engine::generateFreeTimeCalendar(cals, startDate, endDate);
		cout << "writing commonCal." << endl;
		ofstream outFile("commonCal.ics", ios::out);
		outFile << commonCal;
		outFile.close();
		cout << "done." << endl;
	} catch (runtime_error& e) {
		cout << "Error: " << e.what() << endl;
	}
}


