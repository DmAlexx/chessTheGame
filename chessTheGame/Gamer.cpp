#include "Gamer.h"

Gamer::Gamer(FigureColor gamerFigureColor, std::string name)
	: m_gamerFigureColor(gamerFigureColor)
	, m_name(name)
{
}

void Gamer::inputMoveCoordinates()
{
	std::cout << "choose figure to move, enter coordinates : ";
	std::cin >> m_initialCurrentCoordinates;
	std::cout << "choose place to move figure, enter coordinates : ";
	std::cin >> m_initialLastCoordinates;
}

void Gamer::convertCurrentCoordinates()
{
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			for (auto& coord : convertCoordinatesTable)
			{
				if (m_initialCurrentCoordinates[i] == coord.first)
				{
					m_currentPosition.y = coord.second;
				}
			}
		}
		else
		{
			for (auto& coord : convertCoordinatesTable)
			{
				if (m_initialCurrentCoordinates[i] == coord.first)
				{
					m_currentPosition.x = coord.second;
				}
			}
		}
	}
}

void Gamer::convertLastCoordinates()
{
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			for (auto& coord : convertCoordinatesTable)
			{
				if (m_initialLastCoordinates[i] == coord.first)
				{
					m_lastPosition.y = coord.second;
				}
			}
		}
		else
		{
			for (auto& coord : convertCoordinatesTable)
			{
				if (m_initialLastCoordinates[i] == coord.first)
				{
					m_lastPosition.x = coord.second;
				}
			}
		}
	}
}

Position Gamer::getLastPosition()
{
	convertLastCoordinates();
	return m_lastPosition;
}

Position Gamer::getCurrentPosition()
{
	convertCurrentCoordinates();
	return m_currentPosition;
}

FigureColor Gamer::getColor()
{
	return m_gamerFigureColor;
}