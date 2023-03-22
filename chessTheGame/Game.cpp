#include "Game.h"

namespace
{
    const int NUMBERS_OF_FIGURES = 32;
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
	Position tempPosition;
    Position nextPosition;
    int directionX = (lastPos.x > currentPos.x) ? 1 : ((lastPos.x < currentPos.x) ? -1 : 0);
    int directionY = (lastPos.y > currentPos.y) ? 1 : ((lastPos.y < currentPos.y) ? -1 : 0);
	Position currentPosition = currentPos;;
	Position lastPosition;
	lastPosition.x = lastPos.x - directionX;
	lastPosition.y = lastPos.y - directionY;

	switch (figure)
	{
	case FigureType::ROOK:
	case FigureType::QUEEN:
	case FigureType::BISHOP:
	case FigureType::PAWN:

		nextPosition.x = currentPosition.x + directionX;
		nextPosition.y = currentPosition.y + directionY;

		if (lastPosition.x < currentPosition.x && lastPosition.y < currentPosition.y)
		{
			while (nextPosition.x > lastPosition.x && nextPosition.y > lastPosition.y)
			{
				if (m_board.isFigurePlaced(nextPosition) == true)
				{
					return false;
					break;
				}
				nextPosition.x += directionX;
				nextPosition.y += directionY;
			}
		}
		else if (lastPosition.x > currentPosition.x && lastPosition.y > currentPosition.y)
		{
			while (nextPosition.x < lastPosition.x && nextPosition.y < lastPosition.y)
			{
				if (m_board.isFigurePlaced(nextPosition) == true)
				{
					return false;
					break;
				}
				nextPosition.x += directionX;
				nextPosition.y += directionY;
			}
		}
		else if (lastPosition.x < currentPosition.x && lastPosition.y > currentPosition.y)
		{
			while (nextPosition.x > lastPosition.x && nextPosition.y < lastPosition.y)
			{
				if (m_board.isFigurePlaced(nextPosition) == true)
				{
					return false;
					break;
				}
				nextPosition.x += directionX;
				nextPosition.y += directionY;
			}
		}
		else if (lastPosition.x > currentPosition.x && lastPosition.y < currentPosition.y)
		{
			while (nextPosition.x < lastPosition.x && nextPosition.y > lastPosition.y)
			{
				if (m_board.isFigurePlaced(nextPosition) == true)
				{
					return false;
					break;
				}
				nextPosition.x += directionX;
				nextPosition.y += directionY;
			}
		}
		else
		{
			return true;
		}
		break;
	case FigureType::KING:
		for (int i = currentPosition.x - 1; i <= currentPosition.x + 1; i++) 
		{
			for (int j = currentPosition.y - 1; j <= currentPosition.y + 1; j++)
			{
				tempPosition.x = i;
				tempPosition.y = j;
				if (i == lastPosition.x && j == lastPosition.y) 
				{
					continue;
				}
				else if (i >= 0 && i < 8 && j >= 0 && j < 8 && m_board.getSquare(tempPosition)->getFigure()->getType() == FigureType::KING)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		break;
	default:
		return true;
		break;
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
		&& m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) == true && checkFreePath(currentPosition, lastPosition) == true)
	{
		takeOpponentFigure(currentPosition, lastPosition);
		return true;
	}
	else if (m_board.isFigurePlaced(currentPosition) && !m_board.isFigurePlaced(lastPosition)
		&& m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) == true && checkFreePath(currentPosition, lastPosition) == true)
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