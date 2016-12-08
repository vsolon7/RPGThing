#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "portability.h"

#define NORMAL 40
#define INTENSE 25
#define THOUGHT 30 //the delay values in milliseconds of letters appearing on the screen in the printDelayed function
#define SLOW 50

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
	std::string getStringInput()
	{
		std::string in = "";
		std::cout << "\n\n>> ";
			getline(std::cin, in);

		return in;
	}

	int getIntInput()
	{
		int i = 0;
		std::cout << "\n\n>> ";
			std::cin >> i;

		return i;
	}

	void printDelayed(std::string p, int d) //prints one letter at a time, sleeps for a delay in milliseconds. Makes letters appear one at a time.
	{
		if (d == THOUGHT) //just so I don't have to do this manually every time the character thinks.
			setColor(YELLOW);

		for (int i = 0; i < p.length(); i++)
		{
			std::cout << p[i];
			std::cout.flush();
			Sleep(d);
		}
		setColor(WHITE);
	}

	void setColor(int color)
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

	void dotPause(int seconds)
	{
		std::string dots = "";
		int length = 0;
		for (int i = 0; i < ((seconds * 3) * 2); i++)
		{
			if (i % 2 == 0)
				dots += ' ';

			else
				dots += '.';

			length++;
		}

		printDelayed(dots, (((float)seconds / length) * 1000));
		std::cout << BLANK_LINE;
	}

	void enterPause()
	{
		_getch();
		std::cout << "\n";
	}
};

