/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - gameMenu.h
File Contents - The class definition for the gameMenu class. 

Purpose - The class object that provides the basic user interface for the player. 
*/


#pragma once

#include <iostream>
#include <string>

#include "Math_Vector2D.h"

class gameMenu {
public:
	gameMenu(); 

	void printMenu();
	void retrieveMenuSelection();

private:
	void checkInput(std::string theInput, Vector2D& parameterRefrence); // TODO - Add in system for paramenters
};