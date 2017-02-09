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
#include "Settings.h"
#include "GameState.h"

class Grid {
public:
	Grid();
	~Grid();

	void setUpGrid(Settings gridSettings);

	void flagCell(Vector2D cellPosition, GameState& theGameState);
	void unFlagCell(Vector2D cellPosition);
	void revealMines();

	int getNoOfRemainingFlags();

	void checkCell(Vector2D cellPosition, GameState& currentState, bool classicMode);
	int getNumberOfRemainingCells();
	int getNumberOfMines();

	void drawGrid(bool isCheatsEnabled = false);


	void destroyGrid();

private:
	Cell* theCellArray = nullptr;
	int gridWidth = 0;
	int gridHeight = 0;
	int noOfHiddenCells = 0;
	int numberOfMines = 0;
	int numberOfFlags = 0;

	int getCellPosition(Vector2D cellPosition);
	void checkAjacentMines(Vector2D initialCellPosition);
	void placeMines(Difficulty difficultyFactor, int gridArea);

};