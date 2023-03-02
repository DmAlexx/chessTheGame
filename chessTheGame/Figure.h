#pragma once
#include <cmath>

enum class FigureType
{
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
};

enum class FigureColor
{
    BLACK,
    WHITE
};

enum class FigureSprite
{
    WKI,        //white King
    WQ,
    WB,
    WKN,
    WR,
    WP,
    BKI,
    BQ,
    BB,
    BKN,
    BR,
    BP
};

struct Position
{
    int x = 0;
    int y = 0;
};


class Figure
{
public:

	Figure(FigureColor color);
    Figure(Figure& right);
    Figure& operator=(const Figure& right);

    virtual bool checkMove(const Position& currentPosition, const Position& nextPosition) = 0;
    const virtual FigureType& getType() = 0;
    const FigureColor& getColor() const { return m_color; }

private:
    FigureColor m_color;
};

class King :public Figure
{
public:
    King(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};

class Queen :public Figure
{
public:
    Queen(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};

class Bishop :public Figure
{
public:
    Bishop(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};

class Knight :public Figure
{
public:
    Knight(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};

class Rook :public Figure
{
public:
    Rook(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};

class Pawn :public Figure
{
public:
    Pawn(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& nextPosition) override;
    const FigureType& getType() override;

private:
};
