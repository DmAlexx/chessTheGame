#include "Board.h"

Board::Board()
{
	createEmptyBoard();
}

void Board::createEmptyBoard()
{
	Position SquarePosition;
	SquareColor SquareColor;

	for (int i = 0; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = 0; j < LAST_COORD_OF_BOARD; ++j)
		{
			SquarePosition.x = i;
			SquarePosition.y = j;

			if ((i + j) % 2 == 0)
			{
				SquareColor = SquareColor::WHITE;
			}
			else
			{
				SquareColor = SquareColor::BLACK;
			}
			m_board[i][j] = Square(SquarePosition, SquareColor);
		}
	}
}

Square* Board::getSquare(const Position& position)
{
	return &(m_board[position.x][position.y]);
}

bool Board::isValidCoordinates(const Position& currentPosition, const Position& lastPosition)
{
	if (currentPosition.x >= FIRST_COORD_OF_BOARD && currentPosition.x < LAST_COORD_OF_BOARD && currentPosition.y >= FIRST_COORD_OF_BOARD && currentPosition.y < LAST_COORD_OF_BOARD
		&& lastPosition.x >= FIRST_COORD_OF_BOARD && lastPosition.x < LAST_COORD_OF_BOARD && lastPosition.y >= FIRST_COORD_OF_BOARD && lastPosition.y < LAST_COORD_OF_BOARD
		&& currentPosition.x != lastPosition.x && currentPosition.y != lastPosition.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isFigurePlaced(const Position& position)
{
	if (m_board[position.x][position.y].getFigure())
	{
		return true;
	}
	else if (m_board[position.x][position.y].getFigure() == nullptr)
	{
		return false;
	}
}