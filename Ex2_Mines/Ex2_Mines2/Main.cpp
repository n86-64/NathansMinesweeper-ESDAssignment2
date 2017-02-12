/*
Module - UFCFWA-30-1
Name - Nathan Butt
Student No - 16013327

Exersice 2 - Minesweeper
File Name - Main.cpp
File Contents - The entrypoint to the Minesweeper Game. 

Purpose - The main thread where the application will both start and terminate. 
*/


// REVIEW - Use SDL for sound (easier?)

#include <iostream>
#include <string>

#include "Game.h"


int main() 
{
	Game theGame; 

	std::cout << "Welcome to Mainac Minesweeper \n"<<
 " __  __          _   _ _____          _____ \n"
" |  \/  |   /\   | \ | |_   _|   /\   / ____|  \n"
" | \  / |  /  \  |  \| | | |    /  \ | |      \n"
" | |\/| | / /\ \ | . ` | | |   / /\ \| |       \n"
" | |  | |/ ____ \| |\  |_| |_ / ____ | |____   \n" 
" |_|  |_/_/    \_|_| \_|_____/_/    \_\_____|   \n"
		<< std::endl
		<< "Copyright Nathan Butt/Maniac Software 2017"
		<< std::endl
		<< std::endl;

	theGame.startGame(); 

	return 0; 
}