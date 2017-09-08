/*
 * wordSearch.h
 *
 *  Created on: Apr 4, 2015
 *      Author: ecosse_18
 */

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

typedef char* charArrayPtr;

class WordSearch {
public:
	WordSearch(string, string);
	~WordSearch();
	WordSearch(const WordSearch&);
	WordSearch& operator=(const WordSearch&);
	charArrayPtr* getSearch() const;
	int getSize() const;
	int getRowPos() const;
	int getColPos() const;
	char getDirection() const;

private:
	string alphabet;
	charArrayPtr* search;
	int size;
	int rowPos;
	int colPos;
	char direction;
	int randInt(int) const;
	char randChar();
	void setSize(string, string);
	void setDirection();
	void setRowPos();
	void setColPos();
	void setSearch(string);
	void makeEmptySearch();
	void fillSearch();
};

class BadSearchException {
public:
	BadSearchException(const string&);
	string& what();
private:
	string message;
};


#endif /* WORDSEARCH_H_ */
