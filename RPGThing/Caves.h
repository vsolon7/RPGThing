#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Caves
{
public:
	Caves();
	~Caves();
	void doBattle(Player &);
	std::vector<int> createBasicEnemy(int);
	void enterCaves(Player &);

private:

	std::vector<std::string> enemyType = { "Mole","Bat","Bear","Gorgon","Cave Horror" };

};

/* armor formula:

1 - ((0.01 * x) / (1 + (0.01 * |x|))))

*/
