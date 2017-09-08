#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include "wordSearch.h"
using namespace std;

void showSearch(const charArrayPtr* search, const int size) {
	int i, j;
	cout << "\n  ";
	for (i = 0; i < size; i++)
		if (i < 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
	cout << endl;
	for (i = 0; i < size; i++) {
		if (i < 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
		for (j = 0; j < size; j++)
			cout << search[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
} // end showSearch


int main() {
	string toHide;
	string difficulty;
	int guessRow, guessCol;
	int start, finish;
	char guessDirection;

	cout << "Provide a string to hide in the search, all lower case: ";
	cin >> toHide;
	cout << "\nChoose your difficulty level: \"easy\", \"medium\" or \"hard\": ";
	cin >> difficulty;

	WordSearch* ws;
	try {
		ws = new WordSearch(toHide, difficulty);
	} catch (BadSearchException& e) {
		cerr << e.what();
		return 1;
	}
	showSearch(ws->getSearch(), ws->getSize());
	start = static_cast<int>(time(NULL));
	cout << "Enter row location: ";
	cin >> guessRow;
	cout << "Enter column location: ";
	cin >> guessCol;
	cout << "Enter direction (\"n\", \"e\", \"s\" or \"w\"): ";
	cin >> guessDirection;
	finish = static_cast<int>(time(NULL));
	if (guessRow == ws->getRowPos() && guessCol == ws->getColPos() &&
			guessDirection == ws->getDirection())
		cout << "You found it!" << endl;
	else {
		cout << "Wrong location..." << endl;
		cout << "The location is row: " << ws->getRowPos() << " col: " << ws->getColPos()
				<< ", direction: " << ws->getDirection() << endl;
	}
	cout << "You took " << (finish - start) << " seconds." << endl;
	delete ws;
	ws = NULL;
	return 0;
} // end main
