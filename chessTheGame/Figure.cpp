#include "Figure.h"

Figure::Figure(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: m_type(type)
	, m_color(color)
	, m_sprite(sprite)
	, m_position(position)
{
}

Figure::Figure(Figure& right)
	: m_type(right.m_type)
	, m_color(right.m_color)
	, m_sprite(right.m_sprite)
	, m_position(right.m_position)
{
}

Figure& Figure::operator=(const Figure& right)
{
	m_type = right.m_type;
	m_color = right.m_color;
	m_sprite = right.m_sprite;
	m_position = right.m_position;
	return *this;
}

////////////////////////
//KING
////////////////////////

King::King(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: Figure(FigureType::KING, color, sprite, position)
{
}

bool King::checkMove(const Position& position)
{
	return false;
}

////////////////////////
//QUEEN
////////////////////////

Queen::Queen(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	:Figure(FigureType::QUEEN, color, sprite)
{
}

bool Queen::checkMove(const Position& position)
{
	return false;
}

////////////////////////
//BISHOP
////////////////////////

Bishop::Bishop(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: Figure(FigureType::BISHOP, color, sprite)
{
}

bool Bishop::checkMove(const Position& position)
{
	return false;
}

////////////////////////
//KNIGHT
////////////////////////

Knight::Knight(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: Figure(FigureType::KNIGHT, color, sprite)
{
}

bool Knight::checkMove(const Position& position)
{
	return false;
}

////////////////////////
//ROOK
////////////////////////

Rook::Rook(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: Figure(FigureType::ROOK, color, sprite)
{
}

bool Rook::checkMove(const Position& position)
{
	return false;
}

////////////////////////
//PAWN
////////////////////////

Pawn::Pawn(FigureType type, FigureColor color, FigureSprite sprite, Position position)
	: Figure(FigureType::PAWN, color, sprite)
{
}

bool Pawn::checkMove(const Position& position)
{
	return false;
}
