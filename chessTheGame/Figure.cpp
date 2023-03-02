#include "Figure.h"

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
	return false;
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
	return false;
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
	return false;
}

const FigureType& Pawn::getType()
{
	return FigureType::PAWN;
}
