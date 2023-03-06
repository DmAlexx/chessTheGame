#pragma once
#include <iostream>
#include <cstdlib>
#include "Visual.h"
#include <string>

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
	std::string m_choiceFigure;
	std::string m_choiceMove;
	void secondMenu();
};

