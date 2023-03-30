#include "Game.h"

namespace
{
    //const int NUMBERS_OF_FIGURES = 32;
    const int NUMBER_OF_PAWNS_ANY_COLOR = 8;
}

Game::~Game()
{
    for (auto figure : m_figures)
    {
        delete figure;
    }
}

void Game::figuresArrangement()
{

    m_board.createEmptyBoard();

    // Add white figures to the board
    createFigure(FigureType::ROOK, FigureColor::WHITE, { 0,0 });
    createFigure(FigureType::KNIGHT, FigureColor::WHITE, { 0,1 });
    createFigure(FigureType::BISHOP, FigureColor::WHITE, { 0,2 });
    createFigure(FigureType::QUEEN, FigureColor::WHITE, { 0,3 });
    createFigure(FigureType::KING, FigureColor::WHITE, { 0,4 });
    createFigure(FigureType::BISHOP, FigureColor::WHITE, { 0,5 });
    createFigure(FigureType::KNIGHT, FigureColor::WHITE, { 0,6 });
    createFigure(FigureType::ROOK, FigureColor::WHITE, { 0,7 });
    for (int i = 0; i < NUMBER_OF_PAWNS_ANY_COLOR; ++i)
    {
        createFigure(FigureType::PAWN, FigureColor::WHITE, { 1, i });
    }

    // Add black figures to the board
    createFigure(FigureType::ROOK, FigureColor::BLACK, { 7,0 });                                                            
    createFigure(FigureType::KNIGHT, FigureColor::BLACK, { 7,1 });
    createFigure(FigureType::BISHOP, FigureColor::BLACK, { 7,2 });
    createFigure(FigureType::QUEEN, FigureColor::BLACK, { 7,3 });
    createFigure(FigureType::KING, FigureColor::BLACK, { 7,4 });
    createFigure(FigureType::BISHOP, FigureColor::BLACK, { 7,5 });
    createFigure(FigureType::KNIGHT, FigureColor::BLACK, { 7,6 });
    createFigure(FigureType::ROOK, FigureColor::BLACK, { 7,7 });
    for (int i = 0; i < NUMBER_OF_PAWNS_ANY_COLOR; ++i)
    {
        createFigure(FigureType::PAWN, FigureColor::BLACK, { 6, i });
    }
}

void Game::createFigure(FigureType type, FigureColor color, const Position& position)
{
    Figure* figure = nullptr;
	
    if (type == FigureType::ROOK)
    {
        figure = new Rook(color);
    }
    else if (type == FigureType::KNIGHT)
    {
        figure = new Knight(color);
    }
    else if (type == FigureType::BISHOP)
    {
        figure = new Bishop(color);
    }
    else if (type == FigureType::QUEEN)
    {
        figure = new Queen(color);
    }
    else if (type == FigureType::KING)
    {
        figure = new King(color);
    }
    else if (type == FigureType::PAWN)
    {
        figure = new Pawn(color);
    }

	m_board.getSquare(position)->setFigure(figure);
    m_figures.push_back(figure);
}

bool Game::checkFreePath(const Position& currentPos, const Position& lastPos)
{
    auto figure = m_board.getSquare(currentPos)->getFigure()->getType();
	Position nextPosition;
	
    int directionX = (lastPos.x > currentPos.x) ? 1 : ((lastPos.x < currentPos.x) ? -1 : 0);
    int directionY = (lastPos.y > currentPos.y) ? 1 : ((lastPos.y < currentPos.y) ? -1 : 0);
	nextPosition.x = currentPos.x + directionX;
	nextPosition.y = currentPos.y + directionY;

	switch (figure)
	{
	case FigureType::ROOK:
	case FigureType::QUEEN:
		while (nextPosition.x != lastPos.x || nextPosition.y != lastPos.y)
		{
			if (m_board.isFigurePlaced(nextPosition))
			{
				return false;
			}
			nextPosition.x += directionX;
			nextPosition.y += directionY;
		}
		return true;
	case FigureType::BISHOP:
		while (nextPosition.x != lastPos.x && nextPosition.y != lastPos.y) 
		{
			if (nextPosition.x != lastPos.x || nextPosition.y != lastPos.y)
			{
				if (m_board.isFigurePlaced(nextPosition))
				{
					return false;
				}
			}
			nextPosition.x += directionX;
			nextPosition.y += directionY;
		}
		return true;

	case FigureType::PAWN:
		
			while (nextPosition.x != lastPos.x && nextPosition.y != lastPos.y)
			{
				if (m_board.isFigurePlaced(nextPosition))
				{
					return false;
				}
				nextPosition.x += directionX;
				nextPosition.y += directionY;
			}
			return true;
	case FigureType::KING:

		if (!isTargetSquareKingMoveUnderAttak(currentPos, lastPos))
		{
			return false;
		}		
		return true;
	default:
		return true;
	}
}

void Game::takeOpponentFigure(const Position& currentPosition, const Position& lastPosition)
{
	m_tokenFigures.push_back(m_board.getSquare(lastPosition)->getFigure());
	m_board.getSquare(lastPosition)->setFigure(m_board.getSquare(currentPosition)->getFigure());
	m_board.getSquare(currentPosition)->setFigure(nullptr);	
}

bool Game::figureMove(const Position& currentPosition, const Position& lastPosition)
{
	if (m_board.isFigurePlaced(currentPosition) && m_board.isFigurePlaced(lastPosition)
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() != m_board.getSquare(lastPosition)->getFigure()->getFigureColor()
		&& m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) && checkFreePath(currentPosition, lastPosition) 
		&& m_board.getSquare(currentPosition)->getFigure()->isCanAttak(currentPosition, lastPosition))
	{
		takeOpponentFigure(currentPosition, lastPosition);
		return true;
	}
	else if (m_board.isFigurePlaced(currentPosition) && !m_board.isFigurePlaced(lastPosition)
		&& m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) && checkFreePath(currentPosition, lastPosition))
	{
		m_board.getSquare(lastPosition)->setFigure(m_board.getSquare(currentPosition)->getFigure());
		m_board.getSquare(currentPosition)->setFigure(nullptr);
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::isTargetSquareKingMoveUnderAttak(const Position& currentPos, const Position& lastPos)
{
	Position tempPosition;
	for (int i = FIRST_COORD_OF_BOARD; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = FIRST_COORD_OF_BOARD; j < LAST_COORD_OF_BOARD; ++j)
		{
			tempPosition.x = i;
			tempPosition.y = j;
			if (m_board.isFigurePlaced(tempPosition) && m_board.getSquare(tempPosition)->getFigure()->getFigureColor() != m_board.getSquare(currentPos)->getFigure()->getFigureColor()
				&& m_board.getSquare(tempPosition)->getFigure()->checkMove(tempPosition, lastPos) && m_board.getSquare(tempPosition)->getFigure()->isCanAttak(tempPosition, lastPos)
				&& checkFreePath(tempPosition, lastPos))
			{
				return false;
			}
		}
	}
	return true;
}