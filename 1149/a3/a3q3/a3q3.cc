#include "node.h"
#include <iostream>

using namespace std;

void parseLine(std::string line, Node * firstPlayer, Node * firstMatch);

int main() {
	Node * firstPlayer = new Node("FIRSTPLAYER");
	Node * firstMatch = new Node("FIRSTMATCH");
	firstPlayer->opponent1 = firstMatch;
	string input;
	while (getline(cin, input)) {
		parseLine(input, firstPlayer, firstMatch);
	}
	#ifdef DEBUG
	cout << "Now finishing..." << endl;
	#endif
	if (NULL != firstPlayer) {
		delete firstPlayer;
	}
	if (NULL != firstMatch) {
		delete firstMatch;
	}
	return 0;
}

