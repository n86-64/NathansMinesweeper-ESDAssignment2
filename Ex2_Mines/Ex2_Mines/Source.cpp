#include <iostream>
#include <string>

#pragma warning (disable : 4996)



void refrenceTest() 
{
	int* Point = new int(100);
	delete Point;
}



int main() 
{

	char enterChar = '\0';
	std::string test = "Hello world"; 
	std::string test2; 
	std::string printTest;



	for (int i = 0; i < test.length(); i++) 
	{
		printTest += test[i];
	}

	// refrenceTest();


	scanf("%c", &enterChar);

	return 0;
}




// String verification Algorithm:
// 
// scan string for whitespaces (spaces)
// if whitespace detected then string is scanned into buffer and converted into appropriate value and buffer cleared. 
// else value added to buffer