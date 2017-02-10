#include "Settings.h"

Settings::Settings()
	: fieldDimenstions(10,10)
{
}

void Settings::restoreDefaults()
{
	fieldDimenstions.setX(10);
	fieldDimenstions.setY(10);
	classicMode = true;
	difficultyLevel = DIFFICULTY_EASY;
	return;
}

int Settings::getGridWidth()
{
	return fieldDimenstions.getX();
}

int Settings::getGridHeight()
{
	return fieldDimenstions.getY();
}

bool Settings::getClassicModeState()
{
	return classicMode;
}

Difficulty Settings::getDifficultyLevel()
{
	return difficultyLevel;
}

void Settings::setGridWidth(int newValue)
{
	fieldDimenstions.setX(newValue);
	return;
}

void Settings::setGridHeight(int newValue)
{
	fieldDimenstions.setY(newValue);
	return;
}

void Settings::setClassicModeState(int newValue)
{
	classicMode = newValue;
	return;
}

void Settings::setDifficultyLevel(int newValue)
{
	difficultyLevel = (Difficulty)newValue;
	return;
}
