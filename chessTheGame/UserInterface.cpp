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
			clearConsole();
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
		std::cout << "First player, enter your name : \n";
		std::cin >> gamerName;
		Gamer firstGamer(FigureColor::WHITE, gamerName);
		std::cout << firstGamer.getName() << " you will play with white figures\n\n";
		std::cout << "Second player, enter your name : \n";
		std::cin >> gamerName;
		Gamer secondGamer(FigureColor::BLACK, gamerName);
		std::cout << secondGamer.getName() << " you will play with black figures\n";
				
		waitForPressAnyKey();
		clearConsole();

		Game openGame;
		Board* board = openGame.getBoard();
		int counter = 0;
		openGame.figuresArrangement();
		Visual visual;
		int switchForKingCheck = 0;
		while (true)
		{
			clearConsole();
			if (counter % 2 == 0)
			{
				gamerMove(counter, openGame, firstGamer, visual, board);
			}
			else
			{
				gamerMove(counter, openGame, secondGamer, visual, board);
			}
		}
		break;
	}
}

	void UserInterface::gamerMove(int& counter, Game& openGame, Gamer& gamer, const Visual& visual, Board* board)
	{
		std::string figureColorOutput;
		if (counter % 2 == 0)
		{
			figureColorOutput = "white";
			visual.printBoardFiguresForWhite(board);
		}
		else 
		{
			figureColorOutput = "black";
			visual.printBoardFiguresForWhite(board);
		}
		std::cout << "Moving "<< figureColorOutput << ", " << gamer.getName() << ": ";
		gamer.inputMoveCoordinates();
		
		if (counter % 2 == 0 && openGame.getBoard()->getSquare(gamer.getCurrentPosition())->getFigure()->getFigureColor() == FigureColor::WHITE
			&& openGame.figureMove(gamer.getCurrentPosition(), gamer.getLastPosition()))
		{
			++counter;
		}
		else if (counter % 2 != 0 && openGame.getBoard()->getSquare(gamer.getCurrentPosition())->getFigure()->getFigureColor() == FigureColor::BLACK
			&& openGame.figureMove(gamer.getCurrentPosition(), gamer.getLastPosition()))
		{
			--counter;
		}
		else
		{
			if (counter % 2 == 0 && openGame.getBoard()->getSquare(gamer.getCurrentPosition())->getFigure()->getFigureColor() != FigureColor::WHITE)
			{
				std::cout << "Wrong coordinates, moving white...\n";
			}
			else if (counter % 2 != 0 && openGame.getBoard()->getSquare(gamer.getCurrentPosition())->getFigure()->getFigureColor() == FigureColor::WHITE)
			{
				std::cout << "Wrong coordinates, moving black...\n";
			}
			waitForPressAnyKey();
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
	std::cout << "press any key...\n";
#ifdef _WIN32
	_getch();
#endif // !_WIN32
#ifdef _linux
	getchar();
#endif //!_linux
}

