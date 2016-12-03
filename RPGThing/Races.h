#pragma once
#include <string>

struct Improvisation
{
	int raceVal = 1;
	std::string adaptionName = "Improvisation";
	std::string abilityOne = "JACK OF ALL TRADES: \n-You get double stats when you level up!\n";
	std::string abilityTwo = "ADAPTABILITY: \n-You gain a flat +5% buff to all stats that involve percents.";
};

struct Grace
{
	int raceVal = 2;
	std::string raceName = "Grace";
	std::string abilityOne = "QUICK THINKING: \n-You have a multiplicative 15% increase to agility related stats.\n";
	std::string abilityTwo = "DEATH DODGER: \n-You avoid death when you would normally recieve a fatal blow once per battle.";
};

struct Battlewise
{
	int raceVal = 3;
	std::string raceName = "Battlewise";
	std::string abilityOne = "BRED TO FIGHT: \n-You deal 10% more melee damage.\n";
	std::string abilityTwo = "TOUGH AS NAILS: \n-You have 25% increased armor.";
};

struct Shaper
{
	int raceVal = 4;
	std::string raceName = "Shaper";
	std::string abilityOne = "FORCE: \n-You deal 7% more magic damage.\n";
	std::string abilityTwo = ": \n-You have 15% increased life regeneration rate.";
};

struct Outlasting
{
	int raceVal = 5;
	std::string raceName = "Outlasting";
	std::string abilityOne = "HOLY STRENGTH: \n-You have a multiplicative 40% more crit multiplier.\n";
	std::string abilityTwo = "PURITY: \n-You have a base 7% lifesteal.";
};