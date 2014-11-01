#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "scoreboard.h"

ScoreBoard::ScoreBoard(){
	// initialize vars
	for (int i = 0; i < 16; ++i) {
		board[i] = ' ';
	}
	gameEnd = true;
	winsByA = 0;
	winsByB = 0;
	games = 1;
}

ScoreBoard::~ScoreBoard() {
	exists = false;
	// Singleton
	delete single;
}

ScoreBoard* ScoreBoard::single = NULL;
bool ScoreBoard::exists = false;

ScoreBoard* ScoreBoard::getInstance() { // singleton pointer getter
	if(! exists) {
		single = new ScoreBoard(); // Deleted in ~ScoreBoard()
		exists = true;
		return single;
	}
	else {
		return single;
	}
}

char ScoreBoard::getSquare(int x, int y) { // return the character at square (x, y)
	if (x > 3 || x < 0 || y > 3 || y < 0) {
		return '.';
	}
	// if the x, y is out of bounds, return '.'

	return board[x+4*y];
}
void ScoreBoard::startGame(Player* a, Player* b) { // Called at the start of every game
	gameEnd = false;
	A = a;
	B = b;
}
bool ScoreBoard::gameOver() { // Check if the game is over. Called by main to check before calling Player::MakeMove
	if (gameEnd) {
		return true;
	}
	for (int i = 0; i < 16; ++i) {
		if (' ' == board[i]) {
			return false;
		}
	}
	if (A->getPoints() > B->getPoints()) {
		winsByA += 1;
		std::cout << "A wins with " << A->getPoints() << " points" << std::endl;
	}
	if (B->getPoints() > A->getPoints()) {
		winsByB += 1;
		std::cout << "B wins with " << B->getPoints() << " points" << std::endl;
	}
	std::cout << "Score is" << std::endl;
	std::cout << "A " << A->getPoints() << std::endl;
	std::cout << "B " << B->getPoints() << std::endl;
	games += 1;
	gameEnd = true;
	return true;
}

bool ScoreBoard::isOccupied(int x, int y) { // check if square is ' '
	return (' ' != getSquare(x, y));
}

int ScoreBoard::madeSOS(int x, int y) { // returns number of SOS's made
	int result = 0;
	if (getSquare(x,y) == 'S') {
		if (getSquare(x,y-1) == 'O' && getSquare(x,y-2) == 'S') {
			result++;
		}
		if (getSquare(x+1,y-1) == 'O' && getSquare(x+2,y-2) == 'S') {
			result++;
		}
		if (getSquare(x+1,y) == 'O' && getSquare(x+2,y) == 'S') {
			result++;
		}
		if (getSquare(x+1,y+1) == 'O' && getSquare(x+2,y+2) == 'S') {
			result++;
		}
		if (getSquare(x,y+1) == 'O' && getSquare(x,y+2) == 'S') {
			result++;
		}
		if (getSquare(x-1,y+1) == 'O' && getSquare(x-2,y+2) == 'S') {
			result++;
		}
		if (getSquare(x-1,y) == 'O' && getSquare(x-2,y) == 'S') {
			result++;
		}
		if (getSquare(x-1,y-1) == 'O' && getSquare(x-2,y-2) == 'S') {
			result++;
		}
	}
	if (getSquare(x,y) == 'O') {
		if (getSquare(x,y-1) == 'S' && getSquare(x,y+1) == 'S') {
			result++;
		}
		if (getSquare(x+1,y-1) == 'S' && getSquare(x-1,y+1) == 'S') {
			result++;
		}
		if (getSquare(x-1,y-1) == 'S' && getSquare(x+1,y+1) == 'S') {
			result++;
		}
		if (getSquare(x-1,y) == 'S' && getSquare(x+1,y) == 'S') {
			result++;
		}
	}
	return result;
}
void ScoreBoard::makeMove(int x, int y, char M, char name) { // registers the move with the scoreboard, assigns points, calls repeat move on success
	int m = x, n = y, i = 0;
	std::cout << name << "’s move" << std::endl;
	while (isOccupied(m,n) && i < 17) {
		m++;
		if (m > 3) {
			m = 0;
			n++;
		}
		if (n > 3) {
			n = 0;
			m = 0;
		}
		i++; // counter to make program keep going
	}
	board[m+4*n] = M;
	int points = madeSOS(m,n);
	if (name == 'A') {
		if (points) {
			A->addPoints(points);
			A->makeMove();
		}
		if (A->isFstream()) {
			std::cout << "(plays " << n << " " << m << " " << M << ")" << std::endl;
		}
	}
	if (name == 'B') {
		if (points) {
			B->addPoints(points);
			B->makeMove();
		}
		if (B->isFstream()) {
			std::cout << "(plays " << n << " " << m << " " << M << ")" << std::endl;
		}
	}
}

bool ScoreBoard::oddGame() {
	return (1 == games%2);
}


