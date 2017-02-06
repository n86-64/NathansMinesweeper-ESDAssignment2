#include "Game.h"

Game::Game()
{
}

Game::~Game() 
{
	// TODO - add cleanup logic here. 
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
			break;
		case 2:
			break;
		case 3:
			break;
		}

	} while (!quitGame);
	
}
