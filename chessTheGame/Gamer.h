#pragma once
#include "Figure.h"
#include <string>
#include <iostream>
#include <map>
#include "Figure.h"

namespace
{
	const std::map<char, int> convertCoordinatesTableChar = {
		{'h',0 },
		{'g',1 },
		{'f',2 },
		{'e',3 },
		{'d',4 },
		{'c',5 },
		{'b',6 },
		{'a',7 }
	};

	const std::map<char, int> convertCoordinatesTableNumbers = {
		{'1',0 },
		{'2',1 },
		{'3',2 },
		{'4',3 },
		{'5',4 },
		{'6',5 },
		{'7',6 },
		{'8',7 },
	};

}

class Gamer
{
public:
	Gamer(FigureColor gamerFigureColor, std::string name);
	void inputMoveCoordinates();
	std::string getName() { return m_name; }
	Position getCurrentPosition();
	Position getLastPosition();
	FigureColor getColor();
private:
	void convertCurrentCoordinates();
	void convertLastCoordinates();
	std::string m_name;
	std::string m_initialCurrentCoordinates;
	std::string m_initialLastCoordinates;
	Position m_currentPosition;
	Position m_lastPosition;
	FigureColor m_gamerFigureColor;
};

