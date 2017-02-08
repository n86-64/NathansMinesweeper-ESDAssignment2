
#pragma warning (disable : 4996)

#include <locale>
#include "Game.h"

Game::Game()
	: theSettingsMenu(&gameSettings)
{
}

Game::~Game() 
{
}

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

	bool playingGame = true;
	bool cheats = false;
	bool isCorrectInput;

	std::string playerInput;
	std::locale loc;

	system("cls");
	theGrid.setUpGrid(gameSettings);
	std::cout << "Here is your grid, Good luck: " << std::endl;

	if (gameSettings.getClassicModeState()) 
	{
		startTime = std::chrono::system_clock::now();
	}

	while (playingGame)
	{
		system("cls");
		theGrid.drawGrid(cheats);
		std::cout << "Press F followed by a coordinate to flag a position" << std::endl
		          << "Press R followed by a coordinate in order to remove a flag. " << std::endl
		          << "Press G followed by a coordinate in order to guess a position" << std::endl
		          << "Press Q to quit this current session" << std::endl;

		std::cout << "Enter an X value between 0 and " << gameSettings.getGridWidth() - 1
			<< ". Along with"
			<< " a Y value between 0 and " << gameSettings.getGridHeight() - 1
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
					theGrid.flagCell(cellToCheck);
					break;
				case 'R':
					theGrid.unFlagCell(cellToCheck);
					break;
				case 'G':
					theGrid.checkCell(cellToCheck, gameState);
					if (gameState != GAMESTATE_PLAYING) 
					{
						playingGame = false;
					}
					break;
				case 'Q':
					std::cout << "Returning you to the main menu." << std::endl;
					playingGame = false;
					break;
				case 'Z':
					if (!cheats) 
					{
						cheats = true;
					}
					else 
					{
						cheats = false;
					}
					break;
				default:
					std::cout << "Error you have entered an invalid option. "
						      << "Please enter a valid selection. " << std::endl;
					isCorrectInput = false;
				}
			}
			else 
			{
				std::cout << "Error you have entered invalid parameters. "
					<< "Please enter a valid selection. " << std::endl;
				isCorrectInput = false;
			}

		} while (!isCorrectInput);

		cellToCheck.zeroVector();
	}

	// ensures no memory leaks when the application is terminated. 
	theGrid.destroyGrid();

	// TODO - Add the game loop here. 
}

bool Game::checkInput(std::string theInput, Vector2D& parameterValues)
{
	std::string valueBuffer;
	int whitespaces = 0;
	bool returnValue = true;


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
							switch (whitespaces) 
							{
							case 1:
								parameterValues.setX(std::stoi(valueBuffer));
								valueBuffer.clear();
								break;
							}
						}
						whitespaces++;

						break;
					default:
						if (theInput[i] >= 48 && theInput[i] <= 57)
						{
							valueBuffer += theInput[i];
						}
						else 
						{
							returnValue = false;
						}
					}
				}
				else 
				{
					returnValue = false;
				}
			}
		}
	}

	if (valueBuffer.empty() && theInput.length() > 1) 
	{
		returnValue = false;
	}
	else if (!valueBuffer.empty())
	{
		parameterValues.setY(std::stoi(valueBuffer));
	}

	return returnValue;
}
