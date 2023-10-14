#include "n_Queens.h"
#include <iostream>
#include <string>
#include <cmath>
#include "input.h"

bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace);

n_Queens::n_Queens()
{
	shiftDirection = 'R';
	firstColumnPermutaions = 0;
	boardSize = 0;
	filled = 0;
	gameWon = false;
}

void n_Queens::setBoardSize(int newBoardSize)
{
	boardSize = newBoardSize;
}

void n_Queens::setFilled(int newFilledAmount)
{
	filled = newFilledAmount;
}

int n_Queens::getBoardSize() const
{
	return boardSize;
}

int n_Queens::getFilled() const
{
	return filled;
}

void n_Queens::fillBoard()
{
	system("cls");
	BoardSpaces currentSpace;
	bool queenConflict = false;
	boardSize = inputInteger("Enter a number(1..100) of queens: ", 1, 100);
	currentSpace.setColumn(inputInteger("Enter the column to place the first queen : ", 1, boardSize));
	filledSpaces.push(currentSpace);
	firstColumnPermutaions++;
	do
	{
		queenConflict = checkIfConflict(boardSize, filledSpaces, currentSpace);
		if (queenConflict == false)
		{
			filled++;
			if (filled == boardSize)
			{
				gameWon = true;
				displayBoard(filledSpaces);
				break;
			}
			else
			{
				currentSpace.setRow(currentSpace.getRow() + 1);
				currentSpace.setColumn(1);
				filledSpaces.push(currentSpace);
			}
		}
		else if (currentSpace.getColumn() < boardSize)
		{
			currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
			filledSpaces.top() = currentSpace;
			
		}
		else if (currentSpace.getColumn() >= boardSize)
		{
			while (filledSpaces.size() > 1)
			{
				if (filledSpaces.top().getColumn() < boardSize)
				{
					currentSpace.setRow(filledSpaces.top().getRow());
					currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
					filledSpaces.top() = currentSpace;
					break;
				}
				filledSpaces.pop();
				filled--;				
			}
			if (filledSpaces.top().getRow() == 1)
			{
				if (firstColumnPermutaions == boardSize)
				{
					cout << "No Solution Found. " << endl;
					return;
				}
				else if (filledSpaces.top().getColumn() == boardSize)
				{
					filledSpaces.top().setColumn(boardSize - firstColumnPermutaions);
					currentSpace.setRow(1);
					currentSpace.setColumn(filledSpaces.top().getColumn());
					shiftDirection = 'L';
				}
				else
				{
					currentSpace.setRow(1);
					if (shiftDirection == 'L')
					{
						currentSpace.setColumn(filledSpaces.top().getColumn() - 1);
					}
					currentSpace.setColumn(filledSpaces.top().getColumn() + 1);
					filledSpaces.top() = currentSpace;
					firstColumnPermutaions++;
				}
				
			}		
		}

		
						
	} while (gameWon == false);
}



void n_Queens::displayBoard(stack<BoardSpaces> filledSpaces) const
{
	cout << endl << "\t" << boardSize << "-Queens Soulution." << endl;
	
	////going to get me the chessboard size and give me the box
	//cout << "\n\t" << string(boardSize * 2 + 1, char(205)) << endl;
	////have to loop through the chessboard (so the queensBoard)
	//for (const vector<char>& row : chessboard) 
	//{
	//	cout << "\t" << char(186);
	//	//print out the '-'
	//	for (char i : row) 
	//	{
	//		cout << i << char(186);
	//	}
	//	cout << endl;
	//	cout << "\t" << string(chessboard.size() * 2 + 1, char(205)) << endl;
	//}

	cout << "\n\t" << std::string(1, char(201));
    cout <<  string(boardSize * 2 + 1, char(205));
	cout << string(1, char(187)) << endl;
	/*for (int index = 0; index < boardSize - 1; index++)
	{
		std::cout << std::string(3, char(205));
	}*/

	for (int index = 0; index < boardSize; index++)
	{
		cout << "\t" << string(1, char(186)) << " ";
		for (int j = 0; j < boardSize; j++)
		{
			if (filledSpaces.top().getColumn() == (j + 1))
			{
				cout << 'Q';
			}
			else
			{
				cout << '-';
			}
			if (j < boardSize - 1)
			{
				cout << string(1, char(179));
			}			
		}
		cout << " " << string(1, char(186)) << endl;
		filledSpaces.pop();
	}

	/*for (int index = 0; index < boardSize; index++)
	{
		std::cout << std::string(1, char(186));
		for (int j = 0; j < boardSize; j++)
		{
			std::cout << " " << " " << std::string(1, char(186));
		}
	}*/
	
	cout << "\t" << std::string(1, char(200));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(188)) << endl;

	system("pause");
}



bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace)
{
	int stackSize = filledSpaces.size();

	if (filledSpaces.size() > 1)
	{
		filledSpaces.pop();
		if (abs(filledSpaces.top().getColumn() - currentSpace.getColumn()) <= 1)
		{
			return true;
		}
		else
		{
			while (!filledSpaces.empty())
			{
				if (filledSpaces.top().getColumn() == currentSpace.getColumn())
				{
					return true;
				}
				filledSpaces.pop();
			}
		}
	}	

	return false;
}


void n_QueensMenu()
{
	n_Queens game;
	game.fillBoard();
	do
	{		
		break;

	} while (true);

}