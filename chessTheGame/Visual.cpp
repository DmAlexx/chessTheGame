#include "Visual.h"

Visual::Visual()
{
	
}

void Visual::printBoardFiguresForWhite(Board* board) const
{
	Position position;
	for (int i = (LAST_COORD_OF_BOARD - 1); i > - 1; --i)
	{
		for (int j = (LAST_COORD_OF_BOARD - 1); j > -1; --j)
		{
			position.y = j;
			position.x = i;
			std::cout << SEPARATOR;

			if (board->getSquare(position)->getSquareColor() == SquareColor::BLACK && !board->isFigurePlaced(position))
			{
				std::cout << "X ";
			}
			else if (board->getSquare(position)->getSquareColor() == SquareColor::WHITE && !board->isFigurePlaced(position))
			{
				std::cout << EMPTY_FILLER << EMPTY_FILLER;
			}
			else
			{
				if (board->getSquare(position)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WB";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BB";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KING && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WK";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KING && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BK";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "Wk";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Bk";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::PAWN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WP";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::PAWN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BP";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WQ";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BQ";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::ROOK && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WR";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::ROOK && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BR";
				}
			}
		}
		std::cout << " " << i+1 << std::endl;
	}
	std::cout << " a  b  c  d  e  f  g  h\n\n\n";
}

void Visual::printBoardFiguresForBlack(Board* board) const
{
	Position position;
	for (int i = 0; i < LAST_COORD_OF_BOARD; ++i)
	{
		for (int j = 0; j< LAST_COORD_OF_BOARD; ++j)
		{
			position.y = j;
			position.x = i;
			std::cout << SEPARATOR;

			if (board->getSquare(position)->getSquareColor() == SquareColor::BLACK && !board->isFigurePlaced(position))
			{
				std::cout << "X ";
			}
			else if (board->getSquare(position)->getSquareColor() == SquareColor::WHITE && !board->isFigurePlaced(position))
			{
				std::cout << EMPTY_FILLER << EMPTY_FILLER;
			}
			else
			{
				if (board->getSquare(position)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WB";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::BISHOP && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BB";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KING && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WK";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KING && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BK";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "Wk";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::KNIGHT && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "Bk";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::PAWN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WP";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::PAWN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BP";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WQ";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::QUEEN && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BQ";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::ROOK && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::WHITE)
				{
					std::cout << "WR";
				}
				else if (board->getSquare(position)->getFigure()->getType() == FigureType::ROOK && board->getSquare(position)->getFigure()->getFigureColor() == FigureColor::BLACK)
				{
					std::cout << "BR";
				}
			}
		}
		std::cout << " " << 1+i << std::endl;
	}
	std::cout << " h  g  f  e  d  c  b  a\n\n\n";
}