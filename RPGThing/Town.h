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

private:
	int visits;
};

