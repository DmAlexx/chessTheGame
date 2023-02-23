#pragma once

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

	Figure(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    Figure(Figure& right);
    Figure& operator=(const Figure& right);

    virtual bool checkMove(const Position& position) = 0;
    const FigureType& getType() const { return m_type; }
    const FigureColor& getColor() const { return m_color; }

private:
    FigureType m_type;
    FigureColor m_color;
    FigureSprite m_sprite;
    Position m_position;
};

class King :public Figure
{
public:
    King(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;
private:
};

class Queen :public Figure
{
public:
    Queen(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;

private:
};

class Bishop :public Figure
{
public:
    Bishop(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;

private:
};

class Knight :public Figure
{
public:
    Knight(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;

private:
};

class Rook :public Figure
{
public:
    Rook(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;

private:
};

class Pawn :public Figure
{
public:
    Pawn(FigureType type, FigureColor color, FigureSprite sprite, Position position);
    bool checkMove(const Position& position) override;

private:
};
