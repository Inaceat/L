#include "stdafx.h"

#include "ConsoleUtils.hpp"

#include "StringUtils.hpp"


#include "Calculator.hpp"



void Task1()
{
	std::string first;
	std::string second;


	std::cout << "First string: ";
	std::cin >> first;

	std::cout << "Second string: ";
	std::cin >> second;


	auto dumbResult = new char[first.size() + second.size() + 1];
	auto libResult = new char[first.size() + second.size() + 1];


	strcpy(dumbResult, first.c_str());
	strcpy(libResult, first.c_str());


	DumbStrCat(dumbResult, second.c_str());
	strcat(libResult, second.c_str());

	std::cout << "Dumb result: " << dumbResult << std::endl;
	std::cout << "Library result: " << libResult << std::endl;


	delete[] dumbResult;
	delete[] libResult;
}

void Task2()
{
	std::string str;

	do
	{
		std::cout << "Enter your string: ";
		std::cin >> str;

		std::cout << "This is " << (IsPalindrome(str.c_str()) ? "" : "not ") << "palindrome." << std::endl << std::endl;
		std::cout << "Press space to try again:" << std::endl;
	}
	while (_getwch() == ' ');
}

void TaskExtra()
{
	std::string expression;

	std::cout << "Welcome to the most stupid calculator! " << std::endl;
	std::cout << "Please, use only digits, parentheses and +, -, * and / operations." << std::endl;
	
	ConsoleHelper::SaveConsoleCursorPosition();

	do
	{
		ConsoleHelper::RestoreConsoleCursorPosition();


		std::cout << "Expression input: " << std::endl;
		std::cin >> expression;


		std::cout << Evaluate(expression) << std::endl;

		std::cout << "Press space to another try..." << std::endl;
	} 
	while (_getch() == ' ');
}



int main()
{
	//Task1();
	//Task2();

	TaskExtra();
}