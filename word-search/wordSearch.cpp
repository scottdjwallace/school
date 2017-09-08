#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include "wordSearch.h"
using namespace std;

BadSearchException::BadSearchException(const string& m) : message(m) {}


string& BadSearchException::what() { return message; }


WordSearch::WordSearch(string toHide, string difficulty){
	if (toHide.length() < 3 || toHide.length() > 10) {
		throw BadSearchException("Hidden string incorrect length");
	}
	if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard") {
		throw BadSearchException("Incorrect difficulty selection");
	}
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	size = 0;
	rowPos = 0;
	colPos = 0;
	direction = 'n';
	search = NULL;
	setSize(toHide,difficulty);
	makeEmptySearch();
	setRowPos();
	setColPos();
	setDirection();
	setSearch(toHide);
}


WordSearch::~WordSearch(){
	for (int i = 0; i < size; i++){
		delete[] search[i];
		search[i] = NULL;
	}
	delete[] search;
	search = NULL;
}


WordSearch::WordSearch(const WordSearch& original) {
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	size = original.getSize();
	rowPos = original.getRowPos();
	colPos = original.getColPos();
	direction = original.getDirection();
	search = new charArrayPtr [size];
	for (int i = 0; i < size; i++){
			search[i] = new char[size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			search[i][j] = original.getSearch()[i][j];
		}
	}
}


WordSearch& WordSearch::operator=(const WordSearch& right) {
	if (this != &right) {
		for (int i = 0; i < size; i++){
			delete[] search[i];
		}
		delete[] search;
		alphabet = "abcdefghijklmnopqrstuvwxyz";
		size = right.getSize();
		rowPos = right.getRowPos();
		colPos = right.getColPos();
		direction = right.getDirection();
		search = new charArrayPtr [size];
		for (int i = 0; i < size; i++){
			search[i] = new char[size];
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				search[i][j] = right.getSearch()[i][j];
			}
		}
	}
	return *this;
}


int WordSearch::getSize() const { return size; }
int WordSearch::getRowPos() const { return rowPos; }
int WordSearch::getColPos() const { return colPos; }
char WordSearch::getDirection() const { return direction; }


charArrayPtr* WordSearch::getSearch() const {
	charArrayPtr* newSearch = new charArrayPtr [size];
	for (int i = 0; i < size; i++){
		newSearch[i] = new char[size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			newSearch[i][j] = search[i][j];
		}
	}
	return newSearch;
}


int WordSearch::randInt(int upper) const {
	return static_cast<int>(1.0 * upper * rand() / RAND_MAX);
}

// gets a random character from our alphabet array
char WordSearch::randChar() {
	return alphabet.at(randInt(26));
}

// sets the size of the game based on length of string and the difficulty selected
void WordSearch::setSize(string toHide, string difficulty) {
	int length = toHide.length();
	if (difficulty == "easy") {
		size = 2 * length;
	}
	else if (difficulty == "medium") {
		size = 3 * length;
	}
	else if (difficulty == "hard") {
		size = 4 * length;
	}
}

// sets the rowPos for where we will hide the string
void WordSearch::setRowPos() {
	rowPos = randInt(size - 1);
}

// sets the colPos for where we will hide the string
void WordSearch::setColPos() {
	colPos = randInt(size - 1);
}

// sets the direction we will hide the string
void WordSearch::setDirection() {
	string dir = "nesw";
	direction = dir.at(randInt(4));
}

// creates an jumble full of zeroes
void WordSearch::makeEmptySearch(){
	search = new charArrayPtr [size];
	for (int i = 0; i < size; i++){
	    search[i] = new char[size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			search[i][j] = '0';
		}
	}
}


void WordSearch::setSearch(string toHide) {
	int hidden = 1;
	search[rowPos][colPos] = toHide.at(0);
	for (int i = 1; i < toHide.length(); i++) {
		if (direction == 'n') {
			if (rowPos - i < 0)
				break;
			search[rowPos - i][colPos] = toHide.at(i);
			hidden++;
		}
		else if (direction == 'e') {
			if (colPos + i > size - 1)
				break;
			search[rowPos][colPos + i] = toHide.at(i);
			hidden++;
		}
		else if (direction == 's') {
			if (rowPos + i > size - 1)
				break;
			search[rowPos + i][colPos] = toHide.at(i);
			hidden++;
		}
		else if (direction == 'w') {
			if (colPos - i < 0)
				break;
			search[rowPos][colPos - i] = toHide.at(i);
			hidden++;
		}
	}
	if (hidden == toHide.length()) {
		fillSearch();
	} else {
		setDirection();
		setSearch(toHide);
	}

}

// fills the rest of jumble with random letters
void WordSearch::fillSearch() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (search[i][j] == '0')
				search[i][j] = randChar();
		}
	}
}
