/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - GameState.h
File Contents - An enumeration definition for the current state of the game. 

Purpose - Used to track the game state and to rispond accordingly.
*/

#pragma once

enum GameState
{
	GAMESTATE_PLAYING = 0,
	GAMESTATE_WIN,
	GAMESTATE_LOSS,
	GAMESTATE_QUIT
};

