#pragma once

class BoardSpaces
{
private:
	int row;
	int column;

public:
	BoardSpaces();
	void setRow(int newRow);
	void setColumn(int newColumn);
	int getRow() const;
	int getColumn() const;
};

