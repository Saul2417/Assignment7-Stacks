#pragma once
#include "BoardSpaces.h"

BoardSpaces::BoardSpaces()
{
	row = 1;
	column = 0;
}
void BoardSpaces::setRow(int newRow)
{
	row = newRow;
}
void BoardSpaces::setColumn(int newColumn)
{
	column = newColumn;
}
int BoardSpaces::getRow() const
{
	return row;
}
int BoardSpaces::getColumn() const
{
	return column;
}