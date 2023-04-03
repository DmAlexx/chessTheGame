#pragma once
#include "Board.h"
#include "Figure.h"
#include "Square.h"
#include <vector>
#include <string>
#include <stack>
#include <utility>

#ifdef _WIN32
#include <conio.h>
#endif // !_WIN32

#ifdef _linux
#include <termios.h>
#endif // !_linux

namespace
{
	const int NUMBER_OF_KINGS = 2;
}

class Game
{
public:
	Game() = default;
	~Game();
	void figuresArrangement();
	bool figureMove(const Position& currentPos, const Position& lastPos);
	void takeBackLastMove();
	Board* getBoard() { return &m_board; }
	

private:
	void createFigure(FigureType type, FigureColor color, const Position& position);
	void takeOpponentFigure(const Position& currentPosition, const Position& lastPosition);
	bool isKingUnderAttakAfterMove(const int whiteOrBlack);
	bool checkFreePath(const Position& currentPosition, const Position& lastPosition);
	void replaceTheCapturedFigure();
	void movesLogging(const Position& currentPosition, const Position& lastPosition);
	void changeKingsCoordinatesLog(const Position& currentPosition, const Position& lastPosition, const int switchKing);
	void makeMove(const Position& currentPosition, const Position& lastPosition);
	void waitForPressAnyKey();
	void isRooksMoved(const Position& currentPosition, const Position& lastPosition);
	void castling(const Position& currentPosition, const Position& lastPosition);
	void moveRookIfCastling(const Position& currentPosition, const Position& lastPosition);

	std::vector<Figure*> m_figures;
	std::stack<std::pair<Position, Position>> m_movesLog;
	std::stack<Figure*> m_tokenFigures;
	Position m_kingsKoordinates[NUMBER_OF_KINGS] = { {0,3}, {7,3} }; // [0] - white , [1] - black
	Board m_board;
	int m_switchTakeOpponentFigure = 0; //0 - last coordinats in log without take opponent figure, 1 - with
	int m_switchIfWhiteKingMoved = 0; //0 - don't move, 1 - had moved
	int m_switchIfBlackKingMoved = 0; //0 - don't move, 1 - had moved
	int m_switchIfWhiteRightRookMoved = 0; //0 - don't move, 1 - had moved
	int m_switchIfWhiteLeftRookMoved = 0; //0  don't move, 1 - had moved
	int m_switchIfBlackRightRookMoved = 0; //0 - don't move, 1 - had moved
	int m_switchIfBlackLeftRookMoved = 0; //0 - don't move, 1 - had moved
};

