/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Math_Vector2D.h
File Contents - The class definition for the Vector2D class.

Purpose - Used for storing and setting grid coordinates and other similar parameters. 
*/


#pragma once


class Vector2D {
public:
	Vector2D();
	Vector2D(int X, int Y);

	int getX();
	int getY();
	int setX(int newValue);
	int setY(int newValue);

private:
	// REVIEW - should be constructed to -1 by default? 
	int x = 0;
	int y = 0;
};