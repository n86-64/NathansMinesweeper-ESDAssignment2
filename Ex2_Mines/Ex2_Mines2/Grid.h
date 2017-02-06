/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Grid.h
File Contents - The class definition for a grid.

Purpose - Contains the interface and logic for the minesweeper grid.
*/



#pragma once


#include "Cell.h"

class Grid {
public:
	Grid();

private:
	Cell* theGrid = nullptr;
	int cellWidth; 
};