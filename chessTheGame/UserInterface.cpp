#include "UserInterface.h"


UserInterface::UserInterface()
{
	while (true)
	{
		std::cout << "Make your choice\n";
		std::cout << "1. Start game with AI\n";
		std::cout << "2. Start game human VS human\n";
		std::cout << "0. Exit game\n\n";
		std::cout << "version 1.0\n";
		std::cin >> m_choice;
		if (m_choice == 0)
		{
			std::cout << "Exit game...\n";
			break;
		}
		else
		{
#ifdef _WIN32
			system("cls");
#endif // !_WIN32
#ifdef _linux
			system("clear");
#endif //!_linux
			
			secondMenu();
		}
	}
}

void UserInterface::secondMenu()
{
	switch (m_choice)
	{
	case 1:
		std::cout << "Available in next versions...\n";
		std::cout << "Press any key to continue\n";
		
#ifdef _WIN32
		_getch();
		system("cls");
#endif // !_WIN32
#ifdef _linux
		getchar();
		system("clear");
#endif //!_linux
		break;
	case 2:
		Visual visual;
		std::cout << "Choose figure to move...\n";
		std::cin >> m_choiceFigure;
		std::cout << "Choose field where figure move...\n";
		std::cin >> m_choiceMove;
		break;
	}
}

