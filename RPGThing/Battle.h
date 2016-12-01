#pragma once
#include "Player.h"
#include <vector>
class Battle
{
public:
	Battle();
	~Battle();
	
	int dmgRoll(int);
	bool dodgeRoll(float);
	bool critRoll(float);
	int doBattle(Player, std::vector<int>);
	int enemyAttack(Player, std::vector<int>);
	int playerAttack(Player, std::vector<int>);
};

