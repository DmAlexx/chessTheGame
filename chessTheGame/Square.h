#pragma once
#include "Figure.h"

enum class SquareColor
{
	BLACK,
	WHITE
};

class Square
{
public:
	Square() = default;
	Square(Position squarePosition, SquareColor colorOfSquare, Figure* figure = nullptr);
	void setFigure(Figure* figure);
	Figure* getFigure();
	const SquareColor& getSquareColor();
	const Position& getPosition();
private:
	SquareColor m_colorOfSquare;
	Position m_squarePosition;
	Figure* m_figure;
};

