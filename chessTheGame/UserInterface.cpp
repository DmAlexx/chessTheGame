#include "UserInterface.h"
#include "Gamer.h"


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
		std::cout << "Press any key to continue...\n";
		waitForPressAnyKey();
		clearConsole();
		break;
	case 2:
		std::string gamerName;
		std::cout << "First gamer, enter your name : \n";
		std::cin >> gamerName;
		Gamer firstGamer(FigureColor::WHITE, gamerName);
		std::cout << firstGamer.getName() << " you will play with white figures\n";
		std::cout << "Second gamer, enter your name : \n";
		std::cin >> gamerName;
		Gamer secondGamer(FigureColor::BLACK, gamerName);
		std::cout << secondGamer.getName() << " you will play with black figures\n";
		std::cout << "Press any key to continue...\n";
		
		waitForPressAnyKey();
		clearConsole();

		Game openGame;
		Board* board = openGame.getBoard();
		int counter = 0;
		openGame.figuresArrangement();
		Visual visual;
		
		while (true)
		{
			if (counter % 2 == 0)
			{
				clearConsole();
				visual.printBoardFiguresForWhite(board);
				std::cout << "Moving white, " << firstGamer.getName() << " :";
				firstGamer.inputMoveCoordinates();
				if (openGame.figureMove(firstGamer.getCurrentPosition(), firstGamer.getLastPosition()))
				{
					openGame.figureMove(firstGamer.getCurrentPosition(), firstGamer.getLastPosition());
				}
				else
				{
					std::cout << "Can't make a move, press any key...\n";
					waitForPressAnyKey();
					--counter;
				}
				
			}
			else
			{
				clearConsole();
				visual.printBoardFiguresForBlack(board);
				std::cout << "Moving black, " << secondGamer.getName()<<" :";
				secondGamer.inputMoveCoordinates();
				if (openGame.figureMove(secondGamer.getCurrentPosition(), secondGamer.getLastPosition()))
				{
					openGame.figureMove(secondGamer.getCurrentPosition(), secondGamer.getLastPosition());
				}
				else
				{
					std::cout << "Can't make a move, press any key...\n";
					waitForPressAnyKey();
					--counter;
				}
			}
			++counter;
		}
		break;
	}
}

void UserInterface::clearConsole()
{
#ifdef _WIN32
	system("cls");
#endif // !_WIN32
#ifdef _linux
	system("clear");
#endif //!_linux
}

void UserInterface::waitForPressAnyKey()
{
#ifdef _WIN32
	_getch();
#endif // !_WIN32
#ifdef _linux
	getchar();
#endif //!_linux
}

