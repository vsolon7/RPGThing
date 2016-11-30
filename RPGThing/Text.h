#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

struct Text
{
	std::string Text::getInput()
	{
		std::string in = "";
		std::cout << "\n\n>> ";
			getline(std::cin, in);

		return in;
	}
};

