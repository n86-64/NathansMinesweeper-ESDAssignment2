

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "Grid.h"

Grid::Grid()
{}

Grid::~Grid()
{}

void Grid::setUpGrid(Settings gridSettings)
{
	int gridArea;
	gridWidth = gridSettings.getGridWidth();
	gridHeight = gridSettings.getGridHeight();

	gridArea = gridWidth * gridHeight;

	if (theCellArray != nullptr) 
	{
		delete[] theCellArray;
		theCellArray = nullptr;
	}

	theCellArray = new Cell[gridArea];
	placeMines(gridSettings.getDifficultyLevel(), gridArea);
	return;
}

void Grid::flagCell(Vector2D cellPosition, GameState& theGameState)
{
	cellPosition.correctVector();
	Cell* cellToFlag = nullptr;

	if ((cellPosition.getX() < gridWidth) && (cellPosition.getY() < gridHeight)) 
	{
		cellToFlag = &theCellArray[getCellPosition(cellPosition)];

		if (cellToFlag->isCurrentlyFlagged())
		{
			std::cout << "This position is already flagged" << std::endl;
			std::cout << "Press enter to continue - ";
			getchar();
		}
		else
		{
			if (cellToFlag->isAMine())
			{
				numberOfMines--;

				if (numberOfMines == 0) 
				{
					theGameState = GAMESTATE_WIN;
				}
			}

			cellToFlag->setFlagState(true);
			numberOfFlags--;
		}
	}
	else 
	{
		std::cout << "This position is out of range. Please enter a value"
			<< " within range." << std::endl
			<< "Press enter to continue - ";
		getchar();
	}
	return;
}

void Grid::unFlagCell(Vector2D cellPosition)
{
	cellPosition.correctVector();
	Cell* cellToUnFlag = nullptr;

	if ((cellPosition.getX() < gridWidth) && (cellPosition.getY() < gridHeight))
	{
		cellToUnFlag = &theCellArray[getCellPosition(cellPosition)];
		if (!cellToUnFlag->isCurrentlyFlagged())
		{
			std::cout << "This position dosent have a flag on it."
				<< "Press enter to continue";
			getchar();
		}
		else
		{
			if (cellToUnFlag->isAMine())
			{
				numberOfMines++;
			}

			cellToUnFlag->setFlagState(false);
			numberOfFlags++;
		}
	}
	else
	{
		std::cout << "This position is out of range. Please enter a value"
				<< " within range." << std::endl
				<< "Press enter to continue - ";
		getchar();
	}
	return;
}

void Grid::revealMines()
{
	for (int i = 0; i < (gridWidth * gridHeight); i++) 
	{
		if (theCellArray[i].isAMine()) 
		{
			theCellArray[i].revealCell();
		}
	}
	return;
}

int Grid::getNoOfRemainingFlags()
{
	return numberOfFlags;
}

void Grid::checkCell(Vector2D cellPosition, GameState& currentState, bool classicMode)
{
	cellPosition.correctVector();
	Cell* currentCell = nullptr;
	
	if ((cellPosition.getX() < gridWidth) && (cellPosition.getY() < gridHeight))
	{
		currentCell = &theCellArray[getCellPosition(cellPosition)];
		if (!currentCell->isCurrentlyVisible())
		{
			currentCell->revealCell();
			noOfHiddenCells--;

			if (currentCell->isAMine())
			{
				currentState = GAMESTATE_LOSS;
			}
			else if (currentCell->getNumberOfAjacentMines() == 0 && classicMode)
			{
				checkAjacentMines(cellPosition);
			}

			if (noOfHiddenCells == 0) 
			{
				currentState = GAMESTATE_WIN;
			}
		}
		else
		{
			std::cout << "You have already selected this cell." << std::endl
				<< "Press enter to continue - ";
			getchar();
		}
	}
	else 
	{
		std::cout << "This position is out of range. Please enter a value"
			<< " within range." << std::endl
			<< "Press enter to continue - ";
		getchar();
	}
	return;
}

int Grid::getNumberOfRemainingCells()
{
	return noOfHiddenCells;
}

int Grid::getNumberOfMines()
{
	return numberOfMines;
}

void Grid::drawGrid(bool isCheatsEnabled)
{
	Cell* currentCell = nullptr;
	Vector2D cellToDraw;

	for (int y = 0; y <= gridHeight; y++) 
	{
		if (y != gridHeight)
		{
			cellToDraw.setY(y);

			if (y + 1 < 10)
			{
				std::cout << y + 1 << "  |";
			}
			else
			{
				std::cout << y + 1 << " |";
			}
		}

		for (int x = 0; x < gridWidth; x++) 
		{
				cellToDraw.setX(x);

				currentCell = &theCellArray[getCellPosition(cellToDraw)];

				if (currentCell->isCurrentlyFlagged())
				{
					std::cout << "F ";
				}
				else if ((!currentCell->isCurrentlyVisible()) && isCheatsEnabled == false)
				{
					std::cout << "* ";
				}
				else
				{
					if (currentCell->isAMine())
					{
						std::cout << "M ";
					}
					else
					{
						std::cout << currentCell->getNumberOfAjacentMines() << " ";
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

void Grid::checkAjacentMines(Vector2D initialCellPosition)
{
	Cell* currentCell = nullptr;
	Vector2D currentPos;
	Vector2D valueBuffer;

	std::vector<Vector2D> positonList;
	positonList.push_back(initialCellPosition);

	while (!positonList.empty()) 
	{
		valueBuffer = positonList.back();
		positonList.pop_back();

		for (int y = valueBuffer.getY() - 1; y < valueBuffer.getY() + 2; y++) 
		{
			for (int x = valueBuffer.getX() - 1; x < valueBuffer.getX() + 2; x++) 
			{
				if (!((x == valueBuffer.getX() && y == valueBuffer.getY()) || (x < 0 || y < 0) || (x >= gridWidth || y >= gridHeight)))
				{
					currentPos.setX(x);
					currentPos.setY(y);

					currentCell = &theCellArray[getCellPosition(currentPos)];

					if ((!currentCell->isCurrentlyVisible()) && (!currentCell->isAMine()))
					{
							currentCell->revealCell();
							noOfHiddenCells--;

							if (currentCell->getNumberOfAjacentMines() == 0)
							{
								positonList.push_back(currentPos);
							}
					}
				}
				currentPos.resetVector();
			}
		}
	}

	positonList.clear();
	return;
}

void Grid::placeMines(Difficulty difficultyFactor, int gridArea)
{
	srand(time(NULL));
	Vector2D minePosition;
	Vector2D navigationVector;
	Cell* currentCell = nullptr; // TODO - add pointer here to do conditional checks on the cell 
	
	numberOfFlags = numberOfMines = ((int)difficultyFactor * gridArea) / 10;
	noOfHiddenCells = gridArea - numberOfMines;

	for (int i = numberOfMines; i != 0; i--) 
	{
		minePosition.setX(rand() % gridWidth);
		minePosition.setY(rand() % gridHeight);

		currentCell = &theCellArray[getCellPosition(minePosition)];

		if (!currentCell->isAMine())
		{
			currentCell->placeMineHere();
			for (int y = minePosition.getY() - 1; y < minePosition.getY() + 2; y++) 
			{
				for (int x = minePosition.getX() - 1; x < minePosition.getX() + 2; x++)
				{
					if (!((x == minePosition.getX() && y == minePosition.getY()) || (x < 0 || y < 0) || (x >= gridWidth || y >= gridHeight))) 
					{
						navigationVector.setX(x);
						navigationVector.setY(y);

						theCellArray[getCellPosition(navigationVector)].addToNumberOfAjacentMines();
					}
				}
			}
		}
		else 
		{
			i++;
		}

		minePosition.resetVector();
		navigationVector.resetVector();
	}
	return;
}
