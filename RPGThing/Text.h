#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#define NORMAL 40
#define INTENSE 25
#define THOUGHT 50 //the delay values in milliseconds of letters appearing on the screen in the printDelayed function

class Text //all functions that will affect text output such as color changes
{
public:
	std::string Text::getStringInput()
	{
		std::string in = "";
		std::cout << "\n\n>> ";
			getline(std::cin, in);

		return in;
	}

	int Text::getIntInput()
	{
		int i = 0;
		std::cout << "\n\n>> ";
			std::cin >> i;

		return i;
	}

	void Text::printDelayed(std::string p, int d) //prints one letter at a time, sleeps for a delay in milliseconds. Makes letters appear one at a time.
	{
		for (int i = 0; i < p.length(); i++)
		{
			std::cout << p[i];
			Sleep(d);
		}
	}
};

