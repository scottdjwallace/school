/*
 * icsReadNext.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: 7cm5_000
 */

#include <iostream>
#include "icsHelpers.h"

char getNewlineChar(ifstream& file){
	streampos pos = file.tellg();
	string line;
	getline(file, line);
	file.seekg(pos, ios_base::beg);

	return line.at(line.length() - 1);
}

void trimRight(string& s){
	int j = s.length() - 1;
	for (; j >= 0; j -= 1){
		int c = s[j];
		if (!(c == 0 || c == 0x20 || (c >= 0x9 && c <= 0xd))){
			break;
		}
	}
	s = s.substr(0, j + 1);
}

/*
void printWithSpacing(int n, string s){
	for (int i = 0; i < n; i += 1){
		cout << "    ";
	}
	cout << s << endl;
}
*/
