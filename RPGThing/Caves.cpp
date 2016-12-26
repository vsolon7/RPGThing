#include "Caves.h"
#include "Battle.h"
#include "Text.h"
#include <random>
#include <ctime>

//TODO: caves area enemy generation!!

Caves::Caves()
{}

std::vector<int> Caves::createBasicEnemy(int level)
{
	Enemy e;
	

	std::vector<int> tempenemy = e.basicCaveEnemy;

	tempenemy[0] += (2 + (pow(1.1, level) - 1.1)); //1.1^x -1.1
	tempenemy[1] += 0;
	tempenemy[2] += 1;
	tempenemy[3] += (((.33) * (level + 3) * (level + 3)) - (2 * level + 3)) + 5; // (1/3 (x+3)^2) - (2x + 3);
	tempenemy[4] += 0;
	tempenemy[5] = level;

	return tempenemy;
}

void Caves::doBattle(Player &p)
{
	Enemy e;
	Battle b;
	Text t;

	static int totalInstanceFights = 0;

	std::mt19937 randEngine(time(0));
	std::uniform_int_distribution<int> tierRandomGen(0, 10000 - totalInstanceFights * 100); //the longer you stay in, the harder prefixes you roll.
	std::uniform_int_distribution<int> randomPref(1, 6);

	std::vector<int> enemy(6);

	int currentPlayerLevel = p.getLevel();
	enemy = createBasicEnemy(currentPlayerLevel);

	int rTier = tierRandomGen(randEngine);
	int tier;

	if (rTier < 5000)
	{
		if (rTier < 2500)
		{
			if (rTier < 1250)
			{
				if (rTier < 625)
				{
					if (rTier < 313)
					{
						tier = 6;
					} else
						tier = 5;
				} else
					tier = 4;
			} else 
				tier = 3;
		} else
			tier = 2;
	} else
		tier = 1;

	int prefPick = (6 * (tier - 1)) + randomPref(randEngine);

	for (unsigned int i = 0; i < enemy.size(); i++)
		enemy[i] *= e.prefixStats[prefPick].at(i);

	std::cout << BLANK_LINE;
	std::cout << "A " << e.getPrefix(prefPick) << " ";
	std::cout << enemyType[rand() % 5] << " attacks you!";
	std::cout << BLANK_LINE;
	
	if (b.doBattle(p, enemy) != 0)
	{
		t.setColor(RED);
		t.printDelayed("You take a fatal hit. The world goes black...", 100); t.setColor(WHITE);
		std::cout << BLANK_LINE;
		system("cls");
	} 

	totalInstanceFights++;
}

void Caves::enterCaves(Player &p)
{
	Text t;
	std::string choice;
	bool fight = true;
	p.instance = CAVES;

	t.printDelayed("You enter the caves.", 50);
	t.enterPause();

	std::cout << std::endl;
	while (fight == true)
	{
		t.printDelayed("What would you like to do, ", 8); t.setColor(RED);
		t.printDelayed("fight", 8); t.setColor(WHITE);
		t.printDelayed(" or ", 8); t.setColor(YELLOW);
		t.printDelayed("leave", 8); t.setColor(WHITE);
		std::cout << std::endl;

		do
		{
			choice = t.getStringInput();
		} while (choice != "fight" && choice!= "Fight" && choice != "leave" && choice != "Leave" && choice != "");
		
		if (choice == "fight" || choice == "Fight" || choice == "")
		{
			doBattle(p);
		}
		if (choice == "leave" || choice == "Leave")
		{
			t.printDelayed("You leave the caves", 50);
			t.enterPause();
			std::cout << BLANK_LINE;
			fight = false;
		}
	}
}

Caves::~Caves()
{}
