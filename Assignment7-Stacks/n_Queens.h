#pragma once
#include <stack>
#include "BoardSpaces.h"

using namespace std;

class n_Queens : public BoardSpaces
{
private:

	stack <BoardSpaces> filledSpaces;
	char shiftDirection;
	int firstColumnPermutaions;
	int filled;
	int boardSize;
	bool gameWon;

public:
	n_Queens();
	void setBoardSize(int newBoardSize);
	void setFilled(int newFilledAmount);
	int getBoardSize() const;
	int getFilled() const;
	void fillBoard();
	void displayBoard(stack<BoardSpaces> filledSpaces) const;
};


