#pragma once
#include <cmath>
#include <map>
#include <string>

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
    virtual bool checkMove(const Position& currentPosition, const Position& lastPosition) = 0;
    virtual bool isCanAttak(const Position& currentPosition, const Position& lastPosition) = 0;
    const virtual FigureType& getType() = 0;
    const FigureColor& getFigureColor() const { return m_color; }

protected:
    FigureColor m_color;
};

class King :public Figure
{
public:
    King(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
    bool attakAndMove(const Position& currentPosition, const Position& lastPosition);
};

class Queen :public Figure
{
public:
    Queen(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
    bool attakAndMove(const Position& currentPosition, const Position& lastPosition);
};

class Bishop :public Figure
{
public:
    Bishop(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
    bool attakAndMove(const Position& currentPosition, const Position& lastPosition);
};

class Knight :public Figure
{
public:
    Knight(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
    bool attakAndMove(const Position& currentPosition, const Position& lastPosition);
};

class Rook :public Figure
{
public:
    Rook(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
    bool attakAndMove(const Position& currentPosition, const Position& lastPosition);
};

class Pawn :public Figure
{
public:
    Pawn(FigureColor color);
    bool checkMove(const Position& currentPosition, const Position& lastPosition) override;
    bool isCanAttak(const Position& currentPosition, const Position& lastPosition) override;
    const FigureType& getType() override;

private:
};
