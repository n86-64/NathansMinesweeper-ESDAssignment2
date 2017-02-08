#include "Cell.h"

Cell::Cell()
{
}

Cell::~Cell()
{

}

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
}

void Cell::placeMineHere()
{
	isMine = true;
}

void Cell::setFlagState(bool newFlagState)
{
	isFlagged = newFlagState;
}

void Cell::revealCell()
{
	isVisible = true;
}


