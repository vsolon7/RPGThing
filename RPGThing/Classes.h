#pragma once
#include <string>

struct Warrior
{
	std::string className = "Warrior";
	int classVal = 1;
	std::string classDesc = "The basic melee class. Good damage, good defenses! E a s y.";

	int primaryStat = 1;
	int minStr = 10;
	int minAgi = 1;
	int minInt = 1;
};

struct Archer
{
	std::string className = "Archer";
	int classVal = 2;
	std::string classDesc = "The ranged class, gets bonus attack speed! Bad defenses";

	int primaryStat = 2;
	int minStr = 1;
	int minAgi = 10;
	int minInt = 1;
};

struct Mage
{
	std::string className = "Mage";
	int classVal = 3;
	std::string classDesc = "The magic class. Bad defenses good damage. Casts spells :0.";

	int primaryStat = 3;
	int minStr = 1;
	int minAgi = 1;
	int minInt = 10;
};

struct Rogue
{
	std::string className = "Rogue";
	int classVal = 4;
	std::string classDesc = "The second melee class. Great crits, great dodge - bad defenses.";

	int primaryStat = 2;
	int minStr = 7;
	int minAgi = 7;
	int minInt = 1;
};

struct Tank
{
	std::string className = "Tank";
	int classVal = 5;
	std::string classDesc = "The third melee class \"Why should I dodge blows that I do not fear?\"";

	int primaryStat = 1;
	int minStr = 14;
	int minAgi = 1;
	int minInt = 1;
};