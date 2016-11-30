#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

struct Text //all functions that will affect text output such as color changes
{
	std::string Text::getInput()
	{
		std::string in = "";
		std::cout << "\n\n>> ";
			getline(std::cin, in);

		return in;
	}
};

