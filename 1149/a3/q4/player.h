#include "scoreboard.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player {
private:
	std::string input; // source for the moves the player makes
	char name; // Player name - either 'A' or 'B'
	int mypoints; // Player's score in the game
	ScoreBoard* score; // Singleton scoreBoard object
	std::ifstream myReadFile; // File from which to read commands

	// A new player object is created every game
public:
	Player(char name, ScoreBoard* score, std::string in);
	~Player();
	void makeMove();
	int getPoints();
	void addPoints(int p);
	bool isFstream();
};

#endif // __PLAYER_H__
