/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Settings.h
File Contents - The class definition for the Settings Class as well as the difficulty parameter definition. 

Purpose - The main class object which will process store the parameters for the minesweeper application.
*/

#pragma once


#include "Math_Vector2D.h"


enum Difficulty {
	DIFFICULTY_EASY = 1,
	DIFFICULTY_MEDIUM,
	DIFFICULTY_HARD
};


class Settings {
public:
	Settings();

	void restoreDefaults(); 

	// get/set
	int getGridWidth();
	int getGridHeight();
	bool getClassicModeState();
	Difficulty getDifficultyLevel(); 


	void setGridWidth(int newValue);
	void setGridHeight(int newValue);
	void setClassicModeState(int newValue);
	void setDifficultyLevel(int newValue);

private:
	Vector2D fieldDimenstions;
	bool classicMode = true; 
	Difficulty difficultyLevel = DIFFICULTY_EASY;
};