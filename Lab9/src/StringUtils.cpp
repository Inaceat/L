#include "stdafx.h"

#include "StringUtils.hpp"


//If destinationis not large enough to contain the concatenated resulting string — it's only your problems! 
char* DumbStrCat(char* destination, const char* source)
{
	// ReSharper disable once CppCStyleCast
	//Yes, this is really shitty thing. Never repeat it at home!!!
	return (char*)memcpy(destination + strlen(destination), source, sizeof(char) * (strlen(source) + 1));
}


bool IsPalindrome(const char* string)
{
	auto stringLength = strlen(string);

	if (stringLength == 0)
		return true;


	auto first = string;
	auto last = string + stringLength - 1;


	while (true)
	{
		//Advance 'first' forward to 1st not 'delimiter'
		while (*first == ' ')
			first++;


		//Advance 'last' backward to 1st not 'delimiter', but not before 'first'
		while (*last == ' ' && last > first)
			last--;


		//We didn't find any contradictions, and 'last' before or the same as 'first' means that we ran out of valid chars. So it's palindrome.
		if (last <= first)
			return true;


		//Now 'first' and 'last' point to (maybe same) valid chars, and we can compare them.
		if (*first != *last)
			return false;

		first++;
		last--;
	}
}