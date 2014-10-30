#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__
class ScoreBoard {
    char board[16];
    bool gameEnd;
    int winsByA;
    int winsByB;
    int games;
public:
	ScoreBoard();
	~ScoreBoard();

	char getSquare(int x, int y);
	void setSquare(int x, int y);
	bool gameOver();
};
#endif