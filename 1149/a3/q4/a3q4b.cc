#include <iostream>
#include <string>
#include <fstream>
#include "scoreboard.h"
#include "player.h"

using namespace std;

int main() {
	ScoreBoard* sb = sb->getInstance();
	string s;
	while (true) {
		cin >> s;
		if (s == "quit") {
			break;
		} else if (s == "game") {
			cin >> s;
			Player* A = new Player('A', sb, s);
			cin >> s; 
			Player* B = new Player('B', sb, s);

			sb->startGame(A, B);

			#ifdef DEBUG
			cout << sb->oddGame() << endl;
			#endif

			if (sb->oddGame()) {
				A->makeMove();
			}
			while(!sb->gameOver()) {
				#ifdef DEBUG
				cout << "still playing the game" << endl;
				#endif
				B->makeMove();
				if (!sb->gameOver())
				{
					A->makeMove();
				}
			}

			delete A;
			delete B;
		}
	}
	return 0;
}