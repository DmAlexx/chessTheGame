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
	converterCoordinates(m_currentPosition, m_initialCurrentCoordinates);
}

void Gamer::convertLastCoordinates()
{
	converterCoordinates(m_lastPosition, m_initialLastCoordinates);
}

void Gamer::converterCoordinates(Position& currentOrLastPosition, std::string& initialCurrentOrLastCoordinates)
{
	for (int i = 0; i < 2; ++i)
	{
		if (i == 0)
		{
			for (auto& coord : convertCoordinatesTableChar)
			{
				if (initialCurrentOrLastCoordinates[i] == coord.first)
				{
					currentOrLastPosition.y = coord.second;
				}
			}
		}
		else
		{
			for (auto& coord : convertCoordinatesTableNumbers)
			{
				if (initialCurrentOrLastCoordinates[i] == coord.first)
				{
					currentOrLastPosition.x = coord.second;
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