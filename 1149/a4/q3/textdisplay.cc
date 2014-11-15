#include "textdisplay.h"

// char **theDisplay;            //the n x n display 
// const int gridSize;           //size of the grid (n)
// unsigned int colourCount[5];  //number of squares of each color

TextDisplay::TextDisplay(int n): gridSize(n) { //one arg constructor where the parameter is the gridSize
	// initialize colour counts to 0
	for(unsigned i = 1; i < n; ++i) {
		colourCount[i] = 0;
	}
	colourCount[0] = n*n;

	// initialize theDisplay to all '0'
	theDisplay = new char*[n];
	for(unsigned i = 0; i < n; ++i) {
		theDisplay[i] = new char[n];
	}
	for (unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < n; ++j) {
			theDisplay[i][j] = '0';
		}
	}
}

void TextDisplay::notify(int r, int c, char ch) { // called by Cell on change of state
	if (ch != theDisplay[r][c]) {
		int temp = theDisplay[r][c];
		colourCount[temp - '0']--;
		colourCount[ch - '0']++;
		theDisplay[r][c] = ch;
	}
}

bool TextDisplay::isFilled() { // returns whether the grid has n*n of one color and no other colors
	for(unsigned i = 0; i < 5; ++i) {
		if (gridSize*gridSize == colourCount[i]) {
			return true;
		}
		if (0 < colourCount[i]) {
			return false;
		}
	}
	return false;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) { // prints board to out
	for(unsigned i = 0; i < td.gridSize; ++i) {
		for(unsigned j = 0; j < td.gridSize; ++j) {
			out << td.theDisplay[i][j];
		}
		out << std::endl;
	}
	return out;
}

TextDisplay::~TextDisplay() { //dtor
	for (unsigned i = 0; i < gridSize; i++) {
		delete[] theDisplay[i];
	}
	delete[] theDisplay;
}

