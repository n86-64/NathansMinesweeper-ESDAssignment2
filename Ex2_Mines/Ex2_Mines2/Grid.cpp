#include <cstdlib>
#include <time.h>

#include "Grid.h"

Grid::Grid()
{
}

void Grid::setUpGrid(Settings gridSettings)
{
	int gridArea;
	gridWidth = gridSettings.getGridWidth();
	gridHeight = gridSettings.getGridHeight();

	gridArea = gridWidth * gridHeight;

	theGrid = new Cell[gridArea];

	placeMines(gridSettings.getDifficultyLevel(), gridArea);
}

int Grid::getCellPosition(Vector2D cellPosition)
{
	return cellPosition.getX() * (gridWidth * cellPosition.getY());
}

void Grid::placeMines(Difficulty difficultyFactor, int gridArea)
{
	bool* mineStatus = nullptr;

	srand(time(NULL));
	Vector2D minePosition;
	Vector2D navigationVector;
	
	numberOfFlags = numberOfMines = ((int)difficultyFactor * gridArea) / 10;

	for (int i = numberOfMines; i != 0; i--) 
	{
		minePosition.setX(rand() % gridWidth);
		minePosition.setY(rand() % gridHeight);

		mineStatus = theGrid[getCellPosition(minePosition)].isAMine;

		if (!(*mineStatus)) 
		{
			*mineStatus = true;

			for (int y = minePosition.getY() - 1; y <= minePosition.getY() + 1; y++) 
			{
				for (int x = minePosition.getX() - 1; x <= minePosition.getX() + 1; x++)
				{
					if (x != minePosition.getX() && y != minePosition.getY()) 
					{
						navigationVector.setX(x);
						navigationVector.setY(y);

						theGrid[getCellPosition(navigationVector)].addToNumberOfAjacentMines();
					}
				}
			}
		}

		minePosition.zeroVector();
		navigationVector.zeroVector();
	}
}
