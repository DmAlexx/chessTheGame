#pragma once
#include <iostream>
//#include <cstdlib>
#include "Visual.h"
#include "Gamer.h"
#include "Game.h"
#include "Figure.h"
#include <string>
#include "Board.h"

#ifdef _WIN32
	#include <conio.h>
#endif // !_WIN32

#ifdef _linux
#include <termios.h>
#endif // !_linux

class UserInterface
{
public:
	UserInterface();

protected:
	int m_choice = 0;
	void secondMenu();
	void clearConsole();
	void waitForPressAnyKey();
	void gamerMove(int& counter, Game& openGame, Gamer& gamer, const Visual& visual, Board* board);
};

