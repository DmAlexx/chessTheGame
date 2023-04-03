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
	createFigure(FigureType::KING, FigureColor::WHITE, { 0,3 });
	createFigure(FigureType::QUEEN, FigureColor::WHITE, { 0,4 });
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
	createFigure(FigureType::KING, FigureColor::BLACK, { 7,3 });
	createFigure(FigureType::QUEEN, FigureColor::BLACK, { 7,4 });
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
	default:
		return true;
	}
}

void Game::makeMove(const Position& currentPosition, const Position& lastPosition)
{
	castling(currentPosition, lastPosition);
	isRooksMoved(currentPosition, lastPosition);
	changeKingsCoordinatesLog(currentPosition, lastPosition, 1);
	m_board.getSquare(lastPosition)->setFigure(m_board.getSquare(currentPosition)->getFigure());
	m_board.getSquare(currentPosition)->setFigure(nullptr);
	movesLogging(currentPosition, lastPosition);
}

void Game::takeOpponentFigure(const Position& currentPosition, const Position& lastPosition)
{
	m_tokenFigures.push(m_board.getSquare(lastPosition)->getFigure());
	makeMove(currentPosition, lastPosition);
}

void Game::replaceTheCapturedFigure()
{
	m_board.getSquare(m_movesLog.top().second)->setFigure(m_tokenFigures.top());
	m_tokenFigures.pop();
	if (m_switchTakeOpponentFigure == 1)
	{
		m_movesLog.pop();
		m_switchTakeOpponentFigure = 0;
	}
}

void Game::takeBackLastMove()
{
	changeKingsCoordinatesLog(m_movesLog.top().second, m_movesLog.top().first, -1);
	m_board.getSquare(m_movesLog.top().first)->setFigure(m_board.getSquare(m_movesLog.top().second)->getFigure());
	m_board.getSquare(m_movesLog.top().second)->setFigure(nullptr);
	if (m_switchTakeOpponentFigure == 0)
	{
		m_movesLog.pop();
	}
}

bool Game::figureMove(const Position& currentPosition, const Position& lastPosition)
{
	//attack opponent figure
	if (m_board.isFigurePlaced(currentPosition) && m_board.isFigurePlaced(lastPosition)
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() != m_board.getSquare(lastPosition)->getFigure()->getFigureColor()
		&& m_board.getSquare(currentPosition)->getFigure()->isCanAttak(currentPosition, lastPosition)
		&& checkFreePath(currentPosition, lastPosition))
	{
		takeOpponentFigure(currentPosition, lastPosition);
		m_switchTakeOpponentFigure = 1;
		for (int i = 0; i < NUMBER_OF_KINGS; ++i)
		{
			if (m_board.getSquare(lastPosition)->getFigure()->getFigureColor() == m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor()
				&& isKingUnderAttakAfterMove(i))
			{
				if (m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Can't make a move! Black King under attack!\n";
				}
				else
				{
					std::cout << "Can't make a move! White King under attack!\n";
				}
				takeBackLastMove();
				replaceTheCapturedFigure();
				return false;
			}
			else if (m_board.getSquare(lastPosition)->getFigure()->getFigureColor() != m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor()
				&& isKingUnderAttakAfterMove(i))
			{
				if (m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Check for black King!\n";
					waitForPressAnyKey();
				}
				else
				{
					std::cout << "Check for white King!\n";
					waitForPressAnyKey();
				}
				return true;
			}
		}
		return true;
	}
	//figure move
	else if (m_board.isFigurePlaced(currentPosition) && !m_board.isFigurePlaced(lastPosition) && (m_board.getSquare(currentPosition)->getFigure()->checkMove(currentPosition, lastPosition) || m_board.getSquare(currentPosition)->getFigure()->isCanCastling (currentPosition, lastPosition)) 
		&& checkFreePath(currentPosition, lastPosition))
	{
		makeMove(currentPosition, lastPosition);
		for (int i = 0; i < NUMBER_OF_KINGS; ++i)
		{
			if (m_board.getSquare(lastPosition)->getFigure()->getFigureColor() == m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor()
				&& isKingUnderAttakAfterMove(i))
			{
				if (m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Can't make a move! Black King under attack!\n";
				}
				else
				{
					std::cout << "Can't make a move! White King under attack!\n";
				}
				takeBackLastMove();
				return false;
			}
			else if (m_board.getSquare(lastPosition)->getFigure()->getFigureColor() != m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor()
				&& isKingUnderAttakAfterMove(i))
			{
				if (m_board.getSquare(m_kingsKoordinates[i])->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Check for black King!\n";
					waitForPressAnyKey();
				}
				else
				{
					std::cout << "Check for white King!\n";
					waitForPressAnyKey();
				}
				return true;
			}
		}
		return true;
	}
	else
	{
		std::cout << "Can't make a move!\n";
		return false;
	}
}

bool Game::isKingUnderAttakAfterMove(const int whiteOrBlack)
{
	Position virtualFigurePosition;

	for (int i = (LAST_COORD_OF_BOARD - 1); i > -1; --i)
	{
		for (int j = (LAST_COORD_OF_BOARD - 1); j > -1; --j)
		{
			virtualFigurePosition.x = j;
			virtualFigurePosition.y = i;
			if (m_board.isFigurePlaced(virtualFigurePosition) && m_board.getSquare(m_kingsKoordinates[whiteOrBlack])->getFigure()->getFigureColor() != m_board.getSquare(virtualFigurePosition)->getFigure()->getFigureColor()
				&& m_board.getSquare(virtualFigurePosition)->getFigure()->isCanAttak(virtualFigurePosition, m_kingsKoordinates[whiteOrBlack]) && checkFreePath(virtualFigurePosition, m_kingsKoordinates[whiteOrBlack]))
			{
				return true;
			}
		}
	}
	return false;
}

void Game::movesLogging(const Position& currentPosition, const Position& lastPosition)
{
	m_movesLog.push(std::make_pair(currentPosition, lastPosition));
}

void Game::changeKingsCoordinatesLog(const Position& currentPosition, const Position& lastPosition, const int switchKing)
{
	if (m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING && m_board.getSquare(currentPosition)->getFigure()->getFigureColor()==FigureColor::WHITE)
	{
		m_kingsKoordinates[0] = lastPosition;
		m_switchIfWhiteKingMoved+= switchKing;
	}
	else if (m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING && m_board.getSquare(currentPosition)->getFigure()->getFigureColor() != FigureColor::WHITE)
	{
		m_kingsKoordinates[1] = lastPosition;
		m_switchIfBlackKingMoved+= switchKing;
	}
}

void Game::isRooksMoved(const Position& currentPosition, const Position& lastPosition)
{
	if (currentPosition.x == 0 && currentPosition.y == 0 && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::ROOK
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
	{
		m_switchIfWhiteRightRookMoved = 1;
	}
	else if (currentPosition.x == 0 && currentPosition.y == 7 && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::ROOK
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
	{
		m_switchIfWhiteRightRookMoved = 1;
	}
	else if (currentPosition.x == 7 && currentPosition.y == 0 && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::ROOK
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
	{
		m_switchIfBlackRightRookMoved = 1;
	}
	else if (currentPosition.x == 7 && currentPosition.y == 7 && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::ROOK
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
	{
		m_switchIfBlackLeftRookMoved = 1;
	}
		
}

void Game::castling(const Position& currentPosition, const Position& lastPosition)
{
	Position tempCurrentRookPosition;
	Position tempLastRookPosition;

	if (m_switchIfWhiteKingMoved != 1 && m_switchIfWhiteRightRookMoved!=1 && m_board.isFigurePlaced(currentPosition) && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING
		&& m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE && lastPosition.x == 0 && lastPosition.y == 1 && !isKingUnderAttakAfterMove(0))
	{
		tempCurrentRookPosition.x = 0;
		tempCurrentRookPosition.y = 0;
		tempLastRookPosition.x = 0;
		tempLastRookPosition.y = 2;
		moveRookIfCastling(tempCurrentRookPosition, tempLastRookPosition);
	}
	else if (m_switchIfWhiteKingMoved != 1 && m_switchIfWhiteLeftRookMoved != 1 && m_board.isFigurePlaced(currentPosition) && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING &&
		m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::WHITE && lastPosition.x == 0 && lastPosition.y == 5 && !isKingUnderAttakAfterMove(0))
	{
		tempCurrentRookPosition.x = 0;
		tempCurrentRookPosition.y = 7;
		tempLastRookPosition.x = 0;
		tempLastRookPosition.y = 4;
		moveRookIfCastling(tempCurrentRookPosition, tempLastRookPosition);
	}
	else if (m_switchIfBlackKingMoved != 1 && m_switchIfWhiteLeftRookMoved != 1 && m_board.isFigurePlaced(currentPosition) && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING &&
		m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::BLACK && lastPosition.x == 7 && lastPosition.y == 1 && !isKingUnderAttakAfterMove(1))
	{
		tempCurrentRookPosition.x = 7;
		tempCurrentRookPosition.y = 0;
		tempLastRookPosition.x = 7;
		tempLastRookPosition.y = 2;
		moveRookIfCastling(tempCurrentRookPosition, tempLastRookPosition);
	}
	else if (m_switchIfBlackKingMoved != 1 && m_switchIfWhiteLeftRookMoved != 1 && m_board.isFigurePlaced(currentPosition) && m_board.getSquare(currentPosition)->getFigure()->getType() == FigureType::KING &&
		m_board.getSquare(currentPosition)->getFigure()->getFigureColor() == FigureColor::BLACK && lastPosition.x == 7 && lastPosition.y == 5 && !isKingUnderAttakAfterMove(1))
	{
		tempCurrentRookPosition.x = 7;
		tempCurrentRookPosition.y = 7;
		tempLastRookPosition.x = 7;
		tempLastRookPosition.y = 4;
		moveRookIfCastling(tempCurrentRookPosition, tempLastRookPosition);
	}
}

void Game::moveRookIfCastling(const Position& tempCurrentRookPosition, const Position& tempLastRookPosition)
{
	movesLogging(tempCurrentRookPosition, tempLastRookPosition);
	m_board.getSquare(tempLastRookPosition)->setFigure(m_board.getSquare(tempCurrentRookPosition)->getFigure());
	m_board.getSquare(tempCurrentRookPosition)->setFigure(nullptr);
}

void Game::waitForPressAnyKey()
{
	std::cout << "press any key...\n";
#ifdef _WIN32
	_getch();
#endif // !_WIN32
#ifdef _linux
	getchar();
#endif //!_linux
}