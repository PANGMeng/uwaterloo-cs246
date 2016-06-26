#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "grid.h"

using namespace std;

int initIn(string line, Grid *g) { // interprets one line of init input
	// line is the line of input
	stringstream ss(line);
	int x, y, c;

	if (ss >> x && ss >> y) {
		if (-1 == x && -1 == y) {
			return -1;
		}
		if (ss >> c) {
			g->init(x,y,c);
		}
	}
	return 0;
	// returns 0 if the line is not "-1 -1"
	// if the line is "-1 -1", returns -1
}

int reportMoves(Grid* g, int moves) { // run at the end of every game-related command
	// outputs "[moves] moves left"
	// checks if game is over
	// returns 1 if game is over

	// prints moves & checks for loss
	if (moves == 1) {
		cout << "1 move left" << endl;
	} else if (moves == 0) {
		cout << "0 moves left" << endl;
		if (g->isWon()) {
			cout << "Won" << endl;
			return 1;
		} else {
			cout << "Lost" << endl;
			return 1;
		}
	} else {
		cout << moves << " moves left" << endl;
	}

	// checks if the player has won
	if (g->isWon()) {
		cout << "Won" << endl;
		return 1;
	}

	return 0;
}


// functions called when the following commands are detected by the program
//

void cNew(int n, Grid *g) { // command new n
	g->init(n);
}

void cInit(Grid *g) { // command init
	#ifdef DEBUG
		cerr << "in cInit" << endl;
	#endif // DEBUG
	string s;
	if (getline(cin, s)) {
		while (-1 != initIn(s, g)) {
			#ifdef DEBUG
				cerr << "Read line: " << s << endl;
			#endif // DEBUG
			getline(cin, s);
		}
		#ifdef DEBUG
			cerr << "Displaying grid: " << endl;
		#endif // DEBUG
		cout << (*g);
	}
}

void cInclude(string f, Grid *g) { // command include f
	ifstream myfile;
	myfile.open(f.c_str());
	string s;
	while (getline(myfile, s)) {
		initIn(s, g);
	}
	myfile.close();
	cout << (*g);
}

int cSwitch(int s, Grid *g, int &moves) { // command switch
	#ifdef DEBUG
		cerr << "in cSwitch" << endl;
	#endif // DEBUG

	g->change(s);
	moves--;
	cout << *g;
	if (reportMoves(g, moves)) {
		return 1;
	}
	return 0;
}

int main() {
	Grid* g = new Grid();
	int moves = -1; // number of moves left in the current game
	// initialized to -1 so that when checking if moves == 0 returns false

	#ifdef DEBUG
		cerr << "It has begun..." << endl;
	#endif // DEBUG

	string s;
	while (cin >> s) {
		#ifdef DEBUG
			cerr << "Input: " << s << endl;
		#endif // DEBUG
		// "switch" through the possible commands

		if ("new" == s) {
			int n;
			cin >> n;
			cNew(n, g);
		} 
			
		if ("init" == s) {
			cInit(g);
		}

		if ("include" == s) {
			cin >> s;
			cInclude(s, g);
		}
			
		if ("game" == s) {
			cin >> moves;
			// output number of moves left & check victory
			if (1 == reportMoves(g, moves)) {
				delete g;
				return 0;
			}
		}
			
		if ("switch" == s) {
			int n;
			cin >> n;
			#ifdef DEBUG
				cerr << "switching " << n << "..." << endl;
			#endif // DEBUG
			if (1 == cSwitch(n, g, moves)) {
				break;
			}
		}	
	}

	#ifdef DEBUG
		cerr << "It is done" << endl;
	#endif // DEBUG

	delete g;
	return 0;
}