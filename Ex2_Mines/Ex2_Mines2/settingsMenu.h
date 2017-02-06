/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - settingsMenu.h
File Contents - The class definition for the Settings menu class.

Purpose - The provides logic for menu navigation and setting options for the game. 
*/

#pragma once

#include <iostream>
#include <string>

#include "Settings.h"

class settingsMenu {
public:
	settingsMenu(Settings* parameterData); 
	~settingsMenu();

	void printMenu();

private:
	Settings* settingsToModify = nullptr;
	void retrieveMenuSelection(bool& inMenu);
	bool checkInput(std::string input, int& parameterValue);
	bool checkInputRangeValid(int paramValue, int rangeMin, int rangeMax, bool& validFlag);
};