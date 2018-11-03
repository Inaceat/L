#include "stdafx.h"


#include "ConsoleUtils.hpp"


HANDLE ConsoleHelper::_consoleHandle;
_COORD ConsoleHelper::_savedCursorPosition;


void ConsoleHelper::SaveConsoleCursorPosition()
{
	_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(_consoleHandle, &consoleInfo);

	_savedCursorPosition = consoleInfo.dwCursorPosition;
}

void ConsoleHelper::RestoreConsoleCursorPosition(bool clear)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(_consoleHandle, &consoleInfo);

	auto currentCursorPosition = consoleInfo.dwCursorPosition;


	auto charsToFill = 0;


	DWORD written;
	FillConsoleOutputCharacter(_consoleHandle, ' ', charsToFill, _savedCursorPosition, &written);

	SetConsoleCursorPosition(_consoleHandle, _savedCursorPosition);
}