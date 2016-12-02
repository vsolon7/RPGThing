#pragma once
#include <vector>

struct Enemy
{
	//damage, armor, attack speed, health, dodge chance
	std::vector<int> trainingDummy = { 0, 0, 1, 25, 0 };
	std::vector<int> dummyDemon = { 50, 30, 1, 500, 20 };
};