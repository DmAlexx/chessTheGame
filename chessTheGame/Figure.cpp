#include "Figure.h"

namespace
{
	int WHITE_PAWN_START_POSITION_X = 1;
	int BLACK_PAWN_START_POSITION_X = 6;
}

Figure::Figure(FigureColor color)
	: m_color(color)
{
}

Figure::Figure(Figure& right)
	: m_color(right.m_color)
{
}

Figure& Figure::operator=(const Figure& right)
{
	m_color = right.m_color;
	return *this;
}

////////////////////////
//KING
////////////////////////

King::King(FigureColor color)
	: Figure(color)
{
}

bool King::checkMove(const Position& currentPosition, const Position& nextPosition)
{
	if (abs(currentPosition.x - nextPosition.x) <= 1 && abs(currentPosition.y - nextPosition.y) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& King::getType()
{
	return FigureType::KING;
}

////////////////////////
//QUEEN
////////////////////////

Queen::Queen(FigureColor color)
	:Figure(color)
{
}

bool Queen::checkMove(const Position& currentPosition, const Position& nextPosition)
{

	if (abs(currentPosition.x - nextPosition.x) == 0 || abs(currentPosition.y - nextPosition.y) == 0 || abs(currentPosition.x - nextPosition.x) == abs(currentPosition.y - nextPosition.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& Queen::getType()
{
	return FigureType::QUEEN;
}

////////////////////////
//BISHOP
////////////////////////

Bishop::Bishop(FigureColor color)
	: Figure(color)
{
}

bool Bishop::checkMove(const Position& currentPosition, const Position& nextPosition)
{
	if (abs(currentPosition.x - nextPosition.x) == abs(currentPosition.y - nextPosition.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& Bishop::getType()
{
	return FigureType::BISHOP;
}

////////////////////////
//KNIGHT
////////////////////////

Knight::Knight(FigureColor color)
	: Figure(color)
{
}

bool Knight::checkMove(const Position& currentPosition, const Position& nextPosition)
{
	if (abs(currentPosition.x - nextPosition.x) == 1 && abs(currentPosition.y - nextPosition.y) == 2 || abs(currentPosition.x - nextPosition.x) == 2 && abs(currentPosition.y - nextPosition.y) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& Knight::getType()
{
	return FigureType::KNIGHT;
}

////////////////////////
//ROOK
////////////////////////

Rook::Rook(FigureColor color)
	: Figure(color)
{
}

bool Rook::checkMove(const Position& currentPosition, const Position& nextPosition)
{
	if (currentPosition.x == nextPosition.x || currentPosition.y == nextPosition.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& Rook::getType()
{
	return FigureType::ROOK;
}

////////////////////////
//PAWN
////////////////////////

Pawn::Pawn(FigureColor color)
	: Figure(color)
{
}

bool Pawn::checkMove(const Position& currentPosition, const Position& nextPosition)
{
	int direction = 0;
	if (m_color == FigureColor::WHITE)
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}
	if (currentPosition.x + direction == nextPosition.x && currentPosition.y == nextPosition.y 
		|| currentPosition.x + direction * 2 == nextPosition.x && currentPosition.y == nextPosition.y && currentPosition.x == WHITE_PAWN_START_POSITION_X
		|| currentPosition.x + direction * 2 == nextPosition.x && currentPosition.y == nextPosition.y && currentPosition.x == BLACK_PAWN_START_POSITION_X)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const FigureType& Pawn::getType()
{
	return FigureType::PAWN;
}
