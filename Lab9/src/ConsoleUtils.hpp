#pragma once


#include <Windows.h>


class ConsoleHelper
{
private:
	static HANDLE _consoleHandle;
	static _COORD _savedCursorPosition;


public:
	static void SaveConsoleCursorPosition();

	//Moves console cursor to previous saved position, deleting all symbols after it, if 'clear' set to true.
	static void RestoreConsoleCursorPosition(bool clear = true);
};