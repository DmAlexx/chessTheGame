#pragma once
#include "Board.h"
#include "Figure.h"
#include <vector>

class Game
{
public:
	Game() = default;
	~Game();
	void figuresArrangement();
	bool figureMove(const Position& currentPos, const Position& lastPos);
	Board* getBoard() { return &m_board; }

private:
	void createFigure(FigureType type, FigureColor color, const Position& position);
	void takeOpponentFigure(const Position& currentPosition, const Position& lastPosition);
	bool checkFreePath(const Position& currentPosition, const Position& lastPosition);
	std::vector<Figure*> m_figures;
	std::vector<Figure*> m_tokenFigures;
	Board m_board;

};

