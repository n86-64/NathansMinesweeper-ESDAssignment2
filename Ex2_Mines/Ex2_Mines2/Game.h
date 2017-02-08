/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Game.h
File Contents - The class definition for the Game Class. 

Purpose - The main class object which will process all the game logic. 
*/


#pragma once


#include <iostream>
#include <chrono>
#include <string>
#include <time.h>

#include "GameState.h"
#include "gameMenu.h"
#include "Settings.h"
#include "settingsMenu.h"
#include "Grid.h"


class Game {
public:
	Game();
	~Game();

	void startGame();

private: 
	void startGameLoop();
	void endSession();
	bool checkInput(std::string theInput, Vector2D& parameterValues);
	void Quit(); 

private:
	gameMenu theGameMenu;
	settingsMenu theSettingsMenu;
	Settings gameSettings;
	Grid theGrid;

	std::chrono::time_point<std::chrono::system_clock> startTime;
};