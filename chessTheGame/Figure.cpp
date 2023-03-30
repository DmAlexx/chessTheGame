#include "Figure.h"

namespace
{
	const int WHITE_PAWN_START_POSITION_Y = 1;
	const int BLACK_PAWN_START_POSITION_Y = 6;
}

bool Figure::isCanAttak(const Position& currentPosition, const Position& lastPosition)
{
	return true;
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

bool King::checkMove(const Position& currentPosition, const Position& lastPosition)
{
	if (abs(currentPosition.x - lastPosition.x) <= 1 && abs(currentPosition.y - lastPosition.y) <= 1)
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

bool Queen::checkMove(const Position& currentPosition, const Position& lastPosition)
{

	if (abs(currentPosition.x - lastPosition.x) == 0 || abs(currentPosition.y - lastPosition.y) == 0 || abs(currentPosition.x - lastPosition.x) == abs(currentPosition.y - lastPosition.y))
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

bool Bishop::checkMove(const Position& currentPosition, const Position& lastPosition)
{
	if (abs(currentPosition.x - lastPosition.x) == abs(currentPosition.y - lastPosition.y))
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

bool Knight::checkMove(const Position& currentPosition, const Position& lastPosition)
{
	if (abs(currentPosition.x - lastPosition.x) == 1 && abs(currentPosition.y - lastPosition.y) == 2 || abs(currentPosition.x - lastPosition.x) == 2 && abs(currentPosition.y - lastPosition.y) == 1)
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

bool Rook::checkMove(const Position& currentPosition, const Position& lastPosition)
{
	if (currentPosition.x == lastPosition.x || currentPosition.y == lastPosition.y)
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

bool Pawn::checkMove(const Position& currentPosition, const Position& lastPosition)
{
	int direction = (m_color == FigureColor::WHITE) ? 1 : -1;
	int startRow = (m_color == FigureColor::WHITE) ? WHITE_PAWN_START_POSITION_Y : BLACK_PAWN_START_POSITION_Y;

	if (currentPosition.x + direction == lastPosition.x && currentPosition.y == lastPosition.y
		|| currentPosition.x + direction * 2 == lastPosition.x && currentPosition.y == lastPosition.y && currentPosition.x == WHITE_PAWN_START_POSITION_Y
		|| currentPosition.x + direction * 2 == lastPosition.x && currentPosition.y == lastPosition.y && currentPosition.x == BLACK_PAWN_START_POSITION_Y
		|| abs(lastPosition.x - currentPosition.x) == 1 && abs(lastPosition.y - currentPosition.y) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pawn::isCanAttak(const Position& currentPosition, const Position& lastPosition)
{
	if (abs(lastPosition.x - currentPosition.x) == 1 && abs(lastPosition.y - currentPosition.y) == 1)
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
