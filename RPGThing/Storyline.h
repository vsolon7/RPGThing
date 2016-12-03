#pragma once
#include <string>
#include "Player.h"
class Storyline
{
public:
	Storyline();
	~Storyline();

	void introduction();
	void printCharacterSelection();
	void printClassSelection();
	void rollChar(int);
	std::string classNumberToString(int);
	std::string adaptionNumberToString(int);
	void theStoryIntro();

	Player p;
};

