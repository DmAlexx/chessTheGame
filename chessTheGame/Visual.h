#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

namespace
{
    const int LENGTH_WIDTH_SIZE_BOARD = 8;
    const int NUMBER_OF_FIGURES_EVERY_COLOR = 8;
    const int BLACK_FIGURES_START_POSITION = 0;
    const int BLACK_PAWNS_START_POSITION = 1;
    const int WHITE_PAWNS_START_POSITION = 6;
    const int WHITE_FIGURES_START_POSITION = 7;
    const char BOARD_LETTERS[LENGTH_WIDTH_SIZE_BOARD] = { 'a','b','c','d','e','f','g','h' };
    

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

protected:
    FigureSprite m_videoOutSpriteWhite[NUMBER_OF_FIGURES_EVERY_COLOR] = { FigureSprite::WR, FigureSprite::Wk, FigureSprite::WB, FigureSprite::WQ, FigureSprite::WK, FigureSprite::WB, FigureSprite::Wk, FigureSprite::WR };
    FigureSprite m_videoOutSpriteBlack[NUMBER_OF_FIGURES_EVERY_COLOR] = { FigureSprite::BR, FigureSprite::Bk, FigureSprite::BB, FigureSprite::BQ, FigureSprite::BK, FigureSprite::BB, FigureSprite::Bk, FigureSprite::BR };
    
};