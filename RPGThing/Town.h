#pragma once
#include "Storyline.h"
#include <iostream>

class Town
{
public:
	Town();
	~Town();
	void visitTown(Player&);
	void townFirstVisit(Player&);
	void mapChoice(Player&);
	void printMap();

private:
	int visits;
};

