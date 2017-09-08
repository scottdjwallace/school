/*
 * Testing script for all Engine objects, except ICS_Clock,ICS_Day and ICS_Date
 *
 * All objects are located in ../ics_files/*
 */

#include <string>
#include <vector>
#include <cstdlib>
#include <ios>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "Test_ICS_Date.h"

#include "ICS_Clock_Test.h"
#include "ICS_Day_Test.h"
#include "ICS_Daylight_Test.h"
#include "ICS_Standard_Test.h"
#include "ICS_TestHelper.h"
#include "ICS_Timezone_Test.h"
#include "../ics_files/ics.h"

using namespace std;

void unit_tests(){

	cout << "TESTING SCRIPT HAS BEGUN...\n" << endl;
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_CLOCK...\n" << endl;
	test_ICS_Clock();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_Date...\n" << endl;
	Test_ICS_Date::test();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_Day...\n" << endl;
	test_ICS_Day();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_Timezone...\n" << endl;
	test_ICS_Timezone();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_Daylight...\n" << endl;
	test_ICS_Daylight();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ICS_Standard...\n" << endl;
	test_ICS_Standard();
/**************************************************************************/
	cout << "\nCURRENTLY TESTING ics...\n" << endl;
	test_ICS();
/**************************************************************************/
	cout << "TESTING SCRIPT HAS ENDED!!!\n" << endl;
}
