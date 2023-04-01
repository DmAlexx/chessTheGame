#include "Game.h"

namespace
{
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
	std::cout << "Вызвал функцию checkFreePath\n";

	switch (figure)
	{
	case FigureType::ROOK:
	case FigureType::QUEEN:
		while (nextPosition.x != lastPos.x || nextPosition.y != lastPos.y)
		{
			return countNextPosition(nextPosition, directionX, directionY);
		}
		return true;
	case FigureType::BISHOP:
		while (nextPosition.x != lastPos.x && nextPosition.y != lastPos.y)
		{
			return countNextPosition(nextPosition, directionX, directionY);
		}
		return true;

	case FigureType::PAWN:

		while (nextPosition.x != lastPos.x && nextPosition.y != lastPos.y)
		{
			return countNextPosition(nextPosition, directionX, directionY);
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
	std::cout << "вызвал функцию figureMove\n";
	_getch();
	if (m_board.isFigurePlaced(currentPosition) && m_board.isFigurePlaced(lastPosition)
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() != m_board.getSquare(lastPosition)->getFigure()->getFigureColor()
		&& m_board.getSquare(currentPosition)->getFigure()->isCanAttak(currentPosition, lastPosition)
		&& checkFreePath(currentPosition, lastPosition))
	{
		if (m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING && isKingUnderAttakAfterHisMove(currentPosition, lastPosition))
		{
			std::cout << "Wrong move, King will be under attack!\n";
			return false;
		}
		else
		{
			std::cout << "побил\n";
			_getch();
			takeOpponentFigure(currentPosition, lastPosition);
			return true;
		}
	}
	else if (m_board.isFigurePlaced(currentPosition) && !m_board.isFigurePlaced(lastPosition) && m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) && checkFreePath(currentPosition, lastPosition))
	{
		std::cout << "попал в нужнфй блок при ходе\n";
		if (m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING && isKingUnderAttakAfterHisMove(currentPosition, lastPosition))
		{
			std::cout << "Wrong move, King will be under attack!\n";
			return false;
		}
		else
		{
			std::cout << "фигура походила\n";
			_getch();
			m_board.getSquare(lastPosition)->setFigure(m_board.getSquare(currentPosition)->getFigure());
			m_board.getSquare(currentPosition)->setFigure(nullptr);
			return true;
		}
	}
	else
	{
		std::cout << "Can't make a move!\n";
		return false;
	}
}

bool Game::isKingUnderAttakAfterHisMove(const Position& currentPos, const Position& lastPos)
{
	Position virtualFigurePosition;

	for (int i = 0; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = 0; j < LAST_COORD_OF_BOARD; ++j)
		{
			virtualFigurePosition.x = i;
			virtualFigurePosition.y = j;
			if (m_board.getSquare(currentPos)->getFigure()->getType() == FigureType::KING && m_board.isFigurePlaced(virtualFigurePosition)
				&& m_board.getSquare(currentPos)->getFigure()->getFigureColor() != m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor()
				&& m_board.getSquare(virtualFigurePosition)->getFigure()->isCanAttak(virtualFigurePosition, lastPos) && checkFreePath(virtualFigurePosition, lastPos))
			{
				if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::BISHOP && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WB";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::BISHOP && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BB";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::KING && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WK";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::KING && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BK";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::KNIGHT && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "Wk";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::KNIGHT && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Bk";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::PAWN && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WP";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::PAWN && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BP";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::QUEEN && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WQ";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::QUEEN && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BQ";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::ROOK && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WR";
				}
				else if (m_board.getSquare(virtualFigurePosition)->getFigure()->getType() == FigureType::ROOK && m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BR";
				}
				return true;
			}
		}
	}
	return false;
}

bool Game::isCheckForKingAfterMoveOtherFigures(const Position& currentPos, const Position& lastPos)
{
	Position tempPosition;
	for (int i = FIRST_COORD_OF_BOARD; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = FIRST_COORD_OF_BOARD; j < LAST_COORD_OF_BOARD; ++j)
		{
			tempPosition.x = i;
			tempPosition.y = j;

			if (m_board.isFigurePlaced(tempPosition) && m_board.getSquare(tempPosition)->getFigure()->getFigureColor() != m_board.getSquare(currentPos)->getFigure()->getFigureColor()
				&& m_board.getSquare(tempPosition)->getFigure()->getType() == FigureType::KING
				&& m_board.getSquare(lastPos)->getFigure()->checkMove(lastPos, tempPosition) && m_board.getSquare(lastPos)->getFigure()->isCanAttak(lastPos, tempPosition)
				&& checkFreePath(lastPos, tempPosition))
			{
				std::string figureColor;
				std::string figureType = "King";

				if (m_board.getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					figureColor = "white";
				}
				else
				{
					figureColor = "black";
				}

				std::cout << "Check for " << figureColor << " " << figureType << "\n";
				return true;
			}
		}
	}
	return false;
}

bool Game::countNextPosition(Position& nextPosition, const int directionX, const int directionY)
{
	if (m_board.isFigurePlaced(nextPosition))
	{
		return false;
	}
	nextPosition.x += directionX;
	nextPosition.y += directionY;
}