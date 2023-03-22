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
    const char BOARD_LETTERS[LENGTH_WIDTH_SIZE_BOARD] = { 'a','b','c','d','e','f','g','h' };
    const char SEPARATOR = '|';
    const char EMPTY_FILLER = ' ';
    const enum class FigureSprite
    {
        WK,        //white King
        WQ,         //white Queen
        WB,         //white Bishop
        Wk,         //white Knight
        WR,         //white Rook
        WP,         //white Pawn
        BK,        //black King
        BQ,         //black Queen
        BB,         //black Bishop
        Bk,         //black Knight
        BR,         //black Rook
        BP          //black Pawn
    };

    std::map<FigureSprite, std::string> FigureSpriteOut{ {FigureSprite::WK, "WK"},
                                                         {FigureSprite::WQ, "WQ"},
                                                         {FigureSprite::WB, "WB"},
                                                         {FigureSprite::Wk, "Wk"},
                                                         {FigureSprite::WR, "WR"},
                                                         {FigureSprite::WP, "WP"},
                                                         {FigureSprite::BK, "BK"},
                                                         {FigureSprite::BQ, "BQ"},
                                                         {FigureSprite::BB, "BB"},
                                                         {FigureSprite::Bk, "Bk"},
                                                         {FigureSprite::BR, "BR"},
                                                         {FigureSprite::BP, "BP"} };
}


class Visual
{

public:
	Visual();
    void printBoardFiguresForWhite(Board* board) const;
    void printBoardFiguresForBlack(Board* board) const;
protected:
    
};