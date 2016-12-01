#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#define NORMAL 40
#define INTENSE 25
#define THOUGHT 30 //the delay values in milliseconds of letters appearing on the screen in the printDelayed function
#define SLOW 75

#define WHITE 1
#define RED 2
#define BLUE 3
#define GREEN 4
#define YELLOW 5
#define MAGENTA 6

#define BLANK_LINE "\n\n" //blank line
#define SPACER "==================================================\n" //spacer
#define GAME_NAME "RPGThing" //the name of the game, may change

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

	void Text::setColor(int color)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (color)
		{
		case 1:
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		case 2:
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case 3:
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 4:
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 5:
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 6:
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		}
	}
};

