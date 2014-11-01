#include <iostream>
#include <string>
#include <fstream>
#include "scoreboard.h"
#include "player.h"

Player::Player(char name, ScoreBoard* score, std::string in): mypoints(0), name(name), score(score), input (in) { // Constructor
	if ("stdin" != input) {
		myReadFile.open(input.c_str());
	}
}

Player::~Player() { // Destructor
	if (input != "stdin") {
		myReadFile.close();
	}
}

void Player::makeMove() { // called by main or scoreboard when it's the player's turn
	int x, y;
	char m;
	if ("stdin" == input) {
		std::cin >> x >> y >> m;
	} else {
		if (myReadFile.is_open()) {
			myReadFile >> x >> y >> m;
		}
	}
	score->makeMove(x,y,m, name); // passes the rest of the responsibility to scoreboard
}

int Player::getPoints() { // called by scoreboard to see who won the game
	return mypoints;
}

void Player::addPoints(int p) { // called by scoreboard when player's turn gives them points
	mypoints += p;
}

bool Player::isFstream() {
	return (input != "stdin");
}



