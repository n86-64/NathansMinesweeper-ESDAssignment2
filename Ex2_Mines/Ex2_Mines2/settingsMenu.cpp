#include <locale>
#include "settingsMenu.h"


settingsMenu::settingsMenu(Settings* parameterData)
	: settingsToModify(parameterData)
{
}

settingsMenu::~settingsMenu()
{
}

void settingsMenu::printMenu()
{
	bool stayInMenu = true;

	while (stayInMenu)
    {
		system("cls");

		std::cout << "Press the corresponding character followed by the new parameter value you wish to set." << std::endl
			<< "W - Grid Width (Current Value = " << settingsToModify->getGridWidth() << ")" << std::endl
			<< "H - Grid Height (Current Value = " << settingsToModify->getGridHeight() << ")" << std::endl
			<< "E - Enable Classic Mode (Time and revealing blank ajacent cells) (1 = Enabled, 0 = Disabled) (Current Value = "
			<< (int)settingsToModify->getClassicModeState()
			<< ")" << std::endl
			<< "D - Difficulty Level (1 = easy, 2 = medium, 3 = hard) (Current Value = " << (int)settingsToModify->getDifficultyLevel() << ")" << std::endl
			<< "R - Restore default settings " << std::endl
			<< "B - Go Back to the main menu" << std::endl;


		retrieveMenuSelection(stayInMenu);
	}
	return;
}

void settingsMenu::retrieveMenuSelection(bool& inMenu)
{
	bool isValid; 
	std::string theInput;
	std::locale loc;
	int parameterValue;

	do  
	{
		std::cin.clear();
		theInput.clear();
		parameterValue = 0;

		std::cout << ">>> ";
		std::getline(std::cin, theInput);
		theInput[0] = std::toupper(theInput[0], loc);

		isValid = true; 
		if (checkInput(theInput, parameterValue)) 
		{
			switch (theInput[0])
			{
			case 'W':
				if (checkInputRangeValid(parameterValue,8,100,isValid)) 
				{
					settingsToModify->setGridWidth(parameterValue);
				}
				break;
			case 'H':
				if (checkInputRangeValid(parameterValue, 8, 100, isValid))
				{
					settingsToModify->setGridHeight(parameterValue);
				}
				break;
			case 'E':
				if (checkInputRangeValid(parameterValue, 0, 1, isValid))
				{
					settingsToModify->setClassicModeState(parameterValue);
				}
				break;
			case 'D':
				if (checkInputRangeValid(parameterValue, 1, 3, isValid))
				{
					settingsToModify->setDifficultyLevel(parameterValue);
				}
				break;
			case 'R':
				settingsToModify->restoreDefaults();
				break;
			case 'B':
				inMenu = false;
				break;
			default:
				std::cout << "Error the input entered is invalid please re-enter your selection (<Option> <Value>)"
					<< std::endl;
				isValid = false; 
			}
		}
		else 
		{
			isValid = false;
			std::cout << "Error the input entered is invalid please re-enter your selection (<Option> <Value>)"
				<< std::endl;
		}

	} while (!isValid);
	return;
}

// REVIEW - consider cleaning up this function as unnessecery evaluation takes place. 
bool settingsMenu::checkInput(std::string input, int& parameterValue)
{
	int whitespaces = 0;
	std::string valueBuffer;
	
	if (input[0] == 'B' || input[0] == 'R') 
	{
		return true;
	}
	else 
	{
		if (input.length() >= 3)
		{
			for (int i = 1; i < (int)input.length(); i++)
			{
				if (whitespaces <= 1)
				{
					if (input[i] == ' ')
					{
						whitespaces++;
					}
					else
					{
						if (input[i] >= 48 && input[i] <= 57)
						{
							valueBuffer += input[i];
						}
					}
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}

		if (!valueBuffer.empty()) 
		{
			parameterValue = std::stoi(valueBuffer);
			return true;
		}
		else 
		{
			return false;
		}
	}
}

bool settingsMenu::checkInputRangeValid(int paramValue, int rangeMin, int rangeMax, bool & validFlag)
{
	if (paramValue < rangeMin || paramValue > rangeMax) 
	{
		std::cout << "Error your value is out of range. Please enter a valid value."
			<< std::endl;
		validFlag = false;
		return false;
	}

	return true;
}

