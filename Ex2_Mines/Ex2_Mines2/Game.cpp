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
}
