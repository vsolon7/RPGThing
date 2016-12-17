#pragma once
#include <vector>
#include <string>

class Caves
{
public:
	Caves();
	~Caves();

private:

	std::vector<std::string> enemyType = { "Mole","Bat","Bear","Gorgon","Cave Horror" };

};

/* armor formula:

1 - ((0.01 * x) / (1 + (0.01 * |x|))))

*/
