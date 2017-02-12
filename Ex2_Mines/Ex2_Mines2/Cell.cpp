#include "Cell.h"

Cell::Cell()
{}

Cell::~Cell()
{}

bool Cell::isAMine()
{
	return isMine;
}

bool Cell::isCurrentlyFlagged()
{
	return isFlagged;
}

bool Cell::isCurrentlyVisible()
{
	return isVisible;
}

int Cell::getNumberOfAjacentMines()
{
	return noOfAjacentMines;
}

void Cell::addToNumberOfAjacentMines()
{
	noOfAjacentMines++;
	return;
}

void Cell::placeMineHere()
{
	isMine = true;
	return;
}

void Cell::setFlagState(bool isCellFlagged)
{
	isFlagged = isCellFlagged;
	return;
}

void Cell::revealCell()
{
	isVisible = true;
	return;
}


