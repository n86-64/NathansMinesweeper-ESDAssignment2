#include <iostream>
#include <string>

#pragma warning (disable : 4996)

int main() 
{
	char enterChar = '\0';
	std::string test = "Hello world"; 
	std::string printTest;

	for (int i = 0; i < test.length(); i++) 
	{
		printTest += test[i];
	}

	std::cout << printTest;
	scanf("%c", &enterChar);

	return 0;
}




// String verification Algorithm:
// 
// scan string for whitespaces (spaces)
// if whitespace detected then string is scanned into buffer and converted into appropriate value and buffer cleared. 
// else value added to buffer