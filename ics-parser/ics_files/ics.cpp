/*
 * ics.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: 13ch23
 */

#include <iostream>
#include <ios>
#include <fstream>
#include "ics.h"
#include "../dataStructures/stack.h"
using namespace std;

bool isValid(string filename){
	ifstream icsFile(filename.c_str(), ios::binary);
	Stack<string> stack;
	string line,value,tag,endVal;
	int pos = 0;
	bool valid = true;
	while (!icsFile.eof()){
		line = "";value = "";tag = "";endVal="";
		getline(icsFile, line);
		tag = line.substr(0,line.find(':'));
		pos = line.find(':');
		value = line.substr(pos+1,line.find("\r"));
		if(tag.compare("BEGIN") == 0)
			stack.push(value);
		if(tag.compare("END") == 0) {
			endVal = stack.pop();
			if(value.compare(endVal) != 0) {
				valid = false;
				break;
			}
		}
	}
	return valid;
}

void test_ICS() {
	bool valid = isValid("engine/testing/sample_ics/coursecalendar.ics");
	cout << "Testing ICS file structure coursecalendar should be 1 = " << valid << endl;
	valid = isValid("engine/testing/sample_ics/coursecalendar1.ics");
	cout << "Testing ICS file structure coursecalendar1 should be 0 = " << valid << endl;
	valid = isValid("engine/testing/sample_ics/coursecalendar2.ics");
	cout << "Testing ICS file structure coursecalendar2 should be 0 = " << valid << endl;
}
