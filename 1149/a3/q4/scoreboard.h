#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

class Player;

class ScoreBoard {
	char board[16]; // actual values of game board - init to ' '
	bool gameEnd; // whether or not a game is in play
	int winsByA; // Number of wins by player A
	int winsByB; // Number of wins by player B
	int games; // Number of games so far

	// Singleton
	static ScoreBoard *single;
	static bool exists;

	// Players
	Player *A;
	Player *B;
public:
	ScoreBoard();
	~ScoreBoard();

	// Singleton
	ScoreBoard* getInstance();

	char getSquare(int x, int y);
	void startGame(Player* a, Player* b);
	bool gameOver();
	bool isOccupied(int x, int y);
	int madeSOS(int x, int y);
	void makeMove(int x, int y, char M, char name);
	bool oddGame();
};
#endif