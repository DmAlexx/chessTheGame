#include "Visual.h"

Visual::Visual()
{
	for (int i = 0; i < LENGTH_WIDTH_SIZE_BOARD; ++i)
	{
		for (int j = 0; j < LENGTH_WIDTH_SIZE_BOARD; ++j)
		{
			switch (i)
			{
			case BLACK_FIGURES_START_POSITION:
				for (auto it : FigureSpriteOut)
				{
					if (it.first == m_videoOutSpriteBlack[j])
					{
						std::cout << "|" << it.second;
					}
				}
				break;
			case BLACK_PAWNS_START_POSITION:
				std::cout << "|" << "BP";
				break;
			case WHITE_PAWNS_START_POSITION:
				std::cout << "|" << "WP";
				break;
			case WHITE_FIGURES_START_POSITION:
				for (auto it : FigureSpriteOut)
				{
					if (it.first == m_videoOutSpriteWhite[j])
					{
						std::cout << "|" << it.second;
					}
				}
				break;
			default:
				std::cout << "|";
				if (j % 2 == 0 && i % 2 == 0 || j % 2 != 0 && i % 2 != 0)
				{
					std::cout << "* ";
				}
				else
				{
					std::cout << "  ";
				}
				break;
			}
		}
		std::cout << " " << LENGTH_WIDTH_SIZE_BOARD - i << std::endl;
	}
	for (int i = 0; i < LENGTH_WIDTH_SIZE_BOARD; ++i)
	{
		std::cout << " " << BOARD_LETTERS[i] << " ";
	}
	std::cout << "\n\n";
}