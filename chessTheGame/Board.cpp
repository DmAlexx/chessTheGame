#include "Board.h"



Board::Board()
{
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			if (i == 0 || i == 1 || i == 6 || i == 7)
			{
				m_board[i][j] = 1;
			}
			else
			{
				m_board[i][j] = 0;
			}
		}
	}
}
