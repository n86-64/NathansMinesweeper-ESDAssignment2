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
}
