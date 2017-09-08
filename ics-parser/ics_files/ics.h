/*
 * ics.h
 *
 *  Created on: Mar 19, 2015
 *      Author: 13ch23
 */

#ifndef ICS_H_
#define ICS_H_

#include <string>
using namespace std;

// returns a boolean value representing whether an icsFile is valid structure(start tags match end tags in order)
bool isValid(string filename);
void test_ICS();

#endif /* ICS_H_ */
