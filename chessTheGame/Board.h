#pragma once
#include "Figure.h"
#include "Square.h"

namespace
{
	const int FIRST_COORD_OF_BOARD = 0;
	const int LAST_COORD_OF_BOARD = 8;
}

class Board
{
public:
	Board();
	void createEmptyBoard();
	Square* getSquare(const Position& position);
	bool isValidCoordinates(const Position& currentPosition, const Position& lastPosition);
	bool isFigurePlaced(const Position& position);

protected:
	Square m_board[LAST_COORD_OF_BOARD][LAST_COORD_OF_BOARD];
};

