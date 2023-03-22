#include "Square.h"

Square::Square(Position squarePosition, SquareColor colorOfSquare, Figure* figure)
	: m_colorOfSquare(colorOfSquare)
	, m_squarePosition(squarePosition)
	, m_figure(figure)
{
}

const SquareColor& Square::getSquareColor()
{
	return m_colorOfSquare;
}

const Position& Square::getPosition()
{
	return m_squarePosition;
}

void Square::setFigure(Figure* figure)
{
	m_figure = figure;
}

Figure* Square::getFigure()
{
	return m_figure;	 
}