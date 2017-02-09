#pragma warning (disable : 4996)

#include <locale>
#include "Game.h"

Game::Game()
	: theSettingsMenu(&gameSettings)
{}

Game::~Game() 
{}

void Game::startGame()
{
	bool quitGame = false;

	do 
	{
		theGameMenu.printMenu();
		switch (theGameMenu.retrieveMenuSelection()) 
		{
		case 1:
			startGameLoop();
			break;
		case 2:
			theSettingsMenu.printMenu();
			break;
		case 3:
			quitGame = true;
			break;
		}

		system("cls");

	} while (!quitGame);
	return;
}

void Game::startGameLoop()
{
	Vector2D cellToCheck;
	GameState gameState = GAMESTATE_PLAYING;
	std::chrono::duration<double> timeResult;

	bool playingGame = true;
	bool cheats = false;
	bool isCorrectInput;

	std::string playerInput;
	std::locale loc;

	system("cls");
	theGrid.setUpGrid(gameSettings);
	std::cout << "Here is your grid, "
		<< "You need to find " << theGrid.getNumberOfMines() << " Mines " << std::endl
		<<"Good luck: " 
		<< std::endl;
	theGrid.drawGrid();

	std::cout << "Press enter to continue - ";
	getchar();

	if (gameSettings.getClassicModeState()) 
	{
		startTime = std::chrono::system_clock::now();
	}

	while (playingGame)
	{
		system("cls");
		theGrid.drawGrid(cheats);
		std::cout << "Press F followed by a coordinate to flag a position (F <Xpos> <yPos>)" << std::endl
		          << "Press R followed by a coordinate in order to remove a flag. (R <Xpos> <yPos>)" << std::endl
		          << "Press G followed by a coordinate in order to guess a position (G <Xpos> <yPos>)" << std::endl
		          << "Press Q to quit this current session" << std::endl;

		std::cout << "Enter an X value between 1 and " << gameSettings.getGridWidth()
			<< ". Along with"
			<< " a Y value between 1 and " << gameSettings.getGridHeight()
			<< std::endl;

		do 
		{
			std::cout << ">>> ";
			isCorrectInput = true;

			std::getline(std::cin, playerInput);
			playerInput[0] = std::toupper(playerInput[0], loc);

			if (checkInput(playerInput,cellToCheck)) 
			{
				switch (playerInput[0]) 
				{
				case 'F':
					if (theGrid.getNoOfRemainingFlags() != 0) 
					{
						theGrid.flagCell(cellToCheck,gameState);

						if (gameState == GAMESTATE_WIN) 
						{
							playingGame = false; 
						}
					}
					else 
					{
						std::cout << "You dont have any flags left."
							<< "Remove a flag if you wish to place one" << std::endl
							<< "Press enter to continue - ";
						getchar();
					}
					break;
				case 'R':
					theGrid.unFlagCell(cellToCheck);
					break;
				case 'G':
					theGrid.checkCell(cellToCheck, gameState,gameSettings.getClassicModeState());
					if (gameState != GAMESTATE_PLAYING) 
					{
						playingGame = false;
					}
					break;
				case 'Q':
					std::cout << "Returning you to the main menu." << std::endl
						<< "Press enter to continue - ";
					getchar();
					playingGame = false;
					break;
				case 'Z':
					cheats = !cheats;
					break;
				default:
					std::cout << "Error you have entered an invalid option. "
						      << "Please enter a valid selection. " << std::endl
						      << "Press enter to continue - ";
					getchar();
					isCorrectInput = false;
				}
			}
			else 
			{
				std::cout << "Error you have entered invalid parameters. "
					<< "Please enter a valid selection. " << std::endl;
				std::cout << "Press enter to continue - ";
				getchar();
				isCorrectInput = false;
			}

		} while (!isCorrectInput);

		cellToCheck.resetVector();
	}
	 
	system("cls");

	switch (gameState) 
	{
	case GAMESTATE_LOSS:
		theGrid.revealMines();
		theGrid.drawGrid();
		std::cout << "BOOOOOOOOOOOOOOOOMMMMMMMMMMMMMMMMMM" << std::endl
			<< "No you hit a mine "
			<< "Game Over"
			<< std::endl;
		std::cout << "Press enter to return to the main menu - ";
		getchar();
		break;

	case GAMESTATE_WIN:
		theGrid.drawGrid();
		std::cout << "Well done you cleared the board"
			<< std::endl;

		if (gameSettings.getClassicModeState()) 
		{
			endTime = std::chrono::system_clock::now();
			timeResult = endTime - startTime;
			std::cout << "You cleared the board in "
				<< std::round(timeResult.count())
				<< " secounds"
				<< std::endl
				<< "Press enter to return to the main menu";
			getchar();
		}
		break;
	}

	theGrid.destroyGrid();
	return;
}

bool Game::checkInput(std::string theInput, Vector2D& parameterValues)
{
	std::string valueBuffer;
	int whitespaces = 0;
	bool returnValue = false;


	if ((theInput[0] == 'Q' || theInput[0] == 'Z') && theInput.length() == 1) 
	{
		returnValue = true;
	}
	else 
	{
		if (theInput.length() > 3) 
		{
			for (int i = 1; i < (int)theInput.length(); i++) 
			{
				if (whitespaces <= 2) 
				{
					switch (theInput[i])
					{
					case ' ':
						if (!valueBuffer.empty()) 
						{
							parameterValues.setX(std::stoi(valueBuffer));
							valueBuffer.clear();
						}
						whitespaces++;

						break;
					default:
						if (theInput[i] >= 48 && theInput[i] <= 57)
						{
							valueBuffer += theInput[i];
						}
					}
				}
			}
		}
	}

	if (!valueBuffer.empty() && (parameterValues.getX() != 0))
	{
		parameterValues.setY(std::stoi(valueBuffer));
		returnValue = true;
	}

	return returnValue;
}
