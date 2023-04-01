#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Square.h"
#include "Board.h"


namespace
{
    const int LENGTH_WIDTH_SIZE_BOARD = 8;
    const char SEPARATOR = '|';
    const char EMPTY_FILLER = ' ';
}


class Visual
{

public:
	Visual();
    void printBoardFiguresForWhite(Board* board) const;
    void printBoardFiguresForBlack(Board* board) const;
protected:
    void fillBoardWithFigures(Position tempPosition, Board* board) const;
    std::string m_Figure;
};