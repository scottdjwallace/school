/*
 * icsReadNext.h
 *
 *  Created on: Feb 28, 2015
 *      Author: 7cm5_000
 */

#ifndef ICSREADNEXT_H_
#define ICSREADNEXT_H_

#include <ios>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

char getNewlineChar(ifstream& file);

void trimRight(string& s);

//void printWithSpacing(int n, string s);


#endif /* ICSREADNEXT_H_ */
