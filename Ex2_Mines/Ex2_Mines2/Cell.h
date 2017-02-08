/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Cell.h
File Contents - The class definition for a grid cell.

Purpose - Contains the logic for the cells that make up the Grid in minesweeper.
*/



#pragma once


class Cell {
public:
	Cell();
	~Cell();

	bool isAMine();
	void placeMineHere();

	int getNumberOfAjacentMines();
	void addToNumberOfAjacentMines();

	bool isCurrentlyFlagged();
	bool isCurrentlyVisible();
	void setFlagState(bool newFlagState);
	void revealCell();

private:
	bool isMine = false;
	int noOfAjacentMines = 0;
	bool isFlagged = false;
	bool isVisible = false;
};