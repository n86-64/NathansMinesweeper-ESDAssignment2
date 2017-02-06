#include <locale>
#include "gameMenu.h"

gameMenu::gameMenu() 
{

}

void gameMenu::printMenu()
{
	std::cout << "Press the corrisponding key + ENTER to select an option"
		<< std::endl
		<< "P - Play" << std::endl
		<< "S - Settings" << std::endl
		<< "E - Exit" << std::endl;
}

int gameMenu::retrieveMenuSelection()
{
	std::string menuInput;
	std::locale loc;
	int menuSelection = 0;
	bool inputIsValid = true; 


	do 
	{
		std::cout << ">>> ";
		std::getline(std::cin, menuInput);
		menuInput[0] = std::toupper(menuInput[0], loc);

		inputIsValid = true;

		if (menuInput.length() == 1) 
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
				std::cout << "Invalid option. Please choose a valid option from above."
				          << std::endl;
				inputIsValid = false;
			}
		}
		else 
		{
			std::cout << "Input is too long. Input should be a single character + the ENTER key. Please enter a valid input"
				      << std::endl;
			inputIsValid = false;
		}


	} while (!inputIsValid);

	return menuSelection;
}
