#pragma once
#include "Figure.h"

namespace
{
	const int X = 8;
	const int Y = 8;
}

class Board
{
public:
	Board();
protected:
	Figure* m_board[X][Y];

};

