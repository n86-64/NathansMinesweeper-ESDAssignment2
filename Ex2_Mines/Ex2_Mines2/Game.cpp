
#pragma warning (disable : 4996)

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
}

void Game::startGameLoop()
{
	theGrid.setUpGrid(gameSettings);

#ifdef _DEBUG
	char ter_char = '\0';
	theGrid.drawGrid(true);
	scanf("%c", &ter_char);
#endif // _DEBUG

}
