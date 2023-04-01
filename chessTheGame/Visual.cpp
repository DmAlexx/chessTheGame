#include "Visual.h"

Visual::Visual()
{
	
}

void Visual::printBoardFiguresForWhite(Board* board) const
{
	Position tempPosition;
	for (int i = (LAST_COORD_OF_BOARD - 1); i > - 1; --i)
	{
		for (int j = (LAST_COORD_OF_BOARD - 1); j > -1; --j)
		{
			tempPosition.y = j;
			tempPosition.x = i;
			std::cout << SEPARATOR;
			fillBoardWithFigures(tempPosition, board);
		}
		std::cout << " " << i+1 << std::endl;
	}
	std::cout << " a  b  c  d  e  f  g  h\n\n\n";
}

void Visual::printBoardFiguresForBlack(Board* board) const
{
	Position tempPosition;
	for (int i = 0; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = 0; j< LAST_COORD_OF_BOARD; ++j)
		{
			tempPosition.y = j;
			tempPosition.x = i;
			std::cout << SEPARATOR;
			fillBoardWithFigures(tempPosition, board);
		}
		std::cout << " " << 1+i << std::endl;
	}
	std::cout << " h  g  f  e  d  c  b  a\n\n\n";
}

void Visual::fillBoardWithFigures(Position tempPosition, Board* board) const
{
	if (board->getSquare(tempPosition)->getSquareColor() == SquareColor::BLACK && !board->isFigurePlaced(tempPosition))
	{
		std::cout << "X ";
	}
	else if (board->getSquare(tempPosition)->getSquareColor() == SquareColor::WHITE && !board->isFigurePlaced(tempPosition))
	{
		std::cout << EMPTY_FILLER << EMPTY_FILLER;
	}
	else
	{
		if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "WB";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "BB";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::KING && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "WK";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::KING && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "BK";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "Wk";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "Bk";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::PAWN && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "WP";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::PAWN && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "BP";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "WQ";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "BQ";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::ROOK && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::WHITE)
		{
			std::cout << "WR";
		}
		else if (board->getSquare(tempPosition)->getFigure()->getType() == FigureType::ROOK && board->getSquare(tempPosition)->getFigure()->getFigureColor() == FigureColor::BLACK)
		{
			std::cout << "BR";
		}
	}
}