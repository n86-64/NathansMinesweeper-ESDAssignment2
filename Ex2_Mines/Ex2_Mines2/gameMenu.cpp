#include <locale>
#include "gameMenu.h"


void gameMenu::printMenu()
{
	std::cout << "Press the corrisponding key + ENTER to select an option"
		<< std::endl
		<< "P - Play" << std::endl
		<< "S - Settings" << std::endl
		<< "E - Exit" << std::endl
		<< ">>> " << std::endl;
}

int gameMenu::retrieveMenuSelection()
{
	std::string menuInput;
	std::locale loc;
	int menuSelection = 0;
	bool inputIsValid = true; 

	do 
	{
		std::getline(std::cin, menuInput);
		std::toupper(menuInput, loc);
		inputIsValid = true;

		if (menuInput.length == 1) 
		{
			switch (menuInput[0])
			{
			case 'P':
				menuSelection = 1;
				break;
			case 'S':
				menuSelection = 2;
				break;
			case 'E':
				menuSelection = 3;
				break;
			default:
				inputIsValid = false;
			}
		}
		else 
		{
			inputIsValid = false;
		}

	} while (!inputIsValid);

	return menuSelection;
}
