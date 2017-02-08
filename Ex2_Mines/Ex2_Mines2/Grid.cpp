#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::setUpGrid(Settings gridSettings)
{
	int gridArea;
	gridWidth = gridSettings.getGridWidth();
	gridHeight = gridSettings.getGridHeight();

	gridArea = gridWidth * gridHeight;

	// REVIEW - Make this a construction function or make the gridArea in scope to ensure it is constructed correctly. 
	theCellArray = new Cell[gridArea];
	placeMines(gridSettings.getDifficultyLevel(), gridArea);
}

void Grid::flagCell(Vector2D cellPosition)
{
	if (theCellArray[getCellPosition(cellPosition)].isCurrentlyFlagged()) 
	{
		std::cout << "This position is already flagged" << std::endl;
	}
	else 
	{
		theCellArray[getCellPosition(cellPosition)].setFlagState(true);
	}
	return;
}

void Grid::unFlagCell(Vector2D cellPosition)
{
	if (!theCellArray[getCellPosition(cellPosition)].isCurrentlyFlagged())
	{
		std::cout << "This position dosent have a flag on it." << std::endl;
	}
	else
	{
		theCellArray[getCellPosition(cellPosition)].setFlagState(false);
	}
	return;
}

void Grid::checkCell(Vector2D cellPosition, GameState& currentState)
{
	Cell* currentCell = &theCellArray[getCellPosition(cellPosition)];
	if (currentCell->isCurrentlyVisible()) 
	{
		currentCell->revealCell();

		if (currentCell->isAMine()) 
		{
			currentState = GAMESTATE_LOSS;
		}
		else if (currentCell->getNumberOfAjacentMines() == 0) 
		{
			// reveal all ajacent mines here. 
		}
	}
	else 
	{
		std::cout << "You have already selected this cell." << std::endl;
	}
}

void Grid::drawGrid(bool isCheatsEnabled)
{
	Cell* currentCell = nullptr;
	Vector2D cellToDraw;

	for (int y = 0; y < gridHeight; y++) 
	{
		cellToDraw.setY(y);
		for (int x = 0; x < gridWidth; x++) 
		{
			cellToDraw.setX(x);

			currentCell = &theCellArray[getCellPosition(cellToDraw)];

			if (currentCell->isCurrentlyFlagged())
			{
				std::cout << "F";
			}
			else if ((!currentCell->isCurrentlyVisible()) && isCheatsEnabled == false)
			{
				std::cout << "*";
			}
			else 
			{
				if (currentCell->isAMine())
				{
					std::cout << "M";
				}
				else 
				{
					std::cout << currentCell->getNumberOfAjacentMines();
				}
			}
		}
		std::cout << std::endl;
	}
	return;
}

void Grid::destroyGrid()
{
	delete[] theCellArray;
	theCellArray = nullptr;
	return;
}

int Grid::getCellPosition(Vector2D cellPosition)
{
	return cellPosition.getX() + (gridWidth * cellPosition.getY());
}

void Grid::placeMines(Difficulty difficultyFactor, int gridArea)
{
	srand(time(NULL));
	Vector2D minePosition;
	Vector2D navigationVector;
	
	numberOfFlags = numberOfMines = ((int)difficultyFactor * gridArea) / 10;

	for (int i = numberOfMines; i != 0; i--) 
	{
		minePosition.setX(rand() % gridWidth);
		minePosition.setY(rand() % gridHeight);

		if (!theCellArray[getCellPosition(minePosition)].isAMine())
		{
			theCellArray[getCellPosition(minePosition)].placeMineHere();
			for (int y = minePosition.getY() - 1; y <= minePosition.getY() + 1; y++) 
			{
				for (int x = minePosition.getX() - 1; x <= minePosition.getX() + 1; x++)
				{
					// REVIEW - is (x < gridWidth && x < gridHeight) check nessecery?
					if ((x != minePosition.getX() && y != minePosition.getY()) && (x >= 0 && y >= 0) && (x < gridWidth && y < gridHeight)) 
					{
						navigationVector.setX(x);
						navigationVector.setY(y);

						theCellArray[getCellPosition(navigationVector)].addToNumberOfAjacentMines();
					}
				}
			}
		}

		minePosition.zeroVector();
		navigationVector.zeroVector();
	}
	return;
}
